#ifndef PC2_RECONSTRUCTED_UI_SCREEN_H
#define PC2_RECONSTRUCTED_UI_SCREEN_H

#include <stdbool.h>
#include <stdint.h>

#include "../menu/menu_state.h"

/* Screen values from GameLoop_DispatchScreens (0x4052C0). */
typedef enum ScreenId {
    SCREEN_MAIN_MENU = 0x15,
    SCREEN_MISSION_BRIEFING = 0x16,
    SCREEN_GAME_SESSION = 0x17,
    SCREEN_FREE_PLAY_SETUP = 0x18,
    SCREEN_SUB_START_MENU_A = 0x19,
    SCREEN_SUB_START_MENU_B = 0x1b,
    SCREEN_CHARACTER_SELECT = 0x1c,
    SCREEN_CLOSE_SUB_MENU = 0x1d,
} ScreenId;

typedef struct ScreenState {
    ScreenId active;
    ScreenId previous;
    bool free_game;
    bool new_game;
    bool sub_menu_open;
    bool has_status;
    char status[64];
} ScreenState;

void ui_screen_init(ScreenState *screen);
void ui_screen_enter(ScreenState *screen, ScreenId next);
void ui_screen_back(ScreenState *screen);
void ui_screen_from_menu_action(ScreenState *screen, MenuAction action);
void ui_screen_character_select_start(ScreenState *screen);
void ui_screen_free_play_start(ScreenState *screen);
void ui_screen_mission_start(ScreenState *screen);
void ui_screen_close_sub_menu(ScreenState *screen);

#endif
