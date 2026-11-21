/* Game_FindCompanyIndex: index of the company record matching a pointer
   (0x4dde70). */
struct IDMap {
    int Lookup(int key, int *out);
};

struct Game {
    int FindCompanyIndex(int record);
};

int Game::FindCompanyIndex(int record)
{
    int count = *(int *)((char *)this + 0x124);
    int index;

    for (index = 0; index < count; index++) {
        if (record == ((struct IDMap *)((char *)this + 0x110))->Lookup(index, 0))
            return index;
    }
    return -1;
}
