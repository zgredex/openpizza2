#include "settings.h"

#include <string.h>

_Static_assert(sizeof(Settings) == 0x164, "settings block must stay 0x164 bytes");
_Static_assert(offsetof(Settings, version) == 0x000, "version offset");
_Static_assert(offsetof(Settings, gender) == 0x004, "gender offset");
_Static_assert(offsetof(Settings, color) == 0x008, "color offset");
_Static_assert(offsetof(Settings, difficulty) == 0x00c, "difficulty offset");
_Static_assert(offsetof(Settings, enterprise_name) == 0x010, "enterprise name offset");
_Static_assert(offsetof(Settings, player_name) == 0x050, "player name offset");
_Static_assert(offsetof(Settings, head) == 0x090, "head offset");
_Static_assert(offsetof(Settings, attributes) == 0x0a4, "attributes offset");
_Static_assert(offsetof(Settings, flag_tutorial) == 0x0bc, "tutorial flag offset");
_Static_assert(offsetof(Settings, max_hq) == 0x0d0, "max HQ offset");
_Static_assert(offsetof(Settings, default_values) == 0x0d4, "default array offset");
_Static_assert(offsetof(Settings, zero_values) == 0x0ec, "zero array offset");
_Static_assert(offsetof(Settings, table_values) == 0x104, "table array offset");
_Static_assert(offsetof(Settings, freeplay_start_index) == 0x11c, "start index offset");
_Static_assert(offsetof(Settings, freeplay_start_money) == 0x120, "start money offset");
_Static_assert(offsetof(Settings, freeplay_game_length) == 0x124, "game length offset");
_Static_assert(offsetof(Settings, date_year) == 0x128, "date year offset");
_Static_assert(offsetof(Settings, language_index) == 0x134, "language offset");
_Static_assert(offsetof(Settings, autosave_interval) == 0x148, "autosave interval offset");
_Static_assert(offsetof(Settings, autosave_tick) == 0x14c, "autosave tick offset");
_Static_assert(offsetof(Settings, autosave_slot_count) == 0x150, "autosave count offset");
_Static_assert(offsetof(Settings, autosave_slot_index) == 0x154, "autosave index offset");
_Static_assert(offsetof(Settings, autosave_enabled) == 0x160, "autosave enabled offset");

void settings_init_defaults(Settings *settings, settings_load_fn load,
                            settings_random_fn random) {
    if (settings == NULL) {
        return;
    }
    memset(settings, 0, sizeof(*settings));
    if (load != NULL && load(settings)) {
        return;
    }

    settings->autosave_interval = 5;
    settings->autosave_slot_count = 4;
    settings->autosave_slot_index = 0;
    settings->autosave_tick = 0;

    if (random != NULL) {
        settings->head = random(0, 1);
        settings->eyes = random(0, 41);
        settings->hair = random(0, 41);
        settings->mouth = random(0, 41);
        settings->logo = random(0, 41);
    }

    settings->freeplay_start_money = 250;
    settings->date_year = -1;
    settings->date_month = -1;
    settings->date_day = -1;
    settings->freeplay_game_length = 11;
    settings->flag_tutorial = 1;
    settings->flag_rival = 0;
    settings->flag_hq = 1;
    settings->flag_scenario = 1;
    settings->language_index = 3;
    settings->max_hq = 6;

    for (size_t index = 0; index < 6; index++) {
        settings->default_values[index] = 100;
        settings->zero_values[index] = 0;
        settings->table_values[index] = index < 2 ? 1u : 0u;
    }
}
