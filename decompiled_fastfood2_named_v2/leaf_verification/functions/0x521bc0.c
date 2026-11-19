// rea decompile_all
// name: FUN_00521bc0
// address: 0x521bc0
// body: available
// range: 0x521bc0-0x521d9a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_00521bc0(void *this,uint param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  void *this_00;
  int iVar4;
  undefined2 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 *this_01;
  float10 extraout_ST0;
  float10 extraout_ST1;
  longlong lVar8;
  short sVar9;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a5eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  iVar1 = FUN_00539840(*(void **)((int)this + 0x68),param_1);
  if ((int)param_2 < 1) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    iVar3 = FUN_00539840(*(void **)((int)this + 0x68),0xff00);
    this_00 = operator_new(0x50);
    this_01 = (undefined4 *)0x0;
    local_4 = 0;
    if (this_00 != (void *)0x0) {
      this_01 = FUN_0053c710(this_00,param_2,param_2,iVar3,0x10,4);
    }
    local_4 = 0xffffffff;
    FUN_0053d6c0(this_01,iVar3);
    Sprite_SetColorKey(this_01,iVar3);
    puVar2 = operator_new(0xc);
    puVar2[1] = this_01;
    *puVar2 = 1;
    iVar3 = FUN_0053d480(this_01);
    if (param_2 == 1) {
      FUN_0053d6c0(this_01,iVar1);
    }
    else {
      iVar4 = (int)param_2 >> 1;
      if ((param_2 & 1) == 0) {
        sVar9 = -(short)iVar4;
        Sprite_SetHotspot(this_01,sVar9,sVar9);
        param_1 = iVar3 + (param_2 + 1) * iVar4 * 2;
        uVar7 = iVar3 + ((iVar4 + -1) * param_2 + iVar4) * 2;
      }
      else {
        sVar9 = -(short)iVar4;
        uVar7 = iVar3 + (param_2 + 1) * iVar4 * 2;
        Sprite_SetHotspot(this_01,sVar9,sVar9);
        param_1 = uVar7;
      }
      if (0.0 <= (float)iVar4) {
        do {
          lVar8 = __ftol();
          iVar3 = (int)lVar8;
          if (iVar3 == 0) {
            iVar3 = 1;
          }
          iVar6 = (param_2 & 1) + iVar3;
          if (-iVar3 < iVar6) {
            puVar5 = (undefined2 *)(uVar7 + iVar3 * -2);
            iVar6 = iVar6 + iVar3;
            do {
              *(short *)((param_1 - uVar7) + (int)puVar5) = (short)iVar1;
              *puVar5 = (short)iVar1;
              puVar5 = puVar5 + 1;
              iVar6 = iVar6 + -1;
            } while (iVar6 != 0);
          }
          param_1 = param_1 + param_2 * 2;
          uVar7 = uVar7 + param_2 * -2;
        } while (extraout_ST0 + extraout_ST1 <= (float10)iVar4);
      }
    }
  }
  ExceptionList = local_c;
  return puVar2;
}

