/* Game_AddRecordTo19C4: clears a record header and appends it to the list at
   0x19c4 (0x47eba0). */
struct List {
    void Add(void *item);
};

struct Game {
    char pad[0x19c4];
    List records;
    void AddRecordTo19C4(int *record);
};

void Game::AddRecordTo19C4(int *record)
{
    *record = 0;
    records.Add(record);
}
