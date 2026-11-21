/* Record_ClearFlags48 (0x533a70, 48 bytes).  Build: /O2 /TP.
   Clears the two flag bytes of a valid record in the 0x48-byte table. */
struct Record {
    void ClearFlags48(int index);
};

void Record::ClearFlags48(int index)
{
    char *record;

    if (index < 0)
        return;
    if (index >= *(int *)((char *)this + 0x48))
        return;
    record = (char *)(*(int *)((char *)this + 0x4c) + index * 0x48);
    if (*(int *)record != -1) {
        record[0x3e] = 0;
        *(char *)(*(int *)((char *)this + 0x4c) + index * 0x48 + 0x3c) = 0;
    }
}
