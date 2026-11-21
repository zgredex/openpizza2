/* Array_ClearStride34: clears the first byte of eight 0x34-byte records (0x47c590). */
void __fastcall Array_ClearStride34(char *this_)
{
    char *record = this_ + 0x154e;
    int count = 8;

    do {
        *record = 0;
        record += 0x34;
    } while (--count);
}
