/* Game_HasIdleOtherPlayer: reports whether another player exists without an
   active order (0x48e060). */
struct Game {
    char pad[0x2ec];
    int selectedSlot;
    char pad2[4];
    struct Game *selectedPlayer;
    struct Game *GetPlayerBySlot(int slot);
    char HasIdleOtherPlayer();
};

char Game::HasIdleOtherPlayer()
{
    int slot = 0;

    while (slot < 6) {
        struct Game *player = GetPlayerBySlot(slot);

        if (player != *(struct Game **)((char *)this +
                                         *(int *)((char *)this + 0x2ec) * 4 +
                                         0x200) &&
            player != 0 && *(int *)((char *)player + 0x50) == 0)
            return 1;
        slot++;
    }
    return 0;
}
