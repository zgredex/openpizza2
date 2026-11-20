#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#include "host.h"
#include "win32hle.h"
#include "ddraw_int.h"
#ifdef PC2_CAPTURE
#include "capture.h"
#endif

int pc2_register_shims(void);

static int pc2_saw_menu;

static uint32_t pc2_checksum(const uint8_t *p, size_t n) {
    uint32_t h = 2166136261u;
    for (size_t i = 0; i < n; i++) h = (h ^ p[i]) * 16777619u;
    return h;
}

static int pc2_blit_hook(surf_t *d, int dl, int dt, int dr, int db,
                         surf_t *s, int sl, int st, int sr, int sb,
                         int keyed, uint32_t klo, uint32_t khi) {
    static int n;
    static int traced;
    int detailed = getenv("PC2_TRACE_DDBLT") && pc2_saw_menu && traced < 6;
    if (n++ >= 20) return 0;
    uint32_t src_sum = s && s->px ? pc2_checksum(s->px, (size_t)s->pitch * (size_t)s->h) : 0;
    uint32_t dst_sum = d && d->px ? pc2_checksum(d->px, (size_t)d->pitch * (size_t)d->h) : 0;
    fprintf(stderr,
            "[trace] DDBLT d=%u primary=%d %dx%d bpp=%d pitch=%d rect=%d,%d..%d,%d "
            "s=%u %dx%d bpp=%d pitch=%d rect=%d,%d..%d,%d keyed=%d srcsum=%08X dstsum_before=%08X\n",
            d ? d->self : 0, d ? d->primary : 0, d ? d->w : 0, d ? d->h : 0,
            d ? d->bpp : 0, d ? d->pitch : 0, dl, dt, dr, db,
            s ? s->self : 0, s ? s->w : 0, s ? s->h : 0, s ? s->bpp : 0,
            s ? s->pitch : 0, sl, st, sr, sb, keyed, src_sum, dst_sum);

    if (!detailed) return 0;

    /* Bounded trace path for the first menu blits: reproduce HLE's unkeyed,
     * same-format, non-stretched copy, then report the real post-copy
     * destination checksum and the HRESULT sf_Blt/sf_BltFast returns. */
    int x0 = dl < 0 ? -dl : 0, y0 = dt < 0 ? -dt : 0;
    if (sl + x0 < 0) x0 = -sl;
    if (st + y0 < 0) y0 = -st;
    int x1 = dr - dl, y1 = db - dt;
    if (dl + x1 > d->w) x1 = d->w - dl;
    if (dt + y1 > d->h) y1 = d->h - dt;
    if (sl + x1 > s->w) x1 = s->w - sl;
    if (st + y1 > s->h) y1 = s->h - st;
    int bpp = d->bpp / 8;
    fprintf(stderr,
            "[trace] DDBLT clip before=%d,%d..%d,%d after=%d,%d..%d,%d "
            "src_after=%d,%d..%d,%d bpp=%d keyed=%d\n",
            dl, dt, dr, db, dl + x0, dt + y0, dl + x1, dt + y1,
            sl + x0, st + y0, sl + x1, st + y1, d->bpp, keyed);

    if (!d || !s || d == s || keyed || d->bpp != s->bpp ||
        (dr - dl) != (sr - sl) || (db - dt) != (sb - st) || bpp < 1 || bpp > 4) {
        fprintf(stderr, "[trace] DDBLT post hr=0x00000000 DD_OK copy=0 dstsum_after=%08X\n", dst_sum);
        traced++;
        return 0;
    }
    if (hle_dd_sync_hook) { hle_dd_sync_hook(d); hle_dd_sync_hook(s); }
    for (int y = y0; y < y1 && x1 > x0; y++)
        memcpy(d->px + (size_t)(dt + y) * (size_t)d->pitch + (size_t)(dl + x0) * (size_t)bpp,
               s->px + (size_t)(st + y) * (size_t)s->pitch + (size_t)(sl + x0) * (size_t)bpp,
               (size_t)(x1 - x0) * (size_t)bpp);
    hle_dd_mark(d);
    uint32_t after = pc2_checksum(d->px, (size_t)d->pitch * (size_t)d->h);
    fprintf(stderr,
            "[trace] DDBLT post d=%u primary=%d pitch=%d bpp=%d hr=0x00000000 DD_OK "
            "dstsum_after=%08X copy=1\n",
            d->self, d->primary, d->pitch, d->bpp, after);
    traced++;
    return 1;
}

