// rea decompile_all
// name: FUN_004d4170
// address: 0x4d4170
// body: available
// range: 0x4d4170-0x4d42b0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d4170(int param_1)

{
  void *this;
  undefined4 uVar1;
  
  if (0 < *(int *)(param_1 + 0x14)) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + -1;
  }
  if (*(int *)(param_1 + 0x14) < 0) {
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  if (0 < *(int *)(param_1 + 0x18)) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -1;
  }
  if (*(int *)(param_1 + 0x18) < 0) {
    *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + -1;
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 1;
  }
  if (0 < *(int *)(param_1 + 0x1c)) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  }
  if (*(int *)(param_1 + 0x1c) < 0) {
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  }
  if (0 < *(int *)(param_1 + 0x20)) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + 1;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + -1;
  }
  if (*(int *)(param_1 + 0x20) < 0) {
    *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + -1;
    *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  }
  this = (void *)FUN_004d3910(param_1);
  if (this != (void *)0x0) {
    uVar1 = FUN_004d4310(param_1);
    if ((char)uVar1 == '\0') {
      if (*(short *)((int)this + 0x40) == 0x25) {
        FUN_00507550(this,0xffff);
      }
      if (*(int *)(param_1 + 0x10) < 0x14) {
        FUN_00507550(this,0x24);
        return;
      }
      if (*(short *)((int)this + 0x40) == 0x24) {
        FUN_00507550(this,0xffff);
      }
      if (*(int *)(param_1 + 0xc) < 0x14) {
        FUN_00507550(this,0x26);
        return;
      }
      if (*(short *)((int)this + 0x40) == 0x24) {
        FUN_00507550(this,0xffff);
      }
      uVar1 = FUN_004d42c0(param_1);
      if ((char)uVar1 == '\0') {
        if (*(short *)((int)this + 0x40) == 0x21) {
          FUN_00507550(this,0xffff);
        }
        uVar1 = FUN_004d42e0(param_1);
        if (((char)uVar1 == '\0') && (*(short *)((int)this + 0x40) == 0x27)) {
          FUN_00507550(this,0xffff);
        }
      }
    }
  }
  return;
}

