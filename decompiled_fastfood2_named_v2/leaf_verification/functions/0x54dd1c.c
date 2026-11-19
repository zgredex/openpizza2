// rea decompile_all
// name: FUN_0054dd1c
// address: 0x54dd1c
// body: available
// range: 0x54dd1c-0x54dd77 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_0054dd1c(void *this,char param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (*(uint *)((int)this + 0x24) < *(uint *)((int)this + 0x28)) {
    iVar2 = Stream_PutBackChar(this,param_1);
  }
  else {
    iVar2 = 1;
    iVar3 = (**(code **)(*(int *)this + 0xc))(0xffffffff,1);
    if (iVar3 == -1) {
      iVar2 = -1;
    }
    else if ((*(int *)((int)this + 8) == 0) && (*(int *)((int)this + 0x2c) != 0)) {
      puVar1 = *(undefined4 **)((int)this + 0x28);
      _memmove((undefined4 *)((int)puVar1 + 1),puVar1,(*(int *)((int)this + 0x2c) - (int)puVar1) - 1
              );
      **(undefined1 **)((int)this + 0x28) = (char)iVar2;
    }
  }
  return iVar2;
}

