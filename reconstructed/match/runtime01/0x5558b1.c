void *memset(void *, int, unsigned int);
#pragma intrinsic(memset)

void CRT_BitSetClear(unsigned long *bits)
{
    memset(bits, 0, 3 * sizeof(*bits));
}
