// rea decompile_all
// name: SoundVoice_WriteSamples
// address: 0x5424b0
// body: available
// range: 0x5424b0-0x5425a2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall SoundVoice_WriteSamples(void *this,int param_1,uint param_2)

{
  void *this_00;
  char *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
                    /* Locks a buffer window and writes decoded sample bytes into it. */
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x38));
  pcVar1 = (char *)FUN_00540a80(*(void **)((int)this + 0x28),param_1,param_2);
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x38));
  if (pcVar1 == (char *)0x0) {
    return -0x7fffbffb;
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x38));
  if (*(char *)((int)this + 0x88) != '\0') {
    this_00 = *(void **)((int)this + 0x2c);
    uVar2 = (uint)*(ushort *)(*(int *)((int)this + 0x28) + 0x24) * *(int *)((int)this + 0x84);
    if (*(uint *)((int)this_00 + 0x28) < uVar2) {
      FUN_0053f790(this_00,0);
      *(undefined4 *)((int)this + 0x84) = 0;
    }
    else {
      FUN_0053f790(this_00,uVar2);
    }
    *(undefined1 *)((int)this + 0x88) = 0;
  }
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x38));
  iVar3 = SoundSample_ReadPCM(*(void **)((int)this + 0x2c),pcVar1,param_2);
  if (-1 < iVar3) {
    *(int *)((int)this + 0x84) =
         *(int *)((int)this + 0x84) + param_2 / *(ushort *)(*(int *)((int)this + 0x28) + 0x24);
  }
  EnterCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x38));
  iVar4 = FUN_00540b50(*(int *)((int)this + 0x28));
  LeaveCriticalSection(*(LPCRITICAL_SECTION *)((int)this + 0x38));
  if (-1 < iVar3) {
    iVar3 = iVar4;
  }
  return iVar3;
}

