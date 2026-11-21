/* Game_GetActiveCompanyById: returns the n-th active company record
   (0x4dde30). */
struct IDMap {
    int *Lookup(int key, int *out);
};

struct Game {
    int *GetActiveCompanyById(int wanted);
};

int *Game::GetActiveCompanyById(int wanted)
{
    int count = *(int *)((char *)this + 0x124);
    int active = 0;
    int index;

    for (index = 0; index < count; index++) {
        int *company = ((struct IDMap *)((char *)this + 0x110))->Lookup(index, 0);

        if (*(char *)((char *)company + 0x1dc) == 1) {
            if (active == wanted)
                return company;
            active++;
        }
    }
    return 0;
}
