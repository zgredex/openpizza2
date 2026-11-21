/* Game_GetMapValue: returns a map word or the sentinel value (0x4eaa10). */
struct Game {
    char pad[0x2e4f4];
    unsigned short values[1];
    unsigned int GetMapValue(unsigned int index);
};

unsigned int Game::GetMapValue(unsigned int index)
{
    if (index != 0xffffffff && index != 0xfffffffe) {
        if ((int)index >= 0) {
            return *(unsigned short *)((char *)this + index * 2 + 0x2e4f4);
        }
        index = 0xffffffff;
    }
    return index;
}
