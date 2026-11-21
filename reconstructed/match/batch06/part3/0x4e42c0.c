/* Game_FindGroupSlot: searches six signed-short slots inside a per-group
   block for a value (0x4e42c0).  Build: /O2 /TP. */
struct Game {
    int FindGroupSlot(int value, int group);
};

int Game::FindGroupSlot(int value, int group)
{
    int index = 0;
    short *slot = (short *)((char *)this + (group * 3 + 0x1e) * 4);

    for (; index < 6; index++, slot++) {
        if (value == *slot)
            return index;
    }
    return -1;
}
