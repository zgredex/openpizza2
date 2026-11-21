/* UI_DecrementTimer: decrements one of the two timer arrays (0x5043f0). */
struct UI {
    char pad[0x88];
    int primary[1];
    char pad2[0xe0];
    int secondary[1];
    void DecrementTimer(int index, char usePrimary);
};

void UI::DecrementTimer(int index, char usePrimary)
{
    int value;

    if (usePrimary != 0) {
        value = *(int *)((char *)this + index * 4 + 0x88);
        if (value > 0)
            *(int *)((char *)this + index * 4 + 0x88) = value - 1;
    } else {
        value = *(int *)((char *)this + index * 4 + 0x16c);
        if (value > 0)
            *(int *)((char *)this + index * 4 + 0x16c) = value - 1;
    }
}
