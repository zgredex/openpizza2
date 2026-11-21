/* String_SkipDelimiters: advances past spaces, tabs and commas (0x4db2e0). */
void __cdecl String_SkipDelimiters(int base, int *offset)
{
    for (;;) {
        char c = *(char *)(*offset + base);

        if (c != ' ' && c != '\t' && c != ',')
            break;
        (*offset)++;
    }
}
