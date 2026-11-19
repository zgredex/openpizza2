// rea decompile_all
// name: Sound_PlaySpeechStatement
// address: 0x548e00
// body: available
// range: 0x548e00-0x548ecb inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Sound_PlaySpeechStatement(void *this,int param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined1 auStack_104 [260];
  
                    /* Formats and plays Speech_Statements_%02d.wav. */
  if (*(char *)((int)this + 0xfc) != '\0') {
    FUN_00401320((int)this + 0x178);
    if ((*(char *)((int)this + 0x100) == '\0') && (param_1 != -1)) {
      uVar1 = FUN_00547270(this,*(uint *)((int)this + 0x10));
      if (((char)uVar1 == '\0') ||
         ((*(int *)((int)this + 0x14) != 1 && (*(int *)((int)this + 0x14) != 3)))) {
        uVar1 = FUN_00547270(this,*(uint *)((int)this + 0x10));
        if ((char)uVar1 == '\0') {
          (**(code **)(**(int **)((int)this + 8) + 0x54))
                    (*(int **)((int)this + 8),*(undefined4 *)((int)this + 0x10));
          *(undefined4 *)((int)this + 0x10) = 0;
          *(undefined4 *)((int)this + 0x14) = 0;
          FUN_0054dd83(auStack_104,(byte *)s_Speech_Statements__02d_wav_00576180,param_1);
          puVar2 = FUN_00547400(this,auStack_104,3);
          *(undefined4 **)((int)this + 0x10) = puVar2;
          if (puVar2 != (undefined4 *)0x0) {
            *(undefined4 *)((int)this + 0x14) = 2;
          }
        }
      }
    }
    FUN_00401340((int)this + 0x178);
  }
  return;
}

