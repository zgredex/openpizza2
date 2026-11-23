// UI_LoadFontByName: ported from Pizza Connection 2 at 0x527090.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527090
#include "pc2_port.h"

uint32_t __thiscall UI_LoadFontByName(void *self,char *arg1)

{
  char cVar1;
  char *cptr2;
  uint32_t *uptr3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  int value6;
  char *cptr7;
  char *cptr8;
  char local_208 [260];
  uint32_t local_104 [65];
  
                    /* Loads or reuses a font by name and returns its font object. */
  uvalue4 = 0xffffffff;
  do {
    cptr2 = arg1;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cptr2 = arg1 + 1;
    cVar1 = *arg1;
    arg1 = cptr2;
  } while (cVar1 != '\0');
  uvalue4 = ~uvalue4;
  cptr2 = cptr2 + -uvalue4;
  cptr8 = local_208;
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)cptr8 = *(uint32_t *)cptr2;
    cptr2 = cptr2 + 4;
    cptr8 = cptr8 + 4;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *cptr8 = *cptr2;
    cptr2 = cptr2 + 1;
    cptr8 = cptr8 + 1;
  }
  cptr2 = _strrchr(local_208,0x2e);
  if (cptr2 != (char *)0x0) {
    *cptr2 = '\0';
  }
  uvalue4 = 0xffffffff;
  cptr2 = &DAT_005742a4;
  do {
    cptr8 = cptr2;
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cptr8 = cptr2 + 1;
    cVar1 = *cptr2;
    cptr2 = cptr8;
  } while (cVar1 != '\0');
  uvalue4 = ~uvalue4;
  value6 = -1;
  cptr2 = local_208;
  do {
    cptr7 = cptr2;
    if (value6 == 0) break;
    value6 = value6 + -1;
    cptr7 = cptr2 + 1;
    cVar1 = *cptr2;
    cptr2 = cptr7;
  } while (cVar1 != '\0');
  cptr2 = cptr8 + -uvalue4;
  cptr8 = cptr7 + -1;
  for (uvalue5 = uvalue4 >> 2; uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)cptr8 = *(uint32_t *)cptr2;
    cptr2 = cptr2 + 4;
    cptr8 = cptr8 + 4;
  }
  for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *cptr8 = *cptr2;
    cptr2 = cptr2 + 1;
    cptr8 = cptr8 + 1;
  }
  SpriteCache_MakeKey(local_208,local_104);
  uptr3 = (uint32_t *)UI_FindFontByName(self,(uint8_t *)local_104);
  if (uptr3 == (uint32_t *)0x0) {
    uptr3 = UI_LoadFont(self,local_208);
    if (uptr3 == (uint32_t *)0x0) {
      return 0;
    }
  }
  uptr3[0x42] = uptr3[0x42] + 1;
  return uptr3[0x41];
}
