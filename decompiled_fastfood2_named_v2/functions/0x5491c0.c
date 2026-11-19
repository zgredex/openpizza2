// rea decompile_all
// name: FUN_005491c0
// address: 0x5491c0
// body: available
// range: 0x5491c0-0x5492f8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005491c0(void *this,int param_1,char param_2,char param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 local_104 [260];
  
  if (*(char *)((int)this + 0xfc) == '\0') {
    return;
  }
  if (9 < param_1) {
    return;
  }
  iVar1 = (int)this + 0x178;
  CS_Enter(iVar1);
  if (param_3 == '\0') {
    *(undefined4 *)((int)this + 0x164) = 0xffffffff;
    CS_Leave(iVar1);
    return;
  }
  if (param_2 == '\0') {
    if (param_1 != *(int *)((int)this + 0x164)) {
      *(undefined4 *)((int)this + 0x16c) = 0x1e;
      iVar4 = param_1 * 2 + 1;
LAB_00549278:
      if (*(int *)((int)this + 0x10) != 0) {
        (**(code **)(**(int **)((int)this + 8) + 0x54))
                  (*(int **)((int)this + 8),*(int *)((int)this + 0x10));
        *(undefined4 *)((int)this + 0x10) = 0;
        *(undefined4 *)((int)this + 0x14) = 0;
      }
      String_Format(local_104,(byte *)s_Speech_Tutorial__02d_wav_005761b8,iVar4);
      puVar3 = FUN_00547400(this,local_104,3);
      *(undefined4 **)((int)this + 0x10) = puVar3;
      if (puVar3 != (undefined4 *)0x0) {
        *(undefined4 *)((int)this + 0x14) = 1;
      }
      *(int *)((int)this + 0x164) = param_1;
      CS_Leave(iVar1);
      return;
    }
  }
  else if ((*(int *)((int)this + 0x14) != 1) ||
          (uVar2 = FUN_00547270(this,*(uint *)((int)this + 0x10)), (char)uVar2 == '\0')) {
    if (*(int *)((int)this + 0x16c) == 0) {
      *(undefined4 *)((int)this + 0x16c) = 0x1e;
      iVar4 = param_1 * 2 + 2;
      goto LAB_00549278;
    }
    *(int *)((int)this + 0x16c) = *(int *)((int)this + 0x16c) + -1;
  }
  CS_Leave(iVar1);
  return;
}

