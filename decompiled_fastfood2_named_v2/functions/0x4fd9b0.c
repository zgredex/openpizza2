// rea decompile_all
// name: FUN_004fd9b0
// address: 0x4fd9b0
// body: available
// range: 0x4fd9b0-0x4fdaf2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004fd9b0(void *this,void *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  void *this_00;
  undefined4 uVar3;
  void *pvVar4;
  void *pvVar5;
  
  iVar1 = FUN_004e1d40(param_1,0x1f);
  if (iVar1 < 2) {
    FUN_004fea70(this,param_1,4.34403e-44);
  }
  piVar2 = FUN_004e1e40(param_1,0x1f);
  if (piVar2 == (int *)0x0) {
    return 3;
  }
  this_00 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 0x3c),*piVar2,(int *)0x0);
  if (this_00 == (void *)0x0) {
    return 3;
  }
  switch(param_3) {
  case 0x1a:
    pvVar5 = (void *)0x1388;
    pvVar4 = (void *)0x3;
    break;
  case 0x1b:
    pvVar5 = (void *)0x2710;
    pvVar4 = (void *)0x7;
    break;
  case 0x1c:
    pvVar5 = (void *)0x2710;
    pvVar4 = (void *)0x9;
    break;
  default:
    pvVar4 = param_1;
    pvVar5 = param_1;
    break;
  case 0x2d:
    pvVar5 = (void *)0x1388;
    pvVar4 = (void *)0xd;
  }
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)(param_2 + 0x30));
  iVar1 = FUN_004ddcc0(iVar1);
  uVar3 = FUN_004e0b60(param_1,0x17,
                       (float)((((*(int *)(iVar1 + 0x68) + *(int *)(iVar1 + 0x50)) * 0x1e + 100) *
                               (int)pvVar5) / 100),'\x01',0xffffffff);
  if ((char)uVar3 == '\0') {
    return 3;
  }
  FUN_0050b680(this_00,param_2,pvVar4);
  *(int *)((int)param_1 + 0x70) = *(int *)((int)param_1 + 0x70) + 1;
  return 1;
}

