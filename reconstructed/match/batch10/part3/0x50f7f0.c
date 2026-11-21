struct Company { int GetPercentModifier(int value); };
int Company::GetPercentModifier(int value)
{
    int divisor;
    if (value == -1)
        value = *(int *)((char *)this + 0x20);
    switch (*(int *)((char *)this + 8)) {
    case 2: divisor = 5000; break;
    case 1: divisor = 10000; break;
    default: return 100;
    }
    return (value * 100) / divisor;
}
