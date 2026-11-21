/* 0x47a4a0 variant explorer */
extern "C" int *DAT_0057c670;

extern "C" int __fastcall Matrix_Max100x8(int *this_)
{
    int maximum = 0;
    int rows =
        *(unsigned short *)((char *)*(int *)((char *)DAT_0057c670 + 0x94) + 10);
    int r;
    int c;

    if (rows > 100)
        rows = 100;
    for (r = 0; r < rows; r++) {
        int *value = this_ + 0x155 + r;

        for (c = 0; c < 8; c++) {
            if (*value > maximum)
                maximum = *value;
            value += 100;
        }
    }
    return maximum;
}
