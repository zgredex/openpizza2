// CompanyBranches_InitBranchRows: ported from Pizza Connection 2 at 0x4b98e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4b98e0
#include "pc2_port.h"

void __cdecl CompanyBranches_InitBranchRows(void *arg1,int arg2)

{
  int value1;
  int value2;
  double fVar3;
  int local_38;
  int local_34;
  int local_2c;
  uint8_t local_28 [36];
  
                    /* Fills branch rows with names and computed recipe prices. */
  value1 = Game_CountActiveCompanies((intptr_t)DAT_0057d6cc);
  local_34 = 0;
  local_2c = 0;
  value2 = 0;
  if (0 < value1 + 1) {
    value2 = 0x511;
    do {
      if ((local_2c == 0) && (arg2 == 0)) {
        local_38 = *(int *)(*(int *)(DAT_0057c670 + 0x9c) + 0x14dc);
      }
      else {
        local_38 = Game_GetActiveCompanyById(DAT_0057d6cc,local_2c + -1 + arg2);
      }
      if (local_38 != 0) {
        UI_ShowChildByID(arg1,value2);
        UI_ShowChildByID(arg1,value2 + 9);
        UI_ShowChildByID(arg1,value2 + -0xb);
        Window_GadgetNotify_Text_SetText(arg1,value2,local_38 + 4);
        fVar3 = Branch_ComputeRecipePrice(local_38,*(int *)(DAT_0057c670 + 0x9c),-999);
        String_Format(local_28,(uint8_t *)s__0_2f_005685f4,SUB84((double)fVar3,0));
        Window_GadgetNotify_Text_SetText(arg1,value2 + 9,local_28);
        local_34 = local_34 + 1;
        value2 = value2 + 1;
        if (value2 == 0x51a) break;
      }
      local_2c = local_2c + 1;
    } while (local_2c < value1 + 1);
    value2 = local_34;
    if (8 < local_34) {
      return;
    }
  }
  value2 = value2 + 0x51a;
  do {
    UI_RemoveObjectByKey(arg1,value2 + -9);
    UI_RemoveObjectByKey(arg1,value2);
    UI_RemoveObjectByKey(arg1,value2 + -0x14);
    value2 = value2 + 1;
  } while (value2 < 0x523);
  return;
}
