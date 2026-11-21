/* Game_FormatObjectNameRandom (0x403150, 49 bytes).  Build: /O2 /TP.
   Picks a random name-table entry and formats the object name into the
   caller's buffer. */
extern char DAT_00563314;
extern "C" int Random_Mod(int modulus);
extern "C" int String_Format(char *buffer, const char *format, ...);

struct Game {
    void FormatObjectNameRandom(char *buffer, int value);
};

void Game::FormatObjectNameRandom(char *buffer, int value)
{
    int index = Random_Mod(*(short *)((char *)this + 0x14));

    String_Format(buffer, &DAT_00563314, value,
                  *(int *)((char *)this + 0xc) + index * 16);
}
