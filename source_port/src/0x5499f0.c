// Sound_ProcessEvent: ported from Pizza Connection 2 at 0x5499f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5499f0
#include "pc2_port.h"


void __thiscall Sound_ProcessEvent(void *self,int arg1,uint32_t arg2,char arg3)

{
  int value1;
  bool flag2;
  uint8_t **pptr3;
  uint8_t *local_108;
  uint8_t local_104 [260];
  
  local_108 = (uint8_t *)0x0;
  if (*(char *)((intptr_t)self + 0xfc) == '\0') {
    return;
  }
  switch(arg2) {
  case 0:
    if (((arg1 == 0x21) || (arg1 == 0xf)) && (arg3 == '\0')) {
      return;
    }
    pptr3 = &local_108;
    value1 = 0;
    goto LAB_00549d28;
  case 1:
    value1 = 1;
    if (arg1 != 0x14) goto LAB_00549d1d;
    local_108 = &DAT_0056421c;
    break;
  case 2:
    value1 = 1;
    if (arg1 != 0x14) goto LAB_00549da8;
LAB_00549a92:
    value1 = 1;
    local_108 = &DAT_00564dcc;
    break;
  case 3:
    if (arg1 != 0x14) goto LAB_00549a92;
LAB_00549ab0:
    value1 = 1;
    local_108 = &DAT_005762dc;
    break;
  case 4:
    if (arg1 != 0x14) goto LAB_00549ab0;
LAB_00549ace:
    value1 = 1;
    local_108 = &DAT_00564218;
    break;
  case 5:
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    if (0 < *(int *)((intptr_t)self + 0x154)) {
      return;
    }
    *(uint32_t *)((intptr_t)self + 0x154) = 7;
    if (arg1 != 0x14) goto LAB_00549ace;
LAB_00549b16:
    value1 = 1;
    local_108 = &DAT_005762d8;
    break;
  case 6:
    value1 = 1;
    if (arg1 != 0x14) goto LAB_00549b16;
    local_108 = &DAT_005762d4;
    break;
  case 7:
    value1 = 1;
    if (arg1 != 0x14) {
      return;
    }
    goto LAB_00549d1d;
  case 8:
    if (arg3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    value1 = 0;
    switch(arg1) {
    case 0xd:
      value1 = 3;
      break;
    case 0x17:
      value1 = 0;
      break;
    case 0x1d:
      value1 = 2;
      break;
    case 0x1e:
      value1 = 1;
    }
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x7c))
              (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + value1 * 8 + 0x244),
               *(uint32_t *)((intptr_t)self + 0x1d8));
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x5c))
              (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + value1 * 8 + 0x244),0);
    return;
  case 9:
    if (arg3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    value1 = 0;
    switch(arg1) {
    case 0xd:
      value1 = 3;
      break;
    case 0x17:
      value1 = 0;
      break;
    case 0x1d:
      value1 = 2;
      break;
    case 0x1e:
      value1 = 1;
    }
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x7c))
              (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + value1 * 8 + 0x248),
               *(uint32_t *)((intptr_t)self + 0x1d8));
    (**(code **)(**(int **)((intptr_t)self + 8) + 0x5c))
              (*(int **)((intptr_t)self + 8),*(uint32_t *)((intptr_t)self + value1 * 8 + 0x248),0);
    return;
  case 10:
    if (arg3 == '\0') {
      return;
    }
    value1 = 2;
    if (arg1 != 0xd) {
      return;
    }
    goto LAB_00549d1d;
  case 0xb:
    if (arg3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    value1 = 3;
    if (arg1 != 10) {
      return;
    }
    goto LAB_00549d1d;
  case 0xc:
    if (arg3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    value1 = 3;
    if (arg1 != 10) {
      return;
    }
    local_108 = &DAT_0056421c;
    break;
  case 0xd:
    if (arg3 == '\0') {
      return;
    }
    flag2 = arg1 == 0x18;
LAB_00549d1b:
    value1 = 3;
    if (!flag2) {
      return;
    }
    goto LAB_00549d1d;
  case 0xe:
    if (arg3 == '\0') {
      return;
    }
    value1 = 3;
    if (arg1 != 0x18) {
      return;
    }
LAB_00549da8:
    local_108 = &DAT_0056421c;
    break;
  case 0xf:
    if (arg3 == '\0') {
      return;
    }
    if (*(int *)(DAT_0057c670 + 0x290) != 4) {
      return;
    }
    value1 = 3;
    if (arg1 != 0x20) {
      flag2 = arg1 == 0xe;
      goto LAB_00549d1b;
    }
LAB_00549d1d:
    local_108 = &DAT_005762b4;
    break;
  default:
    goto switchD_00549a28_default;
  }
  pptr3 = (uint8_t **)0x0;
LAB_00549d28:
  pptr3 = Employee_GetProfessionName(self,arg1,value1,pptr3);
  if (pptr3 != (uint8_t **)0x0) {
    value1 = (intptr_t)self + 0x174;
    if (((uint8_t)((DAT_00575090) >> 8)) != '\0') {
      value1 = DAT_00582530;
    }
    String_Format(local_104,(uint8_t *)s_Speech__s__s__s__s_wav_005762b8,value1);
    Sound_PlayChannel(self,local_104,3);
  }
switchD_00549a28_default:
  return;
}
