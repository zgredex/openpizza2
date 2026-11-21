/* UI_IsValidSize: validates a proposed window size (0x520b60). */
struct UI {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual int ValidateSize(int width, int height);

    char pad[0x14 - 4];
    int field14;
    int field18;
    int field1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;

    int IsValidSize(int width, int height);
};

int UI::IsValidSize(int width, int height)
{
    if (field18 != 0) {
        return 1;
    }
    if (field20 == 0 || field14 == 0 || width < field28 ||
        width >= field30 || height < field2C || height >= field34) {
        return 0;
    }
    return ValidateSize(width - field38, height - field3C);
}
