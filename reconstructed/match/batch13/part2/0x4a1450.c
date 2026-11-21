/* SaveGame_AnyExist (0x4a1450). */
extern char STR_00568d1c[];
extern char STR_00568d04[];
extern void *CRT_FindFirst(char *pattern, void *data);
extern void CRT_FindClose(void *handle);

int SaveGame_AnyExist(void)
{
    unsigned int data[70];
    void *handle;

    handle = CRT_FindFirst(STR_00568d1c, data);
    if (handle == (void *)-1) {
        handle = CRT_FindFirst(STR_00568d04, data);
        if (handle == (void *)-1)
            return 0;
        CRT_FindClose((void *)-1);
    } else {
        CRT_FindClose(handle);
    }
    return 1;
}
