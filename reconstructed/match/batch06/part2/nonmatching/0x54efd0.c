/* _strrchr (0x54efd0) - non-matching.
 *
 * The shipped function is the Visual Studio 1998 CRT assembly leaf: it sets the
 * direction flag (`std`), scans backwards with `repnz scas`, and restores it
 * with `cld` before returning.  No C or C++ source can make the MSVC 6 compiler
 * emit `std`/`repnz scas`; the compiler only ever produces forward `repnz scas`
 * for the strlen intrinsic.  The closest genuine C reconstruction of the CRT
 * source is kept here for reference; it differs from the original at offset 0
 * (the original starts with the `push ebp; mov ebp,esp; push edi` frame).
 */
char *__cdecl _strrchr(const char *string, int ch)
{
    const char *start = string;

    while (*string++)
        ;
    while (--string != start && *string != (char)ch)
        ;
    if (*string == (char)ch)
        return (char *)string;
    return 0;
}
