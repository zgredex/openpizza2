// Game_HandleObjectDeath: ported from Pizza Connection 2 at 0x48c860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48c860
#include "pc2_port.h"

void __thiscall Game_HandleObjectDeath(void *self,void *arg1)

{
  int value1;
  uint32_t unaff_EDI;
  char *cptr2;
  
  if (*(void **)((intptr_t)self + 0x21c) == arg1) {
    UI_QueueControlCommand(*(void **)((intptr_t)self + 0x25c),-0x18624,0x23,0);
    *(uint32_t *)((intptr_t)self + 0x21c) = 0;
    *(uint32_t *)((intptr_t)self + 0x2da8) = 1;
  }
  value1 = *(int *)((intptr_t)arg1 + 0x30);
  if (value1 == 0xd) {
    cptr2 = s_Polizei_tot_00568330;
  }
  else if (value1 == 0x17) {
    cptr2 = s_Wache_tot_0056833c;
  }
  else {
    if (value1 != 0x1d) goto LAB_0048c8e8;
    cptr2 = s_Gangster_tot_00568348;
  }
  DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)cptr2,unaff_EDI);
LAB_0048c8e8:
  UI_ShiftChildRect((intptr_t)arg1);
  *(uint32_t *)((intptr_t)arg1 + 0x30) = 0x23;
  Object_SetState(arg1,2);
  Object_SetFlag104(arg1,1);
  *(uint32_t *)((intptr_t)arg1 + 0x74) = 0;
  UI_DestroyChildObject((intptr_t)arg1);
  return;
}
