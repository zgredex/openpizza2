// rea decompile_all
// name: FUN_004f4ae0
// address: 0x4f4ae0
// body: available
// range: 0x4f4ae0-0x4f4ce1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f4ae0(void *this,void *param_1,int param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  byte bVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  byte *pbVar11;
  byte *pbVar12;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  byte *local_14;
  int local_10;
  int local_c;
  int local_8;
  
  pbVar6 = (byte *)FUN_0053d480(param_1);
  local_14 = *(byte **)(*(int *)((int)this + 8) + 0x28);
  if ((local_14 != (byte *)0x0) && (pbVar6 != (byte *)0x0)) {
    iVar2 = *(int *)(*(int *)((int)this + 8) + 0x20);
    FUN_0053d090(param_1,&local_10,&local_18);
    local_8 = local_10;
    local_c = local_18;
    bVar5 = FUN_0053d420((int)param_1);
    if (((bVar5 & 1) != 0) && (*(byte *)((int)param_1 + 5) < 9)) {
      if ((bVar5 & 4) == 0) {
        iVar9 = param_2;
      }
      else {
        FUN_0053d100(param_1,&local_1c,&local_20);
        param_3 = param_3 + local_20;
        iVar9 = param_2 + local_1c;
      }
      iVar10 = *(int *)((int)this + 8);
      local_24 = 0;
      param_2 = 0;
      iVar8 = *(int *)(iVar10 + 4);
      if (iVar9 < iVar8) {
        local_8 = local_8 + (iVar9 - iVar8);
        param_2 = iVar8 - iVar9;
        iVar9 = iVar8;
      }
      if (*(int *)(iVar10 + 8) < local_8 + iVar9) {
        local_8 = *(int *)(iVar10 + 8) - iVar9;
      }
      iVar4 = local_8;
      iVar8 = param_3;
      if (param_3 < *(int *)(iVar10 + 0xc)) {
        local_c = local_c + (param_3 - *(int *)(iVar10 + 0xc));
        iVar8 = *(int *)(iVar10 + 0xc);
        local_24 = iVar8 - param_3;
      }
      if (*(int *)(iVar10 + 0x10) < local_c + iVar8) {
        local_c = *(int *)(iVar10 + 0x10) - iVar8;
      }
      if ((0 < local_8) && (0 < local_c)) {
        local_14 = (byte *)((int)local_14 + iVar2 * iVar8 + iVar9);
        uVar7 = FUN_0053d430((int)param_1);
        bVar5 = (byte)uVar7;
        for (; iVar9 = param_2, local_24 != 0; local_24 = local_24 + -1) {
          iVar9 = local_10;
          pbVar12 = pbVar6;
          do {
            while (pbVar6 = pbVar12 + 1, *pbVar12 != uVar7) {
              iVar9 = iVar9 + -1;
              pbVar12 = pbVar6;
              if (iVar9 == 0) goto LAB_004f4c4a;
            }
            pbVar12 = pbVar12 + 2;
            iVar9 = iVar9 - (uint)*pbVar6;
            pbVar6 = pbVar12;
          } while (iVar9 != 0);
LAB_004f4c4a:
        }
        do {
          for (; iVar10 = local_8, pbVar12 = local_14, iVar9 != 0; iVar9 = iVar9 + -1) {
            while (*pbVar6 == bVar5) {
              pbVar11 = pbVar6 + 2;
              iVar10 = iVar9 - (uint)pbVar6[1];
              bVar3 = iVar9 < (int)(uint)pbVar6[1];
              iVar9 = iVar10;
              pbVar6 = pbVar11;
              if (iVar10 == 0 || bVar3) {
                pbVar12 = local_14 + -iVar10;
                iVar10 = local_8 + iVar10;
                goto joined_r0x004f4c7e;
              }
            }
            pbVar6 = pbVar6 + 1;
          }
          do {
            while( true ) {
              pbVar11 = pbVar6 + 1;
              bVar1 = *pbVar6;
              if (bVar1 == bVar5) break;
              if (bVar1 < *pbVar12) {
                *pbVar12 = bVar1;
              }
              iVar10 = iVar10 + -1;
              pbVar6 = pbVar11;
              pbVar12 = pbVar12 + 1;
              if (iVar10 == 0) {
                iVar10 = 0;
                goto LAB_004f4caa;
              }
            }
            pbVar11 = pbVar6 + 2;
            pbVar12 = pbVar12 + pbVar6[1];
            iVar10 = iVar10 - (uint)pbVar6[1];
joined_r0x004f4c7e:
            pbVar6 = pbVar11;
          } while (0 < iVar10);
LAB_004f4caa:
          for (iVar10 = ((local_10 - param_2) - iVar4) + iVar10; pbVar6 = pbVar11, iVar10 != 0;
              iVar10 = iVar10 - (uint)pbVar6[1]) {
            while (pbVar11 = pbVar6 + 1, *pbVar6 != bVar5) {
              iVar10 = iVar10 + -1;
              pbVar6 = pbVar11;
              if (iVar10 == 0) goto LAB_004f4ccd;
            }
            pbVar11 = pbVar6 + 2;
          }
LAB_004f4ccd:
          local_14 = local_14 + iVar2;
          local_c = local_c + -1;
          pbVar6 = pbVar11;
          iVar9 = param_2;
        } while (local_c != 0);
      }
    }
  }
  return;
}

