// rea decompile_all
// name: Surface_ApplyWaterDistortion
// address: 0x5283b0
// body: available
// range: 0x5283b0-0x528501 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


longlong __fastcall Surface_ApplyWaterDistortion(int param_1,uint param_2,int param_3,int param_4)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  float fVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar12;
  longlong lVar13;
  int local_654;
  undefined4 local_640 [400];
  
                    /* Depth-1 proposal batch 3/4. */
  uVar1 = *(ushort *)(param_3 + 0x1c);
  iVar3 = *(int *)(param_3 + 0x28);
  uVar2 = *(ushort *)(param_3 + 0x1a);
  uVar9 = (uint)uVar2;
  if (uVar1 < 2) {
    return (ulonglong)param_2 << 0x20;
  }
  fVar4 = (float)param_4 * *(float *)(param_1 + 8) + *(float *)(param_1 + 0xc);
  *(float *)(param_1 + 0xc) = fVar4;
  if ((512.0 < fVar4) && (0.0 < *(float *)(param_1 + 8))) {
    *(float *)(param_1 + 0xc) = 512.0 - (fVar4 - 512.0);
    *(float *)(param_1 + 8) = -*(float *)(param_1 + 8);
  }
  lVar13 = __ftol();
  local_654 = (int)lVar13 >> 10;
  uVar5 = uVar9 * 2;
  uVar8 = (uint)((ulonglong)lVar13 >> 0x20);
  if (0 < local_654) {
    do {
      iVar6 = _rand();
      iVar6 = iVar6 % (int)(uint)uVar1;
      do {
        iVar7 = _rand();
        iVar7 = iVar7 % (int)(uint)uVar1;
      } while (iVar7 == iVar6);
      puVar12 = (undefined4 *)(iVar3 + iVar6 * uVar9 * 2);
      puVar10 = puVar12;
      puVar11 = local_640;
      for (uVar8 = (uint)(uVar2 >> 1); uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar11 = *puVar10;
        puVar10 = puVar10 + 1;
        puVar11 = puVar11 + 1;
      }
      for (uVar8 = uVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar11 = *(undefined1 *)puVar10;
        puVar10 = (undefined4 *)((int)puVar10 + 1);
        puVar11 = (undefined4 *)((int)puVar11 + 1);
      }
      puVar10 = (undefined4 *)(iVar3 + iVar7 * uVar9 * 2);
      puVar11 = puVar10;
      for (uVar8 = (uint)(uVar2 >> 1); uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar12 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + 1;
      }
      for (uVar8 = uVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar12 = *(undefined1 *)puVar11;
        puVar11 = (undefined4 *)((int)puVar11 + 1);
        puVar12 = (undefined4 *)((int)puVar12 + 1);
      }
      puVar12 = local_640;
      for (uVar8 = (uint)(uVar2 >> 1); uVar8 != 0; uVar8 = uVar8 - 1) {
        *puVar10 = *puVar12;
        puVar12 = puVar12 + 1;
        puVar10 = puVar10 + 1;
      }
      local_654 = local_654 + -1;
      for (uVar8 = uVar5 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined1 *)puVar10 = *(undefined1 *)puVar12;
        puVar12 = (undefined4 *)((int)puVar12 + 1);
        puVar10 = (undefined4 *)((int)puVar10 + 1);
      }
      uVar8 = uVar5;
    } while (local_654 != 0);
  }
  return CONCAT44(uVar8,(uint)(-1 < *(int *)(param_1 + 0x1c)));
}

