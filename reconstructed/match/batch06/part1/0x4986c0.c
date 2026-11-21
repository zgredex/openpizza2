/* GlobalArray_FindInt: linear search of the global integer array (0x4986c0). */
extern int *DAT_0057ca08;

int GlobalArray_FindInt(int value, int count)
{
    int index = 0;

    if (count > 0) {
        int *item = DAT_0057ca08;
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
