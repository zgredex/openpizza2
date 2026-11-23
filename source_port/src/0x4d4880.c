// Map_LoadMapSprite: ported from Pizza Connection 2 at 0x4d4880.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4880
#include "pc2_port.h"


void __fastcall Map_LoadMapSprite(int arg1)

{
  uint32_t *uptr1;
  int local_118;
  void *local_114;
  CHAR local_110 [260];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558e4e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  String_Format(local_110,(uint8_t *)s_Maps__s_spr_0056cd14,arg1 + 0x44);
  local_114 = operator_new(0x50);
  local_4 = 0;
  if (local_114 == (void *)0x0) {
    uptr1 = (uint32_t *)0x0;
  }
  else {
    uptr1 = Sprite_Load(local_114,DAT_0057c5c8,DAT_0057c5d8,local_110,&local_118,0,(void *)0x0,0);
  }
  local_4 = 0xffffffff;
  *(uint32_t **)(arg1 + 0x10a8) = uptr1;
  if (local_118 != 0) {
    if (uptr1 != (uint32_t *)0x0) {
      (**(code **)*uptr1)(1);
    }
    *(uint32_t *)(arg1 + 0x10a8) = 0;
  }
  ExceptionList = local_c;
  return;
}
