/* UI_RemoveLastChild: removes the last entry of the selected child array (0x509bf0). */
struct Array {
    char pad[0x14];
    int count;
    void *GetPtr4(int index);
};

void *__fastcall UI_RemoveLastChild(char *ui)
{
    char *child = *(char **)(ui + 0xc8);

    if (child == 0) {
        return 0;
    }
    return ((Array *)(child + 0x14))->GetPtr4(*(int *)(child + 0x18) - 1);
}
