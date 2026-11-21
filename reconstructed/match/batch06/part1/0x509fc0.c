/* Building_IsSpecialType: recognizes the five special building types (0x509fc0). */
int __fastcall Building_IsSpecialType(char *building)
{
    int type = *(int *)(building + 0x30);

    if (type == 4 || type == 5 || type == 0xb || type == 0x21 || type == 0xf) {
        return 1;
    }
    return 0;
}
