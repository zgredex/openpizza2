/* PC2 byte-match candidate: Array_GetRecordByKeyPtr (0x52ff20, 13 bytes).
   Build: /O2 /TP; entry ?GetRecordByKeyPtr@Array@@QAEXH@Z. */
struct Array {
    void GetRecordByKey(int key);
    void GetRecordByKeyPtr(int key);
};

void Array::GetRecordByKeyPtr(int key)
{
    GetRecordByKey(key);
}
