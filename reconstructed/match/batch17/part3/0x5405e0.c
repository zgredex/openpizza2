struct SoundPakManager {
    char *FindExtensionEntry(char *extension);
    void BuildArchivePath(char *name, char *out);
};

extern "C" char *strrchr(const char *text, int character);
extern "C" char *strcpy(char *dest, const char *src);
extern "C" char *strcat(char *dest, const char *src);
extern "C" void CRT_Strlwr(char *text);

void SoundPakManager::BuildArchivePath(char *name, char *out)
{
    if (name[1] != ':') {
        char *dot = strrchr(name, '.');
        if (dot != 0) {
            char *entry = FindExtensionEntry(dot + 1);
            if (entry != 0) {
                strcpy(out, entry);
                strcat(out, name);
                CRT_Strlwr(out);
                return;
            }
        }
    }
    strcpy(out, name);
    CRT_Strlwr(out);
}
