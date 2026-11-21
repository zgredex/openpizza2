/* SaveMenu_MenuFileExists: formats the save-menu file name and reports
   whether it can be opened (0x49b880). */
typedef struct FILE FILE;

extern char DAT_00568a44[];
extern char DAT_00563184[];

int __cdecl String_Format(char *buffer, const char *format, ...);
FILE * __cdecl CRT_Fopen(const char *name, const char *mode);
int __cdecl CRT_Fclose(FILE *file);

char __cdecl SaveMenu_MenuFileExists(char *name)
{
    char buffer[0x200];

    String_Format(buffer, DAT_00568a44, name);
    {
        FILE *file = CRT_Fopen(buffer, DAT_00563184);

        if (file != 0) {
            CRT_Fclose(file);
            return 1;
        }
    }
    return 0;
}