static int pc2_cursor_hook(void) {
    return hle_cursor_shown();
}

/* Bounded lease checkpoint: Player_CreateBranch writes the new branch ID to
 * the site object at +0x2c. Keep the site/slot from entry so the return can
 * report the actual state change. */
static uint32_t pc2_branch_site;
static uint32_t pc2_branch_site_id;
static uint32_t pc2_branch_slot;
void pc2_trace_branch_before(uint32_t player, uint32_t site_id, uint32_t site,
                             uint32_t slot, uint32_t type, uint32_t flags) {
    pc2_branch_site = site;
    pc2_branch_site_id = site_id;
    pc2_branch_slot = slot;
    fprintf(stderr,
            "[trace] BRANCH before player=%X site_id=%d site=%X slot=%d type=%d flags=%d "
            "branch_id_before=%d\n",
            player, site_id, site, slot, type, flags,
            site ? (int)MEM32(site + 0x2c) : -1);
}

void pc2_trace_branch_after(uint32_t branch_id) {
    fprintf(stderr,
            "[trace] BRANCH after player_slot=%d site_id=%d site=%X branch_id=%d "
            "site+2c=%d\n",
            pc2_branch_slot, pc2_branch_site_id, pc2_branch_site, branch_id,
            pc2_branch_site ? (int)MEM32(pc2_branch_site + 0x2c) : -1);
}

void pc2_trace_random_building(uint32_t obj) {
    static int n;
    if (!getenv("PC2_TRACE_RANDOM") || n++ >= 12) return;
    if (!obj) {
        fprintf(stderr, "[trace] RANDOM building null\n");
        return;
    }
    fprintf(stderr,
            "[trace] RANDOM building obj=%X type=%d rect=%d,%d..%d,%d "
            "index=%d cell=%d,%d\n",
            obj, (int)MEM32(obj + 4),
            (int)MEM32(obj + 0x10), (int)MEM32(obj + 0x14),
            (int)MEM32(obj + 0x18), (int)MEM32(obj + 0x1c),
            (int)MEM32(obj + 0x24), (int)MEM32(obj + 0x2c),
            (int)MEM32(obj + 0x30));
}

void pc2_trace_center_object(uint32_t obj) {
    static int n;
    if (!getenv("PC2_TRACE_RANDOM") || n++ >= 12) return;
    if (!obj) {
        fprintf(stderr, "[trace] CENTER object null\n");
        return;
    }
    fprintf(stderr,
            "[trace] CENTER object obj=%X type=%d rect=%d,%d..%d,%d "
            "index=%d cell=%d,%d\n",
            obj, (int)MEM32(obj + 4),
            (int)MEM32(obj + 0x10), (int)MEM32(obj + 0x14),
            (int)MEM32(obj + 0x18), (int)MEM32(obj + 0x1c),
            (int)MEM32(obj + 0x24), (int)MEM32(obj + 0x2c),
            (int)MEM32(obj + 0x30));
}

static _Thread_local struct {
    uint32_t branch, entry, person, role, roster_index, roster_count;
} staff_trace;

void pc2_trace_staff_before(uint32_t branch, uint32_t entry, uint32_t role) {
    staff_trace.branch = 0;
    if (!getenv("PC2_TRACE_STAFF") || !branch || !entry || MEM32(branch + 0x30) != 0) return;
    uint32_t person = MEM32(entry);
    if (!person) return;
    staff_trace.branch = branch;
    staff_trace.entry = entry;
    staff_trace.person = person;
    staff_trace.role = role;
    staff_trace.roster_index = MEM32(branch + 0x150c);
    staff_trace.roster_count = MEM32(branch + 0x1514);
}

