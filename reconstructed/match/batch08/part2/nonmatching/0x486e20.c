/* Closest candidate for Game_CountRecordsForSelectedPlayer (0x486e20).
   The slot == -1 arm differs by register allocation only: the original
   reuses EAX for [this+0x2ec] and EDX for the record value; VC6 keeps the
   field in EDX and the value in EAX (4 differing bytes, first at +0x0a:
   original 0x81, candidate 0x91). */
struct Game {
    char pad[0x2ec];
    int selectedSlot;
    char pad2[4];
    struct Game *selectedPlayer;
    struct Game *GetPlayerBySlot(int slot);
    int CountRecordsByField34(int value);
    void CountRecordsForSelectedPlayer(int value, int slot);
};

void Game::CountRecordsForSelectedPlayer(int value, int slot)
{
    if (slot == -1) {
        (*(struct Game **)((char *)this + *(int *)((char *)this + 0x2ec) * 4 +
                           0x200))
            ->CountRecordsByField34(value);
        return;
    }
    GetPlayerBySlot(slot)->CountRecordsByField34(value);
}
