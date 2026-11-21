/* GlobalArray_FindIndex: linear search of the global integer array (0x49c0e0). */
extern int *DAT_0057ca94;

int GlobalArray_FindIndex(int value, int count)
{
    int index = 0;

    if (count > 0) {
        int *item = DAT_0057ca94;
        while (index < count) {
            if (*item == value) {
                return index;
            }
            index++;
            item++;
        }
    }
    return -1;
}
