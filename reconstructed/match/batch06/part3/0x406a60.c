/* UI_CloseLoadingScreen: tears the loading screen down through the UI
   singleton (0x406a60).  Build: /O2 /TP. */
struct UI {
    void ReplaceActiveObject(int object);
};

struct Clear {
    void Field228();
};

struct Window {
    void DestroyChild(int child);
};

void UI_CloseLoadingScreen()
{
    (*(UI **)0x57c5e0)->ReplaceActiveObject(0);
    (*(Clear **)0x57c5e0)->Field228();
    (*(Window **)0x57c5e0)->DestroyChild(*(int *)0x57c5f4);
}
