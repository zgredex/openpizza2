/* Stub_ReturnZero: x87 FDIV accuracy probe; returns 1 when the processor
   loses precision in the classic 4195835/3145727 case (0x551981). */
extern double DAT_0055cd98;
extern double DAT_0055cd90;
extern double DAT_0055c368;

int __cdecl Stub_ReturnZero(void)
{
    double divisor = DAT_0055cd98;
    double value = DAT_0055cd90;
    double error = value - value / divisor * divisor;

    if (error > DAT_0055c368)
        return 1;
    return 0;
}
