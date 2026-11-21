/* Game_AdjustPlayerPercentByKey: finds a player slot by key and adjusts its
   stored percent by five (0x4fcc00).  Build: /O2 /TP. */
struct GameEntry {
    int key;
    char pad[0x164];
};

struct Object {
    void AdjustShortPercent(int index, int percent);
};

struct Game {
    char pad[0x40];
    GameEntry entries[6];
    void AdjustPlayerPercentByKey(int key);
};

void Game::AdjustPlayerPercentByKey(int key)
{
    int index;

    for (index = 0; index < 6; index++) {
        if (entries[index].key == key) {
            ((Object *)this)->AdjustShortPercent(index, 5);
            return;
        }
    }
}
