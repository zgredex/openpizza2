extern void __fastcall AwardNode_Destructor(void *);
extern void Mem_Free(void *);

void * __fastcall AwardNode_Delete(void *this, int unused, unsigned char param_1)
{
  AwardNode_Destructor(this);
  if ((param_1 & 1) != 0) {
    Mem_Free(this);
  }
  return this;
}
