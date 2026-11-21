/* UI_SetAbsolutePosition: derives the absolute position from the relative base (0x520b40). */
struct UI {
    char pad[0x28];
    int baseX;
    int baseY;
    int absX;
    int absY;
    void SetAbsolutePosition(int dx, int dy);
};

void UI::SetAbsolutePosition(int dx, int dy)
{
    absX = baseX + dx;
    absY = baseY + dy;
}
