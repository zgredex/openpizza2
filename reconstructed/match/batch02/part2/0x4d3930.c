/* Game_GetRecordField814Value - 0x4d3930, 9 bytes */
extern int __fastcall Game_GetRecordByField814(void *this_);

int __fastcall Game_GetRecordField814Value(void *this_)
{
    return Game_GetRecordByField814(this_) + 4;
}
