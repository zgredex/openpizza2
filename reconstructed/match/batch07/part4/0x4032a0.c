/* RegistryKey_WriteValue: writes a REG_BINARY value through the registry API
   (0x4032a0). */
extern int (__stdcall *DAT_0055c00c)(void *key, const char *name,
                                     unsigned long reserved, unsigned long type,
                                     unsigned char *data,
                                     unsigned long length);

struct RegistryKey {
    void *handle;
    int WriteValue(const char *name, unsigned char *data, unsigned long length);
};

int RegistryKey::WriteValue(const char *name, unsigned char *data,
                            unsigned long length)
{
    if (handle == 0)
        return 0;
    if (length == 0)
        return 0;
    return DAT_0055c00c(handle, name, 0, 3, data, length) == 0;
}
