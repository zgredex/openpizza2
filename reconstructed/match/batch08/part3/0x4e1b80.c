/* Game_ResetRecordTurnCounters: clears the turn counter of every record
   (0x4e1b80). */
struct IDMap;

struct Record {
    char pad[0x30c];
    int turnCounter;
};

struct Game {
    void ResetRecordTurnCounters();
};

struct IDMap {
    Record *Lookup(int key, int *out);
};

void Game::ResetRecordTurnCounters()
{
    int i = 0;
    int count = *(int *)((char *)this + 0x124);

    if (count > 0) {
        do {
            Record *record = ((IDMap *)((char *)this + 0x110))->Lookup(i, 0);
            record->turnCounter = 0;
            i++;
        } while (i < *(int *)((char *)this + 0x124));
    }
}
