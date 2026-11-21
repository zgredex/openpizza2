/* City_FindMatchingCity: finds a city record matching the requested vehicle,
   dealer and brand fields (0x4f9c10). */
extern int *DAT_0057c670;

struct IDMap {
    void *Lookup(int index, int *out);
};

extern "C" int __stdcall City_FindMatchingCity(int *param_1)
{
    int result = -1;
    int i = 0;
    int wanted = *(int *)(*param_1 + 0x24);

    while (i < *(int *)((char *)DAT_0057c670 + 0x88)) {
        int *record = (int *)((struct IDMap *)((char *)DAT_0057c670 + 0x74))
                          ->Lookup(i, 0);

        if (record[3] == 5 &&
            (param_1[7] == 0 || *(char *)((char *)record + 0x14) == 0) &&
            (wanted == 4 || record[4] == wanted)) {
            result = i;
            if (param_1[5] != -1 &&
                *(unsigned char *)((char *)record + 0x14) == param_1[6]) {
                return i;
            }
        }
        i++;
    }
    return result;
}
