/* Superseded first attempt for 0x51ef60 (Object_GetByte36Max7).
 * The unsigned-char temporary plus two ifs made VC6 emit a 48-byte
 * branchless clamp with a stack spill.
 * First difference: offset 0, original 0x8b (mov eax,[ecx]) vs 0x51 (push ecx).
 */
unsigned char __fastcall Object_GetByte36Max7(void *this_)
{
    void *child = *(void **)this_;
    unsigned char value;

    if (child == 0)
        return 0;
    value = *(unsigned char *)((char *)child + 0x36);
    if (value > 7)
        return 0;
    return value;
}
