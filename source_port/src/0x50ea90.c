// Player_Save: ported from Pizza Connection 2 at 0x50ea90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50ea90
#include "pc2_port.h"

void __thiscall Player_Save(void *self,void *arg1)

{
  void *this_00;
  void *this_01;
  void *pvVar1;
  void *local_4;
  
  this_00 = arg1;
  local_4 = self;
  CRT_Ostream_Write(arg1,(intptr_t)self + 0x84,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x88,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 8,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0xc,0x20);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x30,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x3c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x40,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x44,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x48,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x4c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x50,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x54,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x58,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x5c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x60,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 100,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x68,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x6c,0x18);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x34,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x38,4);
  Character_Save(*(void **)((intptr_t)self + 4),this_00);
  local_4 = *(void **)((intptr_t)self + 0xa0);
  CRT_Ostream_Write(this_00,&local_4,4);
  arg1 = (void *)0x0;
  if (0 < (intptr_t)local_4) {
    do {
      pvVar1 = this_00;
      this_01 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x8c),(intptr_t)arg1,(int *)0x0);
      Player_Event_Save(this_01,pvVar1);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < (intptr_t)local_4);
  }
  if (*(int *)((intptr_t)self + 0xa8) == 0) {
    arg1 = (void *)0x0;
    CRT_Ostream_Write(this_00,&arg1,4);
  }
  else {
    arg1 = (void *)0x1;
    CRT_Ostream_Write(this_00,&arg1,4);
    Player_AIState_Save(*(void **)((intptr_t)self + 0xa8),this_00);
  }
  if (*(int *)((intptr_t)self + 0xac) == 0) {
    arg1 = (void *)0x0;
    CRT_Ostream_Write(this_00,&arg1,4);
    return;
  }
  arg1 = (void *)0x1;
  CRT_Ostream_Write(this_00,&arg1,4);
  Player_MissionState_Save(*(void **)((intptr_t)self + 0xac),this_00);
  return;
}
