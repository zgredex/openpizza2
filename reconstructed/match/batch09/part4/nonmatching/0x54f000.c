/* _strcmp: compares two NUL-terminated byte strings (0x54f000).
 *
 * The decompile index records this CRT routine as a 67-byte extent
 * (0x54f000-0x54f042), but its internal branches target blocks at 0x54f044
 * and 0x54f04c inside the same routine.  A truthful C implementation of the
 * complete routine necessarily emits those blocks, so the strict extent check
 * rejects it even when the first 67 bytes agree.  Kept as a non-matching
 * reconstruction for reference. */
int _strcmp(char *first, char *second)
{
    unsigned char left;
    unsigned char right;

    for (;;) {
        left = (unsigned char)*first++;
        right = (unsigned char)*second++;
        if (left != right)
            return left < right ? -1 : 1;
        if (left == 0)
            return 0;
    }
}
