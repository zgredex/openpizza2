// rea decompile_all
// name: FUN_004b0d80
// address: 0x4b0d80
// body: available
// range: 0x4b0d80-0x4b10d0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004b0d80(void *param_1,undefined4 *param_2,int param_3,float param_4,float param_5)

{
  uint *puVar1;
  uint *puVar2;
  ushort uVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  void *this;
  void *this_00;
  void *pvVar7;
  uint uVar8;
  int iVar9;
  longlong lVar10;
  longlong lVar11;
  int local_3c;
  int local_38;
  uint *local_34;
  undefined1 local_20 [32];
  
  this = param_1;
  uVar3 = *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  uVar8 = (uint)uVar3;
  this_00 = (void *)FUN_00531cf0(param_1,param_3);
  FUN_00521380((int)this_00);
  if (param_2 == (undefined4 *)0x0) {
    FUN_00521b30((int)this_00);
    return;
  }
  if (uVar8 == 0) {
    FUN_00521ae0(this_00,(int *)&param_1,&param_3);
    pvVar7 = (void *)FUN_00521b10((int)this_00);
    FUN_00535520(DAT_0057d690,(int)param_1 / 2,param_3 / 2,2);
    FUN_00535500(DAT_0057d690,0);
    FUN_00535740(DAT_0057d690,pvVar7,DAT_00581444);
    FUN_0052f9b0(this,(int)param_4,DAT_00582e4c);
    FUN_0052f9b0(this,(int)param_5,DAT_00582e4c);
    FUN_00521b30((int)this_00);
    return;
  }
  param_2 = (undefined4 *)*param_2;
  if (uVar3 < 0x29) {
    local_3c = 0;
    local_34 = (uint *)uVar8;
  }
  else {
    local_3c = uVar8 - 0x28;
    local_34 = (uint *)0x28;
  }
  FUN_00521ae0(this_00,(int *)&param_1,&param_3);
  FUN_00521bc0(this_00,0,3);
  param_1 = (void *)((int)param_1 + -3);
  fVar5 = (float)(int)param_1;
  param_3 = param_3 + -3;
  fVar4 = (float)(int)local_34;
  String_Format(local_20,(byte *)s__0_2f_005685f4,0);
  FUN_0052f9b0(this,(int)param_4,local_20);
  String_Format(local_20,(byte *)s__d__d_00568ef8,*(byte *)(*(int *)(DAT_0057c670 + 0x94) + 8) + 1);
  FUN_0052f9b0(this,(int)param_5,local_20);
  local_34 = &DAT_0056a6f8;
  local_38 = 0;
  param_4 = (float)param_3 * 0.01;
  do {
    param_5 = 0.0;
    iVar6 = local_3c;
    if (local_3c == 0) {
      FUN_004d3940(param_2,local_38,0);
      __ftol();
    }
    else {
      FUN_004d3940(param_2,local_38,local_3c + -1);
    }
    for (; iVar6 < (int)uVar8; iVar6 = iVar6 + 1) {
      param_5 = param_5 + fVar5 / fVar4;
      FUN_004d3940(param_2,local_38,iVar6);
      lVar10 = __ftol();
      iVar9 = param_3 - (int)lVar10;
      lVar10 = __ftol();
      puVar1 = (uint *)((int)lVar10 + 2);
      lVar10 = __ftol();
      lVar11 = __ftol();
      puVar2 = (uint *)((int)lVar11 + 2);
      FUN_00521740(this_00,puVar2,(int)lVar10 + 3,puVar1,iVar9 + 3,0);
      FUN_00521740(this_00,puVar2,(int)lVar10 + 2,puVar1,iVar9 + 2,*local_34);
    }
    local_38 = local_38 + 1;
    local_34 = local_34 + 1;
  } while ((int)local_34 < 0x56a70c);
  return;
}

