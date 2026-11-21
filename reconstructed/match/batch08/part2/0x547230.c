/* Sound_ClampGlobalLimits: clamps the maximum global sound limits
   (0x547230). */
extern unsigned int DAT_00575094;
extern unsigned int DAT_00575098;
extern unsigned int DAT_0057509c;

void __cdecl Sound_ClampGlobalLimits(void)
{
    if (DAT_00575094 > 10000)
        DAT_00575094 = 10000;
    if (DAT_00575098 > 10000)
        DAT_00575098 = 5000;
    if (DAT_0057509c > 10000)
        DAT_0057509c = 5000;
}
