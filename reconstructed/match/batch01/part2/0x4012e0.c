extern void __fastcall NamedLockable_Destroy(void *);
extern void Mem_Free(void *);

void * __fastcall NamedLockable_Delete(void *this, int unused, unsigned char param_1)
{
  NamedLockable_Destroy(this);
  if ((param_1 & 1) != 0) {
    Mem_Free(this);
  }
  return this;
}
