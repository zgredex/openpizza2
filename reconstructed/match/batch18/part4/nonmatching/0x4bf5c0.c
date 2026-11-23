extern char *DAT_0057c670;

/* Stats_BuildCompetitorMatrix: builds the competitor/category matrix
   (0x4bf5c0). */
struct IDMap {
    void *Lookup(int index, int *unused);
};

extern "C" void __cdecl Stats_BuildCompetitorMatrix(int *matrix)
{
    int totals[8];
    int i;
    int j;

    for (i = 0; i < 0x40; i++) {
        matrix[i] = 0;
    }
    for (i = 0; i < 8; i++) {
        totals[i] = 0;
    }
    i = 0;
    if (0 < *(int *)(DAT_0057c670 + 0x50)) {
        do {
            int record = (int)((IDMap *)(DAT_0057c670 + 0x3c))->Lookup(i, 0);
            int category = *(int *)(record + 0x30);

            if (category <= 7) {
                int *entry = (int *)(record + 0xd4);

                totals[category] = totals[category] + 1;
                for (j = 0; j < 8; j++) {
                    if (*(int *)(*entry + 4) ==
                        *(int *)(*(int *)(DAT_0057c670 + 0x218) + 4)) {
                        int cell = j + category * 8;

                        matrix[cell] = matrix[cell] + 1;
                    }
                    entry = entry + 1;
                }
            }
            i = i + 1;
        } while (i < *(int *)(DAT_0057c670 + 0x50));
    }
    for (i = 0; i < 8; i++) {
        int total = totals[i];

        for (j = 0; j < 8; j++) {
            matrix[j] = (total / 2 + matrix[j] * 100) / total;
        }
        matrix = matrix + 8;
    }
}
