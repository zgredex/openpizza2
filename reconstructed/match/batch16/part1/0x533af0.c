// Record_ApplyVariantState @ 0x533af0 (149 bytes)
// Applies a stored variant sample to a record, if the selection is valid.

class Record {
public:
    char pad0[0x48];
    int count;
    char *records;
    char *variants;

    int ApplyVariantState(int index, int sample, unsigned char state);
    void SetVariant(int index, int sample);
};

int Record::ApplyVariantState(int index, int sample, unsigned char state)
{
    int offset;
    int variant;

    if (index < 0 || index >= this->count)
        return 0;
    offset = index * 0x48;
    variant = *(int *)(this->records + offset);
    if (variant == -1)
        return 0;
    if (sample < 0 || sample >= 0x10)
        return 0;
    if (*(short *)(this->variants + variant * 0x98 + sample * 6) == -1)
        return 0;
    this->records[offset + 0x3e] = 1;
    this->records[offset + 0x3c] = 0;
    this->records[offset + 0x3d] = 0;
    this->records[offset + 0x40] = 0;
    this->records[offset + 0x3f] = 0;
    this->SetVariant(index, sample);
    this->records[offset + 0x3d] = state;
    return 1;
}
