// rea decompile_all
// name: CRT_Filebuf_Overflow
// address: 0x54ce81
// body: available
// range: 0x54ce81-0x54cef1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall CRT_Filebuf_Overflow(void *this,uint param_1)

{
  int iVar1;
  
  iVar1 = Stream_GetStatus(this);
  if ((iVar1 == -1) || (iVar1 = CRT_Filebuf_Sync((int)this), iVar1 == -1)) {
    return 0xffffffff;
  }
  if (*(int *)((int)this + 8) == 0) {
    *(undefined4 *)((int)this + 0x18) = *(undefined4 *)((int)this + 0x10);
    *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)((int)this + 0x10);
    *(undefined4 *)((int)this + 0x20) = *(undefined4 *)((int)this + 0x14);
  }
  if (param_1 != 0xffffffff) {
    if ((*(int *)((int)this + 8) == 0) &&
       (*(uint *)((int)this + 0x1c) < *(uint *)((int)this + 0x20))) {
      Stream_PutByte(this,param_1);
    }
    else {
      iVar1 = CRT_Write(*(uint *)((int)this + 0x4c),(char *)&param_1,1);
      if (iVar1 != 1) {
        return 0xffffffff;
      }
    }
  }
  return 1;
}

