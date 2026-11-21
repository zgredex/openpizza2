/* String_RegisterSlot: registers a string slot in the global string table
   (0x403750). */
extern int DAT_0057b558;
extern void *DAT_00563364;
int __cdecl String_RegisterSlot(int value)
{
    if (DAT_0057b558 != 0) {
        void *target = DAT_00563364;
        int index = 0;
        void **slot = (void **)0x579ffc;

        while ((int)slot < 0x57a18c) {
            if (*slot == target) {
                ((void **)0x579ffc)[index] = (void *)value;
                return index;
            }
            slot++;
            index++;
        }
    }
    return 99;
}
