#include "ui_screen.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_screen_ids(void) {
    assert(SCREEN_MAIN_MENU == 0x15);
    assert(SCREEN_MISSION_BRIEFING == 0x16);
    assert(SCREEN_GAME_SESSION == 0x17);
    assert(SCREEN_FREE_PLAY_SETUP == 0x18);
    assert(SCREEN_SUB_START_MENU_A == 0x19);
    assert(SCREEN_SUB_START_MENU_B == 0x1b);
    assert(SCREEN_CHARACTER_SELECT == 0x1c);
    assert(SCREEN_CLOSE_SUB_MENU == 0x1d);
}

static void test_campaign_path(void) {
    ScreenState screen;
    ui_screen_init(&screen);
    assert(screen.active == SCREEN_MAIN_MENU);
    ui_screen_from_menu_action(&screen, MENU_START_NEW_GAME);
    assert(screen.active == SCREEN_CHARACTER_SELECT);
    assert(screen.previous == SCREEN_MAIN_MENU);
    assert(screen.new_game);
    assert(!screen.free_game);

    ui_screen_character_select_start(&screen);
    assert(screen.active == SCREEN_MISSION_BRIEFING);
    ui_screen_mission_start(&screen);
    assert(screen.active == SCREEN_GAME_SESSION);
    ui_screen_back(&screen);
    assert(screen.active == SCREEN_MISSION_BRIEFING);
}

static void test_free_play_path(void) {
    ScreenState screen;
    ui_screen_init(&screen);
    ui_screen_from_menu_action(&screen, MENU_START_FREE_GAME);
    assert(screen.active == SCREEN_CHARACTER_SELECT);
    assert(screen.free_game);
    ui_screen_character_select_start(&screen);
    assert(screen.active == SCREEN_FREE_PLAY_SETUP);
    ui_screen_free_play_start(&screen);
    assert(screen.active == SCREEN_GAME_SESSION);
}

static void test_sub_menus_and_status(void) {
    ScreenState screen;
    ui_screen_init(&screen);
    ui_screen_from_menu_action(&screen, MENU_CONTINUE_GAME);
    assert(screen.active == SCREEN_SUB_START_MENU_A);
    assert(screen.sub_menu_open);
    ui_screen_close_sub_menu(&screen);
    assert(screen.active == SCREEN_MAIN_MENU);
    assert(!screen.sub_menu_open);

    ui_screen_from_menu_action(&screen, MENU_OPTIONS);
    assert(screen.active == SCREEN_SUB_START_MENU_B);
    assert(screen.sub_menu_open);
    ui_screen_back(&screen);
    assert(screen.active == SCREEN_MAIN_MENU);
    assert(!screen.sub_menu_open);

    ui_screen_from_menu_action(&screen, MENU_CREDITS);
    assert(screen.active == SCREEN_MAIN_MENU);
    assert(screen.has_status);
    assert(strcmp(screen.status, "Credits movie") == 0);

    ui_screen_from_menu_action(&screen, MENU_QUIT);
    assert(strcmp(screen.status, "Quit requested") == 0);
}

int main(void) {
    test_screen_ids();
    test_campaign_path();
    test_free_play_path();
    test_sub_menus_and_status();
    puts("UI screen reconstruction: OK");
    return 0;
}
