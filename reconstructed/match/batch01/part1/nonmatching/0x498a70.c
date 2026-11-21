/* SaveGame_ScanSaveFileList (0x498a70). */
struct FindData {
    unsigned attrib;
    long time_create;
    long time_access;
    long time_write;
    long size;
    char name[260];
};

struct List {
    char pad[0x1c];
    List(int);
    void Add(void *entry);
};

struct UIListEntry {
    char pad[0x58];
    UIListEntry(char *text, int value);
};

extern "C" {
extern void *DAT_0057ca04;
extern char s_save_pattern[];
extern char s_extension[];
long _findfirst(const char *pattern, FindData *data);
int _findnext(long handle, FindData *data);
int _findclose(long handle);
void String_Format(char *buffer, const char *format, ...);
char *strchr(const char *text, int character);
char *strcpy(char *dest, const char *source);
}

int SaveGame_ScanSaveFileList()
{
    FindData data;
    char buffer[0x200];
    UIListEntry *entry;

    DAT_0057ca04 = new List(0);
    long handle = _findfirst(s_save_pattern, &data);
    if (handle == -1)
        return 0;
    do {
        String_Format(buffer, "%s", data.name);
        strcpy(strchr(buffer, '.'), s_extension);
        entry = new UIListEntry(buffer, 0);
        ((List *)DAT_0057ca04)->Add(entry);
    } while (_findnext(handle, &data) != -1);
    _findclose(handle);
    return 1;
}
