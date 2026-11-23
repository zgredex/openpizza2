extern "C" char DAT_00567bc0[];
extern float DAT_0055c2e4;
extern "C" void NoOp_Stub(char *message);

struct Stats {
    float SumFilteredFloats2(int group, int filter, int value);
    float GetGroupScore(int group, int filter);
};

float Stats::GetGroupScore(int group, int filter)
{
    float result = DAT_0055c2e4;

    switch (group) {
    case 0:
        result = SumFilteredFloats2(1, -1, filter);
        break;
    case 1:
        result = SumFilteredFloats2(6, -1, filter);
        result = SumFilteredFloats2(7, -1, filter) + result;
        result = SumFilteredFloats2(8, -1, filter) + result;
        result = SumFilteredFloats2(0xa, -1, filter) + result;
        result = SumFilteredFloats2(0xd, -1, filter) + result;
        break;
    case 2:
        result = SumFilteredFloats2(0xc, -1, filter);
        break;
    case 3:
        result = SumFilteredFloats2(0x10, -1, filter);
        result = SumFilteredFloats2(0x11, -1, filter) + result;
        break;
    case 4:
    case 5:
        break;
    case 6:
        result = SumFilteredFloats2(0x13, -1, filter);
        break;
    default:
        NoOp_Stub(DAT_00567bc0);
        break;
    }
    return result;
}
