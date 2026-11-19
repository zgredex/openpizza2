// rea decompile_all
// name: SoundBuffer_SeekSample
// address: 0x53f790
// body: available
// range: 0x53f790-0x53f819 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall SoundBuffer_SeekSample(void *this,uint param_1)

{
  int iVar1;
  
                    /* Depth-1 proposal batch 3/4. */
  iVar1 = *(int *)((int)this + 0xc);
  if (iVar1 == 0) {
    return 0x80070006;
  }
  if (*(short *)((int)this + 0x14) == 1) {
    FUN_00540000(*(int *)((int)this + 0x2c) + param_1,iVar1,0);
    *(uint *)((int)this + 0x30) = param_1;
    return 0;
  }
  FUN_00540000((param_1 /
               ((uint)*(ushort *)((int)this + 0x20) * 4 + (uint)*(ushort *)((int)this + 0x16) * -0xe
               )) * (uint)*(ushort *)((int)this + 0x20) + *(int *)((int)this + 0x2c),iVar1,0);
  *(uint *)((int)this + 0x30) = param_1;
  *(undefined1 *)((int)this + 0x48) = 1;
  return 0;
}

