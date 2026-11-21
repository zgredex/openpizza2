/* NON-MATCHING closest candidate: Rating_ClampAdjusted (0x4d3f90, 48 bytes).
   Build: /O2 /TP.

   The control flow, loads, clamp and both branch values are correct; the
   original is 22 bytes away only because of LEA encoding choices:
     original 8d 44 0a e7   lea eax,-0x19(edx,ecx)   (base=edx, index=ecx)
     ours     8d 44 11 e7   lea eax,-0x19(ecx,edx)   (base=ecx, index=edx)
   and the high branch is (d + base) + 4*d in the original versus
   (base + 4*d) + d here.  Every algebraic spelling tried with the SP5
   front end (base+value-25, value+base-25, parenthesized and unsigned
   variants, arrays/locals, /O1 and /Os) canonicalises to the same two LEAs,
   so the remaining difference is front-end instruction selection. */
extern "C" int __fastcall Rating_ClampAdjusted(int object)
{
    int base = *(int *)(object + 4);
    int value = *(int *)(object + 0x38);
    int result;

    if (value <= 0x32)
        result = base + value - 0x19;
    else
        result = (0x37 - value) * 5 + base;
    if (result < 0)
        return 0;
    if (result > 100)
        result = 100;
    return result;
}
