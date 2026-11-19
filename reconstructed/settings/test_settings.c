#include "settings.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static bool load_fails(Settings *settings) {
    (void)settings;
    return false;
}

static bool load_fills(Settings *settings) {
    settings->autosave_interval = 99;
    return true;
}

static uint32_t random_low(uint32_t low, uint32_t high) {
    (void)high;
    return low;
}

static void test_defaults(void) {
    Settings settings;
    memset(&settings, 0xaa, sizeof(settings));
    settings_init_defaults(&settings, load_fails, random_low);

    assert(settings.version == 0);
    assert(settings.language_index == 3);
    assert(settings.freeplay_start_money == 250);
    assert(settings.freeplay_game_length == 11);
    assert(settings.date_year == -1);
    assert(settings.date_month == -1);
    assert(settings.date_day == -1);
    assert(settings.autosave_interval == 5);
    assert(settings.autosave_tick == 0);
    assert(settings.autosave_slot_count == 4);
    assert(settings.autosave_slot_index == 0);
    assert(settings.autosave_enabled == 0);
    assert(settings.flag_tutorial == 1);
    assert(settings.flag_rival == 0);
    assert(settings.flag_hq == 1);
    assert(settings.flag_scenario == 1);
    assert(settings.max_hq == 6);
    assert(settings.head == 0);
    assert(settings.eyes == 0);
    assert(settings.hair == 0);
    assert(settings.mouth == 0);
    assert(settings.logo == 0);
    for (size_t index = 0; index < 6; index++) {
        assert(settings.default_values[index] == 100);
        assert(settings.zero_values[index] == 0);
        assert(settings.table_values[index] == (index < 2 ? 1u : 0u));
    }
}

static void test_registry_success_skips_defaults(void) {
    Settings settings;
    memset(&settings, 0, sizeof(settings));
    settings_init_defaults(&settings, load_fills, random_low);
    assert(settings.autosave_interval == 99);
    assert(settings.language_index == 0);
}

int main(void) {
    test_defaults();
    test_registry_success_skips_defaults();
    puts("settings reconstruction: OK");
    return 0;
}
