/* Closest candidate for Language_CopyStringIds (0x514690): all instructions
   match except the load's SIB encoding. Original uses [eax+esi-4] (index in
   EAX, table in ESI); VC6 emits [esi+eax-4] for every equivalent source form
   tried. First difference: +0x2c, original 0x30, candidate 0x06 (SIB byte). */
int Language_IndexOfString(int value);
extern int DAT_00580ad4;

void __cdecl Language_CopyStringIds(int *dest, int stringId, int count)
{
    int index = Language_IndexOfString(stringId);

    if (count > 0) {
        index = index << 2;
        for (; count > 0; count--) {
            *dest = *(int *)(index + DAT_00580ad4);
            index = index + 4;
            dest++;
        }
    }
}
