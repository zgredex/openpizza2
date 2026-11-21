extern int DAT_0057c670; extern float DAT_0055c2e4; extern float DAT_0055c458;
double __fastcall Game_GetPlayerWeightedStat(int player)
{
    double total = DAT_0055c2e4;
    int *counts = (int *)(player + 0x64);
    int **values = (int **)(DAT_0057c670 + 0xa8);
    int i = 0x56;
    do {
        if (*counts > 0) {
            double product = *(double *)(*values + 0xc0);
            product *= DAT_0055c458;
            product *= *counts;
            total += product;
        }
        values++;
        counts++;
        i--;
    } while (i != 0);
    return total;
}
