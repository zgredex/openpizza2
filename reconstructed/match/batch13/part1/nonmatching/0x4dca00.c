/* Weather_SelectRandomState (0x4dca00). */
extern unsigned int _rand(void);
struct Weather {
    char pad0[0x10bc];
    unsigned int state;     /* 0x10bc */
    int value;              /* 0x10c0 */

    void SelectRandomState();
};
extern char *DAT_0057c670;
extern int DAT_0056ca28[8][9];

void Weather::SelectRandomState()
{
    unsigned int previous = state;
    unsigned int next;
    int value;
    int base;

    do {
        next = _rand();
        next = next & 7;
        state = next;
    } while (previous == next);

    value = DAT_0056ca28[next][0] -
            *(unsigned char *)(*(int *)(DAT_0057c670 + 0x94) + 7);
    base = value + 0x30;
    this->value = base;
    if (base < 0x19)
        this->value = value + 0x48;
    if (this->value > 0x30)
        this->value = this->value - 0x18;
}
