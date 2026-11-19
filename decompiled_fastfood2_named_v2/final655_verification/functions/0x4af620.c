// rea decompile_all
// name: FUN_004af620
// address: 0x4af620
// body: available
// range: 0x4af620-0x4af796 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004af620(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int *local_534;
  int local_530 [8];
  int local_510 [12];
  int local_4e0;
  int local_480 [96];
  int aiStack_300 [192];
  
  piVar5 = param_1;
  for (iVar3 = 0x40; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  piVar5 = local_530;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  piVar5 = local_510;
  for (iVar3 = 0x24; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  piVar5 = local_480;
  for (iVar3 = 0x120; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  iVar3 = 0;
  if (0 < *(int *)(DAT_0057c670 + 0x50)) {
    do {
      iVar2 = FUN_004017f0((void *)(DAT_0057c670 + 0x3c),iVar3,(int *)0x0);
      if (*(int *)(iVar2 + 0x30) == DAT_0057d664) {
        iVar4 = 0;
        piVar5 = (int *)(iVar2 + 0xd4);
        do {
          iVar2 = *piVar5;
          iVar1 = *(int *)(iVar2 + 4);
          if (iVar1 == 3) {
            aiStack_300[iVar4] = aiStack_300[iVar4] + 1;
            local_4e0 = local_4e0 + 1;
          }
          else {
            iVar1 = iVar4 + iVar1 * 8;
            local_480[iVar1] = local_480[iVar1] + 1;
            iVar2 = *(int *)(iVar2 + 4);
            local_510[iVar2] = local_510[iVar2] + 1;
          }
          piVar5 = piVar5 + 1;
          local_530[iVar4] = local_530[iVar4] + 1;
          iVar4 = iVar4 + 1;
        } while (iVar4 < 8);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < *(int *)(DAT_0057c670 + 0x50));
  }
  piVar5 = local_480;
  local_534 = (int *)0x24;
  do {
    piVar7 = local_530;
    iVar3 = 8;
    piVar6 = piVar5;
    do {
      iVar2 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar5 = piVar6 + 1;
      iVar3 = iVar3 + -1;
      *piVar6 = (iVar2 / 2 + *piVar6 * 100) / iVar2;
      piVar6 = piVar5;
    } while (iVar3 != 0);
    local_534 = (int *)((int)local_534 + -1);
  } while (local_534 != (int *)0x0);
  local_534 = local_510;
  iVar3 = 0;
  piVar5 = local_480;
  do {
    piVar7 = param_1;
    if (0 < *local_534) {
      *param_2 = iVar3;
      param_2 = param_2 + 1;
      piVar7 = param_1 + 8;
      piVar6 = piVar5;
      for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
        *param_1 = *piVar6;
        piVar6 = piVar6 + 1;
        param_1 = param_1 + 1;
      }
    }
    iVar3 = iVar3 + 1;
    local_534 = local_534 + 1;
    piVar5 = piVar5 + 8;
    param_1 = piVar7;
  } while (iVar3 < 0x24);
  return;
}

