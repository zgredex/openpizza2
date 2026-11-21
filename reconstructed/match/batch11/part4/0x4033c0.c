/* String_SetOwned: replaces the owned string with a copy of the given text
   (0x4033c0). */
extern "C" unsigned int strlen(const char *text);
extern "C" char *strcpy(char *dest, const char *src);

void Mem_Free(void *block);
extern "C" void *operator_new(unsigned int size);

struct String {
    char pad[0x44];
    char *owned;

    void SetOwned(char *text);
};

void String::SetOwned(char *text)
{
    if (owned != 0) {
        Mem_Free(owned);
    }
    owned = (char *)operator_new(strlen(text) + 1);
    strcpy(owned, text);
}
