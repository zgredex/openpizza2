/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
struct NamedLockable {
    void Construct(const char *name);
};

extern "C" void __cdecl SpriteCriticalSection_Init(void)
{
    ((NamedLockable *)0x585520)->Construct((const char *)0x5747c4);
}
