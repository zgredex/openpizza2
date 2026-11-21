/* Game_UpdateActivePlayerCount: recomputes the active player count from the
   player and record tables (0x479ab0).  Build: /O2 /TP. */
struct Game {
    char pad[0x186c];
    int activePlayerCount;
    int CountPlayersByByte(int value);
    int CountRecordsByByteC(int value);
    void UpdateActivePlayerCount();
};

void Game::UpdateActivePlayerCount()
{
    activePlayerCount = CountPlayersByByte(3);
    activePlayerCount -= CountRecordsByByteC(6);
}