void pc2_trace_staff_after(void) {
    uint32_t branch = staff_trace.branch;
    if (!branch) return;
    uint32_t person = staff_trace.person;
    uint32_t roster = MEM32(branch + 0x1504);
    uint32_t count = MEM32(branch + 0x1514);
    int on_roster = roster && staff_trace.roster_index < MEM32(branch + 0x150c) &&
                    MEM32(roster + 4 * staff_trace.roster_index) == staff_trace.entry;
    fprintf(stderr, "[trace] STAFF Company_AssignEmployee employee=%u role=%u slot=%u branch=%u "
                    "employee_slot=%u employee_branch=%u roster=%u->%u on_roster=%d\n",
            MEM32(person + 0x814), staff_trace.role, MEM32(branch + 0x30), MEM32(branch + 0x3c),
            MEM32(person + 0x81c), MEM32(person + 0x820), staff_trace.roster_count, count, on_roster);
    staff_trace.branch = 0;
}

static long long pc2_branch_stock(uint32_t branch) {
    uint32_t count = MEM32(branch + 0x19ac);
    uint32_t entries = MEM32(branch + 0x199c);
    long long stock = 0;
    for (uint32_t i = 0; entries && i < count; i++) {
        uint32_t batch = MEM32(entries + 4 * i);
        if (batch && MEM32(batch + 0x1c)) stock += (int32_t)MEM32(batch);
    }
    return stock;
}

void pc2_trace_branch_hour(uint32_t branch, uint32_t hour) {
    if (!getenv("PC2_TRACE_SALES") || !branch || MEM32(branch + 0x30) != 0 || hour >= 24) return;
    fprintf(stderr, "[trace] BRANCH_HOUR slot=0 branch=%u hour=%u scheduled=%u roster=%u stock=%lld\n",
            MEM32(branch + 0x3c), hour, MEM8(branch + 0x1a08 + hour),
            MEM32(branch + 0x1514), pc2_branch_stock(branch));
}

static _Thread_local struct {
    uint32_t branch, order, recipe, sales_count;
    long long stock;
} order_trace;

static float pc2_sale_amount(uint32_t bits) {
    // The original writes the order's revenue with an x87 single-precision store.
    float amount;
    memcpy(&amount, &bits, sizeof amount);
    return amount;
}

void pc2_trace_order_before(uint32_t branch, uint32_t order) {
    order_trace.branch = 0;
    if (!getenv("PC2_TRACE_SALES") || !branch || !order || MEM32(branch + 0x30) != 0) return;
    uint32_t recipe = MEM32(order);
    if (!recipe) return;
    uint32_t records = MEM32(recipe + 0x304);
    order_trace.branch = branch;
    order_trace.order = order;
    order_trace.recipe = recipe;
    order_trace.sales_count = records ? MEM32(records + 0x14) : 0;
    order_trace.stock = pc2_branch_stock(branch);
}

void pc2_trace_order_after(uint32_t result) {
    uint32_t branch = order_trace.branch;
    if (!branch) return;
    uint32_t records = MEM32(order_trace.recipe + 0x304);
    float revenue = result ? pc2_sale_amount(MEM32(order_trace.order + 0x1c)) : 0;
    fprintf(stderr, "[trace] SALE Branch_ProcessCustomerOrder slot=0 branch=%u servings=%u "
                    "stock=%lld->%lld records=%u->%u revenue=%.2f customer=%u\n",
            MEM32(branch + 0x3c), result, order_trace.stock, pc2_branch_stock(branch),
            order_trace.sales_count, records ? MEM32(records + 0x14) : 0, (double)revenue,
            MEM32(order_trace.order + 0x10));
    order_trace.branch = 0;
}

static double pc2_player_cash(uint32_t player) {
    double cash;
    memcpy(&cash, (const void *)(uintptr_t)ADDR(player + 0x108), sizeof cash);
    return cash;
}

static _Thread_local struct {
    uint32_t player, branch_id, customer;
    float amount;
    double cash;
} payment_trace;

void pc2_trace_payment_before(uint32_t branch, uint32_t order) {
    payment_trace.player = 0;
    if (!getenv("PC2_TRACE_SALES") || !branch || !order || MEM32(branch + 0x30) != 0) return;
    uint32_t game = MEM32(0x0057C670);
    uint32_t player = game ? MEM32(game + 0x200) : 0;
    if (!player) return;
    payment_trace.player = player;
    payment_trace.branch_id = MEM32(branch + 0x3c);
    payment_trace.customer = MEM32(order + 0x10);
    payment_trace.amount = pc2_sale_amount(MEM32(order + 0x1c));
    payment_trace.cash = pc2_player_cash(player);
}

