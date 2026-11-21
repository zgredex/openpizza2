/* SpriteCache_MakeKey: builds an upper-case cache key from a path
   (0x5273c0). */
char *strrchr(const char *text, int character);
char *strncpy(char *dest, const char *src, unsigned int count);
void __cdecl CRT_Strupr(char *text);
void __stdcall SpriteCache_MakeKey(char *path, char *key)
{
    char *slash = strrchr(path, 0x5c);
    char *base;

    if (slash != 0)
        base = slash + 1;
    else
        base = path;
    strncpy(key, base, 0x3f);
    key[0x3f] = 0;
    CRT_Strupr(key);
}
