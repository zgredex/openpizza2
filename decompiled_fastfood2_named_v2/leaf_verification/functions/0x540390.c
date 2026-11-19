// rea decompile_all
// name: ResourceTable_FindEntry
// address: 0x540390
// body: available
// range: 0x540390-0x540508 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall ResourceTable_FindEntry(void *this,byte *param_1,int *param_2,int *param_3)

{
  byte bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  byte *pbVar9;
  bool bVar10;
  
                    /* Leaf reversal proposal batch 3. */
  *param_2 = 0;
  uVar6 = *(uint *)((int)this + 0x238);
  if (0 < (int)uVar6) {
    do {
      iVar7 = 0;
      iVar5 = *param_2 * 0x1c;
      iVar4 = **(int **)((int)this + iVar5 + 0x10);
      iVar8 = iVar4 + -1;
      if (0 < iVar4 + -2) {
        iVar4 = iVar8;
        do {
          iVar8 = iVar7 + iVar4 >> 1;
          pbVar2 = *(byte **)(*(int *)((int)this + iVar5 + 0x14) + 0x10 + iVar8 * 0x14);
          pbVar9 = param_1;
          do {
            bVar1 = *pbVar2;
            bVar10 = bVar1 < *pbVar9;
            if (bVar1 != *pbVar9) {
LAB_00540414:
              iVar3 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
              goto LAB_00540419;
            }
            if (bVar1 == 0) break;
            bVar1 = pbVar2[1];
            bVar10 = bVar1 < pbVar9[1];
            if (bVar1 != pbVar9[1]) goto LAB_00540414;
            pbVar2 = pbVar2 + 2;
            pbVar9 = pbVar9 + 2;
          } while (bVar1 != 0);
          iVar3 = 0;
LAB_00540419:
          if (iVar3 == 0) {
            *param_3 = iVar8;
            return 1;
          }
          if (iVar3 < 0) {
            iVar7 = iVar8;
            iVar8 = iVar4;
          }
          iVar4 = iVar8;
        } while (iVar7 < iVar8 + -1);
      }
      iVar5 = *(int *)((int)this + iVar5 + 0x14);
      pbVar2 = *(byte **)(iVar5 + 0x10 + iVar7 * 0x14);
      pbVar9 = param_1;
      do {
        bVar1 = *pbVar2;
        bVar10 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_00540466:
          iVar4 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_0054046b;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar10 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_00540466;
        pbVar2 = pbVar2 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar4 = 0;
LAB_0054046b:
      if (iVar4 == 0) {
        *param_3 = iVar7;
        return CONCAT31((int3)((uint)param_3 >> 8),1);
      }
      pbVar2 = *(byte **)(iVar5 + 0x10 + iVar8 * 0x14);
      pbVar9 = param_1;
      do {
        bVar1 = *pbVar2;
        bVar10 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_005404a3:
          iVar5 = (1 - (uint)bVar10) - (uint)(bVar10 != 0);
          goto LAB_005404a8;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar2[1];
        bVar10 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_005404a3;
        pbVar2 = pbVar2 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar5 = 0;
LAB_005404a8:
      if (iVar5 == 0) {
        *param_3 = iVar8;
        return 1;
      }
      uVar6 = *param_2 + 1;
      *param_2 = uVar6;
    } while ((int)uVar6 < *(int *)((int)this + 0x238));
  }
  return uVar6 & 0xffffff00;
}

