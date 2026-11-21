/* Game_IsRecordLinked: reports whether a record carries link field 0x1dc (0x4e0f10). */
struct Game {
    char HasRecordField14DC(int record);
    bool IsRecordLinked(int record);
};

bool Game::IsRecordLinked(int record)
{
    if (*(char *)(record + 0x1dc) != 0)
        return true;
    bool linked = HasRecordField14DC(record);
    return linked;
}
