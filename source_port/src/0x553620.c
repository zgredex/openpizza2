// _strcpy: ported from Pizza Connection 2 at 0x553620.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553620
#include "pc2_port.h"

uint32_t * __cdecl _strcpy(uint32_t *arg1,uint32_t *arg2)

{
  uint8_t flag1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  uint32_t *uptr4;
  
  uptr4 = arg1;
  while (((uint32_t)arg2 & 3) != 0) {
    flag1 = (uint8_t)*arg2;
    uvalue3 = (uint32_t)flag1;
    arg2 = (uint32_t *)((intptr_t)arg2 + 1);
    if (flag1 == 0) goto LAB_00553708;
    *(uint8_t *)uptr4 = flag1;
    uptr4 = (uint32_t *)((intptr_t)uptr4 + 1);
  }
  do {
    uvalue2 = *arg2;
    uvalue3 = *arg2;
    arg2 = arg2 + 1;
    if (((uvalue2 ^ 0xffffffff ^ uvalue2 + 0x7efefeff) & 0x81010100) != 0) {
      if ((char)uvalue3 == '\0') {
LAB_00553708:
        *(uint8_t *)uptr4 = (uint8_t)uvalue3;
        return arg1;
      }
      if ((char)(uvalue3 >> 8) == '\0') {
        *(short *)uptr4 = (short)uvalue3;
        return arg1;
      }
      if ((uvalue3 & 0xff0000) == 0) {
        *(short *)uptr4 = (short)uvalue3;
        *(uint8_t *)((intptr_t)uptr4 + 2) = 0;
        return arg1;
      }
      if ((uvalue3 & 0xff000000) == 0) {
        *uptr4 = uvalue3;
        return arg1;
      }
    }
    *uptr4 = uvalue3;
    uptr4 = uptr4 + 1;
  } while( true );
}
