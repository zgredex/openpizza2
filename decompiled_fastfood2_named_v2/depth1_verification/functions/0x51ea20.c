// rea decompile_all
// name: UI_SetElementSprite
// address: 0x51ea20
// body: available
// range: 0x51ea20-0x51eada inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall UI_SetElementSprite(void *this,void *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Depth-1 proposal batch 2. */
  FUN_00401320(*(int *)(*(int *)((int)this + 8) + 0x1c8));
  *(void **)this = param_1;
  FUN_0053d090(param_1,&local_c,&local_10);
  if (param_2 != -9999) {
    *(int *)((int)this + 0x1c) = param_2;
  }
  if (param_3 != -9999) {
    *(int *)((int)this + 0x20) = param_3;
  }
  *(undefined4 *)((int)this + 0x14) = 1;
  iVar2 = *(int *)(*(int *)((int)this + 8) + 0x248);
  iVar1 = *(int *)(*(int *)((int)this + 8) + 0x24c);
  FUN_0053d100(*(void **)this,&local_4,&local_8);
  iVar1 = iVar1 + *(int *)((int)this + 0x20);
  iVar2 = iVar2 + *(int *)((int)this + 0x1c);
  FUN_00526d30(*(void **)((int)this + 8),iVar2,iVar1,iVar2 + local_c,iVar1 + local_10);
  if (*(int *)((int)this + 0x18) == 0) {
    *(int *)((int)this + 0xc) = iVar2;
    *(int *)((int)this + 0x10) = iVar1;
  }
  FUN_00401340(*(int *)(*(int *)((int)this + 8) + 0x1c8));
  return 1;
}

