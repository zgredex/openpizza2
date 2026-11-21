/* PC2 byte-match candidate. Build with CL /O2 /TP; see worklog.md and
   verify.py for the exact matcher command and symbol addresses. */
struct NamedLockable {
    void Construct(const char *name);
};

extern "C" void __cdecl AnimCritical_Init(void)
{
    ((NamedLockable *)0x5842a0)->Construct((const char *)0x5744e0);
}
