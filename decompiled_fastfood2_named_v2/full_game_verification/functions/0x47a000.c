// rea decompile_all
// name: Rating_ComputeBuildingScore
// address: 0x47a000
// body: available
// range: 0x47a000-0x47a3ab inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall Rating_ComputeBuildingScore(void *this,int param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  longlong lVar9;
  int local_e8;
  int local_e0 [56];
  
  local_e0[0x28] = 0;
  local_e0[0x2b] = 0;
  local_e0[1] = 0;
  local_e0[0x11] = 0xfffffffe;
  local_e0[0x12] = 0xfffffffe;
  local_e0[0x22] = 0xfffffffe;
  local_e0[0x34] = 0xfffffffe;
  local_e0[0x36] = 0xfffffffe;
  local_e0[0x37] = 0xfffffffe;
  local_e0[8] = 1;
  local_e0[9] = 1;
  local_e0[0xe] = 3;
  local_e0[0xf] = 3;
  local_e0[0x2c] = 4;
  local_e0[0xc] = 4;
  local_e0[0x1b] = 4;
  local_e0[0x29] = 0xfffffffd;
  local_e0[3] = 0xfffffffd;
  local_e0[0x13] = 0xfffffffd;
  local_e0[0x21] = 0xfffffffd;
  local_e0[0x35] = 0xfffffffd;
  iVar8 = 0;
  local_e0[0x2a] = 0xfffffffb;
  local_e0[0x2d] = 5;
  local_e0[0x2e] = 3;
  local_e0[0x2f] = 2;
  local_e0[0] = -7;
  local_e0[2] = 0xfffffffb;
  local_e0[4] = 0xffffffef;
  local_e0[5] = 0xffffffec;
  local_e0[6] = 0xfffffff1;
  local_e0[7] = 0xfffffff5;
  local_e0[0x10] = 0xffffffff;
  local_e0[0x14] = 0xfffffffa;
  local_e0[0x15] = 0xfffffff9;
  local_e0[0x16] = 0xfffffffb;
  local_e0[0x17] = 0xfffffffc;
  local_e0[0x20] = 0xffffffff;
  local_e0[0x23] = 0xfffffffc;
  local_e0[0x24] = 0xfffffff9;
  local_e0[0x25] = 0xfffffff8;
  local_e0[0x26] = 0xfffffffa;
  local_e0[0x27] = 0xfffffffb;
  local_e0[0x30] = 0xffffffff;
  local_e0[0x31] = 0xffffffff;
  local_e0[0x32] = 0xffffffff;
  local_e0[0x33] = 0xffffffff;
  local_e0[10] = 2;
  local_e0[0xb] = 2;
  local_e0[0xd] = 5;
  local_e0[0x18] = 2;
  local_e0[0x19] = 8;
  local_e0[0x1a] = 6;
  local_e0[0x1c] = 0xe;
  local_e0[0x1d] = 0x10;
  local_e0[0x1e] = 0xc;
  local_e0[0x1f] = 10;
  IDMap_Lookup((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0);
  this_00 = *(void **)((int)this + 0x16f0);
  if (this_00 == (void *)0x0) {
    return 0;
  }
  if (param_1 == -1) {
    local_e8 = 7;
    iVar2 = 0;
  }
  else {
    local_e8 = param_1;
    iVar2 = param_1;
  }
  for (; iVar2 <= local_e8; iVar2 = iVar2 + 1) {
    iVar3 = Game_CountFreeBuildingsByType(this_00,0x17);
    iVar7 = local_e0[iVar2 + 0x28];
    iVar4 = Game_CountFreeBuildingsByType(this_00,0x16);
    iVar1 = local_e0[iVar2];
    iVar5 = Game_CountFreeBuildingsByType(this_00,0xf);
    iVar6 = Game_CountFreeBuildingsByType(this_00,0x21);
    iVar8 = iVar8 + iVar3 * iVar7 + iVar4 * iVar1 + (iVar6 + iVar5) * local_e0[iVar2 + 0x18] * 2;
    if (*(int *)((int)this_00 + 0x74) != 0) {
      iVar8 = iVar8 + (*(int *)(*(int *)((int)this_00 + 0x74) + 0x18) / 0x3c +
                      *(int *)((int)this + 0x14b4)) * local_e0[iVar2 + 8];
    }
    iVar7 = Game_CountFreeBuildingsByType(this_00,0x1a);
    if (0 < iVar7) {
      iVar7 = iVar7 / 5 + 1;
      if (4 < iVar7) {
        iVar7 = 4;
      }
      lVar9 = Math_RoundFloat((float)(local_e0[iVar2 + 0x10] * iVar7));
      iVar8 = iVar8 + (int)lVar9;
    }
    iVar7 = Game_CountFreeBuildingsByType(this_00,0x1b);
    if (0 < iVar7) {
      iVar7 = iVar7 / 5 + 1;
      if (4 < iVar7) {
        iVar7 = 4;
      }
      lVar9 = Math_RoundFloat((float)(local_e0[iVar2 + 0x20] * iVar7));
      iVar8 = iVar8 + (int)lVar9;
    }
    iVar7 = Game_CountFreeBuildingsByType(this_00,0x1c);
    if (0 < iVar7) {
      iVar7 = iVar7 / 5 + 1;
      if (4 < iVar7) {
        iVar7 = 4;
      }
      lVar9 = Math_RoundFloat((float)(local_e0[iVar2 + 0x30] * iVar7));
      iVar8 = iVar8 + (int)lVar9;
    }
  }
  if (param_1 == -1) {
    iVar8 = (int)(iVar8 + (iVar8 >> 0x1f & 7U)) >> 3;
  }
  return iVar8;
}

