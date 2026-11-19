// rea decompile_all
// name: FUN_00508c20
// address: 0x508c20
// body: available
// range: 0x508c20-0x508d37 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00508c20(void *this,int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  CS_Enter(*(int *)(DAT_0057c670 + 0x240));
  CS_Enter(*(int *)(DAT_0057c670 + 0x244));
  FUN_00505260((int)this);
  if (*(int *)((int)this + 0x78) != 0) {
    Object_ApplyPendingType(this,*(int *)((int)this + 0x78));
  }
  if (param_1 == 0) {
    *(undefined4 *)((int)this + 0xc4) = param_2;
    if (*(int *)((int)this + 0x30) == 0x10) {
      iVar1 = IDMap_Lookup((void *)(DAT_0057c670 + 0x20),*(int *)((int)this + 0x50),(int *)0x0);
      uVar3 = (uint)*(byte *)(iVar1 + 0x824);
    }
    else {
      uVar3 = 0xffffffff;
    }
    FUN_00504e90(this,0,-1,uVar3);
    iVar1 = Array_GetRecord28(*(void **)((int)this + 0xc4),1,
                              *(int *)(*(int *)((int)this + 0xf4) + 0x54));
    uVar2 = 0;
  }
  else {
    if (param_1 != 1) goto LAB_00508cfc;
    *(undefined4 *)((int)this + 0xc4) = param_2;
    FUN_00504e90(this,1,-1,-1);
    iVar1 = FUN_004f3a90(*(int *)((int)this + 0xc4));
    uVar2 = 1;
  }
  FUN_00505e60(this,uVar2,iVar1);
LAB_00508cfc:
  if (*(int *)((int)this + 0x78) != 0) {
    FUN_00508d50(this,*(int *)((int)this + 0x78));
    *(undefined4 *)((int)this + 0x78) = 0;
  }
  CS_Leave(*(int *)(DAT_0057c670 + 0x244));
  CS_Leave(*(int *)(DAT_0057c670 + 0x240));
  return;
}

