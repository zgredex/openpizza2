/* UI_InitInputHelper: initializes the input helper block (0x51e9d0). */
struct UI {
    int field0;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    UI *InitInputHelper(int value);
};

UI *UI::InitInputHelper(int value)
{
    field4 = 0;
    field0 = 0;
    field8 = value;
    fieldC = -9999;
    field14 = 0;
    field18 = 0;
    field24 = 0;
    return this;
}
