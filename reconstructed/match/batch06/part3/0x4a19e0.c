/* File_Exists: probes a file by opening and closing it (0x4a19e0).
   Build: /O2. */
void *__cdecl CRT_Fopen(char *name, char *mode);
int __cdecl CRT_Fclose(void *file);

unsigned char File_Exists(char *name)
{
    void *file;

    if (name != 0) {
        file = CRT_Fopen(name, (char *)0x563184);
        if (file != 0) {
            CRT_Fclose(file);
            return 1;
        }
    }
    return 0;
}
