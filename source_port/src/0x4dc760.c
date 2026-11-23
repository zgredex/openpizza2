// Map_SpawnAdvertisingZeppelin: ported from Pizza Connection 2 at 0x4dc760.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4dc760
#include "pc2_port.h"

void __thiscall Map_SpawnAdvertisingZeppelin(void *self,uint32_t arg1)

{
  void *this_00;
  int value1;
  int value2;
  int value3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint32_t local_18;
  uint32_t local_14;
  uint32_t local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Spawns the advertising zeppelin at a random screen edge. */
  this_00 = *(void **)(DAT_0057c5cc + 0x2c3d4);
  value1 = *(int *)(DAT_0057c5cc + 0x2c41c + arg1 * 4);
  local_4 = value1;
  Record_GetBounds48(this_00,value1,&local_c,&local_8,&local_14,&local_10);
  Record_GetScreenRect48(this_00,value1,(int *)&local_14,(int *)&local_10);
  uvalue4 = Random_RangeFast(0,3);
  switch(uvalue4) {
  case 0:
    value1 = *(int *)((intptr_t)self + 0xfa8);
    value3 = *(int *)(value1 + 0x30);
    local_18 = (*(int *)(value1 + 0x2c) - local_c) - local_14;
    uvalue4 = *(int *)(value1 + 0x38) + DAT_0057195c;
    uvalue5 = Random_RangeFast(value3,uvalue4);
    *(uint32_t *)(DAT_0057c670 + 0x36c + arg1 * 4) = 4;
    uvalue4 = (((intptr_t)uvalue5 <= (intptr_t)(uvalue4 - value3) / 2 + value3) - 1 & 2) + 2;
    arg1 = uvalue5;
    break;
  case 1:
    value1 = *(int *)((intptr_t)self + 0xfa8);
    value3 = *(int *)(value1 + 0x30);
    local_18 = *(int *)(value1 + 0x34) + DAT_00571958;
    uvalue4 = *(int *)(value1 + 0x38) + DAT_0057195c;
    uvalue5 = Random_RangeFast(value3,uvalue4);
    *(uint32_t *)(DAT_0057c670 + 0x36c + arg1 * 4) = 3;
    uvalue4 = ((intptr_t)uvalue5 <= (intptr_t)(uvalue4 - value3) / 2 + value3) - 1 & 6;
    arg1 = uvalue5;
    break;
  case 2:
    value1 = *(int *)((intptr_t)self + 0xfa8);
    value3 = *(int *)(value1 + 0x30);
    value2 = *(int *)(value1 + 0x2c);
    uvalue4 = *(int *)(value1 + 0x34) + DAT_00571958;
    local_18 = Random_RangeFast(value2,uvalue4);
    *(uint32_t *)(DAT_0057c670 + 0x36c + arg1 * 4) = 1;
    uvalue4 = (((intptr_t)local_18 <= (intptr_t)(uvalue4 - value2) / 2 + value2) - 1 & 0xfffffffe) + 2;
    arg1 = (value3 - local_8) - local_10;
    break;
  case 3:
    value1 = *(int *)((intptr_t)self + 0xfa8);
    value3 = *(int *)(value1 + 0x2c);
    uvalue5 = *(int *)(value1 + 0x38) + DAT_0057195c;
    uvalue4 = *(int *)(value1 + 0x34) + DAT_00571958;
    local_18 = Random_RangeFast(value3,uvalue4);
    *(uint32_t *)(DAT_0057c670 + 0x36c + arg1 * 4) = 2;
    uvalue4 = (((intptr_t)local_18 <= (intptr_t)(uvalue4 - value3) / 2 + value3) - 1 & 2) + 4;
    arg1 = uvalue5;
    break;
  default:
    uvalue4 = arg1;
  }
  value1 = local_4;
  Record_SetRect48((intptr_t)this_00,local_4,SUB84((double)(intptr_t)local_18,0),
                   (intptr_t)((uint64_t)(double)(intptr_t)local_18 >> 0x20),(double)(intptr_t)arg1);
  Record_SelectVariant(this_00,value1,uvalue4);
  return;
}
