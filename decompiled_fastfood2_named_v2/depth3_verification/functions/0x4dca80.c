// rea decompile_all
// name: FUN_004dca80
// address: 0x4dca80
// body: available
// range: 0x4dca80-0x4dcb2c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004dca80(int param_1)

{
  int iVar1;
  void *pvVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int local_20 [8];
  
  piVar8 = (int *)(param_1 + 0x6c);
  piVar5 = local_20;
  iVar6 = 8;
  piVar7 = (int *)(&DAT_0056ca2c + *(int *)(param_1 + 0x10bc) * 0x24);
  do {
    iVar3 = *piVar8;
    iVar1 = *piVar7;
    piVar7 = piVar7 + 1;
    piVar8 = piVar8 + 1;
    *piVar5 = (iVar3 * iVar1) / 100;
    piVar5 = piVar5 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  iVar6 = 0;
  if (0 < *(int *)(DAT_0057c670 + 0x50)) {
    do {
      pvVar2 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 0x3c),iVar6,(int *)0x0);
      iVar3 = FUN_0050dbd0((int)pvVar2);
      if ((((iVar3 == 0) && (iVar3 = *(int *)((int)pvVar2 + 0x30), iVar3 < 8)) &&
          (*(int *)((int)pvVar2 + 0x38) != 0x1a)) &&
         (uVar4 = FUN_004034d0(1,100), (int)uVar4 <= local_20[iVar3])) {
        FUN_0050e4e0(pvVar2);
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(DAT_0057c670 + 0x50));
  }
  return;
}

