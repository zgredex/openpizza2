// FUN_005574b1: ported from Pizza Connection 2 at 0x5574b1.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5574b1
#include "pc2_port.h"

void __cdecl FUN_005574b1(int *arg1,uint32_t arg2,int arg3)

{
  uint32_t uvalue1;
  uint32_t uvalue2;
  uint8_t **pptr3;
  uint8_t **pptr4;
  uint16_t local_10;
  uint32_t local_e;
  uint16_t uStack_a;
  uint8_t *puStack_8;
  
  pptr3 = &PTR_s_November_005773a0;
  if (arg2 != 0) {
    if ((intptr_t)arg2 < 0) {
      arg2 = -arg2;
      pptr3 = (uint8_t **)0x577500;
    }
    if (arg3 == 0) {
      *(uint16_t *)arg1 = 0;
    }
    while (arg2 != 0) {
      pptr3 = pptr3 + 0x15;
      uvalue1 = (intptr_t)arg2 >> 3;
      uvalue2 = arg2 & 7;
      arg2 = uvalue1;
      if (uvalue2 != 0) {
        pptr4 = pptr3 + uvalue2 * 3;
        if (0x7fff < *(uint16_t *)(pptr3 + uvalue2 * 3)) {
          local_10 = SUB42(*pptr4,0);
          local_e = (local_e & ~(0x0u << 16)) | ((((uint16_t)((uint32_t)*pptr4 >> 0x10)) & 0x0u) << 16);
          local_e = (local_e & ~(0xffffu << 16)) | (((SUB42(pptr4[1],0)) & 0xffffu) << 16);
          uStack_a = (uint16_t)((uint32_t)pptr4[1] >> 0x10);
          puStack_8 = pptr4[2];
          local_e = CONCAT22(((uint16_t)((local_e) >> 16)),(uint16_t)local_e) + -1;
          pptr4 = (uint8_t **)&local_10;
        }
        FUN_00557291(arg1,(int *)pptr4);
      }
    }
  }
  return;
}
