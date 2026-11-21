/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
struct GameClock {
    void Destroy(void);
    void *Delete(unsigned char flag);
};

extern "C" void __cdecl Mem_Free(void *p);

void *GameClock::Delete(unsigned char flag)
{
    Destroy();
    if (flag & 1)
        Mem_Free(this);
    return this;
}
