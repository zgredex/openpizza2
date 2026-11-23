// Map_FindShortestPath: ported from Pizza Connection 2 at 0x4f14a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f14a0
#include "pc2_port.h"

int Map_FindShortestPath(void)

{
  uint16_t uvalue1;
  void *pvVar2;
  int value3;
  int value4;
  void *extraout_ECX;
  int value5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint16_t *uptr8;
  int *ptr9;
  uint32_t *uptr10;
  int value11;
  uint32_t *uptr12;
  int value13;
  uint32_t *uptr14;
  uint8_t unaff_retaddr;
  uint32_t uvalue15;
  uint32_t uStack00000004;
  int iStack00000008;
  void *pvStack0000000c;
  int *piStack00000010;
  uint32_t uStack00000014;
  short *psStack0000001c;
  uint32_t uStack00000020;
  uint32_t uStack00000024;
  int iStack0000002c;
  int in_stack_00011970;
  int in_stack_00011974;
  uint16_t *in_stack_00011978;
  uint16_t uStack_7ffffffe;
  uint32_t auStack_7ffffffc [536870905];
  
  __chkstk(unaff_retaddr);
  uvalue6 = (uint32_t)*(uint16_t *)(in_stack_00011970 + 4);
  uvalue1 = *(uint16_t *)(in_stack_00011974 + 4);
  uptr12 = (uint32_t *)((intptr_t)register0x00000010 + 0x5dec);
  for (value5 = 12000; value5 != 0; value5 = value5 + -1) {
    *uptr12 = 0xffffffff;
    uptr12 = uptr12 + 1;
  }
  uStack00000004 = 1;
  pvStack0000000c = extraout_ECX;
  uStack00000024 = uvalue6;
  iStack0000002c = uvalue6;
  value5 = Array_CountValid8(in_stack_00011970);
  if (value5 == 0) {
    return 0;
  }
  *(uint32_t *)((intptr_t)register0x00000010 + uvalue6 * 8 + 0x5dec) = 0;
  *(uint16_t *)((intptr_t)register0x00000010 + uvalue6 * 8 + 0x5df0) = 0;
  while( true ) {
    uvalue15 = 0;
    if ((intptr_t)uStack00000004 < 1) break;
    piStack00000010 = &iStack0000002c;
    uStack00000020 = uStack00000004;
    do {
      pvVar2 = pvStack0000000c;
      uvalue6 = uStack00000004;
      value5 = *piStack00000010;
      uStack00000014 = *(uint32_t *)((intptr_t)register0x00000010 + value5 * 8 + 0x5dec);
      value3 = Array_GetRecord28(pvStack0000000c,1,value5);
      if (*(char *)(value3 + 6) == '\x02') {
        value11 = *(int *)((intptr_t)pvVar2 + 0x130);
        value13 = 0;
        if (0 < value11) {
          uptr10 = (uint32_t *)((intptr_t)&iStack0000002c + (uvalue15 + uvalue6) * 4);
          do {
            value4 = IDMap_Lookup((void *)((intptr_t)pvVar2 + 0x11c),value13,(int *)0x0);
            if (value4 != value3) {
              uvalue6 = (uint32_t)*(uint16_t *)(value4 + 4);
              if (uStack00000014 + 1 < *(uint32_t *)((intptr_t)register0x00000010 + uvalue6 * 8 + 0x5dec)) {
                *(uint32_t *)((intptr_t)register0x00000010 + uvalue6 * 8 + 0x5dec) = uStack00000014 + 1;
                *(short *)((intptr_t)register0x00000010 + uvalue6 * 8 + 0x5df0) = (short)value5;
                *uptr10 = uvalue6;
                uvalue15 = uvalue15 + 1;
                uptr10 = uptr10 + 1;
              }
            }
            value13 = value13 + 1;
          } while (value13 < value11);
        }
      }
      psStack0000001c = (short *)(value3 + 0x14);
      iStack00000008 = 8;
      ptr9 = (int *)((intptr_t)&iStack0000002c + (uvalue15 + uStack00000004) * 4);
      do {
        if (*psStack0000001c != -1) {
          value11 = (intptr_t)*psStack0000001c;
          uvalue6 = *(uint32_t *)((intptr_t)register0x00000010 + value11 * 8 + 0x5dec);
          if (uStack00000014 < uvalue6) {
            value13 = Array_GetRecord28(pvStack0000000c,1,value11);
            value13 = Object_Compare(pvStack0000000c,value3,value13);
            if (value13 + uStack00000014 < uvalue6) {
              *(uint32_t *)((intptr_t)register0x00000010 + value11 * 8 + 0x5dec) = value13 + uStack00000014;
              uvalue15 = uvalue15 + 1;
              *ptr9 = value11;
              *(short *)((intptr_t)register0x00000010 + value11 * 8 + 0x5df0) = (short)value5;
              ptr9 = ptr9 + 1;
            }
          }
        }
        psStack0000001c = psStack0000001c + 1;
        iStack00000008 = iStack00000008 + -1;
      } while (iStack00000008 != 0);
      piStack00000010 = piStack00000010 + 1;
      uStack00000020 = uStack00000020 - 1;
    } while (uStack00000020 != 0);
    uvalue6 = uStack00000024;
    if (uvalue15 == 0) break;
    uptr12 = (uint32_t *)((intptr_t)&iStack0000002c + uStack00000004 * 4);
    uptr14 = &iStack0000002c;
    for (uvalue7 = uvalue15 & 0x3fffffff; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
      *uptr14 = *uptr12;
      uptr12 = uptr12 + 1;
      uptr14 = uptr14 + 1;
    }
    for (value5 = 0; value5 != 0; value5 = value5 + -1) {
      *(uint8_t *)uptr14 = *(uint8_t *)uptr12;
      uptr12 = (uint32_t *)((intptr_t)uptr12 + 1);
      uptr14 = (uint32_t *)((intptr_t)uptr14 + 1);
    }
    uStack00000004 = uvalue15;
  }
  value3 = (uint32_t)uvalue1 * 8;
  value5 = *(int *)((intptr_t)register0x00000010 + value3 + 0x5dec);
  if (value5 == -1) {
    return 0;
  }
  if (in_stack_00011978 != (uint16_t *)0x0) {
    *in_stack_00011978 = uvalue1;
    uvalue1 = *(uint16_t *)((intptr_t)register0x00000010 + value3 + 0x5df0);
    uvalue15 = (uint32_t)uvalue1;
    value5 = 2;
    in_stack_00011978[1] = uvalue1;
    if (uvalue15 != uvalue6) {
      uptr8 = in_stack_00011978 + 2;
      do {
        if (399 < value5) {
          return value5;
        }
        value5 = value5 + 1;
        uvalue1 = *(uint16_t *)((intptr_t)register0x00000010 + uvalue15 * 8 + 0x5df0);
        uvalue15 = (uint32_t)uvalue1;
        *uptr8 = uvalue1;
        uptr8 = uptr8 + 1;
      } while (uvalue15 != uvalue6);
    }
  }
  return value5;
}
