// rea decompile_all
// name: Map_FloodFillMask
// address: 0x531e10
// body: available
// range: 0x531e10-0x531f3f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void Map_FloodFillMask(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int local_288;
  uint local_284;
  uint local_280 [160];
  
                    /* Leaf reversal proposal batch 1. */
  local_288 = 0;
  iVar6 = 1;
  local_280[0] = param_3 * 0x10000 + param_2;
  uVar5 = local_284;
  uVar7 = local_284;
  do {
    puVar1 = local_280 + local_288;
    local_288 = local_288 + 1;
    if (0x9f < local_288) {
      local_288 = 0;
    }
    uVar2 = (int)*puVar1 >> 0x10;
    uVar8 = *puVar1 & 0xffff;
    *(undefined1 *)(uVar2 * param_4 + param_1 + uVar8) = 1;
    local_284 = 0;
    do {
      switch(local_284) {
      case 0:
        uVar5 = uVar8 - 1;
        uVar7 = uVar2;
        break;
      case 1:
        uVar5 = uVar8 + 1;
        uVar7 = uVar2;
        break;
      case 2:
        uVar5 = uVar8;
        uVar7 = uVar2 + 1;
        break;
      case 3:
        uVar5 = uVar8;
        uVar7 = uVar2 - 1;
      }
      if ((((-1 < (int)uVar5) && (-1 < (int)uVar7)) && ((int)uVar5 < param_4)) &&
         (((int)uVar7 < param_5 && (*(char *)(uVar7 * param_4 + uVar5 + param_1) == '\0')))) {
        uVar4 = uVar7 * 0x10000 + uVar5;
        iVar3 = local_288;
        while (iVar3 != iVar6) {
          if (local_280[iVar3] == uVar4) {
            if (iVar3 != iVar6) goto LAB_00531f17;
            break;
          }
          iVar3 = iVar3 + 1;
          if (0x9f < iVar3) {
            iVar3 = 0;
          }
        }
        local_280[iVar6] = uVar4;
        iVar6 = iVar6 + 1;
        if (0x9f < iVar6) {
          iVar6 = 0;
        }
      }
LAB_00531f17:
      local_284 = local_284 + 1;
    } while ((int)local_284 < 4);
    if (local_288 == iVar6) {
      return;
    }
  } while( true );
}

