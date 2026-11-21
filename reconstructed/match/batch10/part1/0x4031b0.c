/* RegistryKey_OpenOrCreate: opens an existing registry key or creates it
   (0x4031b0). */
typedef void *HKEY;
typedef long LSTATUS;

extern "C" {
__declspec(dllimport) LSTATUS __stdcall RegCloseKey(HKEY key);
__declspec(dllimport) LSTATUS __stdcall RegOpenKeyExA(HKEY key, const char *sub,
                                                      unsigned long options,
                                                      unsigned long desired,
                                                      HKEY *result);
__declspec(dllimport) LSTATUS __stdcall RegCreateKeyA(HKEY key, const char *sub,
                                                      HKEY *result);
}

struct RegistryKey {
    HKEY value;
    HKEY OpenOrCreate(HKEY key, const char *sub);
};

HKEY RegistryKey::OpenOrCreate(HKEY key, const char *sub)
{
    if (value != 0) {
        RegCloseKey(value);
    }
    if (RegOpenKeyExA(key, sub, 0, 0x2001f, &value) != 0) {
        if (RegCreateKeyA(key, sub, &value) != 0) {
            return 0;
        }
    }
    return value;
}
