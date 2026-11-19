// rea decompile_all
// name: FUN_005145a0
// address: 0x5145a0
// body: available
// range: 0x5145a0-0x51465c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_005145a0(void)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  
  piVar2 = FUN_00402290(DAT_0057c5d8,s_language_ldf_00573b2c,1);
  uVar3 = FUN_004029d0((int)piVar2);
  DAT_00580ad8 = operator_new(uVar3);
  FUN_00402750(DAT_0057c5d8,(char *)DAT_00580ad8,uVar3,(int)piVar2);
  FUN_00402990(DAT_0057c5d8,(int)piVar2);
  DAT_00580ad0 = *DAT_00580ad8;
  DAT_00580ad4 = operator_new(DAT_00580ad0 * 4);
  piVar2 = DAT_00580ad8 + 1;
  iVar4 = 0;
  if (0 < DAT_00580ad0) {
    do {
      uVar3 = 0xffffffff;
      *(int **)((int)DAT_00580ad4 + iVar4 * 4) = piVar2;
      piVar5 = piVar2;
      do {
        if (uVar3 == 0) break;
        uVar3 = uVar3 - 1;
        iVar1 = *piVar5;
        piVar5 = (int *)((int)piVar5 + 1);
      } while ((char)iVar1 != '\0');
      iVar4 = iVar4 + 1;
      piVar2 = (int *)((int)piVar2 + ~uVar3);
    } while (iVar4 < DAT_00580ad0);
  }
  FUN_005146d0();
  FUN_0051e650();
  CRT_Onexit(0x514580);
  return;
}

