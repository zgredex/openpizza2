// rea decompile_all
// name: FUN_004dc0f0
// address: 0x4dc0f0
// body: available
// range: 0x4dc0f0-0x4dc195 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004dc0f0(void *this,int param_1)

{
  void *this_00;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  this_00 = *(void **)(DAT_0057c670 + 0x90);
  iVar1 = *(int *)(param_1 + 0x4c);
  if ((0 < DAT_0057bb30) && ((char)DAT_0057bb34 != '\0')) {
    FUN_004fd0a0(param_1,this,DAT_0057bb30);
  }
  if (DAT_0057bb20 == '\0') {
    iVar2 = 0;
    if (0 < *(int *)((int)this + 0x364)) {
      puVar3 = (undefined4 *)((int)this + 0x370);
      do {
        if (puVar3[-2] == iVar1) {
          FUN_004f8a80(this_00,iVar1,puVar3[-1],puVar3[1],(void *)*puVar3);
        }
        iVar2 = iVar2 + 1;
        puVar3 = puVar3 + 4;
      } while (iVar2 < *(int *)((int)this + 0x364));
    }
  }
  else if (DAT_0057bb3c._1_1_ != '\0') {
    FUN_004f8a80(this_00,iVar1,0,0,(void *)0xffffffff);
    return;
  }
  return;
}

