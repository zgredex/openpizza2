typedef struct ThreadData {
    char preceding_fields[20];
    unsigned int random_seed;
} ThreadData;

ThreadData *CRT_GetThreadData(void);

void CRT_Srand(unsigned int seed)
{
    CRT_GetThreadData()->random_seed = seed;
}
