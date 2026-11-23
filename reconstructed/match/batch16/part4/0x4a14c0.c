/* SaveGame_CompareTime: compares two save-game timestamps field by field
   (0x4a14c0). */
extern "C" int SaveGame_CompareTime(unsigned short *param_1,
                                    unsigned short *param_2)
{
    if (param_1[0] > param_2[0]) {
        return 1;
    }
    if (param_1[0] < param_2[0]) {
        return -1;
    }
    if (param_1[1] > param_2[1]) {
        return 1;
    }
    if (param_1[1] < param_2[1]) {
        return -1;
    }
    if (param_1[3] > param_2[3]) {
        return 1;
    }
    if (param_1[3] < param_2[3]) {
        return -1;
    }
    if (param_1[4] > param_2[4]) {
        return 1;
    }
    if (param_1[4] < param_2[4]) {
        return -1;
    }
    if (param_1[5] > param_2[5]) {
        return 1;
    }
    if (param_1[5] < param_2[5]) {
        return -1;
    }
    if (param_1[6] > param_2[6]) {
        return 1;
    }
    if (param_1[6] < param_2[6]) {
        return -1;
    }
    return 0;
}
