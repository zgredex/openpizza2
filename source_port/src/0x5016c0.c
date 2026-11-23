// Company_ExecuteAction: ported from Pizza Connection 2 at 0x5016c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5016c0
#include "pc2_port.h"

void __thiscall Company_ExecuteAction(void *self,uint32_t arg1)

{
  short svalue1;
  short svalue2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char cVar5;
  char *cptr6;
  int value7;
  void *pvVar8;
  uint32_t extraout_var;
  int value9;
  int value10;
  int unaff_ESI;
  int unaff_EDI;
  int *ptr11;
  uint64_t uvalue12;
  
                    /* Executes a company's pending AI action. */
  uvalue4 = arg1;
  value10 = 0;
  value9 = 0;
  if (DAT_00572490 == 1) {
    DAT_00572490 = 0;
    ptr11 = &DAT_00580a64;
    do {
      cptr6 = Game_GetPlanName(value10);
      value7 = String_RegisterSlot(cptr6);
      *ptr11 = value7;
      ptr11 = ptr11 + 1;
      value10 = value10 + 1;
    } while ((intptr_t)ptr11 < 0x580ac8);
  }
  value10 = *(int *)((intptr_t)self + arg1 * 0x168 + 0x74);
  uvalue3 = *(uint32_t *)((intptr_t)self + arg1 * 0x168 + 0x80);
  if (value10 < 0) {
    pvVar8 = (void *)0x0;
  }
  else {
    pvVar8 = (void *)Game_GetPlayerSubmapValue
                               (DAT_0057c670,*(int *)((intptr_t)self + arg1 * 0x168 + 0x40),value10);
    if (pvVar8 == (void *)0x0) {
      arg1 = 2;
      goto LAB_00501766;
    }
  }
  if (uvalue3 == 0) {
    return;
  }
  arg1 = uvalue3;
  if (uvalue3 == 0x18) {
    return;
  }
LAB_00501766:
  Profiler_StartTimer((&DAT_00580a64)[arg1]);
  switch(arg1) {
  case 1:
    cVar5 = Game_GetDateStage(self,uvalue4);
    value9 = CONCAT31(extraout_var,cVar5);
    break;
  case 5:
    value9 = AI_Action_BuyOrRentBranch(self,uvalue4);
    break;
  case 7:
    if (pvVar8 != (void *)0x0) {
      value9 = Branch_ValidateMenuAndRecalculate(self,pvVar8);
    }
    break;
  case 8:
    value9 = Customer_VisitBranch
                      (uvalue4,(intptr_t)pvVar8,(void *)0xffffffff,-1,-1,(uint32_t *)0xffffffff,unaff_EDI
                       ,unaff_ESI);
    break;
  case 9:
    value9 = Branch_ApplyStyleSettings(self,uvalue4,pvVar8);
    break;
  case 10:
    value9 = Company_OpenBranchAtSite(self,uvalue4,pvVar8);
    break;
  case 0xb:
    value9 = City_TickBranches(self,uvalue4);
    break;
  case 0xc:
    value9 = AI_Action_AssignSuppliers(self,uvalue4);
    break;
  case 0xd:
    value9 = AI_CheckBranchGuards(self,uvalue4);
    break;
  case 0x10:
    value9 = AI_Action_AnnoyRival(self,uvalue4);
    break;
  case 0x11:
    value9 = AI_ManageGangsters(self,uvalue4);
    break;
  case 0x13:
    value9 = Company_OptimizeMenuPricing(self,uvalue4);
    break;
  case 0x14:
    value9 = AI_ImproveSecurity(self,uvalue4);
    break;
  case 0x15:
    Game_UpdateCompanyAdvancementScore(self,uvalue4);
  case 2:
    value9 = 1;
    break;
  case 0x16:
    uvalue12 = AI_Action_BuildNewBranch(self,uvalue4);
    value9 = (intptr_t)uvalue12;
    break;
  case 0x17:
    value9 = AI_UpdateAdvertisingCampaigns(self,uvalue4);
  }
  Profiler_StopTimer((&DAT_00580a64)[arg1]);
  switch(value9) {
  case 0:
    UI_RemoveListEntryAt(self,uvalue4,0);
    Company_PushRecentEntry(self,uvalue4,1,-1,-1);
    return;
  case 1:
  case 5:
  case 7:
    UI_RemoveListEntryByType(self,uvalue4,arg1,value10);
    return;
  case 2:
    UI_RemoveListEntryByType(self,uvalue4,arg1,value10);
    return;
  case 3:
    svalue2 = *(short *)((intptr_t)self + uvalue4 * 0x168 + 0x7e);
    svalue1 = svalue2 + -1;
    *(short *)((intptr_t)self + uvalue4 * 0x168 + 0x7e) = svalue1;
    if ((svalue2 != 0) && (svalue1 < 1)) {
      UI_RemoveListEntryByType(self,uvalue4,arg1,value10);
    }
  }
  return;
}
