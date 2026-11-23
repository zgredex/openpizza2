extern "C" int __fastcall Rating_AdjustA(int);
extern "C" int __fastcall Rating_AdjustB(int);
extern "C" int g_Rating_ComputeEightCategories_RData[];
extern "C" int g_Rating_ComputeEightCategories_RData_00567758[];

extern "C" void __stdcall Rating_ComputeEightCategories(int *input, int *out)
{
    int values[5];
    int *table;
    int *value;
    int *dst;
    int i;
    int row;
    int j;

    for (i = 0; i < 5; i++) {
        values[i] = 0;
    }
    values[0] = input[1];
    values[1] = Rating_AdjustA((int)input);
    values[2] = input[3];
    values[3] = Rating_AdjustB((int)input);
    values[4] = input[0xe];

    for (j = 0; j < 8; j++) {
        out[j] = 0;
    }
    table = g_Rating_ComputeEightCategories_RData;
    value = values;
    do {
        row = *value;
        dst = out;
        for (i = 0; i < 8; i++) {
            int diff = row - *table++;
            if (diff < 0) {
                diff = diff >> 2;
            } else {
                diff = diff / 5;
            }
            *dst = *dst + diff + 0x19;
            dst++;
        }
        value++;
    } while (table < g_Rating_ComputeEightCategories_RData + 0x20);

    for (j = 0; j < 8; j++) {
        int diff = values[4] - g_Rating_ComputeEightCategories_RData_00567758[j];
        if (diff < 0) {
            diff = -diff;
        }
        out[j] = out[j] - diff;
        if (out[j] < 0) {
            out[j] = 0;
        }
        if (out[j] > 100) {
            out[j] = 100;
        }
    }
}
