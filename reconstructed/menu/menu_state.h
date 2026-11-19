#ifndef PC2_RECONSTRUCTED_MENU_STATE_H
#define PC2_RECONSTRUCTED_MENU_STATE_H

#include <stdbool.h>
#include <stdint.h>

#define MENU_ITEM_COUNT 6
#define MENU_ITEM_X 595
#define MENU_ITEM_WIDTH 204
#define MENU_ITEM_HEIGHT 38
#define MENU_STATUS_CAPACITY 64

typedef enum MenuAction {
    MENU_START_NEW_GAME = 0,
    MENU_START_FREE_GAME = 1,
    MENU_CONTINUE_GAME = 2,
    MENU_OPTIONS = 3,
    MENU_CREDITS = 4,
    MENU_QUIT = 5,
} MenuAction;

typedef struct MenuItem {
    MenuAction action;
    const char *label;
    uint16_t control_id;
    int32_t x;
    int32_t y;
    uint32_t width;
    uint32_t height;
} MenuItem;

typedef struct MenuState {
    MenuItem items[MENU_ITEM_COUNT];
    int selected;
    int hover;                 /* -1 when no item is hovered */
    bool interacted;
    bool has_status;
    char status[MENU_STATUS_CAPACITY];
} MenuState;

/*
 * Reconstructed host-side state for Screen_MainMenu (0x476920). The six
 * controls, labels, ids and coordinates come from the menu reconstruction and
 * the shipped Pe_Startscreen 800x600 layout.
 */
void menu_state_init(MenuState *menu);
void menu_set_selected(MenuState *menu, int index);
void menu_select_next(MenuState *menu);
void menu_select_previous(MenuState *menu);
int menu_button_at(const MenuState *menu, int32_t x, int32_t y);
void menu_set_hover(MenuState *menu, int index);
MenuAction menu_activate(MenuState *menu);
const char *menu_action_label(MenuAction action);
uint16_t menu_action_control_id(MenuAction action);

#endif
