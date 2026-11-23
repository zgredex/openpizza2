#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

#include "host.h"
#include "win32hle.h"
#include "ddraw_int.h"
#include "pc2_vulkan.h"
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
    uint32_t branch, order, recipe, recipe_hash, sales_count, rating;
    long long stock;
    int tip_base;
    int rating_wait;
} order_trace;

static float pc2_sale_amount(uint32_t bits) {
    // The original writes the order's revenue with an x87 single-precision store.
    float amount;
    memcpy(&amount, &bits, sizeof amount);
    return amount;
}

// Host-side copy of IDMap_Lookup (0x4017F0): keys below 100000 index the
// table directly, larger IDs use the sorted key array.
static uint32_t pc2_idmap_lookup(uint32_t map, uint32_t key) {
    if (!map) return 0;
    uint32_t count = MEM32(map + 0x0c);
    uint32_t values = MEM32(map + 4);
    uint32_t keys = MEM32(map + 8);
    if (key < 100000) {
        return key < count ? MEM32(values + 4 * key) : 0;
    }
    if (!count || !values || !keys) return 0;
    int32_t high = (int32_t)count - 1;
    int32_t low = 0;
    while (high - low > 1) {
        int32_t middle = (high + low) >> 1;
        uint32_t found = MEM32(keys + 4 * middle);
        if (found == key) return MEM32(values + 4 * middle);
        if (key < found) {
            high = middle;
        } else {
            low = middle;
        }
    }
    if (MEM32(keys + 4 * low) == key) return MEM32(values + 4 * low);
    if (MEM32(keys + 4 * high) == key) return MEM32(values + 4 * high);
    return 0;
}

// Stable recipe identity across runs; the recipe heap address is not stable.
static uint32_t pc2_recipe_hash(uint32_t recipe) {
    uint32_t hash = 2166136261u;
    if (!recipe) return 0;
    for (int i = 0; i < 0x56; i++) {
        hash ^= MEM32(recipe + 100 + 4 * i);
        hash *= 16777619u;
    }
    return hash;
}

void pc2_trace_order_before(uint32_t branch, uint32_t order) {
    order_trace.branch = 0;
    if (!getenv("PC2_TRACE_SALES") || !branch || !order || MEM32(branch + 0x30) != 0) return;
    uint32_t recipe = MEM32(order);
    if (!recipe) return;
    uint32_t records = MEM32(recipe + 0x304);
    uint32_t game = MEM32(0x0057C670);
    uint32_t calendar = game ? MEM32(game + 0x94) : 0;
    uint32_t customer = MEM32(order + 0x10);
    uint32_t group = game ? pc2_idmap_lookup(game + 0x3c, customer) : 0;
    int tip_base = group ? (int)MEM32(group + 0x2c) : 0;
    uint32_t batches = MEM32(branch + 0x19ac);
    uint32_t entries = MEM32(branch + 0x199c);
    int ingredient_sum = 0;
    for (int i = 0; i < 0x56; i++) ingredient_sum += (int)MEM32(recipe + 100 + 4 * i);
    order_trace.branch = branch;
    order_trace.order = order;
    order_trace.recipe = recipe;
    order_trace.recipe_hash = pc2_recipe_hash(recipe);
    order_trace.sales_count = records ? MEM32(records + 0x14) : 0;
    order_trace.stock = pc2_branch_stock(branch);
    order_trace.tip_base = tip_base;
    order_trace.rating = 0;
    order_trace.rating_wait = 1;
    fprintf(stderr,
            "[trace] ORDER_INPUT slot=0 branch=%u clock=%02u:%02u customer=%u "
            "menu_price=%.8f menu_bits=%08X recipe=%X recipe_hash=%08X "
            "ingredients=%d tip_base=%d stock=%lld batches=%u",
            MEM32(branch + 0x3c), calendar ? MEM8(calendar + 7) : 0,
            calendar ? MEM8(calendar + 6) : 0, customer,
            (double)pc2_sale_amount(MEM32(order + 4)), MEM32(order + 4), recipe,
            order_trace.recipe_hash, ingredient_sum, tip_base,
            (long long)order_trace.stock, batches);
    for (uint32_t i = 0; entries && i < batches; i++) {
        uint32_t batch = MEM32(entries + 4 * i);
        if (batch && MEM32(batch + 0x1c)) {
            fprintf(stderr, " batch%u=%d", i, (int)MEM32(batch));
        }
    }
    for (int i = 0; i < 0x56; i++) {
        uint32_t quantity = MEM32(recipe + 100 + 4 * i);
        if (quantity) fprintf(stderr, " qty%d=%u", i, quantity);
    }
    fputc('\n', stderr);
}

