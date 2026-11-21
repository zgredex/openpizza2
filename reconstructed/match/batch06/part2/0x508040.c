/* UI_ResetChildRecord: clears the active record of the selected child (0x508040). */
struct Record {
    void ClearActive48(int index);
};

void __fastcall UI_ResetChildRecord(char *ui)
{
    char *s1 = *(char **)(ui + 0xc8);
    char *s2 = *(char **)(ui + 0xc8);
    char *record;
    int index;

    if (s1 == 0) {
        record = 0;
    } else {
        record = *(char **)(s1 + 0x58);
    }
    if (s2 == 0) {
        index = -1;
    } else {
        index = *(int *)s2;
    }
    if (record != 0) {
        ((Record *)record)->ClearActive48(index);
    }
}
