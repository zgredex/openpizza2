/* Grid_GetRandomRecord28: picks a random 40-byte record from the grid table
   (0x4f3a90). */
int __cdecl Random_RangeFast(int low, int high);

int __fastcall Grid_GetRandomRecord28(int grid)
{
    int index;

    if (*(int **)(grid + 0x110) != 0) {
        index = Random_RangeFast(1, **(int **)(grid + 0x110));
        if (index > 10)
            index = 1;
        return *(int *)(grid + 0x9c)
               + *(int *)(*(int *)(grid + 0x110) + index * 4) * 0x28;
    }
    return 0;
}