void pc2_trace_payment_after(void) {
    uint32_t player = payment_trace.player;
    if (!player) return;
    fprintf(stderr, "[trace] PAYMENT slot=0 branch=%u customer=%u "
                    "amount=%.2f cash=%.2f->%.2f\n",
            payment_trace.branch_id, payment_trace.customer, (double)payment_trace.amount,
            payment_trace.cash, pc2_player_cash(player));
    payment_trace.player = 0;
}

static const uint8_t *pc2_dd_frame_hook(surf_t *primary) {
    static int n;
    if (n++ < 4) {
        fprintf(stderr, "[trace] DDPRIMARY self=%u %dx%d bpp=%d pitch=%d sum=%08X\n",
                primary ? primary->self : 0, primary ? primary->w : 0,
                primary ? primary->h : 0, primary ? primary->bpp : 0,
                primary ? primary->pitch : 0,
                primary && primary->px ? pc2_checksum(primary->px,
                    (size_t)primary->pitch * (size_t)primary->h) : 0);
    }
    if (pc2_saw_menu) {
        uint32_t ui = MEM32(0x0057C5E0);
        uint32_t renderer = ui ? MEM32(ui + 0xC) : 0;
        uint32_t buf = renderer ? MEM32(renderer + 0x28) : 0;
        if (buf) return (const uint8_t *)(uintptr_t)ADDR(buf);
    }
    return NULL;
}

/* PC2_SAVE_ON_LOAD=1 checkpoints the loaded London state through the game's
 * own SaveGame_Write 0x00487520, into save_games/auto_<slot>.piz. */
static void pc2_save_loaded_checkpoint(void) {
    static int done;
    if (done || !getenv("PC2_SAVE_ON_LOAD")) return;
    uint32_t game = MEM32(0x0057C670);
    uint32_t branch = game ? MEM32(game + 0x9C) : 0;
    uint32_t calendar = game ? MEM32(game + 0x94) : 0;
    if (!game || !branch || !calendar) return;
    if (MEM32(branch + 0x3C) != 100000 || MEM32(branch + 0x30) != 0 ||
        MEM32(branch + 0x1514) != 4) return;
    if (MEM8(calendar + 7) < 8) return;
    const char *slot_s = getenv("PC2_SAVE_SLOT");
    int slot = slot_s && *slot_s ? atoi(slot_s) : 1;
    uint32_t args[2] = {0, (uint32_t)slot};
    fprintf(stderr, "[trace] SAVE checkpoint request slot=%d\n", slot);
    g_ecx = game;
    uint32_t result = hle_call_guest(0x00487520, 2, args);
    fprintf(stderr, "[trace] SAVE checkpoint result=%u slot=%d\n", result, slot);
    done = 1;
}

static void pc2_dump_renderer(const char *path, int tag) {
    uint32_t ui = MEM32(0x0057C5E0);
    uint32_t renderer = ui ? MEM32(ui + 0xC) : 0;
    uint32_t buf = renderer ? MEM32(renderer + 0x28) : 0;
    if (!buf) return;
    const uint16_t *rp = (const uint16_t *)(uintptr_t)ADDR(buf);
    char name[1200];
    snprintf(name, sizeof name, "%s.%d", path, tag);
    FILE *rf = fopen(name, "wb");
    if (!rf) return;
    fprintf(rf, "P6\n800 600\n255\n");
    for (int y = 0; y < 600; y++)
        for (int x = 0; x < 800; x++) {
            uint16_t v = rp[(size_t)y * 800 + x];
            unsigned char rgb[3] = {
                (unsigned char)(((v >> 11) & 0x1f) * 255 / 31),
                (unsigned char)(((v >> 5) & 0x3f) * 255 / 63),
                (unsigned char)((v & 0x1f) * 255 / 31)};
            fwrite(rgb, 1, 3, rf);
        }
    fclose(rf);
    fprintf(stderr, "[trace] raw renderer dump %s buf=%X\n", name, buf);
}

