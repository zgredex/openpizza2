struct Record {
    int unused0;
    int type;
};

struct IDMap {
    Record *Lookup(int index, int *out);
};

struct Array {
    int FindEmptySlot8();
};

struct Game {
    int CountGroupSlots(int group);
};

struct CityData {
    char pad[0x78];
    short first;
};

struct GameData {
    char pad1[0x74];
    IDMap map;
    char pad2[0x10];
    int count;
};

extern GameData *DAT_0057c670;

void *Game_GetCityData(int index);

extern "C" void City_FindListContainingValue(int value, int *outList, int *outGroup)
{
    int i;
    int list;
    int group;
    int end;
    short *row;
    CityData *city;

    *outList = -1;
    city = (CityData *)Game_GetCityData(value);
    if (city == 0)
        return;
    i = 0;
    list = 0;
    if (0 < DAT_0057c670->count) {
        do {
            if (DAT_0057c670->map.Lookup(i, 0) == (Record *)city)
                break;
            i++;
        } while (i < DAT_0057c670->count);
        list = i;
    }
    group = 0;
    end = ((Array *)city)->FindEmptySlot8();
    if (0 < end) {
        i = 0;
        row = (short *)((char *)city + 0x78);
        do {
            int stop = ((Game *)city)->CountGroupSlots(group);
            if (*row <= value &&
                value <= *(short *)((char *)city + (stop + i) * 2 + 0x76)) {
                *outList = list;
                *outGroup = group;
            }
            group++;
            row += 6;
            i += 6;
            end = ((Array *)city)->FindEmptySlot8();
        } while (group < end);
    }
}
