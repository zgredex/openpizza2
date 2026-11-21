/* Player_CountObjectsByType: total number of objects of a type over every
   player record (0x4e0830). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    int CountObjectsByType(unsigned int type);
};

struct Player {
    int CountObjectsByType(unsigned int type);
};

int Player::CountObjectsByType(unsigned int type)
{
    int count = 0;
    int index = 0;

    if (*(int *)((char *)this + 0x15c) > 0) {
        do {
            struct Game *record = (struct Game *)
                ((struct IDMap *)((char *)this + 0x148))->Lookup(index, 0);

            count += record->CountObjectsByType(type);
            index++;
        } while (index < *(int *)((char *)this + 0x15c));
    }
    return count;
}
