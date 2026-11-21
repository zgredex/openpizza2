/* PC2 byte-match candidate: Object_GetPair10 (0x535150, 15 bytes).
   Build: /O2 /TP; entry ?GetPair10@ObjectPair@@QAEHPAH@Z. */
struct ObjectPair {
    int field_00;
    int field_04;
    int field_08;
    int field_0c;
    int field_10;
    int field_14;

    int GetPair10(int *first);
};

int ObjectPair::GetPair10(int *first)
{
    *first = field_10;
    return field_14;
}
