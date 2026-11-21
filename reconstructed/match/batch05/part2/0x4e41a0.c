/* Game_CountGroupSlots: counts leading non-empty slots of a six-entry group
   (0x4e41a0). */
struct Game {
    int CountGroupSlots(int group);
};

int Game::CountGroupSlots(int group)
{
    int count = 0;
    short *slot = (short *)((char *)this + (group * 3 + 0x1e) * 4);
    while (count < 6) {
        if (*slot == -1)
            break;
        count++;
        slot++;
    }
    return count;
}
