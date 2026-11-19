// rea decompile_all
// name: FUN_005219a0
// address: 0x5219a0
// body: available
// range: 0x5219a0-0x521a47 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
FUN_005219a0(void *this,int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int local_8;
  int local_4;
  
  Sprite_GetSize(*(void **)((int)this + 0x60),&local_8,&local_4);
  uVar1 = FUN_00539840(*(void **)((int)this + 0x68),param_5);
  if (param_1 < 0) {
    param_1 = 0;
  }
  if (param_2 < 0) {
    param_2 = 0;
  }
  if (local_8 <= param_3) {
    param_3 = local_8 + -1;
  }
  if (local_4 <= param_4) {
    param_4 = local_4 + -1;
  }
  iVar2 = FUN_0053d480(*(void **)((int)this + 0x60));
  puVar3 = (undefined4 *)(iVar2 + (local_8 * param_2 + param_1) * 2);
  if (param_2 <= param_4) {
    iVar2 = (param_4 - param_2) + 1;
    do {
      Mem_FillWord(puVar3,uVar1,param_3 - param_1);
      iVar2 = iVar2 + -1;
      puVar3 = (undefined4 *)((int)puVar3 + local_8 * 2);
    } while (iVar2 != 0);
  }
  return;
}

