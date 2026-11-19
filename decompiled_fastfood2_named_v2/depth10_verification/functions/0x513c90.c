// rea decompile_all
// name: Storage_Construct
// address: 0x513c90
// body: available
// range: 0x513c90-0x513d28 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall Storage_Construct(void *this,void *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Constructs a storage object, optionally from a save stream. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a4fb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_004013a0((void *)((int)this + 0x44),0);
  local_4 = 0;
  *(undefined ***)this = &PTR_FUN_0055c700;
  if (param_1 != (void *)0x0) {
    FUN_00513d50(this,param_1);
    ExceptionList = local_c;
    return this;
  }
  *(undefined4 *)((int)this + 0x24) = 0xffffffff;
  *(undefined4 *)((int)this + 0x28) = 0xffffffff;
  *(undefined4 *)((int)this + 0x2c) = 1;
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x34) = 0;
  *(undefined1 *)((int)this + 0x3c) = 1;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x30) = 0xffffffff;
  puVar2 = (undefined4 *)((int)this + 0x60);
  for (iVar1 = 0x3c; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  ExceptionList = local_c;
  return this;
}

