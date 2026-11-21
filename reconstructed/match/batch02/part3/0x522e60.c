extern int _atexit(void (__cdecl *func)(void));
extern void dtor_00522e70(void);

void Atexit_RegisterListCritSectDtor(void)
{
    _atexit(dtor_00522e70);
}
