// PlayerCompany_InitDefaults: ported from Pizza Connection 2 at 0x50f590.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50f590
#include "pc2_port.h"

void __fastcall PlayerCompany_InitDefaults(int arg1)

{
  uint32_t uvalue1;
  uint32_t *uptr2;
  uint32_t *uptr3;
  
  *(uint32_t *)(arg1 + 0x3c) = DAT_0057c1f8;
  *(uint32_t *)(arg1 + 0x40) = DAT_0057c1fc;
  *(uint32_t *)(arg1 + 0x44) = DAT_0057c200;
  *(uint32_t *)(arg1 + 0x48) = DAT_0057c204;
  *(uint32_t *)(arg1 + 0x4c) = DAT_0057c208;
  *(uint32_t *)(arg1 + 0x50) = DAT_0057c20c;
  *(uint32_t *)(arg1 + 0x54) = DAT_0057c210;
  *(uint32_t *)(arg1 + 0x58) = DAT_0057c214;
  *(uint32_t *)(arg1 + 0x5c) = DAT_0057c218;
  *(uint32_t *)(arg1 + 0x60) = DAT_0057c21c;
  *(uint32_t *)(arg1 + 100) = DAT_0057c220;
  *(uint32_t *)(arg1 + 0x68) = DAT_0057c224;
  *(uint32_t *)(arg1 + 0x2c) = DAT_0057c240;
  *(uint32_t *)(arg1 + 0x30) = DAT_0057c244;
  uptr3 = (uint32_t *)(arg1 + 0x6c);
  *(uint32_t *)(*(int *)(arg1 + 4) + 0x40) = DAT_0057c248;
  uptr2 = &DAT_0057c228;
  do {
    uvalue1 = *uptr2;
    uptr2 = uptr2 + 1;
    *uptr3 = uvalue1;
    uptr3 = uptr3 + 1;
  } while ((intptr_t)uptr2 < 0x57c240);
  return;
}
