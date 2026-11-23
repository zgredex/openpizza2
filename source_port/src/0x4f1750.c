// AI_ComputeWeightedPath: ported from Pizza Connection 2 at 0x4f1750.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f1750
#include "pc2_port.h"


uint32_t AI_ComputeWeightedPath(void)

{
  void *self;
  uint16_t uvalue1;
  int value2;
  int value3;
  uint16_t *uptr4;
  void *extraout_ECX;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint16_t *uptr8;
  int *ptr9;
  void *pvVar10;
  uint32_t *uptr11;
  int value12;
  uint32_t *uptr13;
  int value14;
  uint32_t *uptr15;
  uint8_t unaff_retaddr;
  uint32_t uvalue16;
  void *pvStack00000004;
  uint16_t *puStack00000008;
  uint32_t uStack0000000c;
  int iStack00000010;
  int *piStack0000001c;
  short *psStack00000020;
  uint32_t uStack00000024;
  uint32_t uStack00000028;
  uint16_t uStack0000002c;
  uint16_t uStack0000002e;
  uint16_t uStack00000030;
  int in_stack_00011c90;
  int in_stack_00011c94;
  void *in_stack_00011c98;
  int in_stack_00011c9c;
  uint16_t uStack_7ffffffe;
  uint32_t auStack_7ffffffc [536870905];
  
  __chkstk(unaff_retaddr);
  if (in_stack_00011c90 == in_stack_00011c94) {
    Object_ClearField4((intptr_t)in_stack_00011c98 + 0x14);
    return 1;
  }
  uptr8 = (uint16_t *)(uint32_t)*(uint16_t *)(in_stack_00011c90 + 4);
  uStack00000028 = CONCAT22(((uint16_t)((uStack00000028) >> 16)),*(uint16_t *)(in_stack_00011c94 + 4));
  uptr13 = (uint32_t *)((intptr_t)register0x00000010 + 0x610c);
  for (value5 = 12000; value5 != 0; value5 = value5 + -1) {
    *uptr13 = 0xffffffff;
    uptr13 = uptr13 + 1;
  }
  uStack0000000c = 1;
  pvStack00000004 = extraout_ECX;
  puStack00000008 = uptr8;
  value5 = Array_CountValid8(in_stack_00011c90);
  if (value5 == 0) {
    NoOp_Stub();
    return 0;
  }
  *(uint32_t *)((intptr_t)register0x00000010 + (intptr_t)uptr8 * 8 + 0x610c) = 0;
  *(uint16_t *)((intptr_t)register0x00000010 + (intptr_t)uptr8 * 8 + 0x6110) = 0;
  pvVar10 = extraout_ECX;
  while( true ) {
    uvalue16 = 0;
    if ((intptr_t)uStack0000000c < 1) break;
    piStack0000001c = (int *)((intptr_t)register0x00000010 + 0x34c);
    uStack00000024 = uStack0000000c;
    do {
      uvalue6 = uStack0000000c;
      value5 = *piStack0000001c;
      uvalue7 = *(uint32_t *)((intptr_t)register0x00000010 + value5 * 8 + 0x610c);
      value2 = Array_GetRecord28(pvVar10,in_stack_00011c9c,value5);
      if (*(char *)(value2 + 6) == '\x02') {
        value12 = *(int *)((intptr_t)pvVar10 + 0x130);
        value14 = 0;
        if (0 < value12) {
          uptr11 = (uint32_t *)((intptr_t)register0x00000010 + (uvalue16 + uvalue6) * 4 + 0x34c);
          do {
            value3 = IDMap_Lookup((void *)((intptr_t)pvVar10 + 0x11c),value14,(int *)0x0);
            if (value3 != value2) {
              uvalue6 = (uint32_t)*(uint16_t *)(value3 + 4);
              if (uvalue7 + 1 < *(uint32_t *)((intptr_t)register0x00000010 + uvalue6 * 8 + 0x610c)) {
                *(uint32_t *)((intptr_t)register0x00000010 + uvalue6 * 8 + 0x610c) = uvalue7 + 1;
                *(short *)((intptr_t)register0x00000010 + uvalue6 * 8 + 0x6110) = (short)value5;
                *uptr11 = uvalue6;
                uvalue16 = uvalue16 + 1;
                uptr11 = uptr11 + 1;
              }
            }
            value14 = value14 + 1;
          } while (value14 < value12);
        }
      }
      psStack00000020 = (short *)(value2 + 0x14);
      iStack00000010 = 8;
      ptr9 = (int *)((intptr_t)register0x00000010 + (uvalue16 + uStack0000000c) * 4 + 0x34c);
      do {
        if (*psStack00000020 != -1) {
          value12 = (intptr_t)*psStack00000020;
          uvalue6 = *(uint32_t *)((intptr_t)register0x00000010 + value12 * 8 + 0x610c);
          if (uvalue7 < uvalue6) {
            value14 = Array_GetRecord28(pvStack00000004,in_stack_00011c9c,value12);
            value14 = Object_Compare(pvStack00000004,value2,value14);
            if (value14 + uvalue7 < uvalue6) {
              *(uint32_t *)((intptr_t)register0x00000010 + value12 * 8 + 0x610c) = value14 + uvalue7;
              uvalue16 = uvalue16 + 1;
              *ptr9 = value12;
              *(short *)((intptr_t)register0x00000010 + value12 * 8 + 0x6110) = (short)value5;
              ptr9 = ptr9 + 1;
            }
          }
        }
        psStack00000020 = psStack00000020 + 1;
        iStack00000010 = iStack00000010 + -1;
      } while (iStack00000010 != 0);
      piStack0000001c = piStack0000001c + 1;
      uStack00000024 = uStack00000024 - 1;
      pvVar10 = pvStack00000004;
    } while (uStack00000024 != 0);
    uptr8 = puStack00000008;
    if (uvalue16 == 0) break;
    uptr13 = (uint32_t *)((intptr_t)register0x00000010 + uStack0000000c * 4 + 0x34c);
    uptr15 = (uint32_t *)((intptr_t)register0x00000010 + 0x34c);
    for (uvalue7 = uvalue16 & 0x3fffffff; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
      *uptr15 = *uptr13;
      uptr13 = uptr13 + 1;
      uptr15 = uptr15 + 1;
    }
    for (value5 = 0; value5 != 0; value5 = value5 + -1) {
      *(uint8_t *)uptr15 = *(uint8_t *)uptr13;
      uptr13 = (uint32_t *)((intptr_t)uptr13 + 1);
      uptr15 = (uint32_t *)((intptr_t)uptr15 + 1);
    }
    uStack0000000c = uvalue16;
  }
  value5 = (uStack00000028 & 0xffff) * 8;
  if (*(int *)((intptr_t)register0x00000010 + value5 + 0x610c) == -1) {
    return 0;
  }
  uStack0000002c = (short)uStack00000028;
  uStack0000002e = *(uint16_t *)((intptr_t)register0x00000010 + value5 + 0x6110);
  uptr4 = (uint16_t *)(uint32_t)uStack0000002e;
  value5 = 2;
  if (uptr4 != uptr8) {
    puStack00000008 = &uStack00000030;
    do {
      if (399 < value5) {
        NoOp_Stub();
      }
      value5 = value5 + 1;
      uvalue1 = *(uint16_t *)((intptr_t)register0x00000010 + (intptr_t)uptr4 * 8 + 0x6110);
      uptr4 = (uint16_t *)(uint32_t)uvalue1;
      *puStack00000008 = uvalue1;
      puStack00000008 = puStack00000008 + 1;
    } while (uptr4 != uptr8);
  }
  self = (void *)((intptr_t)in_stack_00011c98 + 0x14);
  Object_ClearField4((intptr_t)self);
  if (0 < value5) {
    uptr8 = (uint16_t *)((intptr_t)&uStack00000028 + value5 * 2 + 2);
    do {
      value2 = Array_GetRecord28(pvVar10,in_stack_00011c9c,(uint32_t)*uptr8);
      Array_Grow(self,value2);
      uptr8 = uptr8 + -1;
      value5 = value5 + -1;
    } while (value5 != 0);
  }
  Object_SetShort28(in_stack_00011c98,0);
  return 1;
}
