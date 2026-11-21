/* Map_RefreshObjectSprites (0x48cb30): clears the object window and lets each
   map record update its map marker. */
struct IDMap {
    char pad[0x14];
    int count;

    void *Lookup(int key, int *result);
};

struct Record {
    void UpdateObjectMapMarker();
};

struct Window {
    int Get_FieldF0();
    void RemoveObject(int index);
};

struct UIGlobal {
    Window *FindWindowByID(int id, int *result);
};

extern UIGlobal *DAT_0057c5e0;

struct Map {
    char pad[4];
    IDMap objectMap;
    char pad2[0x2f4 - 0x1c];
    int recordId;
    char pad3[0x2dac - 0x2f8];
    int windowId;

    void RefreshObjectSprites();
};

void Map::RefreshObjectSprites()
{
    char *container = (char *)objectMap.Lookup(recordId, 0);
    int id = windowId;
    Window *window = DAT_0057c5e0->FindWindowByID(id, 0);

    if (window != 0) {
        int index = window->Get_FieldF0();

        while (--index >= 0)
            window->RemoveObject(index);
        int count = *(int *)(container + 0xfc0);
        int i = 0;

        if (0 < count) {
            do {
                Record *record = (Record *)
                    ((IDMap *)(container + 0xfac))->Lookup(i, 0);

                if (record != 0)
                    record->UpdateObjectMapMarker();
                i++;
            } while (i < count);
        }
    }
}
