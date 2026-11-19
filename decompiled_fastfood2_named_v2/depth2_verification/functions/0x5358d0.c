// rea decompile_all
// name: Font_DrawGlyphClipped
// address: 0x5358d0
// body: available
// range: 0x5358d0-0x535a9a inclusive
// range: 0x535aa0-0x535b39 inclusive
// range: 0x535b40-0x535c05 inclusive
// non_contiguous: true
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
Font_DrawGlyphClipped
          (void *this,void *param_1,byte *param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  int iVar4;
  bool bVar5;
  ushort uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  byte *pbVar17;
  ushort *puVar18;
  ushort *puVar19;
  int local_c;
  
                    /* Depth-2 proposal batch 1. */
  iVar16 = param_3;
  if (((param_3 != 0) && (param_4 != 0)) && (*(int *)((int)param_1 + 0x28) != 0)) {
    iVar4 = *(int *)((int)param_1 + 0x20);
    param_3 = param_4;
    iVar10 = *(int *)((int)this + 0x9a0) + param_5;
    iVar7 = *(int *)((int)this + 0x9a4) + param_6;
    iVar16 = iVar16 >> 1;
    param_6 = 0;
    param_5 = 0;
    iVar12 = *(int *)((int)param_1 + 4);
    local_c = iVar16;
    if (iVar10 < iVar12) {
      param_5 = iVar12 - iVar10;
      local_c = (iVar10 - iVar12) + iVar16;
      if (local_c < 1) {
        return;
      }
      iVar10 = iVar12;
    }
    if ((iVar10 + local_c <= *(int *)((int)param_1 + 8)) ||
       (local_c = *(int *)((int)param_1 + 8) - iVar10, 0 < local_c)) {
      if (iVar7 < *(int *)((int)param_1 + 0xc)) {
        param_3 = (iVar7 - *(int *)((int)param_1 + 0xc)) + param_4;
        param_6 = *(int *)((int)param_1 + 0xc) - iVar7;
        iVar7 = *(int *)((int)param_1 + 0xc);
        if (param_3 < 1) {
          return;
        }
      }
      if ((param_3 + iVar7 <= *(int *)((int)param_1 + 0x10)) ||
         (param_3 = *(int *)((int)param_1 + 0x10) - iVar7, 0 < param_3)) {
        puVar19 = (ushort *)(*(int *)((int)param_1 + 0x28) + (iVar7 * iVar4 + iVar10) * 2);
        uVar13 = *(uint *)((int)this + 0x9b8);
        uVar8 = uVar13 >> 3 & 0x1f;
        uVar9 = uVar13 >> 0x13 & 0x1f;
        uVar11 = uVar13 >> 0xb & 0x1f;
        uVar6 = FUN_00539840(param_1,uVar13);
        cVar1 = *(char *)((int)param_1 + 0x18);
        for (; iVar12 = param_5, param_6 != 0; param_6 = param_6 + -1) {
          iVar12 = iVar16;
          pbVar17 = param_2;
          do {
            while (param_2 = pbVar17 + 1, *pbVar17 == 0) {
              pbVar17 = pbVar17 + 2;
              iVar12 = iVar12 - (uint)*param_2;
              param_2 = pbVar17;
              if (iVar12 == 0) goto LAB_00535a52;
            }
            iVar12 = iVar12 + -1;
            pbVar17 = param_2;
          } while (iVar12 != 0);
LAB_00535a52:
        }
joined_r0x00535a62:
        do {
          iVar7 = local_c;
          puVar18 = puVar19;
          if (iVar12 == 0) {
LAB_00535a8c:
            iVar12 = iVar7;
            pbVar17 = param_2;
            if (cVar1 == '\0') {
              do {
                while( true ) {
                  param_2 = pbVar17 + 1;
                  bVar2 = *pbVar17;
                  if (bVar2 == 0) break;
                  pbVar17 = param_2;
                  if (bVar2 == 0xf) {
                    *puVar18 = uVar6;
                    puVar18 = puVar18 + 1;
                    iVar12 = iVar12 + -1;
                    if (iVar12 == 0) {
                      iVar7 = 0;
                      goto LAB_00535bcf;
                    }
                  }
                  else {
                    uVar3 = *puVar18;
                    iVar7 = (uint)bVar2 * 0x100 + 0x584594;
                    uVar13 = (uVar3 & 0x7e00) >> 10;
                    uVar14 = uVar3 >> 5 & 0x1f;
                    uVar15 = uVar3 & 0x1f;
                    *puVar18 = (((short)uVar13 +
                                (short)*(undefined4 *)(iVar7 + (uVar8 - uVar13) * 4)) * 0x20 +
                                (short)uVar14 +
                               (short)*(undefined4 *)(iVar7 + (uVar11 - uVar14) * 4)) * 0x20 +
                               (short)uVar15 + (short)*(undefined4 *)(iVar7 + (uVar9 - uVar15) * 4);
                    puVar18 = puVar18 + 1;
                    iVar12 = iVar12 + -1;
                    iVar7 = 0;
                    if (iVar12 == 0) goto LAB_00535bcf;
                  }
                }
                bVar2 = *param_2;
                param_2 = pbVar17 + 2;
                puVar18 = puVar18 + bVar2;
                iVar7 = iVar12 - (uint)bVar2;
                iVar12 = iVar7;
                pbVar17 = param_2;
              } while (0 < iVar7);
            }
            else {
              do {
                while( true ) {
                  pbVar17 = param_2 + 1;
                  bVar2 = *param_2;
                  if (bVar2 == 0) break;
                  param_2 = pbVar17;
                  if (bVar2 == 0xf) {
                    *puVar18 = uVar6;
                    puVar18 = puVar18 + 1;
                    iVar7 = iVar7 + -1;
                    if (iVar7 == 0) {
                      iVar7 = 0;
                      goto LAB_00535bcf;
                    }
                  }
                  else {
                    uVar3 = *puVar18;
                    iVar12 = (uint)bVar2 * 0x100 + 0x584594;
                    uVar13 = uVar3 >> 6 & 0x1f;
                    *puVar18 = (((uVar3 >> 0xb) +
                                (short)*(undefined4 *)(iVar12 + (uVar8 - (uVar3 >> 0xb)) * 4)) *
                                0x20 + (short)uVar13 +
                               (short)*(undefined4 *)(iVar12 + (uVar11 - uVar13) * 4)) * 0x40 +
                               (short)(uVar3 & 0x1f) +
                               (short)*(undefined4 *)(iVar12 + (uVar9 - (uVar3 & 0x1f)) * 4);
                    puVar18 = puVar18 + 1;
                    iVar7 = iVar7 + -1;
                    if (iVar7 == 0) {
                      iVar7 = 0;
                      goto LAB_00535bcf;
                    }
                  }
                }
                param_2 = param_2 + 2;
                puVar18 = puVar18 + *pbVar17;
                iVar7 = iVar7 - (uint)*pbVar17;
              } while (0 < iVar7);
            }
          }
          else {
            do {
              if (*param_2 != 0) {
                param_2 = param_2 + 1;
                iVar12 = iVar12 + -1;
                goto joined_r0x00535a62;
              }
              uVar13 = (uint)param_2[1];
              param_2 = param_2 + 2;
              iVar10 = iVar12 - uVar13;
              bVar5 = (int)uVar13 <= iVar12;
              iVar12 = iVar10;
            } while (iVar10 != 0 && bVar5);
            iVar7 = local_c + iVar10;
            puVar18 = puVar19 + -iVar10;
            if (0 < iVar7) goto LAB_00535a8c;
          }
LAB_00535bcf:
          for (iVar7 = ((iVar16 - param_5) - local_c) + iVar7; pbVar17 = param_2, iVar7 != 0;
              iVar7 = iVar7 - (uint)bVar2) {
            while (param_2 = pbVar17 + 1, *pbVar17 != 0) {
              iVar7 = iVar7 + -1;
              pbVar17 = param_2;
              if (iVar7 == 0) goto LAB_00535bf1;
            }
            bVar2 = *param_2;
            param_2 = pbVar17 + 2;
          }
LAB_00535bf1:
          puVar19 = puVar19 + iVar4;
          param_3 = param_3 + -1;
          iVar12 = param_5;
        } while (param_3 != 0);
      }
    }
  }
  return;
}

