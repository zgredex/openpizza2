/* Game_CountRecordsByByteC: counts records whose byte field matches a value
   (0x47cc10). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Record {
    int GetRecordByteC();
};

struct Game {
    char pad[0x16f8];
    char map[0x14];
    int count;

    int CountRecordsByByteC(unsigned value);
};

int Game::CountRecordsByByteC(unsigned value)
{
    int total = 0;
    int i;

    for (i = 0; i < count; i++) {
        struct Record *player = (struct Record *)
            ((struct IDMap *)map)->Lookup(i, 0);

        if (player != 0) {
            if ((player->GetRecordByteC() & 0xff) == value) {
                total++;
            }
        }
    }
    return total;
}
