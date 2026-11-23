// Person_TruncatePathToCurrentStep: ported from Pizza Connection 2 at 0x507a80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x507a80
#include "pc2_port.h"

void __fastcall Person_TruncatePathToCurrentStep(int arg1)

{
  short svalue1;
  uint32_t uvalue2;
  uint32_t uvalue3;
  DWORD DVar4;
  
                    /* Truncates a person's path to the current and next nodes. */
  svalue1 = *(short *)(*(int *)(arg1 + 200) + 0x28);
  if (-1 < svalue1) {
    uvalue2 = Array_GetPtr4((void *)(*(int *)(arg1 + 200) + 0x14),(intptr_t)svalue1);
    uvalue3 = Array_GetPtr4((void *)(*(int *)(arg1 + 200) + 0x14),
                          *(short *)(*(int *)(arg1 + 200) + 0x28) + 1);
    CS_Enter(*(int *)(DAT_0057c670 + 0x240));
    Object_ClearField4(*(int *)(arg1 + 200) + 0x14);
    Array_Grow((void *)(*(int *)(arg1 + 200) + 0x14),uvalue2);
    Array_Grow((void *)(*(int *)(arg1 + 200) + 0x14),uvalue3);
    Object_SetShort28(*(void **)(arg1 + 200),0);
    DVar4 = timeGetTime();
    Object_UpdateWalkStep(*(void **)(arg1 + 0xc4),*(uint32_t **)(arg1 + 200),DVar4);
    CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  }
  return;
}
