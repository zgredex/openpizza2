// rea decompile_all
// name: FUN_0053bf00
// address: 0x53bf00
// body: available
// range: 0x53bf00-0x53c12a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_0053bf00(void *this,int param_1,uint *param_2,byte *param_3,uint param_4,int param_5)

{
  byte bVar1;
  byte bVar2;
  short sVar3;
  bool bVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  byte *pbVar13;
  byte *pbVar14;
  int iVar15;
  uint *local_2c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  FUN_00535160(param_2,&local_c,&local_10);
  if ((*(byte *)((int)this + 4) & 4) != 0) {
    param_4 = param_4 + (int)*(short *)((int)this + 10);
    param_5 = param_5 + *(short *)((int)this + 0xc);
  }
  iVar10 = (int)*(short *)((int)this + 8);
  local_14 = 0;
  local_18 = 0;
  iVar8 = (int)*(short *)((int)this + 6);
  if ((int)param_4 < 0) {
    iVar8 = iVar8 + param_4;
    local_14 = -param_4;
    if (iVar8 < 1) {
      return;
    }
    param_4 = 0;
  }
  if (param_5 < 0) {
    iVar10 = iVar10 + param_5;
    local_18 = -param_5;
    if (iVar10 < 1) {
      return;
    }
    param_5 = 0;
  }
  if ((((int)(param_4 + iVar8) < local_c) || (iVar8 = local_c - param_4, 0 < iVar8)) &&
     ((param_5 + iVar10 < local_10 || (iVar10 = local_10 - param_5, 0 < iVar10)))) {
    uVar5 = param_4 + iVar8;
    iVar9 = *(int *)(param_1 + 0x20) * param_5 + *(int *)(param_1 + 0x28);
    iVar6 = FUN_00535150(param_2,&local_8);
    iVar8 = *(int *)(param_1 + 0x20);
    sVar3 = *(short *)((int)this + 6);
    param_2 = (uint *)(iVar6 + local_8 * param_5 * 2);
    if (*(char *)((int)this + 5) == '\b') {
      bVar1 = *(byte *)((int)this + 0x1c);
      do {
        local_2c = param_2;
        param_2 = (uint *)((int)param_2 + local_8 * 2);
        for (; local_18 != 0; local_18 = local_18 + -1) {
          iVar6 = (int)sVar3;
          do {
            while (*param_3 == bVar1) {
              pbVar14 = param_3 + 1;
              param_3 = param_3 + 2;
              iVar15 = iVar6 - (uint)*pbVar14;
              bVar4 = (int)(uint)*pbVar14 <= iVar6;
              iVar6 = iVar15;
              if (!(iVar15 != 0 && bVar4)) goto LAB_0053c055;
            }
            param_3 = param_3 + 1;
            iVar6 = iVar6 + -1;
          } while (iVar6 != 0);
LAB_0053c055:
        }
LAB_0053c05d:
        uVar11 = *local_2c;
        local_2c = local_2c + 1;
        uVar7 = uVar11 & 0xffff;
        if (uVar7 != 0xffff) {
          uVar11 = uVar11 >> 0x10;
          if ((int)param_4 < (int)uVar11) {
            if ((int)uVar5 <= (int)uVar7) goto LAB_0053c110;
            if ((int)uVar5 <= (int)uVar11) {
              uVar11 = uVar5;
            }
            if ((int)uVar7 <= (int)param_4) {
              uVar7 = param_4;
            }
            iVar15 = iVar9 + uVar7 * 3;
            iVar6 = (uVar7 - param_4) + local_14;
            pbVar14 = param_3;
            while( true ) {
              iVar12 = uVar11 - uVar7;
              if (iVar6 == 0) break;
              while (pbVar13 = pbVar14 + 1, *pbVar14 == bVar1) {
                pbVar14 = pbVar14 + 2;
                iVar6 = iVar6 - (uint)*pbVar13;
                if (iVar6 < 1) {
                  iVar12 = (uVar11 - uVar7) + iVar6;
                  iVar15 = iVar15 + iVar6 * -3;
                  if (0 < iVar12) goto LAB_0053c0db;
                  goto LAB_0053c05d;
                }
              }
              iVar6 = iVar6 + -1;
              pbVar14 = pbVar13;
            }
LAB_0053c0db:
            do {
              bVar2 = *pbVar14;
              if (bVar2 == bVar1) {
                uVar11 = (uint)pbVar14[1];
                pbVar14 = pbVar14 + 2;
                iVar15 = iVar15 + uVar11 * 3;
                iVar6 = iVar12 - uVar11;
                bVar4 = (int)uVar11 <= iVar12;
                iVar12 = iVar6;
                if (!(iVar6 != 0 && bVar4)) break;
                goto LAB_0053c0db;
              }
              if (*(byte *)(iVar15 + 2) <= bVar2) {
                *(byte *)(iVar15 + 2) = bVar2;
              }
              iVar15 = iVar15 + 3;
              iVar12 = iVar12 + -1;
              pbVar14 = pbVar14 + 1;
            } while (iVar12 != 0);
          }
          goto LAB_0053c05d;
        }
LAB_0053c110:
        iVar9 = iVar9 + iVar8;
        local_18 = 1;
        iVar10 = iVar10 + -1;
      } while (iVar10 != 0);
    }
  }
  return;
}

