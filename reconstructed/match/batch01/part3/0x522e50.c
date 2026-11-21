/* ArrayLock_Init - 0x522e50, 16 bytes */
struct NamedLockable
{
    void Construct(const char *name);
};

extern char DAT_00584180;
extern char STR_0056313c[];

void __cdecl ArrayLock_Init(void)
{
    ((NamedLockable *)&DAT_00584180)->Construct(STR_0056313c);
}
