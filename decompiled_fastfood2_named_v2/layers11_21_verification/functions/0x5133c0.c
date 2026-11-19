// rea decompile_all
// name: FUN_005133c0
// address: 0x5133c0
// body: available
// range: 0x5133c0-0x513589 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_005133c0(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int *local_8;
  int local_4;
  
  piVar2 = (int *)(param_1 + 0x284);
  piVar7 = piVar2;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar7 = 0;
    piVar7 = piVar7 + 1;
  }
  iVar3 = *(int *)(param_1 + 0x250);
  *(int *)(param_1 + 0x2a0) = *(int *)(param_1 + 0x2a0) + iVar3 * 10;
  *(int *)(param_1 + 0x290) = *(int *)(param_1 + 0x290) + iVar3 * -10;
  iVar6 = *(int *)(param_1 + 0x254) * 5;
  iVar4 = *(int *)(param_1 + 0x254) * 10;
  *(int *)(param_1 + 0x28c) = *(int *)(param_1 + 0x28c) + iVar3 * 5 + iVar6;
  iVar8 = *(int *)(param_1 + 0x294) + iVar3 * 5 + iVar4;
  *(int *)(param_1 + 0x294) = iVar8;
  iVar4 = *(int *)(param_1 + 0x298) + iVar4 + iVar3 * 10;
  *(int *)(param_1 + 0x298) = iVar4;
  iVar3 = *(int *)(param_1 + 0x29c) + iVar6 + iVar3 * -10;
  *(int *)(param_1 + 0x29c) = iVar3;
  if (*(int *)(param_1 + 0x240) != 0) {
    *(int *)(param_1 + 0x29c) = iVar3 + 0x1e;
    *(int *)(param_1 + 0x294) = iVar8 + 0x1e;
    *(int *)(param_1 + 0x298) = iVar4 + 5;
    *(int *)(param_1 + 0x2a0) = *(int *)(param_1 + 0x2a0) + 0x1e;
  }
  if (200 < *(int *)(param_1 + 0x1d8)) {
    *piVar2 = *piVar2 + 10;
    *(int *)(param_1 + 0x288) = *(int *)(param_1 + 0x288) + 0x28;
    *(int *)(param_1 + 0x298) = *(int *)(param_1 + 0x298) + -0x14;
  }
  if (300 < *(int *)(param_1 + 0x1d8)) {
    *(int *)(param_1 + 0x290) = *(int *)(param_1 + 0x290) + 0x28;
    *(int *)(param_1 + 0x294) = *(int *)(param_1 + 0x294) + -0x14;
    *(int *)(param_1 + 0x29c) = *(int *)(param_1 + 0x29c) + -0x14;
    *(int *)(param_1 + 0x2a0) = *(int *)(param_1 + 0x2a0) + 0x28;
  }
  iVar3 = FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  local_8 = (int *)(iVar3 + 0x280);
  local_4 = 8;
  piVar7 = piVar2;
  do {
    piVar5 = (int *)(param_1 + 0x1c0);
    iVar3 = 6;
    piVar1 = local_8;
    do {
      iVar6 = *piVar5;
      piVar5 = piVar5 + 1;
      *piVar7 = *piVar7 + iVar6 * *piVar1;
      piVar1 = piVar1 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    piVar7 = piVar7 + 1;
    local_8 = local_8 + 1;
    local_4 = local_4 + -1;
  } while (local_4 != 0);
  iVar3 = *(int *)(param_1 + 0x5c);
  if (iVar3 < 0x14) {
    iVar6 = 8;
    do {
      iVar6 = iVar6 + -1;
      *piVar2 = *piVar2 + (0x14 - iVar3) * -5;
      piVar2 = piVar2 + 1;
    } while (iVar6 != 0);
  }
  return;
}

