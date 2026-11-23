// Record_AdvanceFrameSequence: ported from Pizza Connection 2 at 0x533c90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x533c90
#include "pc2_port.h"

uint32_t __thiscall
Record_AdvanceFrameSequence
          (void *self,int arg1,uint32_t arg2,double *arg3,double *arg4,uint32_t *arg5)

{
  double *pdVar1;
  double dVar2;
  uint16_t uvalue3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  uint32_t uvalue6;
  uint32_t uvalue7;
  uint32_t uvalue8;
  uint32_t uvalue9;
  uint32_t uvalue10;
  double dVar11;
  bool flag12;
  int value13;
  short svalue14;
  short *psVar15;
  int value16;
  int *ptr17;
  int value18;
  int local_30;
  
  if (arg5 != (uint32_t *)0x0) {
    *arg5 = 0;
  }
  value18 = arg1 * 0x48;
  value13 = *(int *)((intptr_t)self + 0x4c) + value18;
  if (*(char *)(value13 + 0x3e) == '\0') {
    return 0;
  }
  local_30 = (intptr_t)*(short *)(value13 + 0x30);
  uvalue3 = *(uint16_t *)(value13 + 0x3a);
  *(uint16_t *)(value13 + 0x30) = 0;
  value13 = *(int *)((intptr_t)self + 0x4c) + value18;
  if (*(char *)(value13 + 0x3c) == '\0') {
    *(uint32_t *)(value13 + 4) = uvalue3 + arg2;
    *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + 0x3c + value18) = 1;
  }
  else {
    if (*(char *)(value13 + 0x40) != '\0') {
      return 0;
    }
    ptr17 = (int *)(value13 + 4);
    uvalue4 = *(uint32_t *)(value13 + 4);
    while (uvalue4 <= arg2) {
      *ptr17 = uvalue4 + uvalue3;
      local_30 = local_30 + 1;
      ptr17 = (int *)(*(int *)((intptr_t)self + 0x4c) + 4 + value18);
      uvalue4 = *(uint32_t *)(*(int *)((intptr_t)self + 0x4c) + 4 + value18);
    }
  }
  do {
    if (local_30 < 1) {
      return 1;
    }
    value13 = (intptr_t)*(short *)(*(int *)((intptr_t)self + 0x4c) + 0x34 + value18);
    ptr17 = (int *)(*(int *)((intptr_t)self + 0x4c) + value18);
    psVar15 = (short *)(*ptr17 * 0x98 + value13 * 6 + *(int *)((intptr_t)self + 0x50));
    if (((*(uint16_t *)((intptr_t)ptr17 + 0x36) & 1) == 0) || (*(char *)((intptr_t)psVar15 + 5) == '\0')) {
      flag12 = true;
    }
    else {
      flag12 = false;
    }
    if (flag12) {
      if (psVar15[1] != *(short *)((intptr_t)ptr17 + 0x32)) goto LAB_00533d98;
LAB_00533dd5:
      *(uint16_t *)((intptr_t)ptr17 + 0x36) = *(uint16_t *)((intptr_t)ptr17 + 0x36) + 1;
      ptr17 = (int *)(*(int *)((intptr_t)self + 0x4c) + value18);
      if (*(short *)((intptr_t)ptr17 + 0x36) < (short)(char)psVar15[2]) {
        if (*(char *)((intptr_t)psVar15 + 5) != '\0') {
          *(char *)(ptr17 + 0xe) = -(char)ptr17[0xe];
          goto LAB_00533d98;
        }
        *(short *)((intptr_t)ptr17 + 0x32) = *psVar15;
      }
      else {
        value16 = 0;
        if (*(char *)((intptr_t)ptr17 + 0x3d) != '\0') {
LAB_00534048:
          Record_ClearFlags48(self,arg1);
          return 1;
        }
        if (*(char *)((intptr_t)ptr17 + 0x3f) == '\0') {
          while( true ) {
            value13 = value13 + 1;
            if (0xf < value13) {
              value13 = 0;
            }
            if (*(short *)(*(int *)((intptr_t)self + 0x50) + value13 * 6 + *ptr17 * 0x98) != -1) break;
            value16 = value16 + 1;
            if (0x11 < value16) goto LAB_00534048;
          }
          if (0x11 < value16) goto LAB_00534048;
        }
        else if (((psVar15[1] == *psVar15) &&
                 (*(double *)(*(int *)((intptr_t)self + 0x50) + 0x60 + *ptr17 * 0x98) == 0.0)) &&
                (*(double *)(*(int *)((intptr_t)self + 0x50) + *ptr17 * 0x98 + 0x68) == 0.0)) {
          *(uint8_t *)(ptr17 + 0x10) = 1;
          local_30 = 1;
        }
        if (value13 == *(short *)(*(int *)((intptr_t)self + 0x4c) + 0x34 + value18)) {
          *(uint8_t *)(*(int *)((intptr_t)self + 0x4c) + value18 + 0x3f) = 1;
        }
        Record_SetVariant(self,arg1,value13);
      }
    }
    else {
      if ((!flag12) && (*psVar15 == *(short *)((intptr_t)ptr17 + 0x32))) goto LAB_00533dd5;
LAB_00533d98:
      value13 = *(int *)((intptr_t)self + 0x4c) + value18;
      svalue14 = *(short *)(value13 + 0x32);
      if (*(char *)(*(int *)((intptr_t)self + 0x4c) + 0x38 + value18) < '\x01') {
        if (svalue14 < 1) {
          svalue14 = *(short *)((intptr_t)self + 0x68) + -1;
        }
        else {
          svalue14 = svalue14 + -1;
        }
      }
      else {
        if (*(int *)((intptr_t)self + 0x68) <= svalue14 + 1) {
          *(uint16_t *)(value13 + 0x32) = 0;
          goto LAB_00533ee8;
        }
        svalue14 = svalue14 + 1;
      }
      *(short *)(value13 + 0x32) = svalue14;
    }
LAB_00533ee8:
    value16 = local_30;
    value13 = *(int *)(*(int *)((intptr_t)self + 0x4c) + value18);
    uvalue5 = *(uint32_t *)(*(int *)((intptr_t)self + 0x50) + 0x68 + value13 * 0x98);
    value13 = *(int *)((intptr_t)self + 0x50) + value13 * 0x98;
    dVar2 = *(double *)(value13 + 0x60);
    uvalue6 = *(uint32_t *)(value13 + 0x6c);
    *arg3 = dVar2 + *arg3;
    dVar11 = (double)CONCAT44(uvalue6,uvalue5) + *arg4;
    *arg4 = dVar11;
    if (arg5 != (uint32_t *)0x0) {
      value13 = *(int *)((intptr_t)self + 0x4c) + value18;
      uvalue7 = *(uint32_t *)(*(int *)((intptr_t)self + 0x4c) + 0x18 + value18);
      uvalue8 = *(uint32_t *)(value13 + 0x1c);
      pdVar1 = (double *)(value13 + 0x20);
      uvalue9 = *(uint32_t *)pdVar1;
      uvalue10 = *(uint32_t *)(value13 + 0x24);
      if ((((dVar2 == 0.0) || ((0.0 < dVar2 && ((double)CONCAT44(uvalue8,uvalue7) <= *arg3)))) ||
          ((dVar2 < 0.0 && (*arg3 <= (double)CONCAT44(uvalue8,uvalue7))))) &&
         ((((double)CONCAT44(uvalue6,uvalue5) == 0.0 ||
           ((0.0 < (double)CONCAT44(uvalue6,uvalue5) && (*pdVar1 <= dVar11)))) ||
          (((double)CONCAT44(uvalue6,uvalue5) < 0.0 && (dVar11 <= *pdVar1)))))) {
        local_30 = 1;
        *(short *)(value13 + 0x30) = (short)value16 + -1;
        *arg5 = 1;
        *(uint32_t *)arg3 = uvalue7;
        *(uint32_t *)((intptr_t)arg3 + 4) = uvalue8;
        *(uint32_t *)arg4 = uvalue9;
        *(uint32_t *)((intptr_t)arg4 + 4) = uvalue10;
      }
    }
    local_30 = local_30 + -1;
  } while( true );
}
