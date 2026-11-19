// rea decompile_all
// name: FUN_005476f0
// address: 0x5476f0
// body: available
// range: 0x5476f0-0x547760 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_005476f0(int *param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  char *pcVar6;
  char *pcVar7;
  int *piVar8;
  
  iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  uVar3 = 0xffffffff;
  pcVar6 = (char *)(iVar2 + 0x44);
  do {
    pcVar7 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  piVar5 = (int *)(pcVar7 + -uVar3);
  piVar8 = param_1 + 0x5d;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *piVar8 = *piVar5;
    piVar5 = piVar5 + 1;
    piVar8 = piVar8 + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)piVar8 = (char)*piVar5;
    piVar5 = (int *)((int)piVar5 + 1);
    piVar8 = (int *)((int)piVar8 + 1);
  }
  FUN_005478c0(param_1);
  param_1[0x51] = 0;
  param_1[0x53] = 0;
  param_1[0x5c] = 0x3f800000;
  param_1[6] = 1000;
  return;
}

