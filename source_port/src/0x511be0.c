// Recipe_StreamConstruct: ported from Pizza Connection 2 at 0x511be0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x511be0
#include "pc2_port.h"


double __thiscall
Recipe_StreamConstruct
          (void *arg1,uint32_t arg2,int arg3,int arg4,int arg5,uint8_t arg6,
          int arg7)

{
  uint8_t uvalue1;
  short svalue2;
  void **ppvVar3;
  uint8_t flag4;
  uint32_t uvalue5;
  int value6;
  uint32_t *uptr7;
  uint8_t *bptr8;
  int value9;
  short local_a8;
  short local_a6;
  uint32_t local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  void *local_90;
  uint8_t local_8c [128];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a49e;
  local_c = ExceptionList;
  local_a4 = CONCAT31(((uint8_t)((local_a4) >> 24)),(char)*(uint32_t *)(arg4 + 0xd0) + -1);
  local_9c = *(int *)(arg4 + 0xac + (uint32_t)arg6 * 4);
  local_a0 = *(int *)(arg3 * 0x140 + 0x388 + DAT_0057c670) << 1;
  local_98 = local_a0 / arg7;
  bptr8 = local_8c;
  for (value6 = 0x20; value6 != 0; value6 = value6 + -1) {
    bptr8[0] = 0;
    bptr8[1] = 0;
    bptr8[2] = 0;
    bptr8[3] = 0;
    bptr8 = bptr8 + 4;
  }
  if (arg7 == 1) {
    ExceptionList = &local_c;
    uvalue5 = Random_RangeFast(0,7);
    local_8c[0] = (uint8_t)uvalue5;
  }
  else {
    value9 = 0;
    value6 = arg7 / 2;
    ExceptionList = &local_c;
    ppvVar3 = &local_c;
    if (0 < value6) {
      do {
        ExceptionList = ppvVar3;
        uvalue5 = Random_RangeFast(0,7);
        flag4 = (uint8_t)uvalue5;
        local_8c[value9] = flag4;
        if (flag4 < 4) {
          local_8c[value6 + value9] = flag4 + 4;
        }
        else {
          local_8c[value6 + value9] = flag4 - 4;
        }
        value9 = value9 + 1;
        ppvVar3 = ExceptionList;
      } while (value9 < value6);
    }
  }
  value6 = 0;
  if (0 < arg7) {
    local_94 = (local_a4 & 0xff) << 2;
    do {
      local_90 = operator_new(0x1c);
      uptr7 = (uint32_t *)0x0;
      local_4 = 0;
      if (local_90 != (void *)0x0) {
        uptr7 = RecipeTopping_StreamConstruct(local_90,(void *)0x0);
      }
      *(uint8_t *)(uptr7 + 1) = (uint8_t)local_a4;
      uvalue1 = *(uint8_t *)(arg4 + 0xa8);
      *(uint8_t *)(uptr7 + 4) = local_8c[value6];
      local_4 = 0xffffffff;
      *(uint8_t *)((intptr_t)uptr7 + 5) = uvalue1;
      *(uint8_t *)((intptr_t)uptr7 + 6) = arg6;
      List_Add((void *)((intptr_t)arg1 + 0x48),uptr7);
      arg5 = arg5 + local_98;
      if (local_a0 < arg5) {
        arg5 = arg5 - local_a0;
      }
      Stream_Seek(((arg3 +
                   ((uint32_t)*(uint8_t *)(uptr7 + 4) + ((uint32_t)*(uint8_t *)((intptr_t)uptr7 + 6) + local_94) * 8)
                   * 0xd) * 0x20 + arg5) * 4 + -0x84,*(int *)((intptr_t)arg1 + 0x310),0);
      Resource_Read(DAT_0057c5d8,(char *)&local_a6,2,*(int *)((intptr_t)arg1 + 0x310));
      Resource_Read(DAT_0057c5d8,(char *)&local_a8,2,*(int *)((intptr_t)arg1 + 0x310));
      uptr7[2] = (intptr_t)local_a6;
      uptr7[3] = (intptr_t)local_a8;
      value9 = (uint32_t)*(uint8_t *)(uptr7 + 4) + (uint32_t)*(uint8_t *)((intptr_t)uptr7 + 6) * 8;
      svalue2 = *(short *)(arg4 + 0x48 + value9 * 2);
      uptr7[5] = ((intptr_t)*(short *)(arg4 + 8 + value9 * 2) >> 1) + uptr7[2];
      uptr7[6] = ((intptr_t)svalue2 >> 1) + uptr7[3];
      Screen_AccumulateColorHistogram
                (arg1,(intptr_t)uptr7,*(int *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18));
      value6 = value6 + 1;
    } while (value6 < arg7);
  }
  ExceptionList = local_c;
  return (double)local_9c * (double)arg7;
}
