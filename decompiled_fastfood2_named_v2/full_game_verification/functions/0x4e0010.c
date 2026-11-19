// rea decompile_all
// name: Company_ComputeTotals
// address: 0x4e0010
// body: available
// range: 0x4e0010-0x4e0160 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Company_ComputeTotals(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 300) + *(int *)(iVar1 + 0x128) + *(int *)(iVar1 + 0x124) +
          *(int *)(iVar1 + 0x120);
  *(int *)(iVar1 + 0xfc) = iVar2;
  iVar1 = *param_1;
  iVar3 = *(int *)(iVar1 + 0x14c) + *(int *)(iVar1 + 0x148) + *(int *)(iVar1 + 0x144) +
          *(int *)(iVar1 + 0x140);
  *(int *)(iVar1 + 0x100) = iVar3;
  iVar1 = *param_1;
  iVar4 = *(int *)(iVar1 + 0x17c) + *(int *)(iVar1 + 0x178) + *(int *)(iVar1 + 0x174) +
          *(int *)(iVar1 + 0x170);
  *(int *)(iVar1 + 0x104) = iVar4;
  iVar1 = *param_1;
  iVar5 = *(int *)(iVar1 + 0x19c) + *(int *)(iVar1 + 0x198) + *(int *)(iVar1 + 0x194) +
          *(int *)(iVar1 + 400);
  *(int *)(iVar1 + 0x108) = iVar5;
  iVar1 = *param_1;
  iVar6 = *(int *)(iVar1 + 0x16c) + *(int *)(iVar1 + 0x168) + *(int *)(iVar1 + 0x164) +
          *(int *)(iVar1 + 0x160);
  *(int *)(iVar1 + 0x10c) = iVar6;
  iVar1 = *param_1;
  iVar7 = *(int *)(iVar1 + 0x15c) + *(int *)(iVar1 + 0x158) + *(int *)(iVar1 + 0x154) +
          *(int *)(iVar1 + 0x150);
  *(int *)(iVar1 + 0x110) = iVar7;
  iVar1 = *param_1;
  iVar8 = *(int *)(iVar1 + 0x13c) + *(int *)(iVar1 + 0x138) + *(int *)(iVar1 + 0x134) +
          *(int *)(iVar1 + 0x130);
  *(int *)(iVar1 + 0x114) = iVar8;
  iVar1 = *param_1;
  iVar9 = *(int *)(iVar1 + 0x18c) + *(int *)(iVar1 + 0x188) + *(int *)(iVar1 + 0x184) +
          *(int *)(iVar1 + 0x180);
  *(int *)(iVar1 + 0x118) = iVar9;
  *(int *)(*param_1 + 0x11c) = iVar9 + iVar2 + iVar3 + iVar4 + iVar5 + iVar6 + iVar7 + iVar8;
  return;
}

