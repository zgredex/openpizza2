#include "player_state.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_layout(void) {
    assert(sizeof(Player) == 0xB0);
    assert(sizeof(PlayerEventList) == 0x1C);
    assert(offsetof(Player, character) == 0x04);
    assert(offsetof(Player, slot) == 0x08);
    assert(offsetof(Player, player_name) == 0x0C);
    assert(offsetof(Player, character_values) == 0x3C);
    assert(offsetof(Player, achievement_bonus_values) == 0x54);
    assert(offsetof(Player, reserved_84) == 0x84);
    assert(offsetof(Player, events) == 0x8C);
    assert(offsetof(Player, ai_state) == 0xA8);
    assert(offsetof(Player, mission_state) == 0xAC);
}

static void test_constructor_fields(void) {
    Player player;
    player_construct_fields(&player, 0x12345678u, 3, "Ada");
    assert(player.character == 0x12345678u);
    assert(player.slot == 3);
    assert(strcmp(player.player_name, "Ada") == 0);
    assert(player.reserved_84 == 1);
    assert(player.award_briefing_enabled == 1);
    assert(player.events.total_added == 0);
    assert(player.ai_state == 0);
    assert(player.mission_state == 0);
    assert(player.reserved_2c == 0);
    assert(player.reserved_30 == 0);
    assert(player.reserved_34 == 0);
    assert(player.attacks_fended_off == 0);
    for (size_t index = 0; index < PLAYER_CHARACTER_VALUE_COUNT; index++) {
        assert(player.character_values[index] == 0);
        assert(player.achievement_bonus_values[index] == 0);
        assert(player.achievement_tiers[index] == 0);
    }
    assert(player_saved_event_count(&player) == 0);
    assert(player_saved_event_count(NULL) == 0);
}

static void test_character_values(void) {
    Player player;
    player_construct_fields(&player, 0, 0, NULL);
    const int32_t values[6] = {3, 1, -2, 0, 1, -1};
    player_set_character_values(&player, values);
    for (size_t index = 0; index < PLAYER_CHARACTER_VALUE_COUNT; index++) {
        assert(player.character_values[index] == values[index]);
    }
    player_set_character_values(&player, NULL);
    player.events.total_added = 7;
    assert(player_saved_event_count(&player) == 7);
}

static void test_achievements_and_events(void) {
    Player player;
    player_construct_fields(&player, 0, 0, NULL);
    for (size_t index = 0; index < PLAYER_CHARACTER_VALUE_COUNT; index++) {
        for (int tier = 0; tier < 4; tier++) {
            assert(player_advance_achievement(&player, index));
        }
        assert(player.achievement_tiers[index] == 4);
        assert(player.achievement_bonus_values[index] == 4);
        assert(!player_advance_achievement(&player, index));
    }
    assert(!player_advance_achievement(&player, 6));
    assert(!player_advance_achievement(NULL, 0));

    assert(PLAYER_EVENT_CITY_PRIZE == 0);
    assert(PLAYER_EVENT_BEST_RESTAURANT == 1);
    assert(PLAYER_EVENT_BEST_BUILDING == 2);
    assert(PLAYER_EVENT_TYPE_COUNT == 3);
    PlayerEvent event;
    memset(&event, 0xAA, sizeof(event));
    player_event_init(&event, PLAYER_EVENT_BEST_BUILDING, 0x1234);
    assert(event.event_type == 2);
    assert(event.date_word == 0x1234);
    assert(event.padding_a[0] == 0);
    assert(event.padding_a[1] == 0);
    assert(sizeof(PlayerEvent) == 0xC);
}

static void test_ai_reset_and_attack_counter(void) {
    Player player;
    player_construct_fields(&player, 0, 1, "AI");
    assert(player.award_briefing_enabled == 1);
    player_apply_ai_slot_defaults(&player);
    assert(player.reserved_84 == 1);
    assert(player.award_briefing_enabled == 0);
    player_apply_ai_slot_defaults(NULL);

    player_record_attack_fended_off(&player);
    player_record_attack_fended_off(&player);
    assert(player.attacks_fended_off == 2);
    player_record_attack_fended_off(NULL);
}

static void test_name_truncation(void) {
    Player player;
    player_construct_fields(&player, 0, 0,
                            "abcdefghijklmnopqrstuvwxyz0123456789");
    assert(player.player_name[PLAYER_NAME_CAPACITY - 1] == '\0');
    assert(strlen(player.player_name) == PLAYER_NAME_CAPACITY - 1);
}

int main(void) {
    test_layout();
    test_constructor_fields();
    test_character_values();
    test_achievements_and_events();
    test_ai_reset_and_attack_counter();
    test_name_truncation();
    puts("player object reconstruction: OK");
    return 0;
}
