// UI_LoadFont: ported from Pizza Connection 2 at 0x526fa0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x526fa0
#include "pc2_port.h"


uint32_t * __thiscall UI_LoadFont(void *self,LPCSTR arg1)

{
  uint32_t uvalue1;
  char *cptr2;
  uint32_t *uptr3;
  int value4;
  uint32_t *uptr5;
  int local_14;
  void *local_10;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a7bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = operator_new(0x9c8);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    cptr2 = (char *)0x0;
  }
  else {
    cptr2 = Font_Load(local_10,*(uint32_t *)((intptr_t)self + 0xc),*(void **)((intptr_t)self + 0x10),
                       arg1,&local_14);
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    if (cptr2 != (char *)0x0) {
      Image_FreePixelData((intptr_t)cptr2);
      Mem_Free(cptr2);
    }
    ExceptionList = local_c;
    return (uint32_t *)0x0;
  }
  uptr3 = operator_new(0x110);
  uptr5 = uptr3;
  for (value4 = 0x44; value4 != 0; value4 = value4 + -1) {
    *uptr5 = 0;
    uptr5 = uptr5 + 1;
  }
  SpriteCache_MakeKey(arg1,uptr3);
  uvalue1 = *(uint32_t *)((intptr_t)self + 0x82c4);
  uptr3[0x41] = (uint32_t)cptr2;
  uptr3[0x43] = uvalue1;
  *(uint32_t **)((intptr_t)self + 0x82c4) = uptr3;
  ExceptionList = local_c;
  return uptr3;
}
