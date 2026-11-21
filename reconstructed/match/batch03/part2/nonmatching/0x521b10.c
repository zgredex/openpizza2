/* Superseded first attempt for 0x521b10 (Object_GetActiveValue).
 * Testing the zero case first put the field68 return block in the
 * fall-through path and inverted the branch.
 * First difference: offset 5, original 0x74 (je) vs 0x75 (jne).
 */
unsigned int __fastcall Object_GetActiveValue(void *this_)
{
    unsigned int value = *(unsigned int *)((char *)this_ + 0x6c);

    if (value == 0)
        return *(unsigned int *)((char *)this_ + 0x68);
    return *(int *)((char *)this_ + 0x78) != 0 ? 0 : value;
}
