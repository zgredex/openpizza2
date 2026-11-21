/* UI_WaitForMenuSelection (0x500ec0): waits for a menu selection in the
   slot's 0x168-byte menu state and pushes the chosen entry. */
struct Company {
    void PushRecentEntry(int slot, int previous, int selection, int argument);
};

struct MenuScreen {
    int ProcessMenuInput(int *selection);
    void WaitForMenuSelection(int slot);
};

struct MenuSelection {
    int value;
    int pad;
    short slot;
    int previous;
};

void MenuScreen::WaitForMenuSelection(int slot)
{
    MenuSelection local;
    int result;

    if (*(int *)((char *)this + slot * 0x168 + 0x80) == 0) {
        local.previous = *(int *)((char *)this + slot * 0x168 + 300);
        local.value = -1;
        local.slot = (short)slot;
        result = ProcessMenuInput(&local.value);
        while (result == 0) {
            result = ProcessMenuInput(&local.value);
        }
        ((Company *)this)->PushRecentEntry(slot, local.previous, local.value, -1);
    }
}
