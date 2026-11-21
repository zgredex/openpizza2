/* Game_MarkObjectsDirtyForState: marks all objects dirty and refreshes one
   array slot when entering state 6 (0x4f78e0). */
struct Array {
    void SetSlot(int index, int value);
};

struct Game {
    void MarkAllObjectsDirty(int state);
};

extern char *DAT_0057c670;

void __stdcall Game_MarkObjectsDirtyForState(Game *game, int state)
{
    if (state == 6) {
        Array *array = *(Array **)(DAT_0057c670 + 0x224);
        Array *owner = *(Array **)((char *)array + 0xac);

        owner->SetSlot(7, 1);
    }
    game->MarkAllObjectsDirty(state);
}
