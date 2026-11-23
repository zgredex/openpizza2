// SoundPakManager_AddExtensionMapping: adds a sound pak extension mapping.

extern "C" {
char *strcpy(char *dst, const char *src);
char *strcat(char *dst, const char *src);
unsigned int strlen(const char *text);
char *CRT_Strlwr(char *text);
extern char g_ResourceManager_RegisterExtensionAlias_RData[];
}

void *operator new(unsigned int size);

struct SoundPakManager {
    char *FindExtensionEntry(char *extension);
    void AddExtensionMapping(char *extension, char *name);
};

void SoundPakManager::AddExtensionMapping(char *extension, char *name)
{
    char *entry;

    entry = FindExtensionEntry(name);
    if (entry == 0) {
        entry = (char *)operator new(0x54);
        strcpy(entry, extension);
        strcpy(entry + 0x40, name);
        CRT_Strlwr(entry + 0x40);
        *(int *)(entry + 0x50) = *(int *)((char *)this + 0x628);
        *(int *)((char *)this + 0x628) = (int)entry;
    } else {
        strcpy(entry, extension);
    }
    if (entry[strlen(entry) - 1] != '\\')
        strcat(entry, g_ResourceManager_RegisterExtensionAlias_RData);
}
