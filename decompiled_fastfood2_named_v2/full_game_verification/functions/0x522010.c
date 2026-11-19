// rea decompile_all
// name: UI_TextLabel_Construct
// address: 0x522010
// body: available
// range: 0x522010-0x5221b2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
UI_TextLabel_Construct
          (void *this,undefined4 param_1,int param_2,int param_3,char *param_4,char *param_5,
          int param_6,int param_7,undefined4 *param_8)

{
  undefined1 uVar1;
  uint uVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int3 extraout_var_01;
  int iVar3;
  undefined3 extraout_var_02;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  undefined4 *puVar7;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Constructs an auto-wrapping text label. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a608;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  UI_Child_Construct(this,param_1,param_2,param_3,param_7);
  *(undefined ***)this = &PTR_UI_LabelElement_Delete_0055c758;
  pvVar5 = *(void **)(param_7 + 0x134);
  *param_8 = 0;
  local_4 = 0;
  *(undefined4 *)((int)this + 0x40) = 4;
  *(undefined4 *)((int)this + 0x58) = 0;
  uVar2 = UI_LoadFontByName(pvVar5,param_4);
  *(uint *)((int)this + 0x54) = uVar2;
  if (uVar2 == 0) {
    *param_8 = 1;
  }
  else {
    UI_SetAbsolutePosition(this,param_6,*(int *)(uVar2 + 0x9b0));
    *(undefined4 *)((int)this + 0x5c) = 0xa0a0a0;
    *(undefined4 *)((int)this + 0x60) = 0xa0a000;
    *(undefined4 *)((int)this + 100) = 0xffffff;
    *(undefined4 *)((int)this + 0x68) = 0xff0000;
    *(undefined4 *)((int)this + 0x74) = 0;
    uVar1 = Font_GetCharWidth(*(void **)((int)this + 0x54),0x20);
    *(int *)((int)this + 0x84) = param_6 - CONCAT31(extraout_var,uVar1);
    *(undefined4 *)((int)this + 0x78) = 0;
    *(undefined4 *)((int)this + 0x6c) = 0;
    *(undefined4 *)((int)this + 0x88) = 0xfffffc19;
    *(undefined4 *)((int)this + 0x98) = 0;
    uVar1 = Font_GetCharWidth(*(void **)((int)this + 0x54),0x20);
    iVar4 = CONCAT31(extraout_var_00,uVar1);
    uVar2 = 0x21;
    do {
      uVar1 = Font_GetCharWidth(*(void **)((int)this + 0x54),uVar2);
      iVar3 = CONCAT31(extraout_var_01,uVar1);
      if ((iVar3 != 0 && -1 < extraout_var_01) && (iVar3 < iVar4)) {
        iVar4 = iVar3;
      }
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x100);
    if (iVar4 == 0) {
      uVar1 = Font_GetCharWidth(*(void **)((int)this + 0x54),0x69);
      iVar4 = CONCAT31(extraout_var_02,uVar1);
    }
    if (*(int *)((int)this + 0x84) < iVar4 * 2) {
      *(int *)((int)this + 0x84) = iVar4 * 2;
    }
    iVar4 = *(int *)((int)this + 0x84) / iVar4;
    *(int *)((int)this + 0x78) = iVar4;
    pvVar5 = operator_new(iVar4 + 1);
    *(void **)((int)this + 0x6c) = pvVar5;
    pvVar5 = operator_new(*(int *)((int)this + 0x78) + 1);
    uVar6 = *(int *)((int)this + 0x78) + 1;
    *(void **)((int)this + 0x70) = pvVar5;
    puVar7 = *(undefined4 **)((int)this + 0x6c);
    for (uVar2 = uVar6 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    uVar6 = *(int *)((int)this + 0x78) + 1;
    puVar7 = *(undefined4 **)((int)this + 0x70);
    for (uVar2 = uVar6 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *(undefined1 *)puVar7 = 0;
      puVar7 = (undefined4 *)((int)puVar7 + 1);
    }
    UI_SetTextFit(this,param_5);
    *(undefined4 *)((int)this + 0x80) = 0;
    *(undefined4 *)((int)this + 0x7c) = 0;
  }
  ExceptionList = local_c;
  return this;
}