static int pc2_raw_done;
static int pc2_raw_char_done;
static int pc2_char_seen;
static int pc2_char_clicked;
static int pc2_mission_seen;
static int pc2_mission_clicked;
static int pc2_lease_clicked;
static int pc2_confirm_clicked;
static int pc2_started;
static void pc2_poll(void) {
    uint32_t pending = MEM32(0x0056386C);
    if (pending == 21) pc2_saw_menu = 1;
    if (pending == 28) pc2_char_seen = 1;
    if (pending == 22) pc2_mission_seen = 1;
    pc2_save_loaded_checkpoint();
#ifdef PC2_CAPTURE
    pc2_capture_poll();
#endif
    const char *path = getenv("PC2_RAW_DUMP");
    if (path && pc2_saw_menu && pending == 0 && !pc2_raw_done) {
        pc2_dump_renderer(path, 100);
        pc2_raw_done = 1;
    }
    if (getenv("PC2_CLICK_START") && pending == 28 && path && !pc2_raw_char_done) {
        pc2_dump_renderer(path, 200);
        pc2_raw_char_done = 1;
    }
    if (getenv("PC2_CLICK_START") && pc2_char_seen && pending == 0 && path) {
        static int after_char;
        if (!after_char) {
            pc2_dump_renderer(path, 300);
            after_char = 1;
        }
    }
    if (getenv("PC2_START_CAMPAIGN") && pc2_char_seen && pending == 0 && !pc2_char_clicked) {
        uint32_t hwnd = hle_first_hwnd();
        if (hwnd) {
            uint32_t lp = ((566u & 0xffffu) << 16) | (700u & 0xffffu);
            hle_post_message(hwnd, 0x0200, 0, lp);
            hle_post_message(hwnd, 0x0201, 1, lp);
            hle_post_message(hwnd, 0x0202, 0, lp);
            pc2_char_clicked = 1;
            fprintf(stderr, "[trace] scripted click Start game at 700,566\n");
        }
    }
    if (getenv("PC2_START_CAMPAIGN") && pc2_mission_seen && pending == 0 && !pc2_mission_clicked) {
        static int mission_polls;
        if (++mission_polls < 4) return;
        uint32_t hwnd = hle_first_hwnd();
        if (hwnd) {
            uint32_t lp = ((560u & 0xffffu) << 16) | (680u & 0xffffu);
            hle_post_message(hwnd, 0x0200, 0, lp);
            hle_post_message(hwnd, 0x0201, 1, lp);
            hle_post_message(hwnd, 0x0202, 0, lp);
            pc2_mission_clicked = 1;
            fprintf(stderr, "[trace] scripted click Start Mission at 680,560\n");
        }
    }
    if (getenv("PC2_START_CAMPAIGN") && pc2_mission_clicked && path) {
        static int game_polls;
        static int game_dumped;
        const char *delay = getenv("PC2_GAME_DUMP_DELAY");
        int target = delay && *delay ? atoi(delay) : 300;
        if (!game_dumped && ++game_polls >= target) {
            pc2_dump_renderer(path, 400);
            game_dumped = 1;
        }
    }
    if (getenv("PC2_CONFIRM_CLICK") && pc2_lease_clicked) {
        static int confirm_polls;
        static int confirm_done;
        const char *delay_s = getenv("PC2_CONFIRM_DELAY");
        int delay = delay_s && *delay_s ? atoi(delay_s) : 300;
        const char *x_s = getenv("PC2_CONFIRM_X");
        int cx = x_s && *x_s ? atoi(x_s) : 740;
        const char *y_s = getenv("PC2_CONFIRM_Y");
        int cy = y_s && *y_s ? atoi(y_s) : 581;
        if (!confirm_done && ++confirm_polls >= delay) {
            uint32_t hwnd = hle_first_hwnd();
            if (hwnd) {
                uint32_t lp = (((uint32_t)cy & 0xffffu) << 16) | ((uint32_t)cx & 0xffffu);
                hle_post_message(hwnd, 0x0200, 0, lp);
                hle_post_message(hwnd, 0x0201, 1, lp);
                hle_post_message(hwnd, 0x0202, 0, lp);
                confirm_done = 1;
                pc2_confirm_clicked = 1;
                fprintf(stderr, "[trace] lease confirm click at %d,%d\n", cx, cy);
            }
        }
    }
    if (getenv("PC2_POST_LEASE_CLICKS") && pc2_confirm_clicked) {
        static int post_polls;
        static int post_clicks;
        const char *want_s = getenv("PC2_POST_LEASE_CLICKS");
        int want = want_s && *want_s ? atoi(want_s) : 0;
        const char *start_s = getenv("PC2_POST_LEASE_START");
        int start = start_s && *start_s ? atoi(start_s) : 300;
        const char *interval_s = getenv("PC2_POST_LEASE_INTERVAL");
        int interval = interval_s && *interval_s ? atoi(interval_s) : 300;
        if (want > post_clicks) {
            post_polls++;
            if (post_polls >= (post_clicks ? interval : start)) {
                uint32_t hwnd = hle_first_hwnd();
                if (hwnd) {
                    uint32_t lp = ((153u & 0xffffu) << 16) | (534u & 0xffffu);
                    hle_post_message(hwnd, 0x0200, 0, lp);
                    hle_post_message(hwnd, 0x0201, 1, lp);
                    hle_post_message(hwnd, 0x0202, 0, lp);
                    post_clicks++;
                    post_polls = 0;
                    fprintf(stderr, "[trace] post-lease click %d at 534,153\n", post_clicks);
                }
            }
        }
    }
    if (getenv("PC2_START_CAMPAIGN") && pc2_mission_clicked) {
        static int tutorial_polls;
        static int tutorial_clicks;
        const char *want_s = getenv("PC2_TUTORIAL_CLICKS");
        int want = want_s && *want_s ? atoi(want_s) : 0;
        const char *start_s = getenv("PC2_TUTORIAL_START");
        int start = start_s && *start_s ? atoi(start_s) : 300;
        const char *interval_s = getenv("PC2_TUTORIAL_INTERVAL");
        int interval = interval_s && *interval_s ? atoi(interval_s) : 200;
        if (want > tutorial_clicks) {
            tutorial_polls++;
            if (tutorial_polls >= (tutorial_clicks ? interval : start)) {
                uint32_t hwnd = hle_first_hwnd();
                if (hwnd) {
                    uint32_t lp = ((153u & 0xffffu) << 16) | (534u & 0xffffu);
                    hle_post_message(hwnd, 0x0200, 0, lp);
                    hle_post_message(hwnd, 0x0201, 1, lp);
                    hle_post_message(hwnd, 0x0202, 0, lp);
                    tutorial_clicks++;
                    tutorial_polls = 0;
                    fprintf(stderr, "[trace] tutorial click %d at 534,153\n", tutorial_clicks);
                }
            }
        }
    }
    if (getenv("PC2_LEASE_CLICK") && pc2_mission_clicked) {
        static int lease_polls;
        static int lease_done;
        const char *delay_s = getenv("PC2_LEASE_DELAY");
        int delay = delay_s && *delay_s ? atoi(delay_s) : 1800;
        const char *x_s = getenv("PC2_LEASE_X");
        int lx = x_s && *x_s ? atoi(x_s) : 745;
        const char *y_s = getenv("PC2_LEASE_Y");
        int ly = y_s && *y_s ? atoi(y_s) : 500;
        if (!lease_done && ++lease_polls >= delay) {
            uint32_t hwnd = hle_first_hwnd();
            if (hwnd) {
                uint32_t lp = (((uint32_t)ly & 0xffffu) << 16) | ((uint32_t)lx & 0xffffu);
                hle_post_message(hwnd, 0x0200, 0, lp);
                hle_post_message(hwnd, 0x0201, 1, lp);
                hle_post_message(hwnd, 0x0202, 0, lp);
                lease_done = 1;
                pc2_lease_clicked = 1;
                fprintf(stderr, "[trace] lease click at %d,%d\n", lx, ly);
            }
        }
    }
    if (getenv("PC2_CLICK_START") && pc2_saw_menu && pending == 0 && !pc2_started) {
        uint32_t hwnd = hle_first_hwnd();
        if (hwnd) {
            uint32_t lp = ((18u & 0xffffu) << 16) | (650u & 0xffffu);
            hle_post_message(hwnd, 0x0200, 0, lp);
            hle_post_message(hwnd, 0x0201, 1, lp);
            hle_post_message(hwnd, 0x0202, 0, lp);
            pc2_started = 1;
            fprintf(stderr, "[trace] scripted click Start new game at 650,18\n");
        }
    }
}

