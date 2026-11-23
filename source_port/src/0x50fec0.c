// PlayerStats_Reset: ported from Pizza Connection 2 at 0x50fec0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x50fec0
#include "pc2_port.h"

void __fastcall PlayerStats_Reset(int arg1)

{
  int value1;
  int value2;
  int value3;
  int *ptr4;
  int value5;
  uint32_t *uptr6;
  
  uptr6 = (uint32_t *)(arg1 + 0x1bc);
  for (value3 = 7; value3 != 0; value3 = value3 + -1) {
    *uptr6 = 0;
    uptr6 = uptr6 + 1;
  }
  uptr6 = (uint32_t *)(arg1 + 100);
  for (value3 = 0x56; value3 != 0; value3 = value3 + -1) {
    *uptr6 = 0;
    uptr6 = uptr6 + 1;
  }
  value5 = 0;
  value3 = 0;
  if (0 < *(int *)(arg1 + 0x5c)) {
    do {
      value2 = IDMap_Lookup((void *)(arg1 + 0x48),value3,(int *)0x0);
      if (*(char *)(value2 + 0x11) == '\0') {
        value1 = *(int *)(DAT_0057c670 + 0xa8 + (uint32_t)*(uint8_t *)(value2 + 4) * 4);
        ptr4 = (int *)(arg1 + 100 + (uint32_t)*(uint8_t *)(value2 + 4) * 4);
        *ptr4 = *ptr4 + *(int *)(value1 + 0xac + (uint32_t)*(uint8_t *)(value2 + 6) * 4);
        ptr4 = (int *)(arg1 + 0x1bc + (uint32_t)*(uint8_t *)(value2 + 5) * 4);
        *ptr4 = *ptr4 + *(int *)(value1 + 0xac + (uint32_t)*(uint8_t *)(value2 + 6) * 4);
        value5 = value5 + *(int *)(value1 + 0xac + (uint32_t)*(uint8_t *)(value2 + 6) * 4);
      }
      value3 = value3 + 1;
    } while (value3 < *(int *)(arg1 + 0x5c));
    if (0 < value5) {
      value3 = 7;
      ptr4 = (int *)(arg1 + 0x1bc);
      do {
        value3 = value3 + -1;
        *ptr4 = (*ptr4 * 100) / value5;
        ptr4 = ptr4 + 1;
      } while (value3 != 0);
    }
  }
  *(int *)(arg1 + 0x1d8) = value5;
  return;
}
