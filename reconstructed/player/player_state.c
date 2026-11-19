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
    player->reserved_84 = 1;
    player->award_briefing_enabled = 1;
}

void player_apply_ai_slot_defaults(Player *player) {
    if (player == NULL) {
        return;
    }
    player->reserved_84 = 1;
    player->award_briefing_enabled = 0;
}

void player_record_attack_fended_off(Player *player) {
    if (player == NULL) {
        return;
    }
    player->attacks_fended_off++;
}

bool player_advance_achievement(Player *player, size_t index) {
    if (player == NULL || index >= PLAYER_CHARACTER_VALUE_COUNT ||
        player->achievement_tiers[index] >= 4) {
        return false;
    }
    player->achievement_tiers[index]++;
    player->achievement_bonus_values[index]++;
    return true;
}

void player_event_init(PlayerEvent *event, int32_t event_type,
                       uint16_t date_word) {
    if (event == NULL) {
        return;
    }
    memset(event, 0, sizeof(*event));
    event->event_type = event_type;
    event->date_word = date_word;
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
