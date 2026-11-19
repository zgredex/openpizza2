// rea decompile_all
// name: FUN_00534e20
// address: 0x534e20
// body: available
// range: 0x534e20-0x535149 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00534e20(void *this,uint *param_1)

{
  uint *puVar1;
  short *psVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  short sVar7;
  uint uVar8;
  int iVar9;
  short sVar10;
  int iVar11;
  short *psVar12;
  short sVar13;
  int iVar14;
  short *psVar15;
  uint *local_20;
  int local_1c;
  int local_14;
  uint local_8;
  
  puVar6 = param_1;
  local_20 = (uint *)(((int)*param_1 < 0) - 1 & *param_1);
  puVar3 = *(uint **)((int)this + 4);
  if ((int)puVar3 < (int)local_20) {
    local_20 = puVar3;
  }
  puVar1 = param_1 + 2;
  param_1 = puVar3;
  if ((int)*puVar1 <= (int)puVar3) {
    param_1 = (uint *)*puVar1;
  }
  uVar8 = puVar6[1];
  uVar8 = ((int)uVar8 < 0) - 1 & uVar8;
  uVar4 = *(uint *)((int)this + 8);
  if ((int)uVar4 < (int)uVar8) {
    uVar8 = uVar4;
  }
  local_8 = puVar6[3];
  if ((int)uVar4 < (int)local_8) {
    local_8 = uVar4;
  }
  if ((0 < (int)param_1 - (int)local_20) && (0 < (int)(local_8 - uVar8))) {
    for (; (int)uVar8 < (int)local_8; uVar8 = uVar8 + 1) {
      iVar5 = *(int *)((int)this + 0x10);
      local_1c = 0;
      psVar2 = (short *)(*(int *)((int)this + 0x14) + iVar5 * uVar8 * 2);
      iVar9 = *(int *)((int)this + 0xc);
      sVar13 = (short)local_20;
      sVar10 = (short)param_1;
      psVar12 = psVar2;
      if (0 < iVar9) {
        do {
          if (*psVar12 == -1) {
            *psVar12 = sVar13;
            psVar12[1] = sVar10;
            break;
          }
          if ((int)local_20 <= (int)*psVar12) {
            if ((int)param_1 < (int)*psVar12) {
              if (psVar2[iVar5 + -4] != -1) {
                iVar11 = *(int *)((int)this + 4) << 1;
                iVar14 = 0;
                if (0 < iVar9 + -1) {
                  psVar15 = psVar2 + 1;
                  do {
                    if ((int)psVar15[1] - (int)*psVar15 < iVar11) {
                      iVar11 = (int)psVar15[1] - (int)*psVar15;
                      local_14 = iVar14;
                    }
                    iVar14 = iVar14 + 1;
                    psVar15 = psVar15 + 2;
                  } while (iVar14 < iVar9 + -1);
                }
                _memmove((undefined4 *)(psVar2 + local_14 * 2 + 1),
                         (undefined4 *)(psVar2 + local_14 * 2 + 3),(local_14 * -4 + iVar5 * 2) - 6);
                psVar2[*(int *)((int)this + 0xc) * 2 + -2] = -1;
                psVar2[*(int *)((int)this + 0xc) * 2 + -1] = -1;
                if (local_14 < local_1c) {
                  psVar12 = psVar12 + -2;
                }
              }
              _memmove((undefined4 *)(psVar12 + 2),(undefined4 *)psVar12,
                       ((int)psVar2 + (iVar5 * 2 - (int)psVar12) + -4 >> 1) << 1);
              psVar12[1] = sVar10;
              *psVar12 = sVar13;
            }
            else {
              *psVar12 = sVar13;
              if ((int)psVar12[1] < (int)param_1) {
                psVar12[1] = sVar10;
                while ((sVar7 = psVar12[2], sVar7 != -1 && ((int)sVar7 <= (int)param_1))) {
                  sVar7 = psVar12[1];
                  if (psVar12[1] <= psVar12[3]) {
                    sVar7 = psVar12[3];
                  }
                  psVar12[1] = sVar7;
                  _memmove((undefined4 *)(psVar12 + 2),(undefined4 *)(psVar12 + 4),
                           ((int)psVar2 + (iVar5 * 2 - (int)psVar12) + -8 >> 1) << 1);
                }
              }
            }
            break;
          }
          if ((int)local_20 <= (int)psVar12[1]) {
            if ((int)psVar12[1] < (int)param_1) {
              psVar12[1] = sVar10;
              while ((sVar7 = psVar12[2], sVar7 != -1 && ((int)sVar7 <= (int)param_1))) {
                sVar7 = psVar12[1];
                if (psVar12[1] <= psVar12[3]) {
                  sVar7 = psVar12[3];
                }
                psVar12[1] = sVar7;
                _memmove((undefined4 *)(psVar12 + 2),(undefined4 *)(psVar12 + 4),
                         ((int)psVar2 + (iVar5 * 2 - (int)psVar12) + -8 >> 1) << 1);
              }
            }
            break;
          }
          psVar12 = psVar12 + 2;
          local_1c = local_1c + 1;
        } while (local_1c < iVar9);
      }
      if (local_1c == *(int *)((int)this + 0xc)) {
        if (psVar2[iVar5 + -4] != -1) {
          iVar11 = 0;
          iVar9 = *(int *)((int)this + 4) << 1;
          iVar14 = *(int *)((int)this + 0xc) + -1;
          if (0 < iVar14) {
            psVar12 = psVar2 + 1;
            do {
              if ((int)psVar12[1] - (int)*psVar12 < iVar9) {
                iVar9 = (int)psVar12[1] - (int)*psVar12;
                local_14 = iVar11;
              }
              iVar11 = iVar11 + 1;
              psVar12 = psVar12 + 2;
            } while (iVar11 < iVar14);
          }
          _memmove((undefined4 *)(psVar2 + local_14 * 2 + 1),
                   (undefined4 *)(psVar2 + local_14 * 2 + 3),(local_14 * -4 + iVar5 * 2) - 6);
        }
        psVar2[iVar5 + -3] = sVar10;
        psVar2[iVar5 + -4] = sVar13;
      }
    }
  }
  return;
}

