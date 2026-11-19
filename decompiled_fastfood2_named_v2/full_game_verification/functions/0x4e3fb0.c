// rea decompile_all
// name: FurnitureType_Construct
// address: 0x4e3fb0
// body: available
// range: 0x4e3fb0-0x4e4021 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __fastcall FurnitureType_Construct(undefined4 *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  
                    /* Constructs a furniture-type record with defaults and tile ranges. */
  uVar3 = 0xffffffff;
  *param_1 = &PTR_FurnitureType_Delete_0055c5a0;
  param_1[2] = 0xc;
  param_1[3] = 0xb;
  param_1[4] = 4;
  param_1[5] = 3;
  pcVar6 = &DAT_00579aec;
  do {
    pcVar7 = pcVar6;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar6 = pcVar7 + -uVar3;
  pcVar7 = (char *)(param_1 + 6);
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  iVar5 = 8;
  puVar2 = param_1 + 0x1e;
  do {
    iVar5 = iVar5 + -1;
    *puVar2 = 0xffffffff;
    puVar2[1] = 0xffffffff;
    puVar2 = puVar2 + 3;
  } while (iVar5 != 0);
  return param_1;
}

