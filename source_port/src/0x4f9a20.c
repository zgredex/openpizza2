// AI_SelectBestPlan: ported from Pizza Connection 2 at 0x4f9a20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f9a20
#include "pc2_port.h"

int AI_SelectBestPlan(uint32_t arg1,int arg2,int arg3,int *arg4,uint32_t *arg5,int arg6,
                     int arg7)

{
  void *pvVar1;
  int value2;
  uint32_t uvalue3;
  int local_90;
  void *local_8c;
  int local_88;
  void **local_84;
  int local_80;
  uint32_t local_7c;
  void *local_78 [30];
  
  uvalue3 = 0;
  local_7c = *(uint32_t *)(arg3 + 0x14);
  local_8c = (void *)0x0;
  local_90 = 0;
  if (*(int *)(DAT_0057c670 + 0x88) < 1) {
    return -1;
  }
  local_84 = local_78;
  do {
    if (0x1d < (intptr_t)uvalue3) break;
    pvVar1 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),local_90,(int *)0x0);
    if ((*(uint32_t *)((intptr_t)pvVar1 + 0xc) == (arg1 & 0xff)) &&
       (((arg2 == 4 || (*(int *)((intptr_t)pvVar1 + 0x10) == 4)) ||
        (*(int *)((intptr_t)pvVar1 + 0x10) == arg2)))) {
      Object_GetPair68(pvVar1,&local_88,&local_80);
      if (arg6 == -1) {
        if ((arg7 != -1) && (value2 = local_80, arg7 != local_88)) {
joined_r0x004f9afe:
          if (arg7 != value2) goto LAB_004f9b31;
        }
      }
      else if (((arg7 != -1) || ((arg6 != local_88 && (arg6 != local_80)))) &&
              ((arg6 != local_88 || (arg7 != local_80)))) {
        value2 = local_88;
        if (arg6 == local_80) goto joined_r0x004f9afe;
        goto LAB_004f9b31;
      }
      if (local_8c == (void *)0x0) {
        local_8c = pvVar1;
      }
      if (((local_7c == 0xffffffff) || (*(uint8_t *)((intptr_t)pvVar1 + 0x14) == 4)) ||
         (*(uint8_t *)((intptr_t)pvVar1 + 0x14) == local_7c)) {
        uvalue3 = uvalue3 + 1;
        *local_84 = pvVar1;
        local_84 = local_84 + 1;
      }
    }
LAB_004f9b31:
    local_90 = local_90 + 1;
  } while (local_90 < *(int *)(DAT_0057c670 + 0x88));
  if (uvalue3 == 0) {
    if (local_8c == (void *)0x0) {
      return -1;
    }
    local_78[0] = local_8c;
    uvalue3 = 1;
  }
  uvalue3 = Random_Mod(uvalue3);
  pvVar1 = local_78[uvalue3];
  value2 = Map_FindIndex((void *)(DAT_0057c670 + 0x74),(intptr_t)pvVar1);
  *arg4 = value2;
  uvalue3 = Array_FindEmptySlot8((intptr_t)pvVar1);
  *arg5 = uvalue3;
  if (*(int *)(arg3 + 0x1c) == 0) {
    value2 = *(int *)(arg3 + 0x20);
    if (value2 == -1) {
      uvalue3 = Random_Mod(uvalue3);
    }
    else if (value2 < (intptr_t)uvalue3) {
      return (intptr_t)*(short *)((intptr_t)pvVar1 + (value2 * 3 + 0x1e) * 4);
    }
  }
  else if (7 < (intptr_t)uvalue3) {
    return (intptr_t)*(short *)((intptr_t)pvVar1 + 0xcc);
  }
  return (intptr_t)*(short *)((intptr_t)pvVar1 + (uvalue3 * 3 + 0x1e) * 4);
}
