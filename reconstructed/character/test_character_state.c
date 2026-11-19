#include "character_state.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_layout(void) {
    assert(sizeof(Character) == 0x828);
    assert(offsetof(Character, skill) == 0x04);
    assert(offsetof(Character, speed) == 0x08);
    assert(offsetof(Character, motivation) == 0x0C);
    assert(offsetof(Character, health) == 0x10);
    assert(offsetof(Character, skill_timer) == 0x14);
    assert(offsetof(Character, gender) == 0x24);
    assert(offsetof(Character, age) == 0x38);
    assert(offsetof(Character, performance) == 0x3C);
    assert(offsetof(Character, rating_data) == 0x44);
    assert(offsetof(Character, registry_id) == 0x814);
    assert(offsetof(Character, profession_type) == 0x824);
    assert(offsetof(Character, activity_state) == 0x825);
}

static void test_constructor_fields(void) {
    Character character;
    character_construct_fields(&character, 55, 44, 33, 22, 30, 3);
    assert(character.skill == 55);
    assert(character.speed == 44);
    assert(character.motivation == 33);
    assert(character.health == 22);
    assert(character.age == 30);
    assert(character.performance == 0);
    assert(character.field_40 == 0);
    assert(character.skill_timer == 0);
    assert(character.speed_timer == 0);
    assert(character.motivation_timer == 0);
    assert(character.health_timer == 0);
    assert(character.registry_id == -1);
    assert(character.object_id == -1);
    assert(character.player_slot == -1);
    assert(character.branch_id == -1);
    assert(character.profession_type == 3);
    assert(character.activity_state == 2);
    for (size_t index = 0; index < CHARACTER_RATING_COUNT; index++) {
        assert(character.rating_data[index] == 0);
    }
}

static void test_decay_timers(void) {
    Character character;
    character_construct_fields(&character, 10, 20, 30, 40, 30, 0);
    character.skill_timer = 2;
    character.speed_timer = -2;
    character.motivation_timer = 0;
    character.health_timer = 3;
    character_apply_decay_timers(&character);
    assert(character.skill == 11);
    assert(character.skill_timer == 1);
    assert(character.speed == 19);
    assert(character.speed_timer == -1);
    assert(character.motivation == 30);
    assert(character.motivation_timer == 0);
    assert(character.health == 41);
    assert(character.health_timer == 2);

    character.skill_timer = -1;
    character.speed_timer = 1;
    character_apply_decay_timers(&character);
    assert(character.skill == 10);
    assert(character.skill_timer == 0);
    assert(character.speed == 20);
    assert(character.speed_timer == 0);
}

static void test_performance_and_rating_blocks(void) {
    Character character;
    character_construct_fields(&character, 1, 2, 3, 4, 5, 1);
    character_set_performance(&character, 77);
    assert(character.performance == 77);
    for (size_t block = 0; block < CHARACTER_RATING_BLOCK_COUNT; block++) {
        character.rating_data[block * CHARACTER_RATING_BLOCK_SIZE] =
            (int32_t)(block + 1);
        assert(character_rating_block(&character, block, 0) ==
               (int32_t)(block + 1));
    }
    assert(character_rating_block(&character, 5, 0) == 0);
    assert(character_rating_block(&character, 0, 100) == 0);
    assert(character_rating_block(NULL, 0, 0) == 0);
}

int main(void) {
    test_layout();
    test_constructor_fields();
    test_decay_timers();
    test_performance_and_rating_blocks();
    puts("character object reconstruction: OK");
    return 0;
}
