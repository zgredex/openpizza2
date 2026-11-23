// Config_SaveOptionsToRegistry @ 0x406cd0 (158 bytes)
// Saves the options and sound setting blocks under the Pizza Connection
// registry key. RegistryKey is a scope object whose constructor clears the
// handle and whose destructor closes any still-open key.
//
// The function has C++ linkage on purpose: VC6 suppresses C++ EH frames for
// extern "C" functions, while the shipped body carries a destructor unwind
// frame (handler 0x557d78 / FuncInfo 0x55d740).

typedef void *HKEY;

extern "C" void __fastcall Clear_Ptr(void **slot);
extern "C" void __fastcall RegistryKey_CloseThunk(void **key);
extern char STR_00563c5c[];
extern char STR_00563c54[];
extern char STR_00563c4c[];
extern int DAT_0057b8a8;
extern char DAT_00575090[];

struct RegistryKey {
    HKEY value;

    RegistryKey() { Clear_Ptr(&value); }
    ~RegistryKey();
    HKEY OpenOrCreate(HKEY root, const char *sub);
    int WriteValue(const char *name, unsigned char *data, unsigned long length);
    void Close();
};

void Config_SaveOptionsToRegistry(void)
{
    RegistryKey key;

    if (key.OpenOrCreate((HKEY)0x80000002, STR_00563c5c) != 0) {
        DAT_0057b8a8 = 0x3ee;
        key.WriteValue(STR_00563c54, (unsigned char *)&DAT_0057b8a8, 0x164);
        key.WriteValue(STR_00563c4c, (unsigned char *)&DAT_00575090, 0x10);
        key.Close();
    }
}
