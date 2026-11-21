extern "C" int __cdecl Random_Mod(int value);
extern "C" int __cdecl String_Format(char *buffer, char *format, ...);
struct Game { char pad0[4]; char *names1; char *names2; char pad2[4]; short count1; short count2; void FormatObjectName(int which, char *buffer, char *name); };
void Game::FormatObjectName(int which, char *buffer, char *name)
{
    char *base = names1;
    int offset = 0;
    if (which == 0) {
        offset = Random_Mod(count1) << 4;
        base = names1;
    } else {
        offset = Random_Mod(count2) << 4;
        base = names2;
    }
    String_Format(buffer, (char *)0x563314, name, base + offset);
}
