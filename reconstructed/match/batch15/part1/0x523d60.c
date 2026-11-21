/* Window_ShowWindowById: shows a window by id and updates the desktop rect
   (0x523d60). */
extern char *DAT_0057c1e0;
extern char STR_005741f4[];

struct Rect {
    int left;
    int top;
    int right;
    int bottom;
};

struct UI {
    void *FindWindowByID(int id, int *out);
    void SetWindowVisible(int visible);
    void Rect_Set1A4(int *rect);
    void ShowWindowById(int id);
};

extern "C" void DebugConsole_Printf(void *console, int color, char *format, ...);

void UI::ShowWindowById(int id)
{
    UI *window = (UI *)FindWindowByID(id, 0);

    if (window != 0 && *(int *)((char *)window + 0x4c) == 0) {
        window->SetWindowVisible(1);
        *(int *)((char *)this + 0x83b8) = 1;
        DebugConsole_Printf(DAT_0057c1e0, 0xff0000, STR_005741f4, id);
        {
            Rect rect;

            rect = *(Rect *)((char *)window + 8);
            Rect_Set1A4((int *)&rect);
        }
    }
}
