// Character_ComputeRatingArray: ported from Pizza Connection 2 at 0x4af7a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4af7a0
#include "pc2_port.h"

void __cdecl Character_ComputeRatingArray(uint32_t *arg1)

{
  int *ptr1;
  int value2;
  uint32_t *uptr3;
  int value4;
  int value5;
  int value6;
  int *ptr7;
  int local_c;
  int local_8;
  
  uptr3 = arg1;
  value6 = DAT_0057d664 - DAT_0057d668;
  local_c = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (local_c == 0) {
    local_c = 0;
  }
  else {
    local_c = local_c + 4;
  }
  for (value5 = 0x12; value5 != 0; value5 = value5 + -1) {
    *arg1 = 0;
    arg1 = arg1 + 1;
  }
  local_8 = 8;
  do {
    value5 = 200;
    *uptr3 = *(uint32_t *)(local_c + 0x1fc + value6 * 4);
    uptr3[2] = *(uint32_t *)(local_c + 0x23c + value6 * 4);
    uptr3[4] = *(uint32_t *)(local_c + 0x21c + value6 * 4);
    uptr3[6] = *(uint32_t *)(local_c + 0x25c + value6 * 4);
    uptr3[8] = *(uint32_t *)(&DAT_0056a08c + value6 * 4);
    uptr3[10] = *(uint32_t *)(&DAT_0056a0ac + value6 * 4);
    uptr3[0xc] = *(uint32_t *)(&DAT_0056a0cc + value6 * 4);
    uptr3[0xe] = *(uint32_t *)(&DAT_0056a0ec + value6 * 4);
    arg1 = uptr3 + 1;
    uptr3[0x10] = *(uint32_t *)(&DAT_0056a10c + value6 * 4);
    ptr7 = (int *)(local_c + 0x27c + value6 * 4);
    do {
      value2 = *ptr7;
      value4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
      ptr1 = (int *)(value5 + value4);
      value5 = value5 + 4;
      ptr7 = ptr7 + 8;
      *arg1 = *(uint32_t *)(&DAT_0056a134 + (*ptr1 + value2) * 4);
      arg1 = arg1 + 2;
    } while (value5 < 0xe0);
    uptr3[0xd] = *(uint32_t *)(&DAT_0056a140 + value6 * 4);
    uptr3[0xf] = *(uint32_t *)(&DAT_0056a180 + value6 * 4);
    local_8 = local_8 + -1;
    uptr3[0x11] = *(uint32_t *)(&DAT_0056a160 + value6 * 4);
  } while (local_8 != 0);
  return;
}
