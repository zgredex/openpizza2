// rea decompile_all
// name: CRT_FRead
// address: 0x54dbdb
// body: available
// range: 0x54dbdb-0x54dc71 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall CRT_FRead(void *this,undefined4 *param_1,uint param_2)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int local_8;
  
  local_8 = 0;
  if (*(int *)((int)this + 8) == 0) {
    while (param_2 != 0) {
      iVar2 = (**(code **)(*(int *)this + 0x20))();
      if (iVar2 == -1) {
        return local_8;
      }
      uVar3 = *(int *)((int)this + 0x2c) - (int)*(undefined4 **)((int)this + 0x28);
      if ((int)param_2 <= (int)uVar3) {
        uVar3 = param_2;
      }
      if (0 < (int)uVar3) {
        _memmove_2(param_1,*(undefined4 **)((int)this + 0x28),uVar3);
        param_1 = (undefined4 *)((int)param_1 + uVar3);
        *(int *)((int)this + 0x28) = *(int *)((int)this + 0x28) + uVar3;
        local_8 = local_8 + uVar3;
        param_2 = param_2 - uVar3;
      }
    }
  }
  else {
    if (*(int *)((int)this + 0xc) == -1) {
      uVar1 = (**(code **)(*(int *)this + 0x20))();
      *(undefined4 *)((int)this + 0xc) = uVar1;
    }
    if (param_2 != 0) {
      do {
        param_2 = param_2 - 1;
        if (*(int *)((int)this + 0xc) == -1) {
          return local_8;
        }
        *(undefined1 *)param_1 = *(undefined1 *)((int)this + 0xc);
        param_1 = (undefined4 *)((int)param_1 + 1);
        local_8 = local_8 + 1;
        uVar1 = (**(code **)(*(int *)this + 0x20))();
        *(undefined4 *)((int)this + 0xc) = uVar1;
      } while (param_2 != 0);
    }
  }
  return local_8;
}

