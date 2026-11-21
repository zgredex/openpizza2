struct NamedLockable { void Construct(const char *name); };
extern char DAT_00579af0;
extern char STR_0056313c[];
void ListLock_Init(void) { ((NamedLockable*)&DAT_00579af0)->Construct(STR_0056313c); }
