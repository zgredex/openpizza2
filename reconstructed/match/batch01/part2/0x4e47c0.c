extern void __fastcall Ingredient_Destroy(void *);
extern void Mem_Free(void *);

void * __fastcall Ingredient_Delete(void *this, int unused, unsigned char param_1)
{
  Ingredient_Destroy(this);
  if ((param_1 & 1) != 0) {
    Mem_Free(this);
  }
  return this;
}
