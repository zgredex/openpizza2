// rea decompile_all
// name: SoundBuffer_Init
// address: 0x540960
// body: available
// range: 0x540960-0x540a2e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall SoundBuffer_Init(void *this,int *param_1,int param_2)

{
  undefined2 uVar1;
  int iVar2;
  void *unaff_ESI;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 *local_4;
  
                    /* Initializes a sound buffer object and its stream. */
  puStack_8 = &LAB_0055af13;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *(undefined4 *)((int)this + 4) = 1;
  *(undefined ***)this = &PTR_LAB_0055c840;
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0xc) = 0;
  *(undefined4 *)((int)this + 0x10) = *(undefined4 *)(param_2 + 0x10);
  *(undefined4 *)((int)this + 0x14) = *(undefined4 *)(param_2 + 0x14);
  *(undefined4 *)((int)this + 0x18) = *(undefined4 *)(param_2 + 0x18);
  *(undefined4 *)((int)this + 0x1c) = *(undefined4 *)(param_2 + 0x1c);
  *(undefined4 *)((int)this + 0x20) = *(undefined4 *)(param_2 + 0x20);
  *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_2 + 0x24);
  uVar1 = *(undefined2 *)(param_2 + 0x28);
  *(undefined4 *)((int)this + 0x2c) = 0;
  *(undefined2 *)((int)this + 0x28) = uVar1;
  *(undefined4 *)((int)this + 0x30) = 0;
  *(undefined1 *)((int)this + 0x34) = *(undefined1 *)(param_2 + 0x34);
  *(undefined4 *)((int)this + 0x38) = 0;
  *(undefined4 *)((int)this + 0x3c) = 0;
  *(undefined4 *)((int)this + 0x40) = 0;
  *(undefined4 *)((int)this + 0x44) = 0;
  local_4 = (undefined4 *)0x1;
  *(undefined ***)this = &PTR_LAB_0055c874;
  (**(code **)(*param_1 + 8))(param_1);
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1,*(undefined4 *)(param_2 + 0x48),(int)this + 0x48);
  if ((-1 < iVar2) && (local_4 != (undefined4 *)0x0)) {
    *local_4 = 0;
  }
  ExceptionList = unaff_ESI;
  return this;
}

