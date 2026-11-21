extern void __fastcall Player_MissionState_Destructor(void *);
extern void Mem_Free(void *);

void * __fastcall Player_MissionState_Delete(void *this, int unused, unsigned char param_1)
{
  Player_MissionState_Destructor(this);
  if ((param_1 & 1) != 0) {
    Mem_Free(this);
  }
  return this;
}
