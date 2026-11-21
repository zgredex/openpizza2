/* PC2 byte-match candidate: Set_Field9B8 (0x535500, 13 bytes).
   Build: /O2 /TP; entry ?SetField9B8@FieldSet@@QAEXH@Z. */
struct FieldSet {
    char pad_0000[0x9b8];
    int field_9b8;

    void SetField9B8(int value);
};

void FieldSet::SetField9B8(int value)
{
    field_9b8 = value;
}
