// rea decompile_all
// name: FUN_00501aa0
// address: 0x501aa0
// body: available
// range: 0x501aa0-0x501b4a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_00501aa0(void *this,void *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a1eb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004013a0((void *)((int)this + 0x68),0);
  local_4 = 0;
  *(undefined ***)this = &PTR_FUN_0055c664;
  if (param_1 != (void *)0x0) {
    FUN_00501b80(this,param_1);
    ExceptionList = local_c;
    return this;
  }
  FUN_00503280((int)this);
  puVar3 = (undefined4 *)((int)this + 0xc);
  for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)((int)this + 0x88);
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  puVar3 = (undefined4 *)((int)this + 0x16c);
  for (iVar2 = 0x39; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  uVar1 = FUN_004034d0(0xd,0x16);
  *(uint *)((int)this + 0x5c) = uVar1;
  ExceptionList = local_c;
  return this;
}

