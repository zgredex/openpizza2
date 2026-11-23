// Branch_ValidatePersonnelList: ported from Pizza Connection 2 at 0x47fa40.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47fa40
#include "pc2_port.h"

uint32_t __fastcall Branch_ValidatePersonnelList(void *arg1)

{
  int value1;
  void *pvVar2;
  void *self;
  int value3;
  int value4;
  
                    /* Validates a branch's personnel list and resets invalid branches. */
  if (*(int *)((intptr_t)arg1 + 0x2c) != 0) {
    value1 = *(int *)(*(int *)((intptr_t)arg1 + 0x16f0) + 0x8c);
    value4 = value1;
    while (value4 = value4 + -1, -1 < value4) {
      pvVar2 = (void *)Game_MapRecordToGlobal(*(void **)((intptr_t)arg1 + 0x16f0),value4);
      if (*(int *)((intptr_t)pvVar2 + 0x74) == 0) {
        DebugConsole_Printf(DAT_0057c1e0,0xff,(uint8_t *)s_Falsche_Personenliste_____s__00567d14,
                            (intptr_t)pvVar2 + 4);
        Game_RemoveObjectFromList(*(void **)((intptr_t)arg1 + 0x16f0),pvVar2,0);
      }
      else {
        value3 = *(int *)((intptr_t)pvVar2 + 0x30);
        if (((value3 < 0x2b) || (0x2f < value3)) && ((value3 < 0x1a || (0x1c < value3)))) break;
      }
    }
    if (value4 == -1) {
      if (*(int *)((intptr_t)arg1 + 0x2c) != 6) {
        if (*(int *)((intptr_t)arg1 + 0x2c) != 7) {
          Branch_HandleBuildCommand(arg1);
          return 0;
        }
        pvVar2 = *(void **)((intptr_t)arg1 + 0x16f0);
        self = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                    (int *)0x0);
        City_CreateExplosionEffect(self,1,0x2e,pvVar2);
      }
      return 1;
    }
    value4 = 0;
    if (0 < value1) {
      do {
        value3 = Game_MapRecordToGlobal(*(void **)((intptr_t)arg1 + 0x16f0),value4);
        value4 = value4 + 1;
        *(uint8_t *)(value3 + 0x81) = 1;
      } while (value4 < value1);
    }
  }
  return 0;
}
