/* Recipe_AccumulateQualityDelta: accumulates the quality difference between
   two products (0x512c40). */
extern "C" int abs(int value);
#pragma intrinsic(abs)

struct Recipe {
    void *MapCategory(char *product);

    char pad[0x258];
    int quality;
    char pad2[0x4];
    int samples;

    void AccumulateQualityDelta(char *first, char *second);
};

void Recipe::AccumulateQualityDelta(char *first, char *second)
{
    int difference;

    if (MapCategory(first) == 0) {
        return;
    }
    difference = (unsigned char)first[0x10] - (unsigned char)second[0x10];
    if (difference > 4) {
        difference -= 8;
    }
    if (difference < -4) {
        difference += 8;
    }
    quality += abs(difference) - 2;
    samples++;
}
