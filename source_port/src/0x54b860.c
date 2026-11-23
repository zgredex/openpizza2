// Sprite_LoadSequence: ported from Pizza Connection 2 at 0x54b860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b860
#include "pc2_port.h"


void Sprite_LoadSequence(uint8_t *arg1,void *arg2,void *arg3,void *arg4)

{
  uint32_t *uptr1;
  int value2;
  int local_118;
  void *local_114;
  CHAR local_110 [260];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b9be;
  local_c = ExceptionList;
  value2 = 0;
  ExceptionList = &local_c;
  while( true ) {
    String_Format(local_110,arg1,value2);
    local_114 = operator_new(0x50);
    local_4 = 0;
    if (local_114 == (void *)0x0) {
      uptr1 = (uint32_t *)0x0;
    }
    else {
      uptr1 = Sprite_Load(local_114,arg3,arg4,local_110,&local_118,0,(void *)0x0,0);
    }
    local_4 = 0xffffffff;
    if (local_118 != 0) break;
    List_Add(arg2,uptr1);
    value2 = value2 + 1;
  }
  if (uptr1 != (uint32_t *)0x0) {
    (**(code **)*uptr1)(1);
  }
  ExceptionList = local_c;
  return;
}