void pc2_trace_order_rating_result(uint32_t rating) {
    if (!order_trace.rating_wait || !order_trace.branch) return;
    order_trace.rating = rating;
    fprintf(stderr, "[trace] ORDER_RATING slot=0 branch=%u customer=%u rating=%u tip_base=%d\n",
            MEM32(order_trace.branch + 0x3c), MEM32(order_trace.order + 0x10), rating,
            order_trace.tip_base);
    order_trace.rating_wait = 0;
}

void pc2_trace_order_after(uint32_t result) {
    order_trace.rating_wait = 0;
    uint32_t branch = order_trace.branch;
    if (!branch) return;
    uint32_t records = MEM32(order_trace.recipe + 0x304);
    float revenue = result ? pc2_sale_amount(MEM32(order_trace.order + 0x1c)) : 0;
    float price = pc2_sale_amount(MEM32(order_trace.order + 4));
    int observed_tip = 0;
    if (result && price > 0.0f) {
        float factor = (float)result * price * 0.01f;
        if (factor > 0.0f) observed_tip = (int)(revenue / factor - 100.0f);
    }
    int predicted_tip = 0;
    if (order_trace.rating) {
        predicted_tip = ((int)order_trace.rating - order_trace.tip_base) >> 1;
        if (predicted_tip < 0) predicted_tip = 0;
    }
    fprintf(stderr, "[trace] SALE Branch_ProcessCustomerOrder slot=0 branch=%u servings=%u "
                    "stock=%lld->%lld records=%u->%u revenue=%.2f customer=%u "
                    "menu_price=%.8f menu_bits=%08X revenue_bits=%08X recipe=%X "
                    "recipe_hash=%08X rating=%u tip_base=%d tip=%d\n",
            MEM32(branch + 0x3c), result, order_trace.stock, pc2_branch_stock(branch),
            order_trace.sales_count, records ? MEM32(records + 0x14) : 0, (double)revenue,
            MEM32(order_trace.order + 0x10), (double)price,
            MEM32(order_trace.order + 4), MEM32(order_trace.order + 0x1c),
            order_trace.recipe, order_trace.recipe_hash, order_trace.rating,
            order_trace.tip_base, predicted_tip ? predicted_tip : observed_tip);
    order_trace.branch = 0;
}

static double pc2_player_cash(uint32_t player) {
    double cash;
    memcpy(&cash, (const void *)(uintptr_t)ADDR(player + 0x108), sizeof cash);
    return cash;
}

static _Thread_local struct {
    uint32_t player, branch_id, customer, recipe, recipe_hash;
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
    payment_trace.recipe = MEM32(order);
    payment_trace.recipe_hash = pc2_recipe_hash(payment_trace.recipe);
    payment_trace.amount = pc2_sale_amount(MEM32(order + 0x1c));
    payment_trace.cash = pc2_player_cash(player);
}

