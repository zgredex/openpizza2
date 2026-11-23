// Rating_StoreDailyResults: ported from Pizza Connection 2 at 0x4d4480.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4480
#include "pc2_port.h"

void __fastcall Rating_StoreDailyResults(int arg1)

{
  int value1;
  int value2;
  
  value2 = *(uint16_t *)(*(int *)(DAT_0057c670 + 0x94) + 10) - 1;
  value1 = Rating_GetComposite(arg1);
  *(int *)(arg1 + 0x44 + value2 * 4) = value1;
  value1 = Rating_ClampAdjusted(arg1);
  *(int *)(arg1 + 0x1d4 + value2 * 4) = value1;
  value1 = Rating_AdjustA(arg1);
  *(int *)(arg1 + 0x364 + value2 * 4) = value1;
  *(uint32_t *)(arg1 + 0x4f4 + value2 * 4) = *(uint32_t *)(arg1 + 0xc);
  value1 = Rating_AdjustB(arg1);
  *(int *)(arg1 + 0x684 + value2 * 4) = value1;
  return;
}
