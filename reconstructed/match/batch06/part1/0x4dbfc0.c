/* Market_GetPriceModifier: price modifier for one market slot (0x4dbfc0). */
struct Market {
    int GetPriceModifier(int first, int second);
};

int Market::GetPriceModifier(int first, int second)
{
    int value = *(int *)((char *)this + (second + 0xa0 + first * 8) * 4);

    if (value == 0) {
        return 0;
    }
    return value == 1 ? 10 : -10;
}
