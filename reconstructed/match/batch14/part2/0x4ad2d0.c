/* Stats_SumByStorageMode (0x4ad2d0): dispatches the statistic sum to the
   representation selected by the current storage mode. */
extern int DAT_0057c670;
extern int DAT_0057d62c;
extern float DAT_0055c4bc;

struct Company {
    int SumStatGridAll(int param_1, int param_2, void *param_3);
    float SumRecordFloatMatrix(int param_1, int param_2, int param_3);
    int SumPlayerMatrixValues(int param_1, int param_2, void *param_3);
};

float __cdecl Stats_SumByStorageMode(int param_1, void *param_2)
{
    Company *company;

    company = (Company *)*(void **)(DAT_0057c670 +
                                    *(int *)(DAT_0057c670 + 0x2ec) * 4 + 0x200);
    switch (DAT_0057d62c) {
    case 0:
        return (float)company->SumStatGridAll(param_1, 8, param_2);
    case 1:
        return company->SumRecordFloatMatrix(param_1, 8, (int)param_2);
    case 2:
        return (float)company->SumPlayerMatrixValues(param_1, 8, param_2);
    case 3:
    case 4:
    case 5:
        return DAT_0055c4bc;
    default:
        return *(float *)&param_2;
    }
}
