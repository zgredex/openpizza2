/* Game_FindMapRecordByTypeE: finds the first record of type 0xe in the
   game's local map (0x477360). */
struct Game {
    char pad[0x8c];
    int count;
    int MapRecordToGlobal(int record);
};

struct GameRoot {
    char pad[0x16f0];
    struct Game *owner;
};

int __fastcall Game_FindMapRecordByTypeE(struct GameRoot *this_)
{
    int index = 0;
    struct Game *owner = this_->owner;

    while (index < owner->count) {
        int record = owner->MapRecordToGlobal(index);

        if (*(int *)(record + 0x30) == 0xe)
            return record;
        owner = this_->owner;
        index++;
    }
    return 0;
}
