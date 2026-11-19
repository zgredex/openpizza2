// rea decompile_all
// name: FUN_004d43a0
// address: 0x4d43a0
// body: available
// range: 0x4d43a0-0x4d446b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004d43a0(void *this,undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  void *this_00;
  int iVar3;
  undefined2 uVar4;
  
  switch(param_1) {
  case 0:
    *(undefined4 *)((int)this + 0x14) = 0x14;
    break;
  case 1:
    iVar3 = *(int *)((int)this + 0x3c);
    iVar1 = FUN_004d4330(this,1);
    FUN_004d4160(this,iVar1 + iVar3);
    iVar3 = *(int *)((int)this + 0xc) + 0x14;
    if (100 < iVar3) {
      iVar3 = 100;
    }
    FUN_004d4120(this,iVar3);
    break;
  case 2:
    *(undefined4 *)((int)this + 0x20) = 0x14;
    break;
  case 3:
    *(undefined4 *)((int)this + 0x18) = 0x14;
  }
  uVar2 = FUN_004d42c0((int)this);
  if ((((char)uVar2 != '\0') || (uVar2 = FUN_004d42e0((int)this), (char)uVar2 != '\0')) &&
     (this_00 = (void *)FUN_004d3910((int)this), this_00 != (void *)0x0)) {
    uVar2 = FUN_004d42c0((int)this);
    if ((char)uVar2 == '\0') {
      uVar4 = 0x27;
    }
    else {
      uVar4 = 0x21;
    }
    FUN_00507550(this_00,uVar4);
    if (((*(int *)((int)this_00 + 0x74) != 0) && (iVar3 = *(int *)((int)this_00 + 0xf4), iVar3 != 0)
        ) && (iVar3 = FUN_00489820(DAT_0057c670,*(int *)(iVar3 + 8),*(int *)(iVar3 + 0x2c)),
             iVar3 != 0)) {
      Game_UpdateObjectRatingScales(iVar3);
    }
  }
  return;
}

