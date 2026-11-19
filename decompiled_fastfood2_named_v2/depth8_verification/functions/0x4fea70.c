// rea decompile_all
// name: FUN_004fea70
// address: 0x4fea70
// body: available
// range: 0x4fea70-0x4feba5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004fea70(void *this,void *param_1,float param_2)

{
  short sVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  
  fVar2 = param_2;
  iVar3 = FUN_004e3730(param_1,(int)param_2);
  iVar4 = *(int *)((int)param_1 + 0x4c);
  if (param_2 == 4.06377e-44) {
    sVar1 = *(short *)((int)this + iVar4 * 0x168 + 0x130);
joined_r0x004feae2:
    iVar4 = ((int)sVar1 >> 5) + 4;
  }
  else {
    if (param_2 == 4.2039e-44) {
      sVar1 = *(short *)((int)this + iVar4 * 0x168 + 0x130);
      goto joined_r0x004feae2;
    }
    if (param_2 != 4.34403e-44) goto LAB_004feae6;
    iVar4 = ((int)*(short *)((int)this + iVar4 * 0x168 + 0x130) >> 5) + 2;
  }
  if (iVar4 <= iVar3) {
    iVar3 = iVar4;
  }
LAB_004feae6:
  iVar4 = FUN_004e1d40(param_1,(int)param_2);
  if (iVar3 <= iVar4 + 1) {
    return 0;
  }
  iVar4 = FUN_004ddcc0((int)param_1);
  if (param_2 == 4.06377e-44) {
    param_2 = 20000.0;
  }
  else if (param_2 == 4.2039e-44) {
    param_2 = 10000.0;
  }
  else {
    if (param_2 != 4.34403e-44) {
      return 0;
    }
    param_2 = 5000.0;
  }
  iVar3 = *(int *)(iVar4 + 0x58);
  iVar4 = *(int *)(iVar4 + 0x40);
  iVar5 = FUN_00483c90(DAT_0057c670,(int)fVar2,'\x01');
  if (iVar5 == 0) {
    return 0;
  }
  uVar6 = FUN_004e0b60(param_1,0x17,(float)(((10 - iVar3) - iVar4) * 10) * param_2 * 0.01,'\x01',
                       0xffffffff);
  if ((char)uVar6 != '\0') {
    FUN_004e2080(param_1,*(int *)(iVar5 + 0x164),(int)fVar2);
  }
  return 1;
}

