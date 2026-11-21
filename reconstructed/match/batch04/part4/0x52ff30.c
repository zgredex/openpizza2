/* PC2 byte-match candidate: Array_GetRecordField40 (0x52ff30, 26 bytes).
   Build: /O2 /TP.  Looks the key up and reads record field 0x40. */
struct Record;
struct Array {
    Record *GetRecordByKey(int key);
    int GetRecordField40(int key);
};

int Array::GetRecordField40(int key)
{
    Record *record = GetRecordByKey(key);
    if (record == 0)
        return -1;
    return *(int *)((char *)record + 0x40);
}
