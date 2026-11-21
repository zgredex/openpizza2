/* Game_AverageObjectField0C: average of the field at 0xc over every map
   record (0x478250). */
struct IDMap {
    int **Lookup(int key, int *out);
};

int __fastcall Game_AverageObjectField0C(int game)
{
    int count = *(int *)(game + 0x1514);
    int sum = 0;
    int index;

    for (index = 0; index < count; index++) {
        int **object = ((struct IDMap *)(game + 0x1500))->Lookup(index, 0);

        sum += *(int *)((char *)*object + 0xc);
    }
    if (count == 0)
        return 0;
    return sum / count;
}
