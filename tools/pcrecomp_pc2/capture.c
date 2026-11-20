#include "capture.h"
#include "win32hle.h"

#include <stdatomic.h>
#include <sys/uio.h>
#include <unistd.h>

/* The little-endian capture protocol is also read and written by capture.py. */
enum command_kind {
    BEGIN = 1, END, SNAPSHOT, WAIT_FUNCTION, WAIT_VALUE, DELAY_MS,
    MOUSE, KEY, WHEEL, ASSERT_VALUE, POST, CLICK,
};
enum event_kind { ENTRY = 1, EDGE, MESSAGE, STEP, WATCH, FINISH, LIMIT };
enum finish_reason { COMPLETED = 1, ASSERTION_FAILED, GUEST_EXIT };
enum edge_result { MISSING = 0, RESOLVED, RETURN_SENTINEL };

struct command { uint32_t op, a, b, c; };
struct watch {
    uint32_t address, size, depth, offsets[6];
};
struct plan_header { uint32_t magic, version, commands, watches, event_limit; };
struct event { uint32_t op, thread, a, b, c, d, e, f, g, h, i; };

_Static_assert(sizeof(struct command) == 16, "capture command format");
_Static_assert(sizeof(struct watch) == 36, "capture watch format");
_Static_assert(sizeof(struct plan_header) == 20, "capture plan format");
_Static_assert(sizeof(struct event) == 44, "capture event format");

static struct plan_header plan;
static struct command *commands;
static struct watch *watches;
static FILE *events;
static FILE *imports;
static _Atomic int finished;
static uint32_t step, function_hits, delay_start;
static int active, delay_armed;
static uint32_t recorded;
static _Atomic uint32_t next_thread;
static _Thread_local uint32_t thread_id;
static _Thread_local uint32_t import_in_progress;
static _Thread_local uint32_t indirect_site;
static _Thread_local enum pc2_edge_kind indirect_kind;

static void fail(const char *reason) {
    fprintf(stderr, "PC2 capture: %s\n", reason);
    _Exit(2);
}

static void write_event(struct event event) {
    if (!thread_id) thread_id = atomic_fetch_add(&next_thread, 1) + 1;
    event.thread = thread_id;
    if (fwrite(&event, sizeof event, 1, events) != 1) fail("could not write events");
}

static void emit_runtime(struct event event) {
    if (atomic_load_explicit(&finished, memory_order_relaxed)) return;
    if (plan.event_limit && recorded >= plan.event_limit) {
        if (recorded == plan.event_limit) {
            write_event((struct event){.op = LIMIT, .a = plan.event_limit});
            recorded++;
        }
        return;
    }
    write_event(event);
    recorded++;
}

static void flush(void) {
    if (fflush(events) || fflush(imports)) fail("could not flush capture files");
}

static void write_finish(enum finish_reason reason, int status) {
    if (!events || atomic_exchange(&finished, 1)) return;
    write_event((struct event){.op = FINISH, .a = reason, .b = (uint32_t)status, .c = step});
    flush();
}

void pc2_capture_guest_exit(int status) {
    write_finish(GUEST_EXIT, status);
}

static void trace_message(uint32_t hwnd, uint32_t msg, uint32_t wp, uint32_t lp) {
    if (active)
        emit_runtime((struct event){.op = MESSAGE, .a = hwnd, .b = msg, .c = wp, .d = lp,
                                    .e = g_cur_func});
}

static FILE *open_output(const char *variable) {
    const char *path = getenv(variable);
    FILE *file = path ? fopen(path, "wb") : NULL;
    if (!file) fail(variable);
    return file;
}

void pc2_capture_init(void) {
    const char *path = getenv("PC2_CAPTURE_PLAN");
    if (!path) return;
    FILE *file = fopen(path, "rb");
    if (!file || fread(&plan, sizeof plan, 1, file) != 1 || plan.magic != 0x54324350u ||
        plan.version != 1 || !plan.commands || plan.commands > 10000 || plan.watches > 1024)
        fail("invalid replay plan header");
    commands = calloc(plan.commands, sizeof *commands);
    watches = calloc(plan.watches ? plan.watches : 1, sizeof *watches);
    if (!commands || !watches ||
        fread(watches, sizeof *watches, plan.watches, file) != plan.watches ||
        fread(commands, sizeof *commands, plan.commands, file) != plan.commands || fgetc(file) != EOF)
        fail("invalid replay plan body");
    fclose(file);
    for (uint32_t i = 0; i < plan.watches; ++i) {
        if (watches[i].depth > 6 || (watches[i].size != 1 && watches[i].size != 2 &&
                                    watches[i].size != 4 && watches[i].size != 8))
            fail("invalid watch");
    }
    events = open_output("PC2_CAPTURE_EVENTS");
    imports = open_output("PC2_CAPTURE_IMPORTS");
    hle_proc_hook = trace_message;
    hle_on_exit = pc2_capture_guest_exit;
}

void pc2_capture_import(uint32_t address, const char *name) {
    if (imports && fprintf(imports, "%08x\t%s\n", address, name) < 0)
        fail("could not write import names");
}

void pc2_capture_invoke_shim(uint32_t address, recomp_func_t fn) {
    uint32_t previous = import_in_progress;
    import_in_progress = address;
    fn();
    import_in_progress = previous;
}

