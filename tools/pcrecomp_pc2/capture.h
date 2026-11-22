#ifndef PC2_CAPTURE_H
#define PC2_CAPTURE_H

#include "recomp_types.h"

enum pc2_edge_kind {
    PC2_EDGE_DIRECT = 1,
    PC2_EDGE_INDIRECT,
    PC2_EDGE_TAIL,
    PC2_EDGE_RETURN_JUMP,
    PC2_EDGE_HOST_CALL,
};

void pc2_capture_init(void);
void pc2_capture_boot_ready(void);
void pc2_capture_poll(void);
void pc2_capture_guest_exit(int status);
void pc2_capture_enter(uint32_t address);
void pc2_capture_direct(uint32_t site, uint32_t target);
void pc2_capture_site(uint32_t site, enum pc2_edge_kind kind);
void pc2_capture_resolved(uint32_t target, int resolved);
void pc2_capture_host_call(uint32_t target, int resolved, int nargs);
void pc2_capture_import(uint32_t address, const char *name);
void pc2_capture_invoke_shim(uint32_t address, recomp_func_t fn);

struct pc2_fixture_scope {
    uint32_t address, object, plan_slot, args[4], before[8];
};

extern uint32_t pc2_capture_fixture_mode;
struct pc2_fixture_scope pc2_capture_fixture_begin(uint32_t address);
void pc2_capture_fixture_end(struct pc2_fixture_scope *scope);

#define PC2_CAPTURE_FIXTURE_SCOPE(address) \
    struct pc2_fixture_scope pc2_fixture __attribute__((cleanup(pc2_capture_fixture_end))) = \
        pc2_capture_fixture_mode ? pc2_capture_fixture_begin(address) : (struct pc2_fixture_scope){0}

static inline recomp_func_t pc2_capture_resolve(uint32_t address) {
    recomp_func_t fn = recomp_resolve(address);
    pc2_capture_resolved(address, fn != NULL);
    return fn;
}

#define PC2_CAPTURE_ENTER(address) do { \
    RECOMP_ENTER(address); \
    pc2_capture_enter(address); \
} while (0)

#define PC2_CAPTURE_CALL(site, address, call, fn) do { \
    pc2_capture_direct(site, address); \
    call(fn); \
} while (0)

#define PC2_CAPTURE_INDIRECT(site, kind, call, target) do { \
    pc2_capture_site(site, kind); \
    call(target); \
} while (0)

#endif
