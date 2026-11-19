#ifndef PC2_RECONSTRUCTED_SETTINGS_H
#define PC2_RECONSTRUCTED_SETTINGS_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/*
 * Layout of the serialized global options block at 0x57B8A8 (0x164 bytes).
 * Field offsets match the addresses read by Settings_InitDefaults,
 * Settings_LoadFromRegistry, Config_SaveOptionsToRegistry,
 * CharacterSelect_UpdateScreen, FreePlaySetup_InitWindow,
 * AutosaveOptions_Init and Game_AutoSaveTick.
 */
#pragma pack(push, 1)
typedef struct Settings {
    uint32_t version;                 /* 0x000  0x57B8A8 */
    uint32_t gender;                  /* 0x004  0x57B8AC */
    uint32_t color;                   /* 0x008  0x57B8B0 */
    uint32_t difficulty;              /* 0x00C  0x57B8B4 */
    char enterprise_name[64];         /* 0x010  0x57B8B8 */
    char player_name[64];             /* 0x050  0x57B8F8 */
    uint32_t head;                    /* 0x090  0x57B938 */
    uint32_t eyes;                    /* 0x094  0x57B93C */
    uint32_t hair;                    /* 0x098  0x57B940 */
    uint32_t mouth;                   /* 0x09C  0x57B944 */
    uint32_t logo;                    /* 0x0A0  0x57B948 */
    int32_t attributes[6];            /* 0x0A4  0x57B94C */
    uint32_t flag_tutorial;           /* 0x0BC  0x57B964 */
    uint32_t flag_rival;              /* 0x0C0  0x57B968 */
    uint32_t flag_hq;                 /* 0x0C4  0x57B96C */
    uint32_t flag_scenario;           /* 0x0C8  0x57B970 */
    uint32_t start_branch_size;       /* 0x0CC  0x57B974 */
    uint32_t max_hq;                  /* 0x0D0  0x57B978 */
    int32_t default_values[6];        /* 0x0D4  0x57B97C */
    int32_t zero_values[6];           /* 0x0EC  0x57B994 */
    uint32_t table_values[6];         /* 0x104  0x57B9AC */
    uint32_t freeplay_start_index;    /* 0x11C  0x57B9C4 */
    uint32_t freeplay_start_money;    /* 0x120  0x57B9C8 */
    uint32_t freeplay_game_length;    /* 0x124  0x57B9CC */
    int32_t date_year;                /* 0x128  0x57B9D0 */
    int32_t date_month;               /* 0x12C  0x57B9D4 */
    int32_t date_day;                 /* 0x130  0x57B9D8 */
    uint32_t language_index;          /* 0x134  0x57B9DC */
    uint8_t reserved_138[0x10];       /* 0x138 */
    int32_t autosave_interval;        /* 0x148  0x57B9F0 */
    int32_t autosave_tick;            /* 0x14C  0x57B9F4 */
    int32_t autosave_slot_count;      /* 0x150  0x57B9F8 */
    int32_t autosave_slot_index;      /* 0x154  0x57B9FC */
    uint8_t reserved_158[0x8];        /* 0x158 */
    uint8_t autosave_enabled;         /* 0x160  0x57BA08 */
    uint8_t reserved_161[0x3];        /* 0x161 */
} Settings;
#pragma pack(pop)

typedef bool (*settings_load_fn)(Settings *settings);
typedef uint32_t (*settings_random_fn)(uint32_t low, uint32_t high);

/*
 * Reconstructed from Settings_InitDefaults (0x406A90). The original clears the
 * 0x59-dword block, tries the registry, and otherwise writes the defaults
 * below. The callbacks keep the host build independent of Win32.
 */
void settings_init_defaults(Settings *settings, settings_load_fn load,
                            settings_random_fn random);

#endif
