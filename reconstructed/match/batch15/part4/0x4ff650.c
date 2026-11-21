struct Math {
    int CompareRounded(void *record, int multiplier);
};

int Math::CompareRounded(void *record, int multiplier)
{
    int index = *(int *)((char *)record + 0x4c);
    char *object = (char *)this + index * 0x168;
    int first = (int)(((100 - *(short *)(object + 0x130)) * 2 * 0.01 + 1.0) *
                      multiplier);
    int second = (int)(first * ((100 - *(short *)(object + 0x128)) * 8 * 0.01 +
                                1.0));
    return second < (int)*(double *)((char *)record + 0x108);
}
