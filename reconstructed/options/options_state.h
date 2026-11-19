#ifndef PC2_RECONSTRUCTED_OPTIONS_STATE_H
#define PC2_RECONSTRUCTED_OPTIONS_STATE_H

#include <stdbool.h>
#include <stdint.h>

#include "../settings/settings.h"

#define OPTIONS_AUTOSAVE_INTERVAL_COUNT 11
#define OPTIONS_SOUND_CHANNEL_COUNT 4

typedef enum OptionsPage {
    OPTIONS_PAGE_GENERAL = 0,
    OPTIONS_PAGE_AUTOSAVE = 1,
} OptionsPage;

typedef struct OptionsState {
    int32_t sound[OPTIONS_SOUND_CHANNEL_COUNT]; /* enabled, music, effects, voice */
    uint32_t language_index;
    int32_t autosave_interval_index;
    int32_t autosave_interval_value;
    int32_t autosave_slot_count;
    bool autosave_enabled;
    OptionsPage page;
    bool open;
} OptionsState;

/*
 * Options/autosave screen state. The slider bounds and the interval table are
 * from SubStartMenu_FillOptions (0x4C7D80), AutosaveOptions_Init (0x4A21F0),
 * Options_GetGlobalSettings (0x547770) and the 0x568D88 table:
 * 1, 2, 5, 10, 15, 20, 25, 30, 45, 60, 120.
 */
void options_state_init(OptionsState *options, const Settings *settings);
void options_open(OptionsState *options, OptionsPage page);
void options_set_sound(OptionsState *options, int channel, int32_t value);
void options_set_language(OptionsState *options, uint32_t index);
void options_set_autosave_interval_index(OptionsState *options, int32_t index);
void options_toggle_autosave(OptionsState *options);
void options_apply(const OptionsState *options, Settings *settings);
int32_t options_autosave_interval_value(int32_t index);

#endif
