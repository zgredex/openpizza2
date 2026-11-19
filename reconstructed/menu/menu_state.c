#include "menu_state.h"

#include <stdio.h>
#include <string.h>

static void set_status(MenuState *menu, const char *text) {
    if (menu == NULL) {
        return;
    }
    menu->has_status = true;
    snprintf(menu->status, sizeof(menu->status), "%s", text);
}

void menu_state_init(MenuState *menu) {
    if (menu == NULL) {
        return;
    }
    *menu = (MenuState){
        .items =
            {
                {MENU_START_NEW_GAME, "Start new game", 0x3ee, MENU_ITEM_X, 6,
                 MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT},
                {MENU_START_FREE_GAME, "Start free game", 0x3ef, MENU_ITEM_X, 48,
                 MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT},
                {MENU_CONTINUE_GAME, "Continue game", 0x3f0, MENU_ITEM_X, 91,
                 MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT},
                {MENU_OPTIONS, "Options", 0x3f1, MENU_ITEM_X, 133,
                 MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT},
                {MENU_CREDITS, "Credits", 0x3f7, MENU_ITEM_X, 175,
                 MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT},
                {MENU_QUIT, "Quit", 0x3f6, MENU_ITEM_X, 560,
                 MENU_ITEM_WIDTH, MENU_ITEM_HEIGHT},
            },
        .selected = 0,
        .hover = -1,
        .interacted = false,
        .has_status = false,
        .status = {0},
    };
}

void menu_set_selected(MenuState *menu, int index) {
    if (menu != NULL && index >= 0 && index < MENU_ITEM_COUNT) {
        menu->selected = index;
    }
}

void menu_select_next(MenuState *menu) {
    if (menu == NULL) {
        return;
    }
    menu->selected = (menu->selected + 1) % MENU_ITEM_COUNT;
    menu->hover = -1;
    menu->interacted = true;
}

void menu_select_previous(MenuState *menu) {
    if (menu == NULL) {
        return;
    }
    menu->selected = (menu->selected + MENU_ITEM_COUNT - 1) % MENU_ITEM_COUNT;
    menu->hover = -1;
    menu->interacted = true;
}

int menu_button_at(const MenuState *menu, int32_t x, int32_t y) {
    if (menu == NULL) {
        return -1;
    }
    for (int index = 0; index < MENU_ITEM_COUNT; index++) {
        const MenuItem *item = &menu->items[index];
        if (x >= item->x && y >= item->y && x < item->x + (int32_t)item->width &&
            y < item->y + (int32_t)item->height) {
            return index;
        }
    }
    return -1;
}

void menu_set_hover(MenuState *menu, int index) {
    if (menu == NULL) {
        return;
    }
    if (index >= 0 && index < MENU_ITEM_COUNT) {
        menu->hover = index;
        menu->interacted = true;
    } else {
        menu->hover = -1;
    }
}

MenuAction menu_activate(MenuState *menu) {
    if (menu == NULL) {
        return MENU_QUIT;
    }
    MenuAction action = menu->items[menu->selected].action;
    switch (action) {
    case MENU_CONTINUE_GAME:
        set_status(menu, "No saved games found.");
        break;
    case MENU_OPTIONS:
        set_status(menu, "Options screen is not rebuilt yet.");
        break;
    case MENU_CREDITS:
        set_status(menu, "Pizza Connection 2 menu reconstruction.");
        break;
    case MENU_QUIT:
        menu->has_status = false;
        menu->status[0] = '\0';
        break;
    case MENU_START_NEW_GAME:
    case MENU_START_FREE_GAME:
        set_status(menu, "Starting a new game...");
        break;
    }
    return action;
}

const char *menu_action_label(MenuAction action) {
    switch (action) {
    case MENU_START_NEW_GAME:
        return "Start new game";
    case MENU_START_FREE_GAME:
        return "Start free game";
    case MENU_CONTINUE_GAME:
        return "Continue game";
    case MENU_OPTIONS:
        return "Options";
    case MENU_CREDITS:
        return "Credits";
    case MENU_QUIT:
        return "Quit";
    }
    return "";
}

uint16_t menu_action_control_id(MenuAction action) {
    switch (action) {
    case MENU_START_NEW_GAME:
        return 0x3ee;
    case MENU_START_FREE_GAME:
        return 0x3ef;
    case MENU_CONTINUE_GAME:
        return 0x3f0;
    case MENU_OPTIONS:
        return 0x3f1;
    case MENU_CREDITS:
        return 0x3f7;
    case MENU_QUIT:
        return 0x3f6;
    }
    return 0;
}
