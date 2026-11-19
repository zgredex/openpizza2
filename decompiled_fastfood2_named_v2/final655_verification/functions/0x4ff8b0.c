// rea decompile_all
// name: AI_ManageGangsters
// address: 0x4ff8b0
// body: available
// range: 0x4ff8b0-0x4ff9da inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall AI_ManageGangsters(void *this,int param_1)

{
  void *this_00;
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  float fVar5;
  
                    /* Adjusts gangster salaries or protection levels. */
  this_00 = *(void **)((int)this + param_1 * 0x168 + 0x70);
  FUN_004e2280((int)this_00);
  uVar1 = _rand();
  if ((uVar1 & 1) == 0) {
    iVar2 = FUN_004e3730(this_00,0x1e);
    iVar3 = FUN_004e1d40(this_00,0x1e);
    if (iVar2 <= iVar3) goto LAB_004ff916;
    fVar5 = 4.2039e-44;
  }
  else {
    iVar2 = FUN_004e3730(this_00,0x1d);
    iVar3 = FUN_004e1d40(this_00,0x1d);
    if (iVar2 <= iVar3) goto LAB_004ff916;
    fVar5 = 4.06377e-44;
  }
  Player_AcquireBranch(this,this_00,fVar5);
LAB_004ff916:
  iVar2 = FUN_004e3820((int)this_00);
  if (iVar2 != -1) {
    if ((double)((100 - *(short *)((int)this + param_1 * 0x168 + 0x130)) * iVar2 * 6) <
        *(double *)((int)this_00 + 0x108)) {
      uVar4 = FUN_004e0b60(this_00,0x17,(float)iVar2,'\x01',0xffffffff);
      if ((char)uVar4 != '\0') {
        FUN_004e2950((int)this_00);
      }
    }
  }
  iVar2 = FUN_004e3890((int)this_00);
  if (iVar2 != -1) {
    if ((double)((100 - *(short *)((int)this + param_1 * 0x168 + 0x130)) * iVar2 * 9) <
        *(double *)((int)this_00 + 0x108)) {
      uVar4 = FUN_004e0b60(this_00,0x17,(float)iVar2,'\x01',0xffffffff);
      if ((char)uVar4 != '\0') {
        FUN_004e28e0((int)this_00);
      }
    }
  }
  return 1;
}

