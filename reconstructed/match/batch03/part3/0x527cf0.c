struct UI {
    char pad0[0x8338];
    int scrollStart;
    int scrollEnd;
    char pad1[8];
    int scrollMode;

    void ClearScrollDrag();
};

void UI::ClearScrollDrag()
{
    scrollStart = 0;
    scrollEnd = 0;
    scrollMode = 0;
}
