#ifndef PC2_RECONSTRUCTED_MISSION_STATE_H
#define PC2_RECONSTRUCTED_MISSION_STATE_H

#include <stddef.h>
#include <stdint.h>

/*
 * Player mission state, size 0xD8, as constructed by Player_MissionState_Construct
 * (0x4F5DF0) and initialised by Game_InitDateState (0x4F6BD0).
 *
 * The goal ids live at +0x04/+0x08/+0x0C, the per-goal progress slots at
 * +0x10/+0x14/+0x18, the deadline at +0xC0, and the completed flags at
 * +0xC4/+0xC5/+0xC6. Those are exactly the offsets used by
 * tools/emulate_mission_goals.c.
 */
#pragma pack(push, 1)
typedef struct MissionState {
    uint32_t vtable;                /* 0x00 */
    int32_t goals[3];               /* 0x04..0x0F */
    int32_t goal_progress[3];       /* 0x10..0x1B: +0x14 is goal 1 */
    uint8_t reserved_1c[0xA4];      /* 0x1C..0xBF */
    int32_t deadline;               /* 0xC0 */
    uint8_t completed[3];           /* 0xC4..0xC6 */
    uint8_t reserved_c7;            /* 0xC7 */
    int32_t field_c8;               /* 0xC8 */
    uint8_t field_cc;               /* 0xCC */
    uint8_t reserved_cd[3];         /* 0xCD..0xCF */
    int32_t field_d0;               /* 0xD0 */
    int32_t field_d4;               /* 0xD4 */
} MissionState;
#pragma pack(pop)

/*
 * Prefix of the city definition read by Game_InitDateState. Only the fields
 * used by the campaign branch are modelled.
 */
#pragma pack(push, 1)
typedef struct CityMissionData {
    uint8_t reserved_00[0x33C];
    int32_t field_33c;              /* 0x33C */
    uint8_t reserved_340[0x8];
    int32_t game_length;            /* 0x348 */
    int32_t goals[3];               /* 0x34C..0x357 */
} CityMissionData;
#pragma pack(pop)

/* Campaign branch of Game_InitDateState (0x4F6BD0). */
void game_init_date_state(MissionState *state, const CityMissionData *city);

#endif
