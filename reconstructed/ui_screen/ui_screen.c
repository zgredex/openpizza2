#include "ui_screen.h"

#include <stdio.h>
#include <string.h>

static void set_status(ScreenState *screen, const char *text) {
    if (screen == NULL) {
        return;
    }
    screen->has_status = true;
    snprintf(screen->status, sizeof(screen->status), "%s", text);
}

void ui_screen_init(ScreenState *screen) {
    if (screen == NULL) {
        return;
    }
    *screen = (ScreenState){
        .active = SCREEN_MAIN_MENU,
        .previous = SCREEN_MAIN_MENU,
        .free_game = false,
        .new_game = false,
        .sub_menu_open = false,
        .has_status = false,
        .status = {0},
    };
}

void ui_screen_enter(ScreenState *screen, ScreenId next) {
    if (screen == NULL) {
        return;
    }
    screen->previous = screen->active;
    screen->active = next;
}

void ui_screen_back(ScreenState *screen) {
    if (screen == NULL) {
        return;
    }
    if (screen->active == SCREEN_SUB_START_MENU_A ||
        screen->active == SCREEN_SUB_START_MENU_B) {
        screen->sub_menu_open = false;
    }
    screen->active = screen->previous;
}

void ui_screen_from_menu_action(ScreenState *screen, MenuAction action) {
    if (screen == NULL) {
        return;
    }
    screen->has_status = false;
    screen->status[0] = '\0';
    switch (action) {
    case MENU_START_NEW_GAME:
        screen->new_game = true;
        screen->free_game = false;
        ui_screen_enter(screen, SCREEN_CHARACTER_SELECT);
        break;
    case MENU_START_FREE_GAME:
        screen->new_game = true;
        screen->free_game = true;
        ui_screen_enter(screen, SCREEN_CHARACTER_SELECT);
        break;
    case MENU_CONTINUE_GAME:
        screen->sub_menu_open = true;
        ui_screen_enter(screen, SCREEN_SUB_START_MENU_A);
        break;
    case MENU_OPTIONS:
        screen->sub_menu_open = true;
        ui_screen_enter(screen, SCREEN_SUB_START_MENU_B);
        break;
    case MENU_CREDITS:
        set_status(screen, "Credits movie");
        break;
    case MENU_QUIT:
        set_status(screen, "Quit requested");
        break;
    }
}

void ui_screen_character_select_start(ScreenState *screen) {
    if (screen == NULL) {
        return;
    }
    ui_screen_enter(screen,
                    screen->free_game ? SCREEN_FREE_PLAY_SETUP : SCREEN_MISSION_BRIEFING);
}

void ui_screen_free_play_start(ScreenState *screen) {
    if (screen != NULL) {
        ui_screen_enter(screen, SCREEN_GAME_SESSION);
    }
}

void ui_screen_mission_start(ScreenState *screen) {
    if (screen != NULL) {
        ui_screen_enter(screen, SCREEN_GAME_SESSION);
    }
}

void ui_screen_close_sub_menu(ScreenState *screen) {
    if (screen == NULL) {
        return;
    }
    screen->sub_menu_open = false;
    ui_screen_enter(screen, SCREEN_MAIN_MENU);
}
