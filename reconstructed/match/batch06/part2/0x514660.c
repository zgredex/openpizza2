/* Language_IndexOfString: finds a translated string index (0x514660). */
extern int DAT_00580ad0;
extern int *DAT_00580ad4;

int Language_IndexOfString(int value)
{
    int index = 0;

    if (DAT_00580ad0 > 0) {
        int *item = DAT_00580ad4;
        while (index < DAT_00580ad0) {
            if (*item == value) {
                return index;
            }
            index++;
            item++;
        }
    }
    return 0;
}
