// rea decompile_all
// name: FUN_00547c60
// address: 0x547c60
// body: available
// range: 0x547c60-0x547dd4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00547c60(void *this,int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_104 [260];
  
  *(int *)((int)this + 0x104) = param_1;
  if (*(char *)((int)this + 0xfc) != '\0') {
    if (param_1 == 1) {
      uVar3 = FUN_00547270(this,*(uint *)((int)this + 0x10));
      if ((char)uVar3 == '\0') {
        *(undefined4 *)((int)this + 0x20) = 0;
      }
      else {
        *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0x10);
      }
      (**(code **)(**(int **)((int)this + 8) + 0x7c))
                (*(int **)((int)this + 8),*(undefined4 *)((int)this + 0x80),
                 *(undefined4 *)((int)this + 0x1d0));
      (**(code **)(**(int **)((int)this + 8) + 0x58))
                (*(int **)((int)this + 8),*(undefined4 *)((int)this + 0x80),1);
    }
    else if (param_1 != 2) {
      if (param_1 != 3) {
        return;
      }
      uVar3 = FUN_00547270(this,*(uint *)((int)this + 0x10));
      if ((char)uVar3 == '\0') {
        puVar1 = (undefined4 *)((int)this + 0x20);
        (**(code **)(**(int **)((int)this + 8) + 0x34))
                  (*(int **)((int)this + 8),s_Speech_Statements_01_wav_005760ec,1,puVar1);
        (**(code **)(**(int **)((int)this + 8) + 0x80))
                  (*(int **)((int)this + 8),*puVar1,*(undefined4 *)((int)this + 0x1d8));
        (**(code **)(**(int **)((int)this + 8) + 0x60))(*(int **)((int)this + 8),*puVar1,1);
        *(undefined1 *)((int)this + 0xff) = 1;
        return;
      }
      *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0x10);
      return;
    }
    puVar1 = (undefined4 *)((int)this + 0xc);
    if (((*(int *)((int)this + 0xc) == 0) && (iVar2 = *(int *)((int)this + 0x108), iVar2 != -1)) &&
       (iVar2 < 0xc)) {
      FUN_0054dd83(local_104,(byte *)s_Music__s_005760e0,
                   (&PTR_s_Mus_Menue_Start_wav_00575220)[iVar2]);
      (**(code **)(**(int **)((int)this + 8) + 0x34))(*(int **)((int)this + 8),local_104,1,puVar1);
      (**(code **)(**(int **)((int)this + 8) + 0x78))
                (*(int **)((int)this + 8),*puVar1,
                 *(undefined4 *)((int)this + *(int *)((int)this + 0x108) * 4 + 0x10c));
      (**(code **)(**(int **)((int)this + 8) + 0x80))
                (*(int **)((int)this + 8),*puVar1,*(undefined4 *)((int)this + 0x1d4));
      (**(code **)(**(int **)((int)this + 8) + 0x60))(*(int **)((int)this + 8),*puVar1,1);
    }
  }
  return;
}

