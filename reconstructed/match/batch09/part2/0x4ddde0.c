/* Game_CountActiveCompanies: counts the companies flagged active
   (0x4ddde0). */
struct IDMap {
    int *Lookup(int key, int *out);
};

int __fastcall Game_CountActiveCompanies(int game)
{
    int count = 0;
    int index;
    int total = *(int *)(game + 0x124);

    for (index = 0; index < total; index++) {
        int *company = ((struct IDMap *)(game + 0x110))->Lookup(index, 0);

        if (*(char *)((char *)company + 0x1dc) == 1)
            count++;
    }
    return count;
}
