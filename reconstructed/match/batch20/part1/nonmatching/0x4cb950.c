/* HighScore_ReadRegistryBlob (0x4cb950). */
extern "C" void Mem_Free(void *);
extern "C" void *memcpy(void *, const void *, unsigned int);

struct RegistryKey {
    void *handle;
    RegistryKey();
    ~RegistryKey();
    void *OpenOrCreate(void *root, const char *subkey);
    void *ReadValue(const char *name, unsigned int *size);
    void Close();
};

unsigned int HighScore_ReadRegistryBlob(const char *name,
                                                   unsigned char *out)
{
    RegistryKey key;
    unsigned int size;
    unsigned char *buffer;

    if (key.OpenOrCreate((void *)0x80000002,
                         "SOFTWARE\\Software2000\\Pizza Connection 2") == 0) {
        return 0;
    }
    buffer = (unsigned char *)key.ReadValue(name, &size);
    key.Close();
    if (buffer == 0) {
        return 0;
    }
    memcpy(out, buffer, size >= 0xcc ? 0xcc : size);
    Mem_Free(buffer);
    return 1;
}
