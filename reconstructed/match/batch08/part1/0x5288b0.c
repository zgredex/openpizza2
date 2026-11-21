/* UI_GetOuterRect: expands the element rectangle by its double border
   (0x5288b0). */
struct UI {
    char pad[0x28];
    int x;
    int y;
    int width;
    int height;
    int left;
    int top;
    void GetOuterRect(int *rect);
};

void UI::GetOuterRect(int *rect)
{
    rect[0] = left;
    rect[1] = top;
    rect[2] = x + width * 2 + left;
    rect[3] = y + height * 2 + top;
}
