// rea decompile_all
// name: FUN_00549070
// address: 0x549070
// body: available
// range: 0x549070-0x54916d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00549070(void *this,int param_1,char param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined1 local_104 [260];
  
  if (((*(char *)((int)this + 0xfc) == '\0') || (param_1 < 0)) || (9 < param_1)) {
    return;
  }
  iVar1 = (int)this + 0x178;
  CS_Enter(iVar1);
  if (param_2 == '\0') {
    iVar3 = param_1 * 2 + 1;
    if (0 < param_1) {
      iVar3 = param_1 * 2;
    }
  }
  else {
    if (param_1 < 1) {
      CS_Leave(iVar1);
      return;
    }
    iVar3 = param_1 * 2 + 1;
    if (iVar3 == *(int *)((int)this + 0x160)) {
      CS_Leave(iVar1);
      return;
    }
  }
  if (*(int *)((int)this + 0x10) != 0) {
    (**(code **)(**(int **)((int)this + 8) + 0x54))
              (*(int **)((int)this + 8),*(int *)((int)this + 0x10));
    *(undefined4 *)((int)this + 0x10) = 0;
    *(undefined4 *)((int)this + 0x14) = 0;
  }
  FUN_0054dd83(local_104,(byte *)s_Speech_Missionen__02d_wav_0057619c,iVar3);
  puVar2 = Sound_Play(this,local_104,3);
  *(undefined4 **)((int)this + 0x10) = puVar2;
  if (puVar2 != (undefined4 *)0x0) {
    *(undefined4 *)((int)this + 0x14) = 3;
    *(int *)((int)this + 0x160) = iVar3;
  }
  CS_Leave(iVar1);
  return;
}

