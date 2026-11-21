extern int DAT_0057c670;
extern "C" void *memset(void *dest, int value, unsigned int count);
struct IDMap { void *Lookup(int key, int *out); };
struct Company { void CountNearbyObjectTypes(int type, int *matrix); };
void __stdcall Game_FillNearbyTypeCompanyMatrix(int param_1, int *matrix)
{
    int key;
    void *company;
    IDMap *map;
    memset(matrix, 0, 0x100);
    key = *(int *)(param_1 + 0x34);
    map = (IDMap *)(DAT_0057c670 + 4);
    company = map->Lookup(key, 0);
    if (company != 0 && *(int *)(param_1 + 0x16f0) != 0)
        ((Company *)company)->CountNearbyObjectTypes(*(int *)(param_1 + 0x16f0), matrix);
}
