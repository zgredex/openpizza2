/* Array_GetRandomRecord28: picks a random 40-byte record from the array table
   (0x4f3ad0). */
int __cdecl Random_RangeFast(int low, int high);

int __fastcall Array_GetRandomRecord28(int grid)
{
    int index;

    if (*(int **)(grid + 0x114) != 0) {
        index = Random_RangeFast(1, **(int **)(grid + 0x114));
        if (index > 10)
            index = 1;
        return *(int *)(grid + 0x9c)
               + *(int *)(*(int *)(grid + 0x114) + index * 4) * 0x28;
    }
    return 0;
}
