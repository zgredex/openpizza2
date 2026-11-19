// rea decompile_all
// name: SoundBuffer_Construct
// address: 0x546220
// body: available
// range: 0x546220-0x5462ff inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall SoundBuffer_Construct(void *this,int *param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  DWORD DVar3;
  int iVar4;
  int iVar5;
  undefined4 *puVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Depth-1 proposal batch 2. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b718;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  FUN_00540960(this,param_1,param_2);
  puVar1 = (undefined4 *)((int)this + 0x5c);
  *(undefined4 *)((int)this + 0x4c) = 0;
  *(undefined4 *)((int)this + 0x50) = 0;
  *(undefined4 *)((int)this + 0x54) = 0;
  *(undefined4 *)((int)this + 0x58) = 0;
  local_4 = 0;
  *puVar1 = 0;
  *(undefined1 *)((int)this + 0xa0) = 0;
  *(undefined1 *)((int)this + 0xa1) = 0;
  DVar3 = timeGetTime();
  *(DWORD *)((int)this + 0xa4) = DVar3;
  *(DWORD *)((int)this + 0xa8) = DVar3;
  *(undefined ***)this = &PTR_LAB_0055c8c8;
  if (-1 < *param_3) {
    iVar4 = (**(code **)**(undefined4 **)((int)this + 0x48))
                      (*(undefined4 **)((int)this + 0x48),&DAT_0055cb88,puVar1);
    if (iVar4 < 0) {
      *puVar1 = 0;
    }
    else {
      puVar2 = (undefined4 *)((int)this + 0x60);
      puVar6 = puVar2;
      for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar6 = 0;
        puVar6 = puVar6 + 1;
      }
      *puVar2 = 0x40;
      (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,puVar2);
    }
    *(uint *)((int)this + 0x50) = *(uint *)((int)this + 0x50) | 3;
    if (param_3 != (int *)0x0) {
      *param_3 = iVar4;
    }
  }
  ExceptionList = local_c;
  return this;
}

