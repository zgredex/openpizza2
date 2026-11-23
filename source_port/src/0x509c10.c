// Building_PruneStaleListRow: ported from Pizza Connection 2 at 0x509c10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x509c10
#include "pc2_port.h"

void __fastcall Building_PruneStaleListRow(int arg1)

{
  short svalue1;
  uint8_t uvalue2;
  uint32_t extraout_var;
  int value3;
  int value4;
  
                    /* Prunes a stale building list row and rebuilds the list. */
  if (*(int *)(arg1 + 200) != 0) {
    CS_Enter(*(int *)(DAT_0057c670 + 0x240));
    uvalue2 = Object_IsVisibleThisFrame(arg1);
    if (CONCAT31(extraout_var,uvalue2) == 0) {
      CS_Leave(*(int *)(DAT_0057c670 + 0x240));
      return;
    }
    svalue1 = *(short *)(*(int *)(arg1 + 200) + 0x28);
    if (svalue1 != -1) {
      value4 = (intptr_t)svalue1;
      value3 = Array_GetPtr4((void *)(*(int *)(arg1 + 200) + 0x14),value4);
      while (value3 != 0) {
        value3 = Array_GetPtr4((void *)(*(int *)(arg1 + 200) + 0x14),value4);
        if (*(int *)(*(int *)(*(int *)(*(int *)(arg1 + 0xc4) + 0x4c) + 8 +
                             *(int *)(value3 + 8) * 0xc) + 0x28) == 0) {
          UI_RemoveLastChild(arg1);
          Person_RecomputePathStep(arg1);
          CS_Leave(*(int *)(DAT_0057c670 + 0x240));
          return;
        }
        value4 = value4 + 1;
        value3 = Array_GetPtr4((void *)(*(int *)(arg1 + 200) + 0x14),value4);
      }
    }
    CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  }
  return;
}
