// FurnitureType_InitTable: ported from Pizza Connection 2 at 0x4e41c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e41c0
#include "pc2_port.h"

void __fastcall FurnitureType_InitTable(int arg1)

{
  uint32_t *uptr1;
  int value2;
  int *ptr3;
  uint32_t unaff_ESI;
  int *ptr4;
  int value5;
  uint32_t *uptr6;
  int *ptr7;
  int *local_10;
  int local_c;
  
  uptr6 = &DAT_0057dfdc;
                    /* Builds the furniture-type table and sprite-id mappings. */
  for (value2 = 0x9c4; value2 != 0; value2 = value2 + -1) {
    *uptr6 = 0;
    uptr6 = uptr6 + 1;
  }
  if (DAT_0056d160 != 0xc) {
    local_10 = &DAT_0056d160;
    uptr6 = &DAT_00583770;
    do {
      uptr1 = operator_new(0xe8);
      if (uptr1 == (uint32_t *)0x0) {
        uptr1 = (uint32_t *)0x0;
      }
      else {
        uptr1 = FurnitureType_Construct(uptr1);
      }
      ptr3 = local_10 + 0x1c;
      String_Format((uint8_t *)(local_10 + 4),(uint8_t *)*uptr6,unaff_ESI);
      uptr6 = uptr6 + 1;
      local_c = 8;
      ptr4 = local_10;
      ptr7 = uptr1 + 2;
      for (value2 = 0x38; value2 != 0; value2 = value2 + -1) {
        *ptr7 = *ptr4;
        ptr4 = ptr4 + 1;
        ptr7 = ptr7 + 1;
      }
      do {
        value2 = 6;
        do {
          value5 = (intptr_t)(short)*ptr3;
          if (value5 != -1) {
            if (((uint32_t *)(&DAT_0057dfdc)[value5] != (uint32_t *)0x0) &&
               ((uint32_t *)(&DAT_0057dfdc)[value5] != uptr1)) {
              NoOp_Stub();
            }
            (&DAT_0057dfdc)[value5] = uptr1;
          }
          ptr3 = (int *)((intptr_t)ptr3 + 2);
          value2 = value2 + -1;
        } while (value2 != 0);
        local_c = local_c + -1;
      } while (local_c != 0);
      List_Add((void *)(arg1 + 0x74),uptr1);
      local_10 = local_10 + 0x38;
    } while (*local_10 != 0xc);
  }
  return;
}
