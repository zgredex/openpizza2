/* AnimSwapCritical_Init - 0x532bb0, 16 bytes */
struct NamedLockable
{
    void Construct(const char *name);
};

extern char DAT_00584248;
extern char STR_005744cc[];

void __cdecl AnimSwapCritical_Init(void)
{
    ((NamedLockable *)&DAT_00584248)->Construct(STR_005744cc);
}
