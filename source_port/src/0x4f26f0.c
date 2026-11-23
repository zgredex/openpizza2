// CityAds_UpdateCampaign: ported from Pizza Connection 2 at 0x4f26f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f26f0
#include "pc2_port.h"

/* WARNING (jumptable): Unable to track spacebase fully for stack */

void __fastcall CityAds_UpdateCampaign(void *arg1)

{
  void *self;
  uint32_t uvalue1;
  int value2;
  int value3;
  int value4;
  void *this_00;
  uint32_t *uptr5;
  uint32_t unaff_EDI;
  int64_t lvalue6;
  uint32_t local_30;
  uint32_t local_2c;
  int local_28;
  int local_24;
  int local_20;
  uint32_t local_1c;
  uint32_t local_18 [2];
  uint32_t local_10 [3];
  
                    /* Updates a city advertising campaign and bills its owner. */
  uptr5 = *(uint32_t **)((intptr_t)arg1 + 0xbc);
  if (uptr5 != (uint32_t *)0x0) {
    DAT_00580a5c = timeGetTime();
    do {
      Object_UpdateWalkStep(arg1,uptr5,DAT_00580a5c);
      uptr5 = (uint32_t *)uptr5[0x1c];
    } while (uptr5 != (uint32_t *)0x0);
    self = *(void **)(*(int *)((intptr_t)arg1 + 4) + 0x2c3d4);
    if (*(int *)((intptr_t)arg1 + 0xc) == 0x40) {
      local_28 = 0x36c;
      local_1c = 0;
      do {
        value4 = *(int *)(local_28 + 0x2c0b0 + *(int *)((intptr_t)arg1 + 4));
        if (((value4 < 0) || (*(int *)((intptr_t)self + 0x48) <= value4)) ||
           (*(char *)(*(int *)((intptr_t)self + 0x4c) + 0x3e + value4 * 0x48) == '\0')) goto LAB_004f298a;
        RecordList_TickFrameAndGetPoints(self,value4,local_18,local_10);
        lvalue6 = __ftol();
        value2 = (intptr_t)lvalue6;
        lvalue6 = __ftol();
        value3 = (intptr_t)lvalue6;
        Record_GetBounds48(self,value4,&local_20,&local_24,&local_2c,&local_30);
        Record_GetScreenRect48(self,value4,(int *)&local_2c,(int *)&local_30);
        switch(*(uint32_t *)(local_28 + (intptr_t)DAT_0057c670)) {
        case 1:
          if ((value2 <= *(int *)((intptr_t)arg1 + 0x34) + DAT_00571958) &&
             (value3 <= *(int *)((intptr_t)arg1 + 0x38) + DAT_0057195c)) {
LAB_004f2870:
            if ((intptr_t)((*(int *)((intptr_t)arg1 + 0x2c) - local_20) - local_2c) <= value2) break;
          }
          goto LAB_004f28fa;
        case 2:
          if ((*(int *)((intptr_t)arg1 + 0x34) + DAT_00571958 < value2) ||
             ((value3 < (intptr_t)((*(int *)((intptr_t)arg1 + 0x30) - local_24) - local_30) ||
              (value2 < (intptr_t)((*(int *)((intptr_t)arg1 + 0x2c) - local_20) - local_2c)))))
          goto LAB_004f28fa;
          break;
        case 3:
          if ((value3 <= *(int *)((intptr_t)arg1 + 0x38) + DAT_0057195c) &&
             ((intptr_t)((*(int *)((intptr_t)arg1 + 0x30) - local_24) - local_30) <= value3))
          goto LAB_004f2870;
LAB_004f28fa:
          Record_ClearFlags48(self,value4);
          uvalue1 = local_1c;
          *(uint32_t *)(local_28 + (intptr_t)DAT_0057c670) = 0xffffffff;
          value4 = Game_GetPlayerBySlot(DAT_0057c670,local_1c);
          value4 = Player_GetFirstRecordType1(value4);
          if ((value4 == 0) || (*(int *)(value4 + 4) == 0)) {
            DebugConsole_Printf(DAT_0057c1e0,0xa000,(uint8_t *)s_Ende_Stadtwerbung_00571cd4,unaff_EDI);
          }
          else {
            DebugConsole_Printf(DAT_0057c1e0,0xa000,&DAT_00571ce8,unaff_EDI);
            this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),
                                           *(int *)((intptr_t)DAT_0057c670 + 0x2f4),(int *)0x0);
            Map_SpawnAdvertisingZeppelin(this_00,uvalue1);
          }
          break;
        case 4:
          if (((*(int *)((intptr_t)arg1 + 0x34) + DAT_00571958 < value2) ||
              (*(int *)((intptr_t)arg1 + 0x38) + DAT_0057195c < value3)) ||
             (value3 < (intptr_t)((*(int *)((intptr_t)arg1 + 0x30) - local_24) - local_30)))
          goto LAB_004f28fa;
        }
LAB_004f298a:
        local_28 = local_28 + 4;
        local_1c = local_1c + 1;
      } while (local_28 < 900);
    }
  }
  return;
}
