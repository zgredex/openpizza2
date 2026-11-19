// rea decompile_all
// name: FUN_00478ae0
// address: 0x478ae0
// body: available
// range: 0x478ae0-0x478bdf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_00478ae0(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  local_10 = 0;
  local_14 = param_1[1];
  local_c = 0;
  local_8 = 0;
  local_4 = 0;
  local_10 = FUN_004d3fc0((int)param_1);
  local_c = param_1[3];
  FUN_004d3fe0((int)param_1);
  iVar1 = param_1[0xe];
  piVar8 = param_2;
  for (iVar3 = 8; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar8 = 0;
    piVar8 = piVar8 + 1;
  }
  param_1 = &local_14;
  piVar8 = &DAT_005676d8;
  do {
    iVar6 = 8;
    iVar3 = *param_1;
    piVar7 = param_2;
    do {
      iVar4 = iVar3 - *piVar8;
      if (iVar4 < 0) {
        iVar4 = iVar4 >> 2;
      }
      else {
        iVar4 = iVar4 / 5;
      }
      piVar8 = piVar8 + 1;
      *piVar7 = *piVar7 + iVar4 + 0x19;
      piVar7 = piVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    param_1 = param_1 + 1;
  } while ((int)piVar8 < 0x567758);
  iVar3 = (int)&DAT_00567758 - (int)param_2;
  iVar6 = 8;
  do {
    uVar2 = iVar1 - *(int *)(iVar3 + (int)param_2);
    uVar5 = (int)uVar2 >> 0x1f;
    iVar4 = *param_2 - ((uVar2 ^ uVar5) - uVar5);
    *param_2 = iVar4;
    if (iVar4 < 0) {
      *param_2 = 0;
    }
    if (100 < *param_2) {
      *param_2 = 100;
    }
    param_2 = param_2 + 1;
    iVar6 = iVar6 + -1;
  } while (iVar6 != 0);
  return;
}

