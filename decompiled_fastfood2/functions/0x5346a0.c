// rea decompile_all
// name: FUN_005346a0
// address: 0x5346a0
// body: available
// range: 0x5346a0-0x534788 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005346a0(void *this,int param_1,uint *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  longlong lVar3;
  
  if ((-1 < param_3) && (param_3 < *(int *)((int)this + 0x48))) {
    FUN_00401320(0x5842a0);
    if (*(int *)(*(int *)((int)this + 0x4c) + param_3 * 0x48) == -1) {
      FUN_00401340(0x5842a0);
      return;
    }
    if (*(char *)((int)this + 0x35) == '\0') {
      FUN_00533400((int)this);
    }
    iVar2 = param_3 * 0x48 + *(int *)((int)this + 0x4c);
    *(undefined2 *)((int)this + 6) =
         *(undefined2 *)(*(int *)((int)this + 0x20) + *(short *)(iVar2 + 0x32) * 2);
    *(undefined2 *)((int)this + 8) =
         *(undefined2 *)(*(int *)((int)this + 0x24) + *(short *)(iVar2 + 0x32) * 2);
    *(undefined2 *)((int)this + 10) =
         *(undefined2 *)(*(int *)((int)this + 0x28) + *(short *)(iVar2 + 0x32) * 2);
    *(undefined2 *)((int)this + 0xc) =
         *(undefined2 *)(*(int *)((int)this + 0x2c) + *(short *)(iVar2 + 0x32) * 2);
    lVar3 = __ftol();
    iVar1 = (int)lVar3;
    lVar3 = __ftol();
    FUN_0053bf00(this,param_1,param_2,
                 *(byte **)(*(int *)((int)this + 0x80) + *(short *)(iVar2 + 0x32) * 4),(uint)lVar3,
                 iVar1);
    FUN_00401340(0x5842a0);
  }
  return;
}

