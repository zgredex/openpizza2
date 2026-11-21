struct UI {
    char pad0[8];
    int field8;
    char pad1[0x228];
    int toggle;

    void SetMenuToggle(int value);
};

void UI::SetMenuToggle(int value)
{
    toggle = 1;
    field8 = value;
}
