// RecordArray_CompactEmpty48: ported from Pizza Connection 2 at 0x527850.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x527850
#include "pc2_port.h"

void __fastcall RecordArray_CompactEmpty48(int arg1)

{
  uint32_t *uptr1;
  int value2;
  int value3;
  int *ptr4;
  int value5;
  int value6;
  int value7;
  int local_c;
  int local_8;
  
  value3 = *(int *)(arg1 + 0x82fc);
  local_c = 0;
  if (0 < value3) {
    local_8 = 0;
    do {
      ptr4 = (int *)(local_8 + 0x44 + *(int *)(arg1 + 0x82f8));
      value2 = local_c;
      if (*(int *)(local_8 + 0x44 + *(int *)(arg1 + 0x82f8)) == 0) {
        for (; (value2 < value3 && (*ptr4 == 0)); ptr4 = ptr4 + 0x12) {
          value2 = value2 + 1;
        }
        value6 = value2 + -1;
        value3 = (value6 - local_c) + 1;
        value5 = value3;
        value7 = local_8;
        if (local_c <= value6) {
          do {
            uptr1 = *(uint32_t **)(value7 + 0x40 + *(int *)(arg1 + 0x82f8));
            if (uptr1 != (uint32_t *)0x0) {
              (**(code **)*uptr1)(1);
            }
            value7 = value7 + 0x48;
            value5 = value5 + -1;
          } while (value5 != 0);
        }
        value5 = (*(int *)(arg1 + 0x82fc) - value6) + -1;
        if (0 < value5) {
          _memmove((uint32_t *)(local_8 + *(int *)(arg1 + 0x82f8)),
                   (uint32_t *)(*(int *)(arg1 + 0x82f8) + (value2 + 8 + value6 * 8) * 8),
                   value5 * 0x48);
        }
        *(int *)(arg1 + 0x82fc) = *(int *)(arg1 + 0x82fc) - value3;
      }
      value3 = *(int *)(arg1 + 0x82fc);
      local_c = local_c + 1;
      local_8 = local_8 + 0x48;
    } while (local_c < value3);
  }
  return;
}
