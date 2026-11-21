/* Game_FindSubrecordIndex: index of the subrecord matching a pointer
   (0x4e2370). */
struct IDMap {
    int Lookup(int key, int *out);
};

struct Game {
    int FindSubrecordIndex(int record);
};

int Game::FindSubrecordIndex(int record)
{
    int count = *(int *)((char *)this + 0x194);
    int index;

    for (index = 0; index < count; index++) {
        if (((struct IDMap *)((char *)this + 0x180))->Lookup(index, 0) == record)
            return index;
    }
    return -1;
}
