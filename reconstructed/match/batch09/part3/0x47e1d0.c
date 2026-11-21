/* UI_FindObjectByField20: searches a UI object's map for an entry whose field
   0x20 matches (0x47e1d0). */
struct IDMap {
    int *Lookup(int key, int *unused);
};

struct UIObject {
    int Get_Field19F4();
    int FindObjectByField20(int value);
};

int UIObject::FindObjectByField20(int value)
{
    char *self = (char *)this;
    int i = 0;
    int count = Get_Field19F4();
    int *record;

    if (0 < count) {
        do {
            record = ((IDMap *)(self + 0x19e0))->Lookup(i, 0);
            if (record != 0 && *(int *)((char *)record + 0x20) == value)
                return (int)record;
            i++;
            count = Get_Field19F4();
        } while (i < count);
    }
    return 0;
}
