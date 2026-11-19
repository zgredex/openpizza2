#include "options_state.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static bool load_fails(Settings *settings) {
    (void)settings;
    return false;
}

static uint32_t random_low(uint32_t low, uint32_t high) {
    (void)high;
    return low;
}

static void test_defaults(void) {
    Settings settings;
    settings_init_defaults(&settings, load_fails, random_low);
    OptionsState options;
    options_state_init(&options, &settings);

    assert(options.sound[0] == 1);
    assert(options.sound[1] == 10000);
    assert(options.sound[2] == 5000);
    assert(options.sound[3] == 5000);
    assert(options.language_index == 3);
    assert(options.autosave_interval_index == 2);
    assert(options.autosave_interval_value == 5);
    assert(options.autosave_slot_count == 4);
    assert(!options.autosave_enabled);
    assert(options.page == OPTIONS_PAGE_GENERAL);
    assert(!options.open);
}

static void test_interval_table_and_clamps(void) {
    assert(options_autosave_interval_value(0) == 1);
    assert(options_autosave_interval_value(2) == 5);
    assert(options_autosave_interval_value(10) == 120);
    assert(options_autosave_interval_value(-5) == 1);
    assert(options_autosave_interval_value(99) == 120);

    OptionsState options;
    options_state_init(&options, NULL);
    options_set_autosave_interval_index(&options, 10);
    assert(options.autosave_interval_value == 120);
    options_set_autosave_interval_index(&options, -1);
    assert(options.autosave_interval_index == 0);
    assert(options.autosave_interval_value == 1);
}

static void test_language_sound_and_apply(void) {
    Settings settings;
    settings_init_defaults(&settings, load_fails, random_low);
    OptionsState options;
    options_state_init(&options, &settings);
    options_open(&options, OPTIONS_PAGE_AUTOSAVE);
    assert(options.open);
    assert(options.page == OPTIONS_PAGE_AUTOSAVE);

    options_set_language(&options, 0);
    assert(options.language_index == 0);
    options_set_language(&options, 9);
    assert(options.language_index == 3);

    options_set_sound(&options, 1, 12000);
    assert(options.sound[1] == 10000);
    options_set_sound(&options, 2, -5);
    assert(options.sound[2] == 0);
    options_set_sound(&options, 4, 100);
    assert(options.sound[3] == 5000);

    options_set_autosave_interval_index(&options, 8);
    options_toggle_autosave(&options);
    options_toggle_autosave(&options);
    assert(!options.autosave_enabled);
    options_toggle_autosave(&options);

    options_apply(&options, &settings);
    assert(settings.language_index == 3);
    assert(settings.autosave_interval == 45);
    assert(settings.autosave_slot_count == 4);
    assert(settings.autosave_enabled == 1);
}

int main(void) {
    test_defaults();
    test_interval_table_and_clamps();
    test_language_sound_and_apply();
    puts("options state reconstruction: OK");
    return 0;
}
