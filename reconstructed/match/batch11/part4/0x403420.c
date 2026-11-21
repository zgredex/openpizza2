/* String_SetField48: replaces the field at 0x48 with a copy of the given text
   (0x403420). */
extern "C" unsigned int strlen(const char *text);
extern "C" char *strcpy(char *dest, const char *src);

void Mem_Free(void *block);
extern "C" void *operator_new(unsigned int size);

struct String {
    char pad[0x48];
    char *field48;

    void SetField48(char *text);
};

void String::SetField48(char *text)
{
    if (field48 != 0) {
        Mem_Free(field48);
    }
    field48 = (char *)operator_new(strlen(text) + 1);
    strcpy(field48, text);
}
