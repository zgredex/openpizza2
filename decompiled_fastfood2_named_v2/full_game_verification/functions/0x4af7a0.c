// rea decompile_all
// name: Character_ComputeRatingArray
// address: 0x4af7a0
// body: available
// range: 0x4af7a0-0x4af8e9 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Character_ComputeRatingArray(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int local_c;
  int local_8;
  
  puVar3 = param_1;
  iVar6 = DAT_0057d664 - DAT_0057d668;
  local_c = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  if (local_c == 0) {
    local_c = 0;
  }
  else {
    local_c = local_c + 4;
  }
  for (iVar5 = 0x12; iVar5 != 0; iVar5 = iVar5 + -1) {
    *param_1 = 0;
    param_1 = param_1 + 1;
  }
  local_8 = 8;
  do {
    iVar5 = 200;
    *puVar3 = *(undefined4 *)(local_c + 0x1fc + iVar6 * 4);
    puVar3[2] = *(undefined4 *)(local_c + 0x23c + iVar6 * 4);
    puVar3[4] = *(undefined4 *)(local_c + 0x21c + iVar6 * 4);
    puVar3[6] = *(undefined4 *)(local_c + 0x25c + iVar6 * 4);
    puVar3[8] = *(undefined4 *)(&DAT_0056a08c + iVar6 * 4);
    puVar3[10] = *(undefined4 *)(&DAT_0056a0ac + iVar6 * 4);
    puVar3[0xc] = *(undefined4 *)(&DAT_0056a0cc + iVar6 * 4);
    puVar3[0xe] = *(undefined4 *)(&DAT_0056a0ec + iVar6 * 4);
    param_1 = puVar3 + 1;
    puVar3[0x10] = *(undefined4 *)(&DAT_0056a10c + iVar6 * 4);
    piVar7 = (int *)(local_c + 0x27c + iVar6 * 4);
    do {
      iVar2 = *piVar7;
      iVar4 = IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
      piVar1 = (int *)(iVar5 + iVar4);
      iVar5 = iVar5 + 4;
      piVar7 = piVar7 + 8;
      *param_1 = *(undefined4 *)(&DAT_0056a134 + (*piVar1 + iVar2) * 4);
      param_1 = param_1 + 2;
    } while (iVar5 < 0xe0);
    puVar3[0xd] = *(undefined4 *)(&DAT_0056a140 + iVar6 * 4);
    puVar3[0xf] = *(undefined4 *)(&DAT_0056a180 + iVar6 * 4);
    local_8 = local_8 + -1;
    puVar3[0x11] = *(undefined4 *)(&DAT_0056a160 + iVar6 * 4);
  } while (local_8 != 0);
  return;
}

