// rea decompile_all
// name: AI_Action_AnnoyRival
// address: 0x4fd610
// body: available
// range: 0x4fd610-0x4fd794 inclusive
// range: 0x4fd7b3-0x4fd813 inclusive
// range: 0x4fd841-0x4fd947 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Switch with 1 destination removed at 0x004fd78e */

undefined4 __thiscall AI_Action_AnnoyRival(void *this,int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  void *pvVar5;
  undefined4 unaff_EDI;
  char *pcVar6;
  undefined4 uVar7;
  byte *pbVar8;
  
                    /* Runs an AI annoyance/sabotage action against a rival. */
  iVar1 = FUN_00489b10((int)DAT_0057c670);
  if (iVar1 < *(int *)((int)this + param_1 * 0x168 + 0x48)) {
    return 1;
  }
  *(int *)((int)this + param_1 * 0x168 + 0x48) =
       (100 - *(short *)((int)this + param_1 * 0x168 + 0x130) >> 1) + 1 + iVar1;
  pvVar2 = (void *)FUN_00488be0(DAT_0057c670,*(int *)((int)this + param_1 * 0x168 + 0x40));
  iVar3 = FUN_004e2280((int)pvVar2);
  if (iVar3 == 0) {
    return 1;
  }
  if (*(int *)((int)this + param_1 * 0x168 + 0x11c) == -1) {
    uVar4 = FUN_004e2280((int)pvVar2);
    uVar4 = FUN_004034d0(1,uVar4);
    *(uint *)((int)this + param_1 * 0x168 + 0x11c) = uVar4;
    switch(uVar4) {
    case 1:
      uVar4 = _rand();
      *(uint *)((int)this + param_1 * 0x168 + 0x120) = uVar4 & 3;
      break;
    case 2:
    case 3:
    case 5:
      uVar4 = _rand();
      *(uint *)((int)this + param_1 * 0x168 + 0x120) = uVar4 & 1;
      break;
    case 4:
      uVar4 = _rand();
      if ((uVar4 & 1) == 0) {
        iVar3 = _rand();
        *(int *)((int)this + param_1 * 0x168 + 0x120) = iVar3 % 3;
      }
      else {
        *(undefined4 *)((int)this + param_1 * 0x168 + 0x120) = 3;
      }
      break;
    case 6:
      *(undefined4 *)((int)this + param_1 * 0x168 + 0x120) = 0;
    }
    *(undefined4 *)((int)this + param_1 * 0x168 + 0x124) = 0;
  }
  uVar4 = 0;
  pvVar5 = (void *)FUN_004fdbe0(this,param_1);
  if (pvVar5 == (void *)0x0) goto switchD_004fd863_switchD;
  switch(*(undefined4 *)((int)this + param_1 * 0x168 + 0x11c)) {
  case 1:
    uVar4 = AI_TryTakeOverRivalBranch(pvVar2,param_1,pvVar5);
    goto LAB_004fd783;
  case 2:
    iVar3 = *(int *)((int)this + param_1 * 0x168 + 0x120);
    if (iVar3 == 0) {
      uVar4 = AI_SendGraffitiPunk(pvVar2,(int)pvVar5);
    }
    else {
      if (iVar3 != 1) break;
      uVar4 = AI_SendTroublePunks(pvVar2,(int)pvVar5);
    }
    goto LAB_004fd783;
  case 3:
    iVar3 = *(int *)((int)this + param_1 * 0x168 + 0x120);
    if (iVar3 == 0) {
      uVar7 = 0x1b;
    }
    else {
      if (iVar3 != 1) break;
      uVar7 = 0x1c;
    }
    goto LAB_004fd77a;
  case 4:
    switch(*(undefined4 *)((int)this + param_1 * 0x168 + 0x120)) {
    case 0:
      uVar7 = 0x1a;
      goto LAB_004fd77a;
    case 1:
      uVar7 = 0x2d;
LAB_004fd77a:
      uVar4 = AI_Annoy_HireHarasser(this,pvVar2,(int)pvVar5,uVar7);
      break;
    case 2:
      uVar4 = AI_Annoy_SendGangsterGroup(this,pvVar2,(int)pvVar5);
      break;
    case 3:
      uVar4 = AI_StartAdvertisingCampaign(pvVar2,(int)pvVar5);
      break;
    default:
      goto switchD_004fd72f_default;
    }
LAB_004fd783:
    if (uVar4 < 5) break;
    pbVar8 = &DAT_00568310;
    goto LAB_004fd852;
  case 5:
    if (*(int *)((int)this + param_1 * 0x168 + 0x120) == 0) {
      AI_AssignBuilderToConstructionSite(pvVar2,pvVar5);
    }
    break;
  case 6:
    if (*(int *)((int)this + param_1 * 0x168 + 0x120) == 0) {
      AI_Annoy_SendThugsToHeadquarters(this,pvVar2,(int)pvVar5);
    }
  }
switchD_004fd72f_default:
  pbVar8 = &DAT_005721cc;
LAB_004fd852:
  FUN_0054a660(DAT_0057c1e0,0xff00ff,pbVar8,unaff_EDI);
  if (4 < uVar4) {
switchD_004fd863_caseD_2:
    pcVar6 = s_KI__KIAnnoy___Undefinied_return___00572194;
    uVar7 = 0xc000;
LAB_004fd92c:
    FUN_0054a660(DAT_0057c1e0,uVar7,(byte *)pcVar6,uVar4);
    return 1;
  }
switchD_004fd863_switchD:
  switch(uVar4) {
  default:
    *(undefined4 *)((int)this + param_1 * 0x168 + 0x11c) = 0xffffffff;
    *(undefined4 *)((int)this + param_1 * 0x168 + 0x120) = 0xffffffff;
    *(int *)((int)this + param_1 * 0x168 + 0x48) = iVar1;
    return 3;
  case 1:
    FUN_004fcc30(this,param_1,-3);
    *(undefined4 *)((int)this + param_1 * 0x168 + 0x11c) = 0xffffffff;
    *(undefined4 *)((int)this + param_1 * 0x168 + 0x120) = 0xffffffff;
    return 1;
  case 2:
    goto switchD_004fd863_caseD_2;
  case 3:
    *(int *)((int)this + param_1 * 0x168 + 0x124) =
         *(int *)((int)this + param_1 * 0x168 + 0x124) + 1;
    uVar4 = FUN_004034d0(0,10);
    if (*(int *)((int)this + param_1 * 0x168 + 0x124) <= (int)uVar4) {
      *(int *)((int)this + param_1 * 0x168 + 0x48) = iVar1 + 1;
      return 1;
    }
    uVar4 = 3;
    *(undefined4 *)((int)this + param_1 * 0x168 + 0x11c) = 0xffffffff;
    pcVar6 = s_Cancel_action_005721bc;
    *(undefined4 *)((int)this + param_1 * 0x168 + 0x120) = 0xffffffff;
    uVar7 = 0xff00ff;
    goto LAB_004fd92c;
  case 4:
    *(int *)((int)this + param_1 * 0x168 + 0x48) = iVar1 + 1;
    return 1;
  }
}