static void pc2_frame_hook(const uint8_t *px, int w, int h, int pitch, int bpp) {
    static int shown;
    static int dumped;
    size_t bytes = (size_t)pitch * (size_t)h;
    if (shown < 8) {
        size_t nonzero = 0;
        for (size_t i = 0; i < bytes; i++) nonzero += px[i] != 0;
        fprintf(stderr, "[trace] frame %d %dx%d bpp=%d nonzero=%zu/%zu\n",
                shown, w, h, bpp, nonzero, bytes);
    }
    shown++;
    const char *path = getenv("PC2_FRAME_DUMP");
    if (path && pc2_saw_menu && MEM32(0x0056386C) == 0 && !dumped && bpp == 16) {
        FILE *f = fopen(path, "wb");
        if (f) {
            fprintf(f, "P6\n%d %d\n255\n", w, h);
            for (int y = 0; y < h; y++) {
                const uint16_t *row = (const uint16_t *)(px + (size_t)y * pitch);
                for (int x = 0; x < w; x++) {
                    uint16_t v = row[x];
                    unsigned char rgb[3] = {
                        (unsigned char)(((v >> 11) & 0x1f) * 255 / 31),
                        (unsigned char)(((v >> 5) & 0x3f) * 255 / 63),
                        (unsigned char)((v & 0x1f) * 255 / 31)};
                    fwrite(rgb, 1, 3, f);
                }
            }
            fclose(f);
            dumped = 1;
            fprintf(stderr, "[trace] frame dump %s\n", path);
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "usage: %s <image.exe>\n", argv[0]);
        return 64;
    }

#ifdef PC2_CAPTURE
    pc2_capture_init();
#endif
    recomp_host_init();
    pc2_register_shims();

    /* PC2 writes a scratch sprite to C:\test.spr while building its loading
     * screen. Map C: to a writable host directory so that path exists. */
    const char *cdrive = getenv("PC2_CDRIVE");
    if (!cdrive || !*cdrive) cdrive = "/tmp/opencode/pc2-cdrive";
    mkdir(cdrive, 0755);
    hle_set_drive('C', cdrive);

    /* WinMain derives its base directory from GetCommandLineA(). The runtime's
     * default "game.exe" has no separator, which leaves the game looking for
     * "gresources\\main.pak". Give it the real guest path. */
    char guest[1024];
    char cmdline[1100];
    hle_guest_path(argv[1], guest, sizeof guest);
    snprintf(cmdline, sizeof cmdline, "\"%s\"", guest);
    hle_set_command_line(cmdline);

    if (recomp_host_boot_permissive(argv[1]) != 0) {
        return 1;
    }

    /* PC2's window proc enables rendering on its first window message. The
     * headless host does not generate that message, so arm the flag once. */
    MEM32(0x00584504) = 1;
    MEM32(0x005844FC) = 0;

    hle_dd_blit_hook = pc2_blit_hook;
    hle_dd_frame_hook = pc2_dd_frame_hook;
    hle_screen_cursor_hook = pc2_cursor_hook;

    int headless = getenv("PC2_HEADLESS") != NULL;
    if (getenv("PC2_TRACE_FRAMES")) hle_screen_frame_hook = pc2_frame_hook;
    if (hle_screen_open("Pizza Connection 2", 0, headless) != 0) {
        return 2;
    }
    hle_screen_poll_hook = pc2_poll;

#ifdef PC2_CAPTURE
    pc2_capture_boot_ready();
#endif
    int status = (int)recomp_host_run();
#ifdef PC2_CAPTURE
    pc2_capture_guest_exit(status);
#endif
    return status;
}
