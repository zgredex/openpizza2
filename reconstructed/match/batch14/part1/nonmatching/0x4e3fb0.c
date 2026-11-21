extern "C" char *strcpy(char *, const char *);
#pragma intrinsic(strcpy)
extern char DAT_0055c5a0;
extern char DAT_00579aec;
int *__fastcall FurnitureType_Construct(int *param_1)
{
    int index;
    int *slot;
    char *name;
    *(void **)param_1 = &DAT_0055c5a0;
    param_1[2] = 0xc;
    param_1[3] = 0xb;
    param_1[4] = 4;
    param_1[5] = 3;
    name = (char *)param_1 + 0x18;
    strcpy(name, &DAT_00579aec);
    *(int *)(name + 0x58) = 0;
    *(int *)(name + 0x5c) = 0;
    index = 8;
    slot = (int *)(name + 0x60);
    do {
        index = index - 1;
        *slot = -1;
        slot[1] = -1;
        slot = slot + 3;
    } while (index != 0);
    return param_1;
}
