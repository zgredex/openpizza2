/* Game_GetDateField0C: reads the date record's field 0xc (0x489b10). */
int __fastcall Game_GetDateField0C(char *this_)
{
    return *(int *)(*(int *)(this_ + 0x94) + 0xc);
}
