#include "player_state.h"

#include <string.h>

void player_construct_fields(Player *player, uint32_t character_address,
                             int32_t slot, const char *name) {
    if (player == NULL) {
        return;
    }
    memset(player, 0, sizeof(*player));
    player->character = character_address;
    player->slot = slot;
    if (name != NULL) {
        size_t length = strlen(name);
        if (length >= PLAYER_NAME_CAPACITY) {
            length = PLAYER_NAME_CAPACITY - 1;
        }
        memcpy(player->player_name, name, length);
        player->player_name[length] = '\0';
    }
    player->field_84 = 1;
    player->field_88 = 1;
}

void player_set_character_values(Player *player, const int32_t values[6]) {
    if (player == NULL || values == NULL) {
        return;
    }
    memcpy(player->character_values, values, sizeof(player->character_values));
}

int32_t player_saved_event_count(const Player *player) {
    return player == NULL ? 0 : player->events.total_added;
}
