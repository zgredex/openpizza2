// RegistryKey_ReadValue @ 0x403200 (158 bytes)
// Reads a REG_BINARY value: query its size, allocate, query the data.

typedef void *HKEY;

extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(
    HKEY key, const char *valueName, unsigned long *reserved,
    unsigned long *type, unsigned char *data, unsigned long *length);

void *operator new(unsigned int size);
void operator delete(void *pointer);

class RegistryKey {
public:
    HKEY key;               // 0x00

    unsigned char *ReadValue(const char *name, unsigned long *size);
};

unsigned char *RegistryKey::ReadValue(const char *name, unsigned long *size)
{
    unsigned long type;
    unsigned long length = 0;

    *size = 0;
    if (key == 0)
        return 0;
    if (RegQueryValueExA(key, name, 0, &type, 0, &length) != 0)
        return 0;

    unsigned char *data = (unsigned char *)operator new(length);
    if (RegQueryValueExA(key, name, 0, &type, data, &length) != 0) {
        operator delete(data);
        return 0;
    }
    *size = length;
    return data;
}
