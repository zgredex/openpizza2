// rea decompile_all
// name: UI_ShowChoiceMessageBox
// address: 0x5268c0
// body: available
// range: 0x5268c0-0x526ce7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __cdecl UI_ShowChoiceMessageBox(void *param_1,char *param_2,int param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  void *this;
  char *pcVar2;
  undefined4 *puVar3;
  DWORD DVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  longlong lVar10;
  int *local_c4;
  int local_c0;
  int local_bc;
  int local_b4;
  int local_b0;
  int local_ac;
  double local_a8;
  undefined4 local_a0 [10];
  int local_78 [10];
  undefined4 local_50 [20];
  
                    /* Creates a modal choice message box and returns the selected button. */
  cVar6 = '\0';
  if (0 < param_3) {
    puVar1 = &param_4;
    puVar3 = local_a0;
    uVar5 = param_4;
    iVar9 = param_3;
    do {
      *puVar3 = uVar5;
      uVar5 = puVar1[1];
      puVar1 = puVar1 + 1;
      puVar3 = puVar3 + 1;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
  }
  this = (void *)UI_LoadFontByName(param_1,*(char **)((int)param_1 + 0x288));
  if (this == (void *)0x0) {
    return -1;
  }
  if (*(int *)((int)param_1 + 0x278) == 1) {
    return -1;
  }
  *(undefined4 *)((int)param_1 + 0x278) = 1;
  while (param_2 != (char *)0x0) {
    local_50[cVar6] = param_2;
    cVar6 = cVar6 + '\x01';
    pcVar2 = _strchr(param_2,10);
    if (pcVar2 == (char *)0x0) break;
    *pcVar2 = '\0';
    param_2 = pcVar2 + 1;
  }
  iVar7 = (int)cVar6;
  local_a8 = (double)iVar7;
  lVar10 = __ftol();
  iVar9 = 0;
  local_c0 = 0;
  if (0 < iVar7) {
    puVar3 = local_50;
    iVar8 = iVar7;
    do {
      local_b0 = Font_MeasureText(this,(char *)*puVar3);
      if (iVar9 < local_b0) {
        iVar9 = local_b0;
        local_c0 = local_b0;
      }
      puVar3 = puVar3 + 1;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  if (0 < param_3) {
    puVar3 = local_a0;
    local_bc = param_3;
    do {
      iVar8 = Font_MeasureText(this,(char *)*puVar3);
      local_b0 = (iVar8 + 0x14) * param_3;
      if (iVar9 < local_b0) {
        iVar9 = local_b0;
        local_c0 = local_b0;
      }
      puVar3 = puVar3 + 1;
      local_bc = local_bc + -1;
    } while (local_bc != 0);
  }
  *(undefined4 *)((int)param_1 + 0x280) = 0;
  local_ac = UI_CreateFixedWindow
                       (param_1,*(int *)((int)param_1 + 0x270) - iVar9 >> 1,
                        *(int *)((int)param_1 + 0x274) - (int)lVar10 >> 1,iVar9,(int)lVar10,
                        &LAB_00526830,0,*(undefined4 *)((int)param_1 + 0x29c),
                        *(undefined4 *)((int)param_1 + 0x2a0),*(undefined4 *)((int)param_1 + 0x2a4),
                        *(undefined4 *)((int)param_1 + 0x2a8));
  puVar3 = (undefined4 *)UI_FindWindowByID(param_1,local_ac,(int *)0x0);
  iVar8 = 0;
  if (0 < iVar7) {
    puVar1 = local_50;
    do {
      UI_AddText(puVar3,iVar8,0,0,*(char **)((int)param_1 + 0x288),(char *)*puVar1);
      lVar10 = __ftol();
      UI_CenterChildVertically(puVar3,iVar8,(int)lVar10);
      Window_GadgetNotify_Text_SetTextColor(puVar3,iVar8,*(undefined4 *)((int)param_1 + 0x298));
      iVar8 = iVar8 + 1;
      puVar1 = puVar1 + 1;
    } while (iVar8 < iVar7);
    iVar9 = local_c0;
  }
  lVar10 = __ftol();
  iVar7 = (int)lVar10;
  local_b4 = 0;
  if (0 < param_3) {
    local_c4 = (int *)0x0;
    iVar9 = 1000;
    do {
      UI_AddTextButton(puVar3,iVar9,0,iVar7,*(char **)((int)param_1 + 0x288),
                       *(char **)((int)local_a0 + (int)local_c4),0,(char *)0x0);
      Gadget_SetButtonColors
                (puVar3,iVar9,*(undefined4 *)((int)param_1 + 0x28c),
                 *(undefined4 *)((int)param_1 + 0x290),*(undefined4 *)((int)param_1 + 0x294));
      Array_GetRectByKey(puVar3,iVar9,(int *)((int)local_78 + (int)local_c4),&local_b0);
      iVar8 = *(int *)((int)local_78 + (int)local_c4);
      if (local_b4 < iVar8) {
        local_b4 = iVar8;
      }
      local_c4 = (int *)((int)local_c4 + 4);
      iVar8 = iVar9 + -999;
      iVar9 = iVar9 + 1;
    } while (iVar8 < param_3);
    iVar9 = local_c0;
  }
  if (param_3 == 1) {
    UI_CenterChildVertically(puVar3,1000,iVar7);
    UI_AddUniquePair(puVar3,1000,0xd);
    iVar9 = 1000;
  }
  else {
    iVar8 = 0;
    if (0 < param_3) {
      local_c4 = local_78;
      local_c0 = 0;
      do {
        UI_SetObjectRangeByKey
                  (puVar3,iVar8 + 1000,(iVar9 / param_3 - *local_c4) / 2 + local_c0,iVar7);
        iVar8 = iVar8 + 1;
        local_c4 = local_c4 + 1;
        local_c0 = local_c0 + iVar9 / param_3;
      } while (iVar8 < param_3);
    }
    if (param_3 != 2) goto LAB_00526c5d;
    UI_AddUniquePair(puVar3,1000,0xd);
    iVar9 = 0x3e9;
  }
  UI_AddUniquePair(puVar3,iVar9,0x1b);
LAB_00526c5d:
  Window_ShowWindowById(param_1,local_ac);
  Set_Field228(param_1,puVar3);
  iVar9 = *(int *)((int)param_1 + 0x280);
  while ((iVar9 == 0 && (DVar4 = WaitForSingleObject(DAT_0057c0d8,0), DVar4 != 0))) {
    Window_ProcessMessageQueue(param_1,0);
    Sleep(10);
    iVar9 = *(int *)((int)param_1 + 0x280);
  }
  Clear_Field228((int)param_1);
  Window_DestroyChild(param_1,puVar3);
  *(undefined4 *)((int)param_1 + 0x278) = 0;
  UI_ReleaseRefCount(param_1,(int)this);
  return *(int *)((int)param_1 + 0x27c) + -1000;
}

