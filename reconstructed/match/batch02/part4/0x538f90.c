/* PC2 byte-match candidate: Surface_LockPrimary (0x538f90, 10 bytes).
   Build: /O2 /TP; entry _Surface_LockPrimary. */
struct Surface {
    void Lock(int left, int top);
};

extern "C" void __fastcall Surface_LockPrimary(Surface *surface)
{
    surface->Lock(0, 0);
}
