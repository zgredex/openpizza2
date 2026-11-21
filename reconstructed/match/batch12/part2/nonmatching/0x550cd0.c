/* _memmove_2 (0x550cd0): best genuine C reconstruction.  The shipped routine is
   a larger hand-written CRT implementation whose first 91 bytes are only the
   forward-copy entry and part of its jump table; a compiler-generated
   memmove cannot reproduce that extent. */
void *_memmove_2(void *destination, const void *source, unsigned count)
{
    unsigned char *dest = (unsigned char *)destination;
    const unsigned char *src = (const unsigned char *)source;

    if (dest < src) {
        while (count != 0) {
            *dest++ = *src++;
            count--;
        }
    } else if (dest > src) {
        dest += count;
        src += count;
        while (count != 0) {
            *--dest = *--src;
            count--;
        }
    }
    return destination;
}
