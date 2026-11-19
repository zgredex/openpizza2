// rea decompile_all
// name: FUN_0048f710
// address: 0x48f710
// body: available
// range: 0x48f710-0x48f854 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_0048f710(void *param_1)

{
  int iVar1;
  longlong lVar2;
  int iVar3;
  
  iVar1 = *(int *)(DAT_0057c670 + 0x9c);
  if ((*(char *)(iVar1 + 0x16f5) == '\0') && (*(int *)(iVar1 + 0x2c) == 0)) {
    if ((*(int *)(iVar1 + 0x38) == 0) || (*(int *)(iVar1 + 0x38) == 1)) {
      Gadget_SetTextf(param_1,0x4eb,(byte *)s__d__s_00568324,2);
    }
    FUN_005316b0(param_1,0x44f);
  }
  else {
    FUN_00531740(param_1,0x44f);
    iVar3 = *(int *)(*(int *)(iVar1 + 0x16f0) + 0x38);
    if (iVar3 == 0) {
      if ((*(int *)(iVar1 + 0x38) != 0) && (*(int *)(iVar1 + 0x38) != 1)) goto LAB_0048f7c6;
      iVar3 = 2;
    }
    Gadget_SetTextf(param_1,0x4eb,(byte *)s__d__s_00568324,iVar3);
  }
LAB_0048f7c6:
  FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(iVar1 + 0x34),(int *)0x0);
  lVar2 = FUN_004d6390(1,*(int *)(iVar1 + 0x38));
  iVar3 = (int)lVar2;
  iVar1 = *(int *)(*(int *)(DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar1 + 0x11c) == 0) {
    if (*(int *)(iVar1 + 0x200) != 0) {
      iVar3 = (iVar3 * 0xf) / 10;
    }
  }
  else {
    iVar3 = (iVar3 * 5) / 10;
  }
  Gadget_SetTextf(param_1,0x4ee,&DAT_005683a4,iVar3);
  return;
}

