// rea decompile_all
// name: FUN_004da300
// address: 0x4da300
// body: available
// range: 0x4da300-0x4da38d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004da300(int param_1)

{
  void *this;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  iVar3 = 0;
  piVar4 = (int *)(param_1 + 0xcc8);
  do {
    this = (void *)Game_GetPlayerBySlot(DAT_0057c670,iVar3);
    if ((this != (void *)0x0) && (piVar4[0x39] != 0)) {
      uVar1 = FUN_004e0b60(this,0x14,(float)(uint)piVar4[0x39],'\x01',0xffffffff);
      if ((char)uVar1 == '\0') {
        piVar4[0x39] = 0;
        *piVar4 = 0;
        iVar2 = Game_GetPlayerCity((int)this);
        iVar2 = *piVar4 + (*(int *)(iVar2 + 0x60) + *(int *)(iVar2 + 0x48)) * 3;
        *piVar4 = iVar2;
        if (iVar2 < 0) {
          *piVar4 = 0;
        }
        if (100 < *piVar4) {
          *piVar4 = 100;
        }
      }
    }
    iVar3 = iVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (iVar3 < 6);
  return;
}

