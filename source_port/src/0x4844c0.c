// SubMenu_BuildBranchInteriorPage: ported from Pizza Connection 2 at 0x4844c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4844c0
#include "pc2_port.h"

int __fastcall SubMenu_BuildBranchInteriorPage(int arg1)

{
  void *pvVar1;
  int local_4;
  
                    /* Builds a branch-interior submenu page. */
  *(uint32_t *)(arg1 + 0x2d8) = 0;
  local_4 = arg1;
  if (*(int *)(arg1 + 0x268) != 0) {
    Game_CloseSelectionDialog(arg1);
  }
  switch(*(uint32_t *)(arg1 + 0x298 + *(int *)(arg1 + 0x290) * 4)) {
  case 1:
    pvVar1 = SubMenu_BuildCompetitorBranchInfo(&local_4);
    Window_UpdateBranchInfoPage(pvVar1,'\0');
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 2:
    pvVar1 = Screen_CompetitorDetails(&local_4);
    PersonnelPanel_Update(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 3:
    pvVar1 = Window_BuildBranchManagerPage(&local_4);
    JobMarketPanel_Update(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 4:
    pvVar1 = Window_BuildBranchProductsPage(&local_4);
    BranchMenu_UpdatePage(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 5:
    pvVar1 = SubMenu_BuildPizzaContestInvitation(&local_4);
    CompanyList_InitCompanyRows(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 6:
    pvVar1 = SubMenu_BuildAnnoyances(&local_4);
    StaffCosts_UpdatePage(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 7:
    pvVar1 = SubMenu_BuildAttacks(&local_4);
    ProtectionDemand_UpdatePage(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  case 8:
    pvVar1 = SubMenu_BuildRatingComparison(&local_4);
    OtherManagerPage_Update(pvVar1);
    *(void **)(arg1 + 0x264) = pvVar1;
    return local_4;
  default:
    *(int *)(arg1 + 0x264) = local_4;
    return local_4;
  }
}
