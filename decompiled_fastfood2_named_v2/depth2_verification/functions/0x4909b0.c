// rea decompile_all
// name: FUN_004909b0
// address: 0x4909b0
// body: available
// range: 0x4909b0-0x490afa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004909b0(void *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  
  DAT_0057c6a0 = *(void **)(DAT_0057c670 + 0x9c);
  FUN_004f2e50(*(void **)((int)DAT_0057c6a0 + 0x14e0),(int)DAT_0057c6a0);
  DAT_00568404 = 0xffffffff;
  DAT_0057c6a4 = *(int *)((int)DAT_0057c6a0 + 0x14d8);
  if (DAT_0057c6a4 == -1) {
    uVar4 = DAT_00582afc;
  }
  else {
    uVar4 = (&DAT_0058374c)[DAT_0057c6a4];
  }
  FUN_0052f830(param_1,0x4d1,uVar4);
  iVar2 = 0x1f59;
  do {
    FUN_00531470(param_1,iVar2,0);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x1f65);
  piVar3 = &DAT_00568420;
  do {
    UI_SetChildLabelText(param_1,*piVar3,1,(char *)0x0);
    piVar3 = piVar3 + 1;
  } while ((int)piVar3 < 0x568450);
  FUN_0052f9b0(param_1,0x562,DAT_00582e4c);
  FUN_004902a0(param_1);
  FUN_00492270(param_1,0x589,DAT_0057c6ac);
  FUN_00531470(param_1,0x589,0);
  FUN_0052f9b0(param_1,0x5a2,DAT_00582e4c);
  FUN_0052f9b0(param_1,0x5a3,DAT_00582e4c);
  FUN_0052f9b0(param_1,0x5a5,DAT_00582e4c);
  FUN_0052f9b0(param_1,0x5a4,DAT_00582e4c);
  iVar2 = 0;
  do {
    iVar5 = DAT_00582320;
    iVar1 = FUN_00478be0(DAT_0057c6a0,DAT_00582320,iVar2);
    FUN_004a80e0(param_1,0x559,iVar2,iVar1,iVar5);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}

