/* MapObject_SetCityFromPlayer: record the player's city on the object's
   map cell (0x4d3020). */
extern "C" int DAT_0057c670;

struct Game {
    void *GetPlayerBySlot(int slot);
    int FindCityIndex(void);
};

struct Record {
    void SetField2D0C(int index, int value);
};

struct MapObject {
    void SetCityFromPlayer(void *player, int slot);
};

void MapObject::SetCityFromPlayer(void *player, int slot)
{
    int index;
    int value;
    struct Record *record = (struct Record *)player;

    *(int *)((char *)this + 8) = slot;
    if (slot != -1) {
        struct Game *playerGame = (struct Game *)
            ((struct Game *)DAT_0057c670)->GetPlayerBySlot(slot);

        value = playerGame->FindCityIndex() + 1;
        index = *(int *)((char *)this + 0x24);
        record->SetField2D0C(index, value);
        return;
    }
    value = 0;
    index = *(int *)((char *)this + 0x24);
    record->SetField2D0C(index, value);
}
