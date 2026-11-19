// rea decompile_all
// name: FUN_0050d310
// address: 0x50d310
// body: available
// range: 0x50d310-0x50d40d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float __thiscall FUN_0050d310(void *param_1,float param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x110));
  uVar2 = FUN_0050b090(param_1,param_2);
  iVar3 = FUN_00489820(DAT_0057c670,*(int *)(*(int *)((int)param_1 + 0xf4) + 8),
                       *(int *)(*(int *)((int)param_1 + 0xf4) + 0x2c));
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  case 0xd:
    iVar1 = FUN_0050e810((int)param_1);
    if (iVar1 == 1) {
LAB_0050d3e7:
      FUN_00548210(DAT_0057ba0c,iVar3,0x29);
      return (float)(uVar2 + 0x30);
    }
    if (iVar1 == 2) {
LAB_0050d3cd:
      FUN_00548210(DAT_0057ba0c,iVar3,0x20);
      return (float)(uVar2 + 0x40);
    }
    bVar4 = iVar1 == 3;
    break;
  default:
    goto switchD_0050d36a_caseD_e;
  case 0x17:
    iVar1 = *(int *)(iVar1 + 100);
    if (iVar1 == 1) goto LAB_0050d3e7;
    if (iVar1 == 2) goto LAB_0050d3cd;
    bVar4 = iVar1 == 3;
    break;
  case 0x1d:
    iVar1 = *(int *)(iVar1 + 0x6c);
    if (iVar1 == 1) goto LAB_0050d3e7;
    if (iVar1 == 2) goto LAB_0050d3cd;
    bVar4 = iVar1 == 3;
    break;
  case 0x1e:
    FUN_00548210(DAT_0057ba0c,iVar3,0x28);
    return (float)(uVar2 + 0x10);
  }
  if (bVar4) {
    FUN_00548210(DAT_0057ba0c,iVar3,0x23);
    return (float)(uVar2 + 0x38);
  }
switchD_0050d36a_caseD_e:
  return param_2;
}

