// Customer_VisitBranch: ported from Pizza Connection 2 at 0x4fb660.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fb660
#include "pc2_port.h"

int Customer_VisitBranch
              (int arg1,int arg2,void *arg3,int arg4,int arg5,uint32_t *arg6,
              int arg7,int arg8)

{
  int value1;
  int extraout_ECX;
  uint32_t unaff_EBX;
  uint32_t uvalue2;
  char *unaff_EBP;
  char *unaff_ESI;
  char *unaff_EDI;
  bool flag3;
  uint8_t unaff_retaddr;
  int value4;
  int iStack00000024;
  uint32_t uStack00000028;
  uint32_t uStack0000002c;
  uint32_t uStack00000030;
  int in_stack_00001938;
  void *in_stack_0000193c;
  int in_stack_00001940;
  int in_stack_00001944;
  int in_stack_00001948;
  uint32_t in_stack_0000194c;
  char cVar5;
  
                    /* Runs a customer's branch visit and charges the bill. */
  __chkstk(unaff_retaddr);
  if ((*(int *)((intptr_t)in_stack_0000193c + 0x2c) != 0) &&
     (*(int *)((intptr_t)in_stack_0000193c + 0x2c) != 3)) {
    return 1;
  }
  if (*(int *)(*(int *)((intptr_t)in_stack_0000193c + 0x16f0) + 0x38) != 0) {
    return 3;
  }
  if (0 < *(int *)(*(int *)((intptr_t)in_stack_0000193c + 0x16f0) + 0x8c)) {
    Game_MarkAllObjectsDirty(in_stack_0000193c,3);
    return 1;
  }
  if (0 < *(int *)((intptr_t)in_stack_0000193c + 0x170c)) {
    if (((*(uint8_t *)((intptr_t)in_stack_0000193c + 0x28) & 4) == 0) &&
       (6 < *(int *)((intptr_t)in_stack_0000193c + 0x170c))) {
      return 1;
    }
    Branch_ClearInteriorObjects(in_stack_0000193c,0);
    MapObject_SettlePendingAmount(in_stack_0000193c);
  }
  uvalue2 = 0;
  uStack00000030 = in_stack_0000194c;
  if (in_stack_00001940 == -1) {
    if (*(int *)(extraout_ECX + 0x134 + in_stack_00001938 * 0x168) < 80000) {
      *(uint32_t *)((intptr_t)in_stack_0000193c + 0x24) = 0;
      in_stack_00001940 = 0;
    }
    else {
      Map_UpdateVisibleTiles((intptr_t)in_stack_0000193c);
      in_stack_00001940 = *(int *)((intptr_t)in_stack_0000193c + 0x24);
      uStack00000030 = in_stack_0000194c;
    }
  }
  else {
    flag3 = in_stack_00001940 == 4;
    if (flag3) {
      in_stack_00001940 = 0;
    }
    uvalue2 = (uint32_t)flag3;
    *(int *)((intptr_t)in_stack_0000193c + 0x24) = in_stack_00001940;
  }
  arg4 = *(int *)((intptr_t)in_stack_0000193c + 0x38);
  value4 = *(int *)((intptr_t)in_stack_0000193c + 0x30);
  arg5 = 1;
  arg6 = (uint32_t *)0x0;
  arg8 = in_stack_00001944;
  if (in_stack_00001944 == -1) {
    arg8 = 2;
  }
  iStack00000024 = arg8;
  if (in_stack_00001948 != -1) {
    iStack00000024 = in_stack_00001948;
  }
  arg3 = in_stack_0000193c;
  uStack00000028 = uvalue2;
  if (uStack00000030 == 0xffffffff) {
    uStack0000002c = _rand();
    uStack0000002c = uStack0000002c & 1;
    uStack00000030 = _rand();
    uStack00000030 = uStack00000030 & 1;
  }
  else {
    uStack0000002c = uStack00000030;
  }
  value1 = CityMap_GenerateLayout
                    (&arg3,unaff_EDI,unaff_ESI,unaff_EBP,unaff_EBX,value4,arg1,arg2,
                     (intptr_t)arg3,arg4,arg5,(intptr_t)arg6,arg7,arg8);
  if (value1 != 1) {
    IDMap_FreeValuesAndDestroy(arg6);
    return value1;
  }
  Stats_SumRecordCounts(arg6,&arg2,&arg1);
  if (uvalue2 == 0) {
    if (*(int *)(extraout_ECX + 0x114 + in_stack_00001938 * 0x168) == 0) {
      uvalue2 = Game_CanAfford(in_stack_0000193c,4,(float)arg1,'\x01',-1);
      uvalue2 = uvalue2 & 0xff;
      if (uvalue2 == 0) {
        uvalue2 = Game_CanAfford(in_stack_0000193c,4,(float)arg2,'\x01',-1);
        uvalue2 = uvalue2 & 0xff;
        if (uvalue2 == 0) goto LAB_004fb8b9;
        cVar5 = '\0';
      }
      else {
        cVar5 = '\x01';
      }
      Map_CommitPendingObjectEdits((int *)&arg3,cVar5);
    }
    else {
      Game_CanAfford(in_stack_0000193c,4,(float)arg1,'\x01',-1);
      Map_CommitPendingObjectEdits((int *)&arg3,'\x01');
      uvalue2 = 1;
    }
  }
  else {
    Map_CommitPendingObjectEdits((int *)&arg3,'\0');
    *(uint32_t *)((intptr_t)in_stack_0000193c + 0x24) = 4;
    uvalue2 = 1;
  }
LAB_004fb8b9:
  Array_ClearStride34((intptr_t)in_stack_0000193c);
  if (uvalue2 == 0) {
    UI_Briefing_Printf(DAT_0057c670,0x29,5,4,7,*(int *)((intptr_t)in_stack_0000193c + 0x16f0),
                       DAT_005828c0,DAT_00582ea0,(intptr_t)in_stack_0000193c + 4);
    return 2;
  }
  Game_CheckObjectUpgrade(in_stack_0000193c);
  Grid_RebuildStreetNodes(*(void **)((intptr_t)in_stack_0000193c + 0x14e0),(intptr_t)in_stack_0000193c);
  Branch_RecalculateRatings();
  if ((*(int *)(extraout_ECX + 0x114 + in_stack_00001938 * 0x168) != 0) ||
     (value1 = Game_GetCurrentPlayerCompanyName(DAT_0057c670), value4 != value1)) {
    Game_UpdateMusicTheme((intptr_t)in_stack_0000193c,0);
    Branch_AutoTunePrice(in_stack_0000193c);
    return 1;
  }
  value4 = in_stack_00001948 + 5 + in_stack_00001940 * 4;
  value1 = value4 * 0xfa;
  if (in_stack_00001944 == 0) {
    value1 = (value4 * 2000) / 10;
  }
  else if (in_stack_00001944 == 2) {
    value1 = (intptr_t)(value4 * 0x9c4 + (value4 * 0x9c4 >> 0x1f & 7U)) >> 3;
  }
  value4 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value4 + 0xd4) == 0) {
    if (*(int *)(value4 + 0x1b8) != 0) {
      value1 = (value1 * 0xf) / 10;
    }
  }
  else {
    value1 = 0;
  }
  Game_CanAfford(in_stack_0000193c,9,(float)value1,'\0',-1);
  value4 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(value4 + 0xd4) != 0) {
    *(int *)(value4 + 0xd4) = *(int *)(value4 + 0xd4) + -1;
    return 1;
  }
  if (*(int *)(value4 + 0x1b8) == 0) {
    return 1;
  }
  *(int *)(value4 + 0x1b8) = *(int *)(value4 + 0x1b8) + -1;
  return 1;
}
