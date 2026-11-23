// Person_ApplyAttackOutcome: ported from Pizza Connection 2 at 0x50c0f0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50c0f0
#include "pc2_port.h"

uint32_t __thiscall Person_ApplyAttackOutcome(void *self,uint32_t arg1,int arg2)

{
  int *ptr1;
  void *this_00;
  void *this_01;
  int value2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Applies a non-group attack outcome and counters. */
  ptr1 = *(int **)((intptr_t)self + 200);
  uvalue4 = 0;
  if (ptr1 == (int *)0x0) {
    return 0;
  }
  Record_GetTwoFloats48((void *)ptr1[0x16],*ptr1,&local_c,&local_4);
  this_00 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 0x3c),arg2,(int *)0x0);
  if (this_00 == (void *)0x0) {
    return 1;
  }
  if (*(int *)((intptr_t)this_00 + 0x74) == 0) {
    return 1;
  }
  if (((*(int *)((intptr_t)self + 0x30) == 0x17) || (*(int *)((intptr_t)self + 0x30) == 0x1d)) &&
     (*(int *)((intptr_t)this_00 + 0xa4) == -1)) {
    return 1;
  }
  if (*(int *)((intptr_t)this_00 + 0x38) == 0x38) {
    return 1;
  }
  ptr1 = *(int **)((intptr_t)this_00 + 200);
  if (ptr1 == (int *)0x0) {
    value2 = -1;
    this_01 = (void *)0x0;
  }
  else {
    value2 = *ptr1;
    this_01 = (void *)ptr1[0x16];
  }
  Record_GetTwoFloats48(this_01,value2,&local_10,&local_8);
  if (((local_10 - local_c) * (local_10 - local_c) + (local_8 - local_4) * (local_8 - local_4) * 4 <
       0xe10) && (*(int *)((intptr_t)this_00 + 0xa4) != -1)) {
    if ((*(int *)((intptr_t)this_00 + 0x110) != -1) &&
       (value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)this_00 + 0x110)),
       *(int *)((intptr_t)this_00 + 0x30) == 0x1f)) {
      if (*(int *)((intptr_t)this_00 + 0xa4) == 0x11) {
        *(int *)(value2 + 0x90) = *(int *)(value2 + 0x90) + 1;
      }
      if (*(int *)((intptr_t)self + 0x30) == 0xd) {
        *(int *)(value2 + 0x84) = *(int *)(value2 + 0x84) + 1;
      }
    }
    if (*(int *)((intptr_t)self + 0x30) == 0xd) {
      value2 = 0x38;
    }
    else {
      if ((*(int *)((intptr_t)this_00 + 0x30) == 0x1f) &&
         (value2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((intptr_t)self + 0x110)), value2 != 0)) {
        value2 = Game_GetPlayerCity(value2);
        *(int *)(value2 + 0x38) = *(int *)(value2 + 0x38) + 1;
      }
      value2 = 0x2a;
    }
    Object_SetState(this_00,value2);
    value2 = *(int *)((intptr_t)this_00 + 200);
    uvalue4 = 1;
    if (value2 == 0) {
      uvalue3 = 0xffffffff;
    }
    else {
      uvalue3 = *(uint32_t *)(value2 + 0xc);
    }
    uvalue3 = uvalue3 & 0x80000007;
    if ((intptr_t)uvalue3 < 0) {
      uvalue3 = (uvalue3 - 1 | 0xfffffff8) + 1;
    }
    *(uint32_t *)((intptr_t)this_00 + 0x88) = uvalue3;
    if (*(short *)(value2 + 0x28) == -1) {
      UI_DetachChildRecord((intptr_t)this_00);
      Object_SetFieldA4Locked(this_00,0xffffffff);
      return 1;
    }
    Person_TruncatePathToCurrentStep((intptr_t)this_00);
    Object_SetFieldA4Locked(this_00,0xffffffff);
  }
  return uvalue4;
}
