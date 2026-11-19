// rea decompile_all
// name: FUN_004ff080
// address: 0x4ff080
// body: available
// range: 0x4ff080-0x4ff1fe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 FUN_004ff080(void *param_1,void *param_2)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  void *this;
  undefined4 uVar8;
  int iVar9;
  int iVar10;
  int local_8;
  
  bVar3 = FUN_004ff650();
  if (CONCAT31(extraout_var,bVar3) == 0) {
    return 2;
  }
  iVar9 = 0;
  iVar10 = 0;
  local_8 = 0;
  bVar1 = *(byte *)(*(int *)(DAT_0057c670 + 0x94) + 7);
  iVar4 = FUN_0047aac0(param_2,0xffffffff);
  if (0 < iVar4) {
    do {
      piVar5 = (int *)IDMap_Lookup((void *)((int)param_2 + 0x1500),iVar9,(int *)0x0);
      iVar2 = *piVar5;
      if ((*(char *)(iVar2 + 0x824) == '\0') || (*(char *)(iVar2 + 0x824) == '\x02')) {
        uVar6 = (piVar5[1] + 3) * 3 - (bVar1 + 4);
        if (0x17 < (int)uVar6) {
          uVar6 = uVar6 - 0x18;
        }
        if ((int)uVar6 < -0x17) {
          uVar6 = uVar6 + 0x18;
        }
        if ((int)((uVar6 ^ (int)uVar6 >> 0x1f) - ((int)uVar6 >> 0x1f)) < 3) {
          iVar7 = FUN_004d3f90(iVar2);
          if ((iVar10 == 0) || (local_8 < iVar7)) {
            iVar10 = iVar2;
            local_8 = iVar7;
          }
        }
      }
      iVar9 = iVar9 + 1;
    } while (iVar9 < iVar4);
    if (iVar10 != 0) {
      iVar10 = FUN_004d3910(iVar10);
      iVar4 = FUN_0050bba0(iVar10);
      if (iVar4 != 0) {
        return 3;
      }
      piVar5 = FUN_004e1fe0(param_1,0x1d);
      if (piVar5 == (int *)0x0) {
        return 3;
      }
      this = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*piVar5,(int *)0x0);
      if (this == (void *)0x0) {
        return 3;
      }
      uVar8 = FUN_004e0b60(param_1,0x17,10000.0,'\x01',0xffffffff);
      if ((char)uVar8 != '\0') {
        FUN_0050bed0(this,(int)param_2,0xe);
        *(undefined4 *)((int)this + 0x10c) = *(undefined4 *)(iVar10 + 0x164);
      }
      return 1;
    }
  }
  return 3;
}

