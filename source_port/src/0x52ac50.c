// UI_RefreshButtonSprites: ported from Pizza Connection 2 at 0x52ac50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52ac50
#include "pc2_port.h"

void __thiscall UI_RefreshButtonSprites(void *self,int arg1)

{
  char cVar1;
  void *this_00;
  char *cptr2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  int value5;
  int *ptr6;
  char *cptr7;
  uint32_t *uptr8;
  char local_208 [260];
  char local_104 [260];
  
  this_00 = *(void **)(*(int *)((intptr_t)self + 8) + 0x134);
  if ((0 < arg1) && (arg1 < 3)) {
    if (arg1 == 1) {
      ptr6 = (int *)((intptr_t)self + 0x454);
      value5 = 3;
      do {
        if (*ptr6 != 0) {
          UI_DecrementRowCounter(this_00,(uint8_t *)(ptr6 + -0x10));
        }
        *ptr6 = 0;
        ptr6 = ptr6 + 0x11;
        value5 = value5 + -1;
      } while (value5 != 0);
      return;
    }
    uvalue3 = 0xffffffff;
    cptr2 = (char *)((intptr_t)self + 0x348);
    do {
      cptr7 = cptr2;
      if (uvalue3 == 0) break;
      uvalue3 = uvalue3 - 1;
      cptr7 = cptr2 + 1;
      cVar1 = *cptr2;
      cptr2 = cptr7;
    } while (cVar1 != '\0');
    uvalue3 = ~uvalue3;
    cptr2 = cptr7 + -uvalue3;
    cptr7 = local_208;
    for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *(uint32_t *)cptr7 = *(uint32_t *)cptr2;
      cptr2 = cptr2 + 4;
      cptr7 = cptr7 + 4;
    }
    for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
      *cptr7 = *cptr2;
      cptr2 = cptr2 + 1;
      cptr7 = cptr7 + 1;
    }
    cptr2 = _strrchr(local_208,0x5f);
    if (cptr2 != (char *)0x0) {
      *cptr2 = '\0';
    }
    if (arg1 == 2) {
      value5 = 0;
      uptr8 = (uint32_t *)((intptr_t)self + 0x414);
      do {
        if (uptr8[0x10] == 0) {
          String_Format(local_104,(uint8_t *)s__s__02d_spr_00573b9c,local_208);
          Window_LoadSpriteCached(this_00,local_104,(uint32_t *)(uint32_t)(value5 < 2),uptr8);
        }
        value5 = value5 + 1;
        uptr8 = uptr8 + 0x11;
      } while (value5 < 3);
    }
  }
  return;
}
