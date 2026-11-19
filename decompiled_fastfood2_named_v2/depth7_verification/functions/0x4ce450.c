// rea decompile_all
// name: FUN_004ce450
// address: 0x4ce450
// body: available
// range: 0x4ce450-0x4ce604 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004ce450(void *param_1)

{
  int iVar1;
  void *pvVar2;
  char *pcVar3;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558cd6;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00532310(param_1,&LAB_004ce3b0,0);
  FUN_0052f9b0(param_1,0x440,DAT_00582464);
  FUN_0052f9b0(param_1,0x441,DAT_00581ac0);
  pvVar2 = operator_new(0x1c);
  local_4 = 0;
  if (pvVar2 == (void *)0x0) {
    DAT_0057df88 = (undefined4 *)0x0;
  }
  else {
    DAT_0057df88 = List_Construct(pvVar2,0);
  }
  local_4 = 0xffffffff;
  DAT_0057df8c = 0;
  FUN_004a1940(DAT_0057df88,0);
  iVar1 = DAT_0057df88[5];
  iVar4 = iVar1 + -1;
  if (iVar4 < 1) {
    iVar4 = 0x7e2;
    do {
      FUN_00531740(param_1,iVar4);
      FUN_00531740(param_1,iVar4 + 100);
      iVar4 = iVar4 + -1;
    } while (2000 < iVar4);
    FUN_00531740(param_1,0x462);
    pvVar2 = operator_new(0x58);
    local_4 = 1;
    if (pvVar2 == (void *)0x0) {
      pcVar3 = (char *)0x0;
    }
    else {
      pcVar3 = FUN_00403370(pvVar2,DAT_00581ab4,0xffffffff);
    }
    local_4 = 0xffffffff;
    FUN_004014b0(DAT_0057df88,pcVar3);
  }
  else if (iVar4 < 0x13) {
    FUN_00531740(param_1,0x462);
    iVar4 = 0x7e2;
    if (iVar1 + 1999 < 0x7e2) {
      do {
        FUN_00531740(param_1,iVar4);
        FUN_00531740(param_1,iVar4 + 100);
        iVar4 = iVar4 + -1;
      } while (iVar1 + 1999 < iVar4);
    }
  }
  else {
    FUN_0052fd00(param_1,0x462,0,(iVar1 + -0x5b + iVar4 * 4) * 0x14,1);
    FUN_0052fd70(param_1,0x462,0,0);
    FUN_0052fce0(param_1,0x462,1);
  }
  FUN_004ce3c0(param_1,DAT_0057df8c);
  ExceptionList = local_c;
  return;
}