void pc2_capture_enter(uint32_t address) {
    if (step < plan.commands && commands[step].op == WAIT_FUNCTION &&
        commands[step].a == address && function_hits < commands[step].b)
        function_hits++;
    if (active)
        emit_runtime((struct event){.op = ENTRY, .a = address, .b = g_eax, .c = g_ecx,
                                    .d = g_edx, .e = g_ebx, .f = g_esp, .g = g_ebp,
                                    .h = g_esi, .i = g_edi});
}

static void trace_edge(uint32_t site, uint32_t target, enum pc2_edge_kind kind,
                       enum edge_result result, uint32_t nargs) {
    if (active)
        emit_runtime((struct event){.op = EDGE, .a = g_cur_func, .b = site, .c = target,
                                    .d = kind, .e = result, .f = import_in_progress,
                                    .g = nargs});
}

void pc2_capture_direct(uint32_t site, uint32_t target) {
    trace_edge(site, target, PC2_EDGE_DIRECT, RESOLVED, 0);
}

void pc2_capture_site(uint32_t site, enum pc2_edge_kind kind) {
    indirect_site = site;
    indirect_kind = kind;
}

void pc2_capture_resolved(uint32_t target, int resolved) {
    enum edge_result result = resolved ? RESOLVED : MISSING;
    if (!resolved && indirect_kind != PC2_EDGE_INDIRECT && target == RECOMP_RETADDR)
        result = RETURN_SENTINEL;
    trace_edge(indirect_site, target, indirect_kind, result, 0);
}

void pc2_capture_host_call(uint32_t target, int resolved, int nargs) {
    trace_edge(0, target, PC2_EDGE_HOST_CALL, resolved ? RESOLVED : MISSING, (uint32_t)nargs);
}

static int read_guest(uint32_t address, void *output, uint32_t size) {
    if (!address) return 0;
    struct iovec local = {output, size};
    struct iovec remote = {hle_ptr(address), size};
    return process_vm_readv(getpid(), &local, 1, &remote, 1, 0) == (ssize_t)size;
}

static struct event read_watch(uint32_t index) {
    if (index >= plan.watches) fail("invalid watch index");
    const struct watch *watch = &watches[index];
    uint32_t address = watch->address;
    struct event event = {.op = WATCH, .a = step, .b = index};
    for (uint32_t i = 0; i < watch->depth; ++i) {
        uint32_t pointer;
        event.f = address;
        if (!read_guest(address, &pointer, sizeof pointer) || !pointer) return event;
        address = pointer + watch->offsets[i];
    }
    uint64_t value = 0;
    event.f = address;
    event.e = read_guest(address, &value, watch->size);
    if (event.e) {
        event.c = (uint32_t)value;
        event.d = (uint32_t)(value >> 32);
    }
    return event;
}

static void checkpoint(void) {
    for (uint32_t i = 0; i < plan.watches; ++i)
        write_event(read_watch(i));
    flush();
}

static void emit_step(void) {
    write_event((struct event){.op = STEP, .a = step, .b = hle_ticks_ms()});
}

static void checkpoint_step(uint32_t op) {
    emit_step();
    checkpoint();
    if (op == BEGIN) active = 1;
    if (op == END) active = 0;
}

void pc2_capture_boot_ready(void) {
    if (events && commands[0].op == BEGIN) {
        checkpoint_step(BEGIN);
        step++;
    }
}

void pc2_capture_poll(void) {
    if (!events || atomic_load_explicit(&finished, memory_order_relaxed)) return;
    while (step < plan.commands) {
        const struct command *command = &commands[step];
        int input = 0;
        switch (command->op) {
        case BEGIN:
        case END:
        case SNAPSHOT:
            checkpoint_step(command->op);
            break;
        case WAIT_FUNCTION:
            if (function_hits < command->b) return;
            emit_step();
            break;
        case WAIT_VALUE:
        case ASSERT_VALUE: {
            struct event value = read_watch(command->a);
            int equal = value.e && value.c == command->b && value.d == command->c;
            if (!equal && command->op == WAIT_VALUE) return;
            emit_step();
            write_event(value);
            if (!equal) {
                write_finish(ASSERTION_FAILED, 1);
                hle_exit(1);
            }
            break;
        }
        case DELAY_MS: {
            uint32_t now = hle_ticks_ms();
            if (!delay_armed) {
                delay_start = now;
                delay_armed = 1;
            }
            if (now - delay_start < command->a) return;
            emit_step();
            break;
        }
        case MOUSE:
            emit_step();
            hle_input_mouse(command->a, (int32_t)command->b, (int32_t)command->c);
            input = 1;
            break;
        case KEY:
            emit_step();
            hle_input_key(command->a, command->b, command->c);
            input = 1;
            break;
        case WHEEL:
            emit_step();
            hle_input_wheel((int32_t)command->a);
            input = 1;
            break;
        case POST: {
            uint32_t hwnd = hle_first_hwnd();
            if (!hwnd) return;
            emit_step();
            hle_post_message(hwnd, command->a, command->b, command->c);
            break;
        }
        case CLICK: {
            uint32_t hwnd = hle_first_hwnd();
            if (!hwnd) return;
            uint32_t point = (command->b << 16) | (command->a & 0xffffu);
            emit_step();
            hle_post_message(hwnd, 0x0200, 0, point);
            hle_post_message(hwnd, 0x0201, 1, point);
            hle_post_message(hwnd, 0x0202, 0, point);
            input = 1;
            break;
        }
        default:
            fail("unknown replay command");
        }
        step++;
        function_hits = 0;
        delay_armed = 0;
        if (input) return;
    }
    write_finish(COMPLETED, 0);
    hle_exit(0);
}
