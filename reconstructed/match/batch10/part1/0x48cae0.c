/* Game_SetObjectInfoWindowVisible: shows or hides the object info window when
   its visibility changes (0x48cae0). */
struct Object {
    int GetId(void *object);
};

struct Window {
    void ShowWindowById(int id);
    void HideWindowById(int id);
};

extern Window *DAT_0057c5e0;

struct Game {
    char pad[0x26c];
    void *infoWindow;

    void SetObjectInfoWindowVisible(int visible);
};

void Game::SetObjectInfoWindowVisible(int visible)
{
    if (infoWindow != 0) {
        int id = ((struct Object *)DAT_0057c5e0)->GetId(infoWindow);

        if (*(int *)((char *)infoWindow + 0x4c) != visible) {
            if (visible) {
                DAT_0057c5e0->ShowWindowById(id);
            } else {
                DAT_0057c5e0->HideWindowById(id);
            }
        }
    }
}
