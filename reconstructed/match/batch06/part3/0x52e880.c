/* Window_GetRect: copies the window's screen rectangle into a caller buffer
   (0x52e880).  Build: /O2 /TP. */
struct Window {
    char pad[4];
    int width;
    int height;
    int x;
    int y;
    void GetRect(int *rect);
};

void Window::GetRect(int *rect)
{
    rect[0] = x;
    rect[1] = y;
    rect[2] = width + x;
    rect[3] = height + y;
}
