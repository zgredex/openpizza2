// rea decompile_all
// name: Map_DrawPlayerMarkerRing
// address: 0x4f3510
// body: available
// range: 0x4f3510-0x4f37cf inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint __thiscall Map_DrawPlayerMarkerRing(void *this)

{
  int iVar1;
  double *pdVar2;
  double *pdVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  void *this_00;
  int iVar8;
  undefined4 *puVar9;
  int *piVar10;
  int *piVar11;
  float10 fVar12;
  longlong lVar13;
  longlong lVar14;
  int in_stack_00000014;
  int in_stack_00000018;
  uint in_stack_0000001c;
  int in_stack_00000020;
  uint local_11c;
  int local_118;
  int local_f8 [20];
  int local_a8 [20];
  uint auStack_58 [21];
  
                    /* Depth-3 proposal batch 1. */
  local_f8[3] = 0x78;
  local_f8[4] = 0x78;
  local_f8[5] = 0x78;
  local_f8[6] = 0xb4;
  local_f8[7] = 0xb4;
  local_f8[8] = 0xb4;
  local_f8[9] = 0xb4;
  local_f8[10] = 0xb4;
  local_f8[0xb] = 0xb4;
  local_f8[0] = 0x30;
  local_f8[1] = 0x48;
  local_f8[2] = 0x5a;
  iVar8 = 0;
  piVar10 = local_f8 + 0xc;
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar10 = 0;
    piVar10 = piVar10 + 1;
  }
  if (DAT_005719f4 != 0) {
    DAT_005719f4 = 0;
    local_118 = 0;
    pdVar2 = (double *)&DAT_00580750;
    do {
      fVar12 = (float10)local_118;
      pdVar3 = pdVar2 + 1;
      local_118 = local_118 + 1;
      fVar12 = (float10)fsin(fVar12 * (float10)0.017453292222222222);
      *pdVar2 = (double)fVar12;
      pdVar2 = pdVar3;
    } while ((int)pdVar3 < 0x580a21);
  }
  iVar5 = *(int *)((int)this + 0x24);
  iVar1 = *(int *)((int)this + 0x28);
  if ((int)in_stack_0000001c < 1) {
    return in_stack_0000001c & 0xffffff00;
  }
  local_11c = 100;
  if (100 < (int)(in_stack_0000001c - 0x14)) {
    piVar10 = local_f8;
    piVar11 = local_a8;
    for (uVar6 = (in_stack_0000001c - 0x47) / 0x32; piVar10 = piVar10 + 1, uVar6 != 0;
        uVar6 = uVar6 - 1) {
      *piVar11 = *piVar10;
      piVar11 = piVar11 + 1;
    }
    do {
      auStack_58[iVar8] = local_11c;
      local_11c = local_11c + 0x32;
      iVar8 = iVar8 + 1;
    } while ((int)local_11c < (int)(in_stack_0000001c - 0x14));
  }
  auStack_58[iVar8] = in_stack_0000001c;
  iVar4 = local_f8[iVar8];
  local_a8[iVar8] = iVar4;
  local_11c = 0;
  if (0 < iVar8 + 1) {
    do {
      iVar4 = local_a8[local_11c];
      if ((int)local_11c < iVar8) {
        this_00 = (void *)(&DAT_005806ec)[in_stack_00000020];
      }
      else {
        this_00 = (void *)(&DAT_0058070c)[in_stack_00000020];
      }
      puVar9 = &DAT_00581290;
      do {
        lVar13 = __ftol();
        lVar14 = __ftol();
        iVar7 = DAT_00585518;
        if (DAT_00585518 < 0xa1) {
          iVar7 = 0xa0;
        }
        FUN_0053d600(this_00,*(uint **)((int)this + 8),DAT_0058072c,
                     (uint *)((in_stack_00000014 - iVar5) + -8 + (int)lVar13),
                     (in_stack_00000018 - iVar1) + -8 + (int)lVar14,iVar7);
        puVar9 = puVar9 + (int)(0x168 / (longlong)iVar4) * -2;
      } while (0x580750 < (int)puVar9);
      iVar4 = local_11c + 1;
      local_11c = iVar4;
    } while (iVar4 < iVar8 + 1);
  }
  return CONCAT31((int3)((uint)iVar4 >> 8),1);
}

