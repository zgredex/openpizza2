/* SaveGame_NextFreeSlot (0x4a13e0). */
extern char STR_00568198[];
extern char STR_00563184[];
extern void String_Format(char *buffer, char *format, int value);
extern void *CRT_Fopen(char *path, char *mode);
extern void CRT_Fclose(void *file);

int SaveGame_NextFreeSlot(void)
{
    char path[260];
    void *file;
    int index = 0;

    String_Format(path, STR_00568198, 0);
    file = CRT_Fopen(path, STR_00563184);
    while (file != 0) {
        CRT_Fclose(file);
        index++;
        String_Format(path, STR_00568198, index);
        file = CRT_Fopen(path, STR_00563184);
    }
    return index;
}
