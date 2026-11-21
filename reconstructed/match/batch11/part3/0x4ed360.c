struct UI {
    char pad[0x2c];
    int margin;
    char pad2[4];
    int extent;
    char pad3[0xb0];
    int scrollY;
    char pad4[0x1007c];
    int visibleHeight;
    int scrollMin;
    bool ClampScrollY(int value);
};
bool UI::ClampScrollY(int value)
{
    int old = scrollY;

    scrollY = value;
    if (scrollY < scrollMin + margin)
        scrollY = scrollMin + margin;
    if (scrollY > extent - visibleHeight)
        scrollY = extent - visibleHeight;
    return old != scrollY;
}
