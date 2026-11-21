/* _strncmp: the C runtime bounded string comparison (0x54e940). */
typedef unsigned int size_t;

int __cdecl _strncmp(const char *string1, const char *string2, size_t count)
{
    unsigned char c1;
    unsigned char c2;

    while (count != 0) {
        count--;
        c1 = (unsigned char)*string1++;
        c2 = (unsigned char)*string2++;
        if (c1 != c2)
            return c1 < c2 ? -1 : 1;
        if (c1 == 0)
            break;
    }
    return 0;
}
