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
    assert(offsetof(Player, extra_character_values) == 0x54);
    assert(offsetof(Player, field_84) == 0x84);
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
    assert(player.field_84 == 1);
    assert(player.field_88 == 1);
    assert(player.events.total_added == 0);
    assert(player.ai_state == 0);
    assert(player.mission_state == 0);
    assert(player.field_2c == 0);
    assert(player.field_30 == 0);
    assert(player.field_34 == 0);
    assert(player.field_38 == 0);
    for (size_t index = 0; index < PLAYER_CHARACTER_VALUE_COUNT; index++) {
        assert(player.character_values[index] == 0);
        assert(player.extra_character_values[index] == 0);
        assert(player.field_6c[index] == 0);
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
    test_name_truncation();
    puts("player object reconstruction: OK");
    return 0;
}
