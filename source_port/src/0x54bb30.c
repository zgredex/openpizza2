// MapBadgeAnim_Construct: ported from Pizza Connection 2 at 0x54bb30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54bb30
#include "pc2_port.h"

uint32_t * __thiscall
MapBadgeAnim_Construct(void *self,void *arg1,uint32_t arg2,uint32_t arg3)

{
  uint32_t *uptr1;
  int value2;
  char local_104 [260];
  
  value2 = 9;
  uptr1 = (uint32_t *)((intptr_t)self + 0x244);
  do {
    uptr1[-0x22] = 0;
    *uptr1 = 0;
    uptr1[-0x20] = 0;
    uptr1[-1] = 0;
    uptr1 = uptr1 + 0x23;
    value2 = value2 + -1;
  } while (value2 != 0);
  *(uint32_t *)((intptr_t)self + 0x1ac) = 0;
  String_Format(local_104,(uint8_t *)s__s1_spr_005765d4,arg2);
  Window_LoadSpriteCached(arg1,local_104,(uint32_t *)0x1,(uint32_t *)((intptr_t)self + 8));
  String_Format(local_104,(uint8_t *)s__s2_spr_005765cc,arg2);
  Window_LoadSpriteCached(arg1,local_104,(uint32_t *)0x1,(uint32_t *)((intptr_t)self + 0x4c));
  String_Format(local_104,(uint8_t *)s__s3_spr_005765c4,arg2);
  Window_LoadSpriteCached(arg1,local_104,(uint32_t *)0x1,(uint32_t *)((intptr_t)self + 0x90));
  String_Format(local_104,(uint8_t *)s__s1_spr_005765d4,arg3);
  Window_LoadSpriteCached(arg1,local_104,(uint32_t *)0x1,(uint32_t *)((intptr_t)self + 0xd4));
  String_Format(local_104,(uint8_t *)s__s2_spr_005765cc,arg3);
  Window_LoadSpriteCached(arg1,local_104,(uint32_t *)0x1,(uint32_t *)((intptr_t)self + 0x118));
  String_Format(local_104,(uint8_t *)s__s3_spr_005765c4,arg3);
  Window_LoadSpriteCached(arg1,local_104,(uint32_t *)0x1,(uint32_t *)((intptr_t)self + 0x15c));
  *(void **)self = arg1;
  *(uint32_t *)((intptr_t)self + 0x1a0) = 0;
  *(uint32_t *)((intptr_t)self + 4) = 0;
  *(uint32_t *)((intptr_t)self + 0x1a8) = 0;
  *(uint32_t *)((intptr_t)self + 0x1a4) = 0;
  return self;
}
