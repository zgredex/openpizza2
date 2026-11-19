#ifndef PC2_RECONSTRUCTED_VALUE_STATE_H
#define PC2_RECONSTRUCTED_VALUE_STATE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct ValueApproachState {
    double value;
    uint8_t dirty;
} ValueApproachState;

/*
 * Advertising value record recovered from Value_Approach (0x4E4670),
 * Game_DecayCityDateBonus (0x4E46F0) and Game_GetAdjustedValue (0x4E4490).
 * The animated value is the branch's customer-proximity radius component.
 */
void value_state_init(ValueApproachState *state, double value);
bool value_approach(ValueApproachState *state, double step, double target);
void value_state_decay_hour(ValueApproachState *state);

int32_t game_adjusted_value(int32_t base_value, int32_t animated_value,
                            int32_t city_event_bonus, bool human_player,
                            uint8_t mission_field_c4, bool mission_field_1ac,
                            int32_t owner_slot, int32_t owner_coverage,
                            int32_t city_field_64, int32_t city_field_4c);

#endif
