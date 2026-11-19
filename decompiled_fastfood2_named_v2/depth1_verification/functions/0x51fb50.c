// rea decompile_all
// name: Map_GenerateRandomTiles
// address: 0x51fb50
// body: available
// range: 0x51fb50-0x51fd9d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Variable defined which should be unmapped: param_3 */

uint * __thiscall Map_GenerateRandomTiles(int param_1,uint *param_2,uint *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  uint *puVar9;
  int local_8;
  
                    /* Depth-1 proposal batch 3/4. */
  puVar6 = param_3;
  iVar1 = _rand();
  *(int *)(param_1 + 0x18) = iVar1 % 10;
  uVar2 = _rand();
  if ((uVar2 & 1) == 0) {
    iVar1 = _rand();
    iVar7 = (int)param_3 * param_4;
    if (0 < iVar7) {
      for (; iVar7 != 0; iVar7 = iVar7 + -1) {
        *param_2 = iVar1 % 10;
        param_2 = param_2 + 1;
      }
    }
  }
  else if (((*(int *)(param_1 + 0x18) == 8) || (*(int *)(param_1 + 0x18) == 9)) &&
          (uVar2 = _rand(), (uVar2 & 1) != 0)) {
    uVar2 = _rand();
    iVar1 = (int)param_3 >> 1;
    if ((uVar2 & 1) == 0) {
      iVar7 = 0;
      if (0 < (int)param_4) {
        param_3 = param_2;
        do {
          iVar8 = 0;
          if (0 < (int)puVar6) {
            iVar3 = iVar7 - ((int)param_4 >> 1);
            puVar9 = param_3;
            do {
              iVar4 = iVar8 - iVar1;
              if ((iVar3 < 1) || (iVar4 < 1)) {
                if (iVar3 < 0) {
                  if (iVar4 < 0) {
                    *puVar9 = 5;
                  }
                  else {
                    if (iVar4 < 1) goto LAB_0051fcc7;
                    *puVar9 = 6;
                  }
                }
                else {
LAB_0051fcc7:
                  if ((iVar3 < 1) || (-1 < iVar4)) {
                    *puVar9 = 9;
                  }
                  else {
                    *puVar9 = 7;
                  }
                }
              }
              else {
                *puVar9 = 4;
              }
              iVar8 = iVar8 + 1;
              puVar9 = puVar9 + 1;
            } while (iVar8 < (int)puVar6);
          }
          iVar7 = iVar7 + 1;
          param_3 = param_3 + (int)puVar6;
          if ((int)param_4 <= iVar7) {
            return param_3;
          }
        } while( true );
      }
    }
    else {
      local_8 = 0;
      if (0 < (int)param_4) {
        do {
          iVar7 = 0;
          if (0 < (int)param_3) {
            uVar2 = local_8 - ((int)param_4 >> 1);
            iVar8 = (uVar2 ^ (int)uVar2 >> 0x1f) - ((int)uVar2 >> 0x1f);
            puVar6 = param_2;
            do {
              uVar5 = iVar7 - iVar1;
              iVar3 = (uVar5 ^ (int)uVar5 >> 0x1f) - ((int)uVar5 >> 0x1f);
              if (((int)uVar2 < 1) || (iVar8 < iVar3)) {
                if (((int)uVar2 < 0) && (iVar3 <= iVar8)) {
                  *puVar6 = 1;
                }
                else if (((int)uVar5 < 0) && (iVar8 < iVar3)) {
                  *puVar6 = 3;
                }
                else if (((int)uVar5 < 1) || (iVar3 <= iVar8)) {
                  *puVar6 = 8;
                }
                else {
                  *puVar6 = 2;
                }
              }
              else {
                *puVar6 = 0;
              }
              iVar7 = iVar7 + 1;
              puVar6 = puVar6 + 1;
            } while (iVar7 < (int)param_3);
          }
          local_8 = local_8 + 1;
          param_2 = param_2 + (int)param_3;
        } while (local_8 < (int)param_4);
        return param_3;
      }
    }
  }
  else {
    iVar1 = _rand();
    iVar1 = iVar1 % 3;
    if (iVar1 == 0) {
      puVar9 = (uint *)0x0;
      puVar6 = (uint *)0x3;
    }
    else if (iVar1 == 1) {
      puVar9 = (uint *)0x4;
      puVar6 = (uint *)0x3;
    }
    else if (iVar1 == 2) {
      puVar6 = (uint *)0x7;
      puVar9 = (uint *)0x0;
    }
    else {
      puVar9 = param_3;
    }
    iVar1 = (int)param_3 * param_4;
    if (0 < iVar1) {
      do {
        uVar2 = _rand();
        iVar1 = iVar1 + -1;
        *param_2 = (uVar2 & (uint)puVar6) + (int)puVar9;
        param_2 = param_2 + 1;
      } while (iVar1 != 0);
      return param_3;
    }
  }
  return param_3;
}

