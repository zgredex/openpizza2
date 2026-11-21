/* UI_ClearChildExtent (0x51eae0). */
struct CS {
    void Enter();
    void Leave();
};
struct Sprite {
    void GetSize(int *width, int *height);
};
struct Rect {
    void Union(int x, int y, int right, int bottom);
};
struct UI {
    int fields[7];

    void ClearChildExtent();
};

void UI::ClearChildExtent()
{
    int local8;
    int local4;

    ((struct CS *)*(int *)(fields[2] + 0x1c8))->Enter();
    if (fields[6] != 0 && (void *)fields[1] != 0) {
        ((struct Sprite *)fields[1])->GetSize(&local4, &local8);
        ((struct Rect *)fields[2])->Union(
            fields[3], fields[4], local4 + fields[3], local8 + fields[4]);
    }
    fields[5] = 0;
    fields[0] = 0;
    ((struct CS *)*(int *)(fields[2] + 0x1c8))->Leave();
}
