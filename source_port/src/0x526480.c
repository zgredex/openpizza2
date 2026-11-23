// UI_LoadSpriteSet: ported from Pizza Connection 2 at 0x526480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526480
#include "pc2_port.h"


uint32_t __thiscall UI_LoadSpriteSet(void *self,uint32_t arg1)

{
  uint32_t *uptr1;
  int value2;
  int *ptr3;
  int *ptr4;
  int iStack_118;
  void *pvStack_114;
  CHAR aCStack_110 [260];
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055a79e;
  pvStack_c = ExceptionList;
  value2 = 8;
  ptr4 = (int *)((intptr_t)self + 0x250);
  ptr3 = ptr4;
  ExceptionList = &pvStack_c;
  do {
    if ((uint32_t *)*ptr3 != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)*ptr3)(1);
      *ptr3 = 0;
    }
    ptr3 = ptr3 + 1;
    value2 = value2 + -1;
  } while (value2 != 0);
  value2 = 0;
  ptr3 = ptr4;
  while( true ) {
    String_Format(aCStack_110,(uint8_t *)s__s__02d_spr_00573b9c,arg1);
    pvStack_114 = operator_new(0x50);
    uStack_4 = 0;
    if (pvStack_114 == (void *)0x0) {
      uptr1 = (uint32_t *)0x0;
    }
    else {
      uptr1 = Sprite_Load(pvStack_114,*(void **)((intptr_t)self + 0xc),*(void **)((intptr_t)self + 0x10),
                           aCStack_110,&iStack_118,0,(void *)0x0,0);
    }
    *ptr3 = (intptr_t)uptr1;
    uStack_4 = 0xffffffff;
    if (iStack_118 != 0) break;
    value2 = value2 + 1;
    ptr3 = ptr3 + 1;
    if (7 < value2) {
      ExceptionList = pvStack_c;
      return 1;
    }
  }
  if (-1 < value2) {
    value2 = value2 + 1;
    do {
      if ((uint32_t *)*ptr4 != (uint32_t *)0x0) {
        (*(code *)**(uint32_t **)*ptr4)(1);
      }
      *ptr4 = 0;
      ptr4 = ptr4 + 1;
      value2 = value2 + -1;
    } while (value2 != 0);
  }
  ExceptionList = pvStack_c;
  return 0;
}
