/* Game_CountPlayersByByte: counts players whose byte field matches a value
   (0x47cc10). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Player {
    int GetPlayerByte8();
};

struct Game {
    char pad[0x16f8];
    char map[0x14];
    int count;

    int CountPlayersByByte(unsigned value);
};

int Game::CountPlayersByByte(unsigned value)
{
    int total = 0;
    int i;

    for (i = 0; i < count; i++) {
        struct Player *player = (struct Player *)
            ((struct IDMap *)map)->Lookup(i, 0);

        if (player != 0) {
            if ((player->GetPlayerByte8() & 0xff) == value) {
                total++;
            }
        }
    }
    return total;
}
