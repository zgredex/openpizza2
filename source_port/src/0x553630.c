// CRT_Strcat: ported from Pizza Connection 2 at 0x553630.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553630
#include "pc2_port.h"

uint32_t * __cdecl CRT_Strcat(uint32_t *arg1,uint32_t *arg2)

{
  uint8_t flag1;
  uint32_t uvalue2;
  uint32_t *uptr3;
  uint32_t uvalue4;
  uint32_t *uptr5;
  
  uptr3 = arg1;
  do {
    if (((uint32_t)uptr3 & 3) == 0) goto LAB_0055364c;
    uvalue4 = *uptr3;
    uptr3 = (uint32_t *)((intptr_t)uptr3 + 1);
  } while ((uint8_t)uvalue4 != 0);
  goto LAB_0055367f;
  while( true ) {
    if ((uvalue4 & 0xff0000) == 0) {
      uptr5 = (uint32_t *)((intptr_t)uptr5 + 2);
      goto joined_r0x0055369b;
    }
    if ((uvalue4 & 0xff000000) == 0) break;
LAB_0055364c:
    do {
      uptr5 = uptr3;
      uptr3 = uptr5 + 1;
    } while (((*uptr5 ^ 0xffffffff ^ *uptr5 + 0x7efefeff) & 0x81010100) == 0);
    uvalue4 = *uptr5;
    if ((char)uvalue4 == '\0') goto joined_r0x0055369b;
    if ((char)(uvalue4 >> 8) == '\0') {
      uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
      goto joined_r0x0055369b;
    }
  }
LAB_0055367f:
  uptr5 = (uint32_t *)((intptr_t)uptr3 + -1);
joined_r0x0055369b:
  do {
    if (((uint32_t)arg2 & 3) == 0) {
      do {
        uvalue2 = *arg2;
        uvalue4 = *arg2;
        arg2 = arg2 + 1;
        if (((uvalue2 ^ 0xffffffff ^ uvalue2 + 0x7efefeff) & 0x81010100) != 0) {
          if ((char)uvalue4 == '\0') {
LAB_00553708:
            *(uint8_t *)uptr5 = (uint8_t)uvalue4;
            return arg1;
          }
          if ((char)(uvalue4 >> 8) == '\0') {
            *(short *)uptr5 = (short)uvalue4;
            return arg1;
          }
          if ((uvalue4 & 0xff0000) == 0) {
            *(short *)uptr5 = (short)uvalue4;
            *(uint8_t *)((intptr_t)uptr5 + 2) = 0;
            return arg1;
          }
          if ((uvalue4 & 0xff000000) == 0) {
            *uptr5 = uvalue4;
            return arg1;
          }
        }
        *uptr5 = uvalue4;
        uptr5 = uptr5 + 1;
      } while( true );
    }
    flag1 = (uint8_t)*arg2;
    uvalue4 = (uint32_t)flag1;
    arg2 = (uint32_t *)((intptr_t)arg2 + 1);
    if (flag1 == 0) goto LAB_00553708;
    *(uint8_t *)uptr5 = flag1;
    uptr5 = (uint32_t *)((intptr_t)uptr5 + 1);
  } while( true );
}
