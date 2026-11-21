/* City_GetProductPriceLevel (0x478140). */

extern char *DAT_0057c670;
extern int DAT_005675ac[];

struct IDMap {
    void *Lookup(int index, int *out);
};

struct City {
    int GetProductPriceLevel();
    int CountRecordsByByteC(int value);
};

int __fastcall Calendar_InterpolateMonthlyValue(void *record);

int City::GetProductPriceLevel()
{
    int value;

    value = Calendar_InterpolateMonthlyValue(
        ((struct IDMap *)(DAT_0057c670 + 4))->Lookup(
            *(int *)((char *)this + 0x34), 0));
    if (value >= 0x1e) {
        return 0x1e;
    }
    value += CountRecordsByByteC(6)
             * DAT_005675ac[*(int *)((char *)this + 0x38)];
    if (value > 0x1e) {
        value = 0x1e;
    } else if (value < 10) {
        value = 10;
    }
    return value;
}
