/* Config_WriteRegistryBlock: writes a 0xcc-byte binary block through the
   registry key wrapper (0x4cba60). */
extern "C" void __fastcall Clear_Ptr(void **slot);
extern "C" void __fastcall RegistryKey_CloseThunk(void **key);
extern char DAT_00563c5c[];

struct RegistryKey {
    void *value;

    RegistryKey() { Clear_Ptr(&value); }
    ~RegistryKey() { RegistryKey_CloseThunk(&value); }
    void *OpenOrCreate(void *root, const char *subkey);
    int WriteValue(const char *name, unsigned char *data, unsigned long length);
    void Close();
};

unsigned int Config_WriteRegistryBlock(const char *param_1,
                                      unsigned char *param_2)
{
    RegistryKey key;

    if (key.OpenOrCreate((void *)0x80000002, DAT_00563c5c) == 0) {
        return 0;
    }
    key.WriteValue(param_1, param_2, 0xcc);
    key.Close();
    return 1;
}
