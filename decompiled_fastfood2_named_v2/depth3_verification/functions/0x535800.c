// rea decompile_all
// name: Text_DrawCharAdvance
// address: 0x535800
// body: available
// range: 0x535800-0x5358c3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Text_DrawCharAdvance(void *this,void *param_1,char param_2)

{
  byte *pbVar1;
  uint local_4;
  
                    /* Depth-3 proposal batch 4. */
  if ((param_2 == '\n') || (param_2 == '\r')) {
    *(undefined4 *)((int)this + 0x9a0) = 0;
    *(int *)((int)this + 0x9a4) = *(int *)((int)this + 0x9a4) + *(int *)((int)this + 0x9b0);
    return;
  }
  local_4 = (uint)(byte)(param_2 - 0x20);
  if ((local_4 < 0xe0) &&
     (pbVar1 = *(byte **)((int)this + local_4 * 4 + 0x460), pbVar1 != (byte *)0x0)) {
    FUN_005358d0(this,param_1,pbVar1,(uint)*(byte *)(local_4 + (int)this),
                 (uint)*(byte *)(local_4 + 0xe0 + (int)this),
                 (uint)*(byte *)(local_4 + 0x2a0 + (int)this),
                 (uint)*(byte *)(local_4 + 0x380 + (int)this));
    *(uint *)((int)this + 0x9a0) =
         *(int *)((int)this + 0x9a0) + (uint)*(byte *)(local_4 + 0x1c0 + (int)this);
    return;
  }
  *(uint *)((int)this + 0x9a0) = *(int *)((int)this + 0x9a0) + (uint)*(byte *)((int)this + 0x1c0);
  return;
}

