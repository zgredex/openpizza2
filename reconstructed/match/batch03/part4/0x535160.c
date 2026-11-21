/* PC2 byte-match candidate: Object_GetPair4 (0x535160, 21 bytes).
   Build: /O2 /TP.  Reads the two dwords at +4/+8 into the caller's outputs. */
struct Object {
    int field_00;
    int field_04;
    int field_08;
    void GetPair4(int *first, int *second);
};

void Object::GetPair4(int *first, int *second)
{
    *first = field_04;
    *second = field_08;
}
