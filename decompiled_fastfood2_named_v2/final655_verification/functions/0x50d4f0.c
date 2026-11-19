// rea decompile_all
// name: Object_ComputeInteractionCell
// address: 0x50d4f0
// body: available
// range: 0x50d4f0-0x50d5ad inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float __thiscall Object_ComputeInteractionCell(void *param_1,float param_2)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  
                    /* Computes the cell a visitor should occupy next to an object. */
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x110));
  uVar2 = FUN_0050b090(param_1,param_2);
  switch(*(undefined4 *)((int)param_1 + 0x30)) {
  case 0xd:
    iVar1 = FUN_0050e810((int)param_1);
    if (iVar1 == 1) {
LAB_0050d570:
      param_2 = (float)(uVar2 + 0x48);
      goto LAB_0050d579;
    }
    if (iVar1 == 2) {
LAB_0050d56b:
      param_2 = (float)(uVar2 + 0x58);
      goto LAB_0050d579;
    }
    bVar3 = iVar1 == 3;
    break;
  default:
    goto switchD_0050d52a_caseD_e;
  case 0x17:
    iVar1 = *(int *)(iVar1 + 100);
    if (iVar1 == 1) goto LAB_0050d570;
    if (iVar1 == 2) goto LAB_0050d56b;
    bVar3 = iVar1 == 3;
    break;
  case 0x1d:
    iVar1 = *(int *)(iVar1 + 0x6c);
    if (iVar1 == 1) goto LAB_0050d570;
    if (iVar1 == 2) goto LAB_0050d56b;
    bVar3 = iVar1 == 3;
    break;
  case 0x1e:
    param_2 = (float)(uVar2 + 0x18);
    UI_SetChildRecordVariant(param_1,(int)param_2);
    goto LAB_0050d579;
  }
  if (bVar3) {
    param_2 = (float)(uVar2 + 0x50);
  }
  else {
switchD_0050d52a_caseD_e:
  }
LAB_0050d579:
  iVar1 = FUN_00489820(DAT_0057c670,*(int *)(*(int *)((int)param_1 + 0xf4) + 8),
                       *(int *)(*(int *)((int)param_1 + 0xf4) + 0x2c));
  FUN_00549970(DAT_0057ba0c,iVar1,*(int *)((int)param_1 + 0x30),8,'\x01');
  return param_2;
}

