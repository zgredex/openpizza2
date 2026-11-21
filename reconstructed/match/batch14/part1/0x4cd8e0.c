/* MapList_AddIniRecord (0x4cd8e0): parses a city definition section and adds
   the record to the list unless an element with the same name exists. */
extern int DAT_0057c5d8;

struct IDMap {
    int Lookup(int key, int *out);
};

struct List {
    void Add(void *item);
};

void *__cdecl CityDefinition_ParseIni(int config, char *section);
extern "C" int __cdecl FUN_005570c0(unsigned char *left, unsigned char *right);
void __cdecl Mem_Free(void *memory);

void __cdecl MapList_AddIniRecord(void *param_1, char *param_2)
{
    void *record;
    int count;
    int index;
    int item;

    record = CityDefinition_ParseIni(DAT_0057c5d8, param_2);
    if (record == 0) {
        return;
    }
    count = *(int *)((char *)param_1 + 0x14);
    for (index = 0; index < count; index++) {
        item = ((IDMap *)param_1)->Lookup(index, 0);
        if (FUN_005570c0((unsigned char *)(item + 0x40),
                             (unsigned char *)record + 0x40) == 0) {
            Mem_Free(record);
            return;
        }
    }
    ((List *)param_1)->Add(record);
}
