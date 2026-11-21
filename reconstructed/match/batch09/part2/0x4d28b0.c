/* Game_RemoveObjectFromUI: removes the object from the current window when
   the array still holds it (0x4d28b0). */
struct UI {
    void *FindWindowByID(int id, int *out);
    void RemoveObject(int id);
};

struct Array {
    int GetRecordByKeyPtr(int key);
};

void __fastcall Game_RemoveObjectFromUI(int object)
{
    int id = *(int *)(*(int *)0x57c670 + 0x2dac);
    void *window = ((struct UI *)*(void **)0x57c5e0)->FindWindowByID(id, 0);

    if (window != 0) {
        if (((struct Array *)window)->GetRecordByKeyPtr(*(int *)(object + 0x54)) != 0)
            ((struct UI *)window)->RemoveObject(*(int *)(object + 0x54));
    }
}
