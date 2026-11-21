/* First attempt for 0x4b0d40 - does not match.
 * A C __fastcall declaration needs a dummy second parameter to keep the
 * stream in ecx, but the explicit 0 argument is then emitted as
 * "xor edx,edx", shifting the call.  The matched candidate models the
 * CRT stream as a C++ class instead.
 */
extern void __fastcall CRT_Istream_Read(void *stream, int unused, void *dest,
                                        int size);
extern char DAT_0056a6d8;

void Personnel_Load(void *stream)
{
    CRT_Istream_Read(stream, 0, &DAT_0056a6d8, 4);
}
