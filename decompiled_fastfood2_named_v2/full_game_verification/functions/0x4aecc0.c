// rea decompile_all
// name: Stats_BuildObjectProductMatrix
// address: 0x4aecc0
// body: available
// range: 0x4aecc0-0x4aed97 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Stats_BuildObjectProductMatrix(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int local_20 [8];
  
  piVar4 = param_1;
  piVar7 = param_1;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  piVar7 = local_20;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  iVar3 = 0;
  if (0 < *(int *)(DAT_0057c670 + 0x50)) {
    do {
      iVar2 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),iVar3,(int *)0x0);
      iVar6 = *(int *)(iVar2 + 0x30);
      if (iVar6 < 8) {
        piVar7 = (int *)(iVar2 + 0xd4);
        local_20[iVar6] = local_20[iVar6] + 1;
        iVar6 = 0;
        do {
          if (*(int *)(*piVar7 + 4) == *(int *)(&DAT_00569f0c + DAT_0057d64c * 4)) {
            iVar1 = iVar6 + *(int *)(iVar2 + 0x30) * 8;
            param_1[iVar1] = param_1[iVar1] + 1;
          }
          iVar6 = iVar6 + 1;
          piVar7 = piVar7 + 1;
        } while (iVar6 < 8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(DAT_0057c670 + 0x50));
  }
  piVar7 = local_20;
  param_1 = (int *)0x8;
  do {
    iVar3 = *piVar7;
    iVar6 = 8;
    piVar5 = piVar4;
    do {
      piVar4 = piVar5 + 1;
      iVar6 = iVar6 + -1;
      *piVar5 = (iVar3 / 2 + *piVar5 * 100) / iVar3;
      piVar5 = piVar4;
    } while (iVar6 != 0);
    piVar7 = piVar7 + 1;
    param_1 = (int *)((int)param_1 + -1);
  } while (param_1 != (int *)0x0);
  return;
}

