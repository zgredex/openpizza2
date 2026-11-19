#include "menu_state.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static void test_layout_and_ids(void) {
    MenuState menu;
    menu_state_init(&menu);
    assert(menu.selected == 0);
    assert(menu.hover == -1);
    assert(!menu.interacted);
    assert(!menu.has_status);
    assert(menu.items[0].control_id == 0x3ee);
    assert(menu.items[1].control_id == 0x3ef);
    assert(menu.items[2].control_id == 0x3f0);
    assert(menu.items[3].control_id == 0x3f1);
    assert(menu.items[4].control_id == 0x3f7);
    assert(menu.items[5].control_id == 0x3f6);
    assert(strcmp(menu.items[0].label, "Start new game") == 0);
    assert(strcmp(menu.items[4].label, "Credits") == 0);
}

static void test_hit_testing(void) {
    MenuState menu;
    menu_state_init(&menu);
    assert(menu_button_at(&menu, 650, 12) == 0);
    assert(menu_button_at(&menu, 650, 140) == 3);
    assert(menu_button_at(&menu, 650, 566) == 5);
    assert(menu_button_at(&menu, 10, 10) == -1);
    assert(menu_button_at(&menu, 594, 12) == -1);
    assert(menu_button_at(&menu, 798, 12) == 0);
}

static void test_navigation_wraps(void) {
    MenuState menu;
    menu_state_init(&menu);
    menu_select_previous(&menu);
    assert(menu.selected == 5);
    menu_select_next(&menu);
    assert(menu.selected == 0);
    menu_select_next(&menu);
    assert(menu.selected == 1);
    assert(menu.interacted);
    assert(menu.hover == -1);
}

static void test_activation_statuses(void) {
    MenuState menu;
    menu_state_init(&menu);
    menu_set_selected(&menu, 2);
    assert(menu_activate(&menu) == MENU_CONTINUE_GAME);
    assert(menu.has_status);
    assert(strcmp(menu.status, "No saved games found.") == 0);

    menu_set_selected(&menu, 3);
    assert(menu_activate(&menu) == MENU_OPTIONS);
    assert(strcmp(menu.status, "Options screen is not rebuilt yet.") == 0);

    menu_set_selected(&menu, 4);
    assert(menu_activate(&menu) == MENU_CREDITS);
    assert(strcmp(menu.status, "Pizza Connection 2 menu reconstruction.") == 0);

    menu_set_selected(&menu, 5);
    assert(menu_activate(&menu) == MENU_QUIT);
    assert(!menu.has_status);
    assert(menu.status[0] == '\0');

    menu_set_selected(&menu, 0);
    assert(menu_activate(&menu) == MENU_START_NEW_GAME);
    assert(strcmp(menu.status, "Starting a new game...") == 0);

    menu_set_selected(&menu, 1);
    assert(menu_activate(&menu) == MENU_START_FREE_GAME);
    assert(strcmp(menu.status, "Starting a new game...") == 0);
}

static void test_hover_selection(void) {
    MenuState menu;
    menu_state_init(&menu);
    menu_set_hover(&menu, 4);
    assert(menu.hover == 4);
    assert(menu.interacted);
    menu_set_hover(&menu, 99);
    assert(menu.hover == -1);
}

int main(void) {
    test_layout_and_ids();
    test_hit_testing();
    test_navigation_wraps();
    test_activation_statuses();
    test_hover_selection();
    puts("menu state reconstruction: OK");
    return 0;
}
