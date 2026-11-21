/* First attempt for 0x53d430 (Sprite_GetColorKey), kept as evidence.
   This is the Ghidra branch polarity written literally:
       if ((flags & 0x10) == 0) return colorKey; return 0;
   CL /O2 /TP emits the mirror image of the shipped layout
   (test/jne + field load first), so 8 bytes differ from offset 4 on.
   The matching candidate in ../0x53d430.c tests the bit with != 0 instead,
   which produces the shipped test/je/xor/ret/mov/ret order.

   Build: /O2 /TP; entry @Sprite_GetColorKey@4. */
extern "C" int __fastcall Sprite_GetColorKey(char *self)
{
    if ((*(unsigned char *)(self + 4) & 0x10) == 0)
        return *(int *)(self + 0x1c);
    return 0;
}
