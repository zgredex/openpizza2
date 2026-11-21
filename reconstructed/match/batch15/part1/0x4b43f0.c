/* CompanyOverview_SortCompanyIndices: sorts the company overview indices with
   one of three comparison functions (0x4b43f0). */
extern int *DAT_0057c670;
extern int *DAT_0057d6a0;
extern int DAT_0057d69c;

extern "C" void CRT_QSort(void *base, int count, int size, void *compare);

extern "C" int Compare0(const void *a, const void *b);
extern "C" int Compare1(const void *a, const void *b);
extern "C" int Compare2(const void *a, const void *b);

extern "C" void CompanyOverview_SortCompanyIndices(int count)
{
    int i;

    if (count > 0) {
        for (i = 0; i < count; i++) {
            DAT_0057d6a0[i] = i;
        }
        if (*(short *)(*(int *)((char *)DAT_0057c670 + 0x94) + 0xa) != 0) {
            switch (DAT_0057d69c) {
            case 0:
                CRT_QSort(DAT_0057d6a0, count, 4, (void *)Compare0);
                break;
            case 1:
                CRT_QSort(DAT_0057d6a0, count, 4, (void *)Compare1);
                break;
            case 2:
                CRT_QSort(DAT_0057d6a0, count, 4, (void *)Compare2);
                break;
            }
        }
    }
}
