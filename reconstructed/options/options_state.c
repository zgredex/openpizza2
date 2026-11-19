#include "options_state.h"

#include <string.h>

static const int32_t AUTOSAVE_INTERVALS[OPTIONS_AUTOSAVE_INTERVAL_COUNT] = {
    1, 2, 5, 10, 15, 20, 25, 30, 45, 60, 120,
};

static int32_t clamp(int32_t value, int32_t low, int32_t high) {
    if (value < low) {
        return low;
    }
    if (value > high) {
        return high;
    }
    return value;
}

void options_state_init(OptionsState *options, const Settings *settings) {
    if (options == NULL) {
        return;
    }
    *options = (OptionsState){
        .sound = {1, 10000, 5000, 5000},
        .language_index = 3,
        .autosave_interval_index = 2,
        .autosave_interval_value = 5,
        .autosave_slot_count = 4,
        .autosave_enabled = false,
        .page = OPTIONS_PAGE_GENERAL,
        .open = false,
    };
    if (settings != NULL) {
        options->language_index = settings->language_index <= 3 ? settings->language_index : 3;
        options->autosave_slot_count = settings->autosave_slot_count;
        options->autosave_enabled = settings->autosave_enabled != 0;
        options->autosave_interval_index = 2;
        for (int32_t index = 0; index < OPTIONS_AUTOSAVE_INTERVAL_COUNT; index++) {
            if (AUTOSAVE_INTERVALS[index] == settings->autosave_interval) {
                options->autosave_interval_index = index;
                break;
            }
        }
        options->autosave_interval_value =
            AUTOSAVE_INTERVALS[options->autosave_interval_index];
    }
}

void options_open(OptionsState *options, OptionsPage page) {
    if (options == NULL) {
        return;
    }
    options->open = true;
    options->page = page;
}

void options_set_sound(OptionsState *options, int channel, int32_t value) {
    if (options == NULL || channel < 0 || channel >= OPTIONS_SOUND_CHANNEL_COUNT) {
        return;
    }
    options->sound[channel] = clamp(value, 0, 10000);
}

void options_set_language(OptionsState *options, uint32_t index) {
    if (options == NULL) {
        return;
    }
    options->language_index = index > 3 ? 3 : index;
}

void options_set_autosave_interval_index(OptionsState *options, int32_t index) {
    if (options == NULL) {
        return;
    }
    index = clamp(index, 0, OPTIONS_AUTOSAVE_INTERVAL_COUNT - 1);
    options->autosave_interval_index = index;
    options->autosave_interval_value = AUTOSAVE_INTERVALS[index];
}

void options_toggle_autosave(OptionsState *options) {
    if (options != NULL) {
        options->autosave_enabled = !options->autosave_enabled;
    }
}

void options_apply(const OptionsState *options, Settings *settings) {
    if (options == NULL || settings == NULL) {
        return;
    }
    settings->language_index = options->language_index;
    settings->autosave_interval = options->autosave_interval_value;
    settings->autosave_slot_count = options->autosave_slot_count;
    settings->autosave_enabled = options->autosave_enabled ? 1 : 0;
}

int32_t options_autosave_interval_value(int32_t index) {
    index = clamp(index, 0, OPTIONS_AUTOSAVE_INTERVAL_COUNT - 1);
    return AUTOSAVE_INTERVALS[index];
}
