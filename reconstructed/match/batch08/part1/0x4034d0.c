/* Random_RangeFast: returns a random value in the inclusive range
   (0x4034d0). */
int rand(void);

unsigned __cdecl Random_RangeFast(int minimum, unsigned maximum)
{
    int value = rand();
    unsigned result = (value * ((maximum - minimum) + 1)) / 0x7fff + minimum;

    if (result > maximum)
        result = maximum;
    return result;
}
