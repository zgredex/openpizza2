/* ResourceManager_OpenArchivePath (0x404460). */
extern "C" int String_Format(char *buffer, const char *format, ...);
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char *path);
extern "C" char DAT_0057c278[];
extern "C" signed char DAT_0057c5c4;

struct ResourceManager {
    void Pak_Open(char *path);
};

int __cdecl ResourceManager_OpenArchivePath(ResourceManager *manager, char *name)
{
    char path[260];
    int attributes;

    String_Format(path, "%sresources\\%s", DAT_0057c278, name);
    attributes = GetFileAttributesA(path);
    if (attributes == -1 || (attributes & 0x10) != 0) {
        String_Format(path, "%c:\\resources\\%s", DAT_0057c5c4, name);
        attributes = GetFileAttributesA(path);
        if (attributes == -1 || attributes % 16 != 0)
            return 0;
    }
    manager->Pak_Open(path);
    return 1;
}
