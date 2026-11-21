/* Game_GetRecordChild14: reads child pointer 0x14 from a 0x48-byte slot (0x4eac00). */
struct ChildSlot {
    int pad[0x12];
};

struct Game {
    char pad[0x68];
    ChildSlot slots[1];
    int GetRecordChild14(int index);
};

int Game::GetRecordChild14(int index)
{
    int *record;

    if (index < 0)
        return 0;
    record = *(int **)&slots[index];
    if (record == 0)
        return 0;
    return record[5];
}
