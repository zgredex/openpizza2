#include "character_state.h"

#include <string.h>

void character_construct_fields(Character *character, int32_t skill,
                                int32_t speed, int32_t motivation,
                                int32_t health, int32_t age,
                                uint8_t profession_type) {
    if (character == NULL) {
        return;
    }
    memset(character, 0, sizeof(*character));
    character->skill = skill;
    character->speed = speed;
    character->motivation = motivation;
    character->health = health;
    character->age = age;
    character->registry_id = -1;
    character->object_id = -1;
    character->player_slot = -1;
    character->branch_id = -1;
    character->profession_type = profession_type;
    character->activity_state = 2;
}

void character_apply_decay_timers(Character *character) {
    if (character == NULL) {
        return;
    }
    if (character->skill_timer > 0) {
        character->skill++;
        character->skill_timer--;
    } else if (character->skill_timer < 0) {
        character->skill--;
        character->skill_timer++;
    }
    if (character->speed_timer > 0) {
        character->speed++;
        character->speed_timer--;
    } else if (character->speed_timer < 0) {
        character->speed--;
        character->speed_timer++;
    }
    if (character->motivation_timer > 0) {
        character->motivation++;
        character->motivation_timer--;
    } else if (character->motivation_timer < 0) {
        character->motivation--;
        character->motivation_timer++;
    }
    if (character->health_timer > 0) {
        character->health++;
        character->health_timer--;
    } else if (character->health_timer < 0) {
        character->health--;
        character->health_timer++;
    }
}

void character_set_performance(Character *character, int32_t value) {
    if (character != NULL) {
        character->performance = value;
    }
}

int32_t character_rating_block(const Character *character, size_t block,
                               size_t index) {
    if (character == NULL || block >= CHARACTER_RATING_BLOCK_COUNT ||
        index >= CHARACTER_RATING_BLOCK_SIZE) {
        return 0;
    }
    return character->rating_data[block * CHARACTER_RATING_BLOCK_SIZE + index];
}
