/* UI_RemoveWindowForObject: removes the window owned by the current object (0x482f10). */
struct Object {
    int GetId();
};

struct Window {
    int GetObjectId(Object *object);
    void RemoveWindowByID(int id);
};

extern Window *DAT_0057c5e0;

struct UI {
    char pad[0x26c];
    Object *object;
    void RemoveWindowForObject();
};

void UI::RemoveWindowForObject()
{
    if (object != 0)
        DAT_0057c5e0->RemoveWindowByID(DAT_0057c5e0->GetObjectId(object));
}
