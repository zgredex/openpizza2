// rea decompile_all
// name: Gfx_DrawFilledEllipse
// address: 0x53e5a0
// body: available
// range: 0x53e5a0-0x53e9fc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl
Gfx_DrawFilledEllipse(int param_1,int param_2,uint param_3,int param_4,undefined2 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  longlong lVar14;
  uint local_34;
  uint local_30;
  int local_2c;
  int local_28;
  uint local_24;
  int local_1c;
  int local_14;
  int local_10;
  
  if (0 < param_4) {
    iVar10 = -9999;
    iVar1 = *(int *)(param_1 + 4);
    local_2c = -9999;
    iVar2 = *(int *)(param_1 + 8);
    iVar3 = *(int *)(param_1 + 0xc);
    iVar4 = *(int *)(param_1 + 0x10);
    iVar5 = *(int *)(param_1 + 0x20);
    local_30 = 0xffffd8f1;
    local_28 = -9999;
    uVar11 = 0xffffd8f1;
    local_1c = 0;
    if (0 < param_4) {
      local_14 = iVar5 * param_3 * 2;
      local_34 = param_3;
      local_24 = param_3;
      local_10 = local_14;
      do {
        if ((iVar4 < (int)local_34) && ((int)local_24 < iVar3)) {
          if (local_1c < param_4) {
            return;
          }
          break;
        }
        lVar14 = __ftol();
        iVar8 = (int)lVar14;
        if (((int)local_34 < iVar4) && (iVar3 <= (int)local_34)) {
          iVar12 = *(int *)(param_1 + 0x28) + local_14;
          if ((uVar11 == 0xffffd8f1) || (uVar13 = param_2 - iVar8, uVar11 == uVar13)) {
            uVar11 = param_2 - iVar8;
            uVar13 = uVar11;
            if ((iVar1 <= (int)uVar11) && ((int)uVar11 < iVar2)) {
              *(undefined2 *)(iVar12 + uVar11 * 2) = param_5;
            }
          }
          else if ((int)uVar11 < (int)uVar13) {
            puVar7 = (undefined2 *)(iVar12 + uVar11 * 2);
            do {
              uVar11 = uVar11 + 1;
              puVar7 = puVar7 + 1;
              if ((iVar1 <= (int)uVar11) && ((int)uVar11 < iVar2)) {
                *puVar7 = param_5;
              }
            } while ((int)uVar11 < (int)uVar13);
          }
          if ((iVar10 == -9999) || (iVar9 = param_2 + iVar8, iVar10 == iVar9)) {
            iVar10 = param_2 + iVar8;
            local_28 = iVar10;
            if ((iVar1 <= iVar10) && (iVar10 < iVar2)) {
              *(undefined2 *)(iVar12 + iVar10 * 2) = param_5;
            }
          }
          else if (iVar9 < iVar10) {
            puVar7 = (undefined2 *)(iVar12 + iVar10 * 2);
            do {
              iVar10 = iVar10 + -1;
              puVar7 = puVar7 + -1;
              if ((iVar1 <= iVar10) && (iVar10 < iVar2)) {
                *puVar7 = param_5;
              }
            } while (iVar9 < iVar10);
            local_28 = iVar10;
          }
          if ((local_34 & 1) != 0) {
            uVar6 = uVar13;
            if ((uVar13 & 1) != 0) {
              uVar6 = uVar13 ^ 1;
            }
            if ((local_34 & 2) == 0) {
              uVar6 = uVar6 | 2;
            }
            else if ((uVar6 & 2) != 0) {
              uVar6 = uVar6 ^ 2;
            }
            if ((int)uVar6 < (int)uVar13) {
              uVar6 = uVar6 + 4;
            }
            if ((int)uVar6 < param_2 + iVar8) {
              puVar7 = (undefined2 *)(iVar12 + uVar6 * 2);
              do {
                if ((iVar1 <= (int)uVar6) && ((int)uVar6 < iVar2)) {
                  *puVar7 = param_5;
                }
                uVar6 = uVar6 + 4;
                puVar7 = puVar7 + 4;
              } while ((int)uVar6 < param_2 + iVar8);
            }
          }
        }
        else {
          iVar10 = iVar8 + param_2;
          uVar11 = param_2 - iVar8;
          uVar13 = uVar11;
          local_28 = iVar10;
        }
        iVar8 = param_2 + iVar8;
        if (((int)local_24 < iVar4) && (iVar3 <= (int)local_24)) {
          iVar12 = *(int *)(param_1 + 0x28) + local_10;
          if ((local_30 == 0xffffd8f1) || (local_30 == uVar13)) {
            local_30 = uVar13;
            if ((iVar1 <= (int)uVar13) && ((int)uVar13 < iVar2)) {
              *(undefined2 *)(iVar12 + uVar13 * 2) = param_5;
            }
          }
          else if ((int)local_30 < (int)uVar13) {
            puVar7 = (undefined2 *)(iVar12 + local_30 * 2);
            do {
              local_30 = local_30 + 1;
              puVar7 = puVar7 + 1;
              if ((iVar1 <= (int)local_30) && ((int)local_30 < iVar2)) {
                *puVar7 = param_5;
              }
            } while ((int)local_30 < (int)uVar13);
            iVar10 = local_28;
          }
          if ((local_2c == -9999) || (local_2c == iVar8)) {
            local_2c = iVar8;
            if ((iVar1 <= iVar8) && (iVar8 < iVar2)) {
              *(undefined2 *)(iVar12 + iVar8 * 2) = param_5;
            }
          }
          else if (iVar8 < local_2c) {
            puVar7 = (undefined2 *)(iVar12 + local_2c * 2);
            do {
              local_2c = local_2c + -1;
              puVar7 = puVar7 + -1;
              if ((iVar1 <= local_2c) && (local_2c < iVar2)) {
                *puVar7 = param_5;
              }
            } while (iVar8 < local_2c);
            iVar10 = local_28;
          }
          if ((local_24 & 1) != 0) {
            uVar6 = uVar13;
            if ((uVar13 & 1) != 0) {
              uVar6 = uVar13 ^ 1;
            }
            if ((local_24 & 2) == 0) {
              uVar6 = uVar6 | 2;
            }
            else if ((uVar6 & 2) != 0) {
              uVar6 = uVar6 ^ 2;
            }
            if ((int)uVar6 < (int)uVar13) {
              uVar6 = uVar6 + 4;
            }
            if ((int)uVar6 < iVar8) {
              puVar7 = (undefined2 *)(iVar12 + uVar6 * 2);
              do {
                if ((iVar1 <= (int)uVar6) && ((int)uVar6 < iVar2)) {
                  *puVar7 = param_5;
                }
                uVar6 = uVar6 + 4;
                puVar7 = puVar7 + 4;
              } while ((int)uVar6 < iVar8);
            }
          }
        }
        else {
          local_30 = uVar13;
          local_2c = iVar8;
        }
        local_14 = local_14 + iVar5 * 2;
        local_1c = local_1c + 1;
        local_10 = local_10 + iVar5 * -2;
        local_34 = local_34 + 1;
        local_24 = local_24 - 1;
      } while (local_1c < param_4);
      if ((((uVar11 != 0xffffd8f1) && (iVar10 != -9999)) &&
          (iVar8 = param_3 + param_4, iVar3 <= iVar8)) &&
         ((iVar8 < iVar4 && ((int)uVar11 < iVar10)))) {
        puVar7 = (undefined2 *)(*(int *)(param_1 + 0x28) + iVar8 * iVar5 * 2 + uVar11 * 2);
        do {
          uVar11 = uVar11 + 1;
          puVar7 = puVar7 + 1;
          if ((iVar1 <= (int)uVar11) && ((int)uVar11 < iVar2)) {
            *puVar7 = param_5;
          }
        } while ((int)uVar11 < iVar10);
      }
      if ((((local_30 != 0xffffd8f1) && (local_2c != -9999)) &&
          (iVar10 = param_3 - param_4, iVar3 <= iVar10)) &&
         ((iVar10 < iVar4 && ((int)local_30 < local_2c)))) {
        puVar7 = (undefined2 *)(*(int *)(param_1 + 0x28) + iVar10 * iVar5 * 2 + local_30 * 2);
        do {
          local_30 = local_30 + 1;
          puVar7 = puVar7 + 1;
          if ((iVar1 <= (int)local_30) && ((int)local_30 < iVar2)) {
            *puVar7 = param_5;
          }
        } while ((int)local_30 < local_2c);
      }
    }
  }
  return;
}

