/* Stats_ComputeTypeThreeShare (0x479a40). */
struct Stats {
    char pad00[0x1868];
    int share1868;

    int CountPlayersByByte(int value);
    int CountRecordsByByteC(int value);
    void Clamp_0_100(int *value);
    void ComputeTypeThreeShare();
};

void Stats::ComputeTypeThreeShare()
{
    int total = CountPlayersByByte(1);
    int records;
    int *share;

    total = total + CountPlayersByByte(2);
    total = total + CountPlayersByByte(4);
    total = total + CountPlayersByByte(3);
    records = CountRecordsByByteC(3);
    total = total + records;
    share = (int *)((char *)this + 0x1868);

    if (total > 0) {
        *share = (records * 100) / total;
        Clamp_0_100(share);
    } else {
        *share = 0;
        Clamp_0_100(share);
    }
}
