// rea decompile_all
// name: UI_LoadFont
// address: 0x526fa0
// body: available
// range: 0x526fa0-0x527088 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


uint * __thiscall UI_LoadFont(void *this,LPCSTR param_1)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  int local_14;
  void *local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Loads a font and caches it in the UI font list. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a7bb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_10 = operator_new(0x9c8);
  local_4 = 0;
  if (local_10 == (void *)0x0) {
    pcVar2 = (char *)0x0;
  }
  else {
    pcVar2 = FUN_00535180(local_10,*(undefined4 *)((int)this + 0xc),*(void **)((int)this + 0x10),
                          param_1,&local_14);
  }
  local_4 = 0xffffffff;
  if (local_14 != 0) {
    if (pcVar2 != (char *)0x0) {
      FUN_005354e0((int)pcVar2);
      FUN_0054dd78(pcVar2);
    }
    ExceptionList = local_c;
    return (uint *)0x0;
  }
  puVar3 = operator_new(0x110);
  puVar5 = puVar3;
  for (iVar4 = 0x44; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  FUN_005273c0(param_1,puVar3);
  uVar1 = *(uint *)((int)this + 0x82c4);
  puVar3[0x41] = (uint)pcVar2;
  puVar3[0x43] = uVar1;
  *(uint **)((int)this + 0x82c4) = puVar3;
  ExceptionList = local_c;
  return puVar3;
}

