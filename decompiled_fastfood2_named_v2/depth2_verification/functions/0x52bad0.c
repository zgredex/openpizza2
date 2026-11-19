// rea decompile_all
// name: FUN_0052bad0
// address: 0x52bad0
// body: available
// range: 0x52bad0-0x52bbbc inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_0052bad0(void *this,int param_1)

{
  void *this_00;
  int iVar1;
  uint uVar2;
  
  if (*(int *)((int)this + 0xa4) == 3) {
    if (((*(undefined4 **)((int)this + 0xb8))[3] == 0) &&
       (iVar1 = _BinkWait_4(**(undefined4 **)((int)this + 0xb8)), iVar1 == 0)) {
      FUN_0052bbc0(this,DAT_0057c5c8);
      FUN_005321f0(*(void **)((int)this + 8),(int *)((int)this + 0x28),1);
      return;
    }
  }
  else {
    uVar2 = *(int *)((int)this + 0xb4) + param_1;
    *(uint *)((int)this + 0xb4) = uVar2;
    if (100 < uVar2) {
      do {
        uVar2 = uVar2 - 100;
      } while (100 < uVar2);
      iVar1 = *(int *)((int)this + 0x98);
      *(uint *)((int)this + 0xb4) = uVar2;
      this_00 = *(void **)((int)this + 0x54);
      if (((-1 < iVar1) && (iVar1 < *(int *)((int)this_00 + 0x48))) &&
         (*(char *)(*(int *)((int)this_00 + 0x4c) + 0x3e + iVar1 * 0x48) != '\0')) {
        FUN_00534150(this_00,iVar1);
        FUN_005321f0(*(void **)((int)this + 8),(int *)((int)this + 0x28),1);
        return;
      }
      if (*(int *)((int)this + 0xb0) == 0) {
        *(undefined4 *)((int)this + 0xb0) = 1;
        UI_QueueControlCommand(*(void **)((int)this + 8),*(int *)((int)this + 4),0,0);
      }
    }
  }
  return;
}

