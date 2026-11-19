// rea decompile_all
// name: FUN_00527850
// address: 0x527850
// body: available
// range: 0x527850-0x527936 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00527850(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_c;
  int local_8;
  
  iVar3 = *(int *)(param_1 + 0x82fc);
  local_c = 0;
  if (0 < iVar3) {
    local_8 = 0;
    do {
      piVar4 = (int *)(local_8 + 0x44 + *(int *)(param_1 + 0x82f8));
      iVar2 = local_c;
      if (*(int *)(local_8 + 0x44 + *(int *)(param_1 + 0x82f8)) == 0) {
        for (; (iVar2 < iVar3 && (*piVar4 == 0)); piVar4 = piVar4 + 0x12) {
          iVar2 = iVar2 + 1;
        }
        iVar6 = iVar2 + -1;
        iVar3 = (iVar6 - local_c) + 1;
        iVar5 = iVar3;
        iVar7 = local_8;
        if (local_c <= iVar6) {
          do {
            puVar1 = *(undefined4 **)(iVar7 + 0x40 + *(int *)(param_1 + 0x82f8));
            if (puVar1 != (undefined4 *)0x0) {
              (**(code **)*puVar1)(1);
            }
            iVar7 = iVar7 + 0x48;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        iVar5 = (*(int *)(param_1 + 0x82fc) - iVar6) + -1;
        if (0 < iVar5) {
          FUN_0054e230((undefined4 *)(local_8 + *(int *)(param_1 + 0x82f8)),
                       (undefined4 *)(*(int *)(param_1 + 0x82f8) + (iVar2 + 8 + iVar6 * 8) * 8),
                       iVar5 * 0x48);
        }
        *(int *)(param_1 + 0x82fc) = *(int *)(param_1 + 0x82fc) - iVar3;
      }
      iVar3 = *(int *)(param_1 + 0x82fc);
      local_c = local_c + 1;
      local_8 = local_8 + 0x48;
    } while (local_c < iVar3);
  }
  return;
}

