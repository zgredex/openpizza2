/* IsSpecialIdRange: true for object ids 0x84c..0x857 (0x4d2e40). */
int __fastcall IsSpecialIdRange(int *object)
{
    int id = object[8];

    if (id < 0x84c || id > 0x857)
        return 0;
    return 1;
}
