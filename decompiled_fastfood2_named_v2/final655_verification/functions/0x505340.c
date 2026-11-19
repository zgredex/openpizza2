// rea decompile_all
// name: MapObject_ReadRenderRecord
// address: 0x505340
// body: available
// range: 0x505340-0x5053c0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall MapObject_ReadRenderRecord(void *this,int param_1,void *param_2)

{
  int iVar1;
  uint uVar2;
  void *local_4;
  
                    /* Reads a map object's optional render-sprite record. */
  local_4 = this;
  if (*(int *)((int)this + 0x30) == 0x10) {
    iVar1 = FUN_004017f0((void *)(DAT_0057c670 + 0x20),*(int *)((int)this + 0x50),(int *)0x0);
    uVar2 = (uint)*(byte *)(iVar1 + 0x824);
  }
  else {
    uVar2 = 0xffffffff;
  }
  FUN_00504e90(this,param_1,*(int *)((int)this + 0x30),uVar2);
  FUN_0054cbc1(param_2,&local_4,4);
  if (local_4 == (void *)0x1) {
    MapActor_ReadFromStream(param_2,*(uint **)((int)this + 200));
    return;
  }
  *(undefined4 *)((int)this + 200) = 0;
  return;
}

