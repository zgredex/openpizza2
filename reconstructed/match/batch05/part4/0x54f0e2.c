/* _rand: the CRT linear-congruential pseudo random generator (0x54f0e2). */
unsigned int * __cdecl CRT_GetThreadData(void);

int __cdecl rand(void)
{
    unsigned int *data = CRT_GetThreadData();

    data[5] = data[5] * 0x343fd + 0x269ec3;
    return (data[5] >> 16) & 0x7fff;
}
