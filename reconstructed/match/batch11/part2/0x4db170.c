/* Market_GetPriceDelta: returns the market price delta for an entry
   (0x4db170). */
extern "C" int *DAT_0057c670;

struct Market {
    char pad[0xc8];
    int values[7];

    int GetPriceDelta(unsigned int index);
};

int Market::GetPriceDelta(unsigned int index)
{
    char *entry =
        *(char **)((char *)DAT_0057c670 + 0xa8 + (index & 0xff) * 4);

    if (entry != 0) {
        int level = *(unsigned char *)(entry + 0xa8);

        if (level >= 1 && level <= 6) {
            int value = *(int *)((char *)this + level * 4 + 0xc8);

            if (value == -1)
                return -40;
            return value != 0 ? 0x28 : 0;
        }
    }
    return 0;
}
