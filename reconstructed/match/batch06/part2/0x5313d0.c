/* Array_GetRecordByKey: returns the record for a key or null (0x5313d0). */
int __fastcall BinarySearch8(void *self, int dummy, int key, int zero);

void *__fastcall Array_GetRecordByKey(char *array, int dummy, int key)
{
    int index = BinarySearch8(array, dummy, key, 0);

    if (index == -1) {
        return 0;
    }
    return *(void **)(*(char **)(array + 0xe8) + index * 8);
}
