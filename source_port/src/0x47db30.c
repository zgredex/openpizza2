// Game_CollectObjectsAtPoint: ported from Pizza Connection 2 at 0x47db30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x47db30
#include "pc2_port.h"

void __thiscall Game_CollectObjectsAtPoint(void *self,void *arg1,int arg2,int arg3)

{
  int *ptr1;
  int value2;
  int value3;
  uint8_t *uptr4;
  void *pvVar5;
  uint32_t local_24;
  int local_20;
  uint32_t local_1c;
  int local_18;
  void *local_14;
  int local_10;
  void *local_c;
  int local_8;
  int local_4;
  
  local_c = self;
  CS_Enter(*(int *)(DAT_0057c670 + 0x244));
  pvVar5 = *(void **)((intptr_t)self + 0x16f0);
  local_10 = 0;
  local_14 = pvVar5;
  if (0 < *(int *)((intptr_t)pvVar5 + 0x8c)) {
    do {
      value2 = Game_MapRecordToGlobal(pvVar5,local_10);
      value3 = State_Is2DOr2E(value2);
      if (value3 == 0) {
        switch(*(uint32_t *)(value2 + 0x30)) {
        case 0xd:
        case 0xe:
        case 0x20:
        case 0x29:
        case 0x2a:
        case 0x2b:
        case 0x2c:
        case 0x2d:
        case 0x2e:
        case 0x2f:
          goto switchD_0047db9b_caseD_d;
        default:
          goto switchD_0047db9b_caseD_f;
        case 0x11:
        case 0x12:
        case 0x13:
        case 0x14:
          value3 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)(value2 + 0x50),(int *)0x0);
          value3 = *(int *)(value3 + 0x81c);
          break;
        case 0x17:
        case 0x1d:
        case 0x1e:
        case 0x1f:
          value3 = *(int *)(value2 + 0x110);
        }
        if (value3 != -1) {
switchD_0047db9b_caseD_f:
          ptr1 = *(int **)(value2 + 200);
          if (ptr1 != (int *)0x0) {
            pvVar5 = (void *)ptr1[0x16];
            value3 = *ptr1;
            Record_GetTwoFloats48(pvVar5,value3,&local_20,&local_18);
            Record_GetBounds48(pvVar5,value3,&local_8,&local_4,&local_24,&local_1c);
            Record_GetScreenRect48(pvVar5,value3,(int *)&local_24,(int *)&local_1c);
            local_20 = local_20 + (local_24 - *(int *)(*(int *)((intptr_t)local_c + 0x14e0) + 0x24));
            local_18 = local_18 + (local_1c - *(int *)(*(int *)((intptr_t)local_c + 0x14e0) + 0x28));
            if ((((local_20 <= arg2) && (arg2 <= local_8 + local_20)) && (local_18 <= arg3)
                ) && (arg3 <= local_4 + local_18)) {
              uptr4 = operator_new(8);
              *uptr4 = 1;
              *(int *)(uptr4 + 4) = value2;
              List_Add(arg1,uptr4);
            }
            pvVar5 = local_14;
          }
        }
      }
switchD_0047db9b_caseD_d:
      local_10 = local_10 + 1;
    } while (local_10 < *(int *)((intptr_t)pvVar5 + 0x8c));
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x244));
  return;
}
