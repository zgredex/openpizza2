// RecipeInfo_FillNutritionRows: ported from Pizza Connection 2 at 0x49e160.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x49e160
#include "pc2_port.h"

void __cdecl RecipeInfo_FillNutritionRows(void *arg1,int arg2)

{
  int value1;
  int *ptr2;
  int value3;
  int local_54;
  int local_50;
  uint8_t local_48 [68];
  
  value3 = 0;
  local_54 = 0;
  value1 = Game_CountActiveStats(DAT_0057cc34);
  local_50 = 0;
  if (0 < value1) {
    ptr2 = &DAT_0057cadc;
    do {
      local_54 = local_54 + 1;
      if (arg2 < local_54) {
        Window_GadgetNotify_Text_SetText
                  (arg1,*(int *)((intptr_t)&DAT_00568b4c + value3),
                   *(int *)(DAT_0057c670 + 0xa8 + *ptr2 * 4) + 0x88);
        if (DAT_00568b48 == 0) {
          String_Format(local_48,(uint8_t *)s__0_2f___005688b0,
                        SUB84(*(double *)(*(int *)(DAT_0057c670 + 0xa8 + *ptr2 * 4) + 0xc0) *
                              (double)*(int *)(DAT_0057cc34 + 100 + *ptr2 * 4) * 0.001,0));
        }
        else {
          String_Format(local_48,&DAT_00568ba4,*(uint32_t *)(DAT_0057cc34 + 100 + *ptr2 * 4));
        }
        Window_GadgetNotify_Text_SetText(arg1,*(int *)((intptr_t)&DAT_00568b78 + value3),local_48);
        value3 = value3 + 4;
      }
      if (0x2b < value3) {
        return;
      }
      ptr2 = ptr2 + 1;
      local_50 = local_50 + 1;
    } while (local_50 < value1);
  }
  return;
}
