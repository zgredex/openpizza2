/* SaveList_FindIndex: linear search of the save-key table for a key, -1 when
   absent (0x496900).  Build: /O2. */
int SaveList_FindIndex(int key)
{
    int count = *(int *)0x57c704;
    int *entry;
    int index = 0;

    if (0 < count) {
        entry = *(int **)0x57c714;
        while (index < count) {
            if (*entry == key)
                return index;
            index++;
            entry++;
        }
    }
    return -1;
}
