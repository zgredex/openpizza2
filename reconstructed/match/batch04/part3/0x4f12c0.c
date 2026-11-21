/* Array_PickRandomActiveRecord28: retries random 0x28-byte records until active
   (byte 6 non-zero) (0x4f12c0). The original prototype carries two unused
   trailing arguments; the caller at 0x507d30 pushes three stack arguments. */
struct Array {
    void *GetRandomRecord28B(int index);
    void PickRandomActiveRecord28(int index, int unused1, int unused2);
};

void Array::PickRandomActiveRecord28(int index, int unused1, int unused2)
{
    char *record;

    do {
        record = (char *)GetRandomRecord28B(index);
    } while (record[6] != 0);
}
