// rea decompile_all
// name: Pak_FindEntry
// address: 0x402060
// body: available
// range: 0x402060-0x4021e7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Pak_FindEntry(void *this,byte *param_1,int *param_2,int *param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  byte *pbVar8;
  bool bVar9;
  
                    /* Binary-searches archive entry tables by name; returns archive index and entry
                       index. */
  *param_2 = 0;
  if (0 < *(int *)((int)this + 0x1684)) {
    do {
      iVar6 = 0;
      iVar2 = *param_2 * 0x120;
      iVar5 = **(int **)((int)this + iVar2 + 0x110);
      iVar7 = iVar5 + -1;
      if (0 < iVar5 + -2) {
        iVar5 = iVar7;
        do {
          iVar7 = iVar6 + iVar5 >> 1;
          pbVar3 = *(byte **)(*(int *)((int)this + iVar2 + 0x114) + 0x10 + iVar7 * 0x14);
          pbVar8 = param_1;
          do {
            bVar1 = *pbVar3;
            bVar9 = bVar1 < *pbVar8;
            if (bVar1 != *pbVar8) {
LAB_004020e7:
              iVar4 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
              goto LAB_004020ec;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar3[1];
            bVar9 = bVar1 < pbVar8[1];
            if (bVar1 != pbVar8[1]) goto LAB_004020e7;
            pbVar3 = pbVar3 + 2;
            pbVar8 = pbVar8 + 2;
          } while (bVar1 != 0);
          iVar4 = 0;
LAB_004020ec:
          if (iVar4 == 0) {
            *param_3 = iVar7;
            return 1;
          }
          if (iVar4 < 0) {
            iVar6 = iVar7;
            iVar7 = iVar5;
          }
          iVar5 = iVar7;
        } while (iVar6 < iVar7 + -1);
      }
      iVar5 = *(int *)((int)this + iVar2 + 0x114);
      pbVar3 = *(byte **)(iVar5 + 0x10 + iVar6 * 0x14);
      pbVar8 = param_1;
      do {
        bVar1 = *pbVar3;
        bVar9 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_0040213c:
          iVar2 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_00402141;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar9 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_0040213c;
        pbVar3 = pbVar3 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar2 = 0;
LAB_00402141:
      if (iVar2 == 0) {
        *param_3 = iVar6;
        return 1;
      }
      pbVar3 = *(byte **)(iVar5 + 0x10 + iVar7 * 0x14);
      pbVar8 = param_1;
      do {
        bVar1 = *pbVar3;
        bVar9 = bVar1 < *pbVar8;
        if (bVar1 != *pbVar8) {
LAB_00402179:
          iVar5 = (1 - (uint)bVar9) - (uint)(bVar9 != 0);
          goto LAB_0040217e;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar3[1];
        bVar9 = bVar1 < pbVar8[1];
        if (bVar1 != pbVar8[1]) goto LAB_00402179;
        pbVar3 = pbVar3 + 2;
        pbVar8 = pbVar8 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_0040217e:
      if (iVar5 == 0) {
        *param_3 = iVar7;
        return 1;
      }
      iVar5 = *param_2;
      *param_2 = iVar5 + 1;
    } while (iVar5 + 1 < *(int *)((int)this + 0x1684));
  }
  return 0;
}

