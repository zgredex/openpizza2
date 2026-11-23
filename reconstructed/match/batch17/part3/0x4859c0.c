struct Gadget;

struct UI {
    Gadget *CreateBitmapGadget(int id, int x, int y, int w, int h, int flags);
    void MoveElementToIndex(int id, int index);
    void BringWindowToFront(int id);
};

struct Object {
    int GetId(void *object);
    int GetActiveValue(int unused1, int unused2);
};

struct Array {
    void SetField14ByKey(int id, int value);
};

struct Game {
    void ResizeZoomSurfaces(int x, int y, int w, int h);
};

struct GameView {
    void SetupZoomedViewport(void *window);
    char pad[0x2da0];
    int zoomShift;
};

extern int DAT_00571958;
extern int DAT_0057195c;
extern int DAT_00571950;
extern int DAT_00571954;
extern int DAT_00580a50;
extern void *DAT_0057c674;
extern UI *DAT_0057c5e0;
extern Game *DAT_0057c5cc;
extern int DAT_0057c5c8;

void GameView::SetupZoomedViewport(void *window)
{
    DAT_0057c674 = window;
    int id = ((Object *)DAT_0057c5e0)->GetId(window);
    Gadget *gadget = ((UI *)window)->CreateBitmapGadget(
        0x2a, 0, 0, DAT_00571958, DAT_0057195c, 0x10);
    ((UI *)window)->MoveElementToIndex(0x2a, 0);
    DAT_0057c5e0->BringWindowToFront(id);
    ((Array *)window)->SetField14ByKey(0x2a, 1);
    int shift = *(int *)((char *)this + 0x2da0);
    DAT_00580a50 = shift;
    DAT_00571950 = DAT_00571958 << shift;
    DAT_00571954 = DAT_0057195c << shift;
    int active = ((Object *)gadget)->GetActiveValue(0, 0);
    DAT_0057c5cc->ResizeZoomSurfaces(DAT_0057c5c8, DAT_00571950, DAT_00571954, active);
}
