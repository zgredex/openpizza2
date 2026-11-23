// FUN_005579b4: ported from Pizza Connection 2 at 0x5579b4.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5579b4
#include "pc2_port.h"

uint32_t * __cdecl FUN_005579b4(int *arg1)

{
  int value1;
  int *ptr2;
  uint32_t *uptr3;
  uint32_t *uptr4;
  int value5;
  uint32_t *uptr6;
  
  value5 = 0;
  if (arg1 == (int *)0x0) {
    return (uint32_t *)0x0;
  }
  value1 = *arg1;
  ptr2 = arg1;
  while (value1 != 0) {
    ptr2 = ptr2 + 1;
    value5 = value5 + 1;
    value1 = *ptr2;
  }
  uptr3 = _malloc(value5 * 4 + 4);
  if (uptr3 == (uint32_t *)0x0) {
    __amsg_exit(9);
  }
  uptr4 = (uint32_t *)*arg1;
  uptr6 = uptr3;
  while (uptr4 != (uint32_t *)0x0) {
    arg1 = arg1 + 1;
    uptr4 = FUN_00557ab2(uptr4);
    *uptr6 = uptr4;
    uptr6 = uptr6 + 1;
    uptr4 = (uint32_t *)*arg1;
  }
  *uptr6 = 0;
  return uptr3;
}
