/* Game_GetActiveCompanyOrdinal: returns the active-company ordinal of a
   company record (0x4ddeb0). */
struct IDMap {
    void *Lookup(int index, int *out);
};

struct Game {
    char pad[0x110];
    char map[0x14];
    int count;

    int GetActiveCompanyOrdinal(int company);
};

int Game::GetActiveCompanyOrdinal(int company)
{
    int ordinal = 0;
    int i;
    int total = count;

    for (i = 0; i < total; i++) {
        int record = (int)((struct IDMap *)map)->Lookup(i, 0);

        if (company == record) {
            return ordinal;
        }
        if (*(char *)(record + 0x1dc) == 1) {
            ordinal++;
        }
    }
    return -1;
}
