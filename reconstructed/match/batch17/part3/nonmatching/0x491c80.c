struct Chart {
    void DrawCustomerGroups(void *param1, int param2, int param3, int *matrix);
};

extern Chart *DAT_0057c670;

extern "C" void Chart_DrawGroupMatrix(void *param_1, int param_2, int param_3,
                                      char *param_4)
{
    if (param_4 != 0) {
        int local_100[64];
        for (int i = 0; i < 0x40; i++)
            local_100[i] = 0;
        int *local_104 = local_100;
        int *pairs = (int *)(param_4 + 0x189c);
        int *dst = local_100 + param_3;
        int index = 0x636;
        do {
            int j = 0;
            *dst = pairs[-1] + *pairs;
            int *row = local_104;
            do {
                if (j != param_3)
                    *row = *(int *)(param_4 + (index + j) * 4);
                j++;
                row++;
            } while (j < 6);
            index += 6;
            dst += 8;
            pairs += 2;
            local_104 += 8;
        } while (index < 0x666);
        DAT_0057c670->DrawCustomerGroups(param_1, param_2, param_3, local_100);
    }
}
