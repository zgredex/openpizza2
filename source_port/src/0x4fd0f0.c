// Player_BuildHeadquarters: ported from Pizza Connection 2 at 0x4fd0f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fd0f0
#include "pc2_port.h"

void Player_BuildHeadquarters(int arg1,void *arg2,void *arg3,int arg4,int arg5)

{
  int value1;
  uint32_t uvalue2;
  
                    /* Starts headquarters construction or upgrade. */
  Game_AcquireStateLock(DAT_0057c670,0);
  value1 = *(int *)((intptr_t)arg3 + 0x48);
  if ((-1 < value1) && (value1 < 4)) {
    value1 = *(int *)(&DAT_00568188 + value1 * 4);
  }
  if (arg5 == 0) {
    uvalue2 = 4;
  }
  else {
    uvalue2 = 6;
  }
  MapObject_SpawnByKind(arg2,arg3,uvalue2,arg1,(void *)0x1c,value1 + 0x818 + arg4 * 4);
  *(uint32_t *)(*(int *)((intptr_t)arg2 + 0xfa8) + 0xf4) = 1;
  *(uint32_t *)((intptr_t)arg3 + 0x4c) = 0;
  *(uint32_t *)((intptr_t)arg3 + 0x50) = 0;
  value1 = Game_GetPlayerBySlot(DAT_0057c670,arg1);
  *(void **)(value1 + 0x1d8) = arg3;
  Window_UnlockState((intptr_t)DAT_0057c670);
  return;
}