void pc2_trace_payment_after(void) {
    uint32_t player = payment_trace.player;
    if (!player) return;
    fprintf(stderr, "[trace] PAYMENT slot=0 branch=%u customer=%u "
                    "amount=%.2f cash=%.2f->%.2f recipe=%X recipe_hash=%08X\n",
            payment_trace.branch_id, payment_trace.customer, (double)payment_trace.amount,
            payment_trace.cash, pc2_player_cash(player), payment_trace.recipe,
            payment_trace.recipe_hash);
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
/* Deterministic native-input smoke test: push the same SDL events as a real
 * click, mapped through the Vulkan viewport. Enabled only by PC2_TEST_CLICK. */
static void pc2_test_click(void) {
    static int done;
    static int ready_frames;
    const char *spec = getenv("PC2_TEST_CLICK");
    if (!spec || done || !pc2_saw_menu || MEM32(0x0056386C) != 0) return;
    if (++ready_frames < 30) return;
    int gx = 650, gy = 18;
    if (sscanf(spec, "%d,%d", &gx, &gy) != 2) return;
    int vx, vy, vw, vh, ww, wh, dw, dh;
    pc2_vulkan_viewport(&vx, &vy, &vw, &vh);
    SDL_Window *win = pc2_vulkan_window();
    if (!win || vw <= 0 || vh <= 0) return;
    SDL_GetWindowSize(win, &ww, &wh);
    SDL_Vulkan_GetDrawableSize(win, &dw, &dh);
    if (ww <= 0 || wh <= 0 || dw <= 0 || dh <= 0) return;
    int x = (vx + gx * vw / 800) * ww / dw;
    int y = (vy + gy * vh / 600) * wh / dh;
    Uint32 window_id = SDL_GetWindowID(win);
    SDL_Event event;
    SDL_zero(event);
    event.type = SDL_MOUSEMOTION;
    event.motion.windowID = window_id;
    event.motion.x = x;
    event.motion.y = y;
    SDL_PushEvent(&event);
    SDL_zero(event);
    event.type = SDL_MOUSEBUTTONDOWN;
    event.button.windowID = window_id;
    event.button.button = SDL_BUTTON_LEFT;
    event.button.state = SDL_PRESSED;
    event.button.clicks = 1;
    event.button.x = x;
    event.button.y = y;
    SDL_PushEvent(&event);
    SDL_zero(event);
    event.type = SDL_MOUSEBUTTONUP;
    event.button.windowID = window_id;
    event.button.button = SDL_BUTTON_LEFT;
    event.button.state = SDL_RELEASED;
    event.button.clicks = 1;
    event.button.x = x;
    event.button.y = y;
    SDL_PushEvent(&event);
    done = 1;
    fprintf(stderr, "[trace] SDL test click guest=%d,%d window=%d,%d drawable=%dx%d\n",
            gx, gy, x, y, dw, dh);
}

static void pc2_poll(void) {
    uint32_t pending = MEM32(0x0056386C);
    static uint32_t last_pending = ~0u;
    if (pending != last_pending) {
        fprintf(stderr, "[trace] pending=%u\n", pending);
        last_pending = pending;
    }
    if (pending == 21) pc2_saw_menu = 1;
    pc2_test_click();
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

/* Headless and capture builds have no window; the guest message loop still
 * needs the checkpoint/scripted-click poll and the frame dump/trace hook. */
static void pc2_native_present(void);
static void pc2_headless_pump(void) {
    pc2_poll();
    pc2_native_present();
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

/* Input trace for checking win32hle's SDL-to-WM mapping (PC2_TRACE_INPUT). */
static void pc2_proc_hook(uint32_t hwnd, uint32_t msg, uint32_t wparam, uint32_t lparam) {
    if (msg >= 0x0200 && msg <= 0x0209)
        fprintf(stderr, "[trace] proc msg=%03X w=%X l=%X\n", msg, wparam, lparam);
}

/* The guest's DirectDraw/GDI frame, presented directly by the native Vulkan
 * module. The sequence keeps a static frame from being uploaded repeatedly;
 * a flip or primary change advances it. */
static unsigned pc2_present_seq;
static int pc2_present_have_seq;
static void pc2_native_present(void) {
    const uint8_t *px = NULL;
    int w = 0, h = 0, pitch = 0, bpp = 0;
    const uint32_t *palette = NULL;
    unsigned seq = 0;
    if (!hle_dd_frame(&px, &w, &h, &pitch, &bpp, &palette, &seq) &&
        !hle_gdi_window_frame(&px, &w, &h, &pitch, &bpp, &seq))
        return;
    (void)palette;
    if (pc2_present_have_seq && seq == pc2_present_seq) return;
    pc2_present_seq = seq;
    pc2_present_have_seq = 1;
    if (bpp != 16) {
        static int logged;
        if (!logged) {
            fprintf(stderr, "[vulkan] unsupported frame bpp=%d (presentation skipped)\n", bpp);
            logged = 1;
        }
        return;
    }
    if (getenv("PC2_TRACE_FRAMES")) pc2_frame_hook(px, w, h, pitch, bpp);
    if (pc2_vulkan_present(px, w, h, pitch, bpp,
                           pc2_saw_menu && MEM32(0x0056386C) == 0) < 0) {
        static int reported;
        if (!reported) { fprintf(stderr, "[vulkan] presentation failed\n"); reported = 1; }
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
    const char *renderer = getenv("PC2_RENDERER");
    if (renderer && *renderer && strcmp(renderer, "vulkan") && strcmp(renderer, "auto")) {
        fprintf(stderr, "[host] unsupported renderer '%s': native Vulkan only\n", renderer);
        return 2;
    }
    if (!headless) {
        if (pc2_vulkan_open("Pizza Connection 2", pc2_poll, pc2_native_present) != 0) return 3;
    } else {
        hle_set_pump_hook(pc2_headless_pump);
    }
    hle_dd_primary_hook = pc2_native_present;
    hle_gdi_window_hook = pc2_native_present;
    if (getenv("PC2_TRACE_INPUT")) hle_proc_hook = pc2_proc_hook;

#ifdef PC2_CAPTURE
    pc2_capture_boot_ready();
#endif
    int status = (int)recomp_host_run();
#ifdef PC2_CAPTURE
    pc2_capture_guest_exit(status);
#endif
    pc2_vulkan_shutdown();
    return status;
}
