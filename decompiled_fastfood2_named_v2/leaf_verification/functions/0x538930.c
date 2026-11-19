// rea decompile_all
// name: FUN_00538930
// address: 0x538930
// body: available
// range: 0x538930-0x538a7c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00538930(void *this,int param_1)

{
  *(undefined4 *)((int)this + 0x2c) = 0;
  if (param_1 == 0) {
    **(undefined4 **)((int)this + 0x40) = 0;
    *(undefined4 *)(*(int *)((int)this + 0x40) + 4) = 0;
    *(undefined4 *)(*(int *)((int)this + 0x40) + 8) = 0;
    *(undefined4 *)(*(int *)((int)this + 0x40) + 0x10) = 0;
    *(undefined4 *)(*(int *)((int)this + 0x40) + 0xc) = 0;
    *(undefined2 *)((int)this + 0x1a) = (undefined2)DAT_00574734;
    *(undefined2 *)((int)this + 0x1c) = (undefined2)DAT_00574738;
    *(undefined4 *)((int)this + 0x48) = 0;
    Surface_ResetFlags((int)this);
    *(undefined4 *)((int)this + 0x84) = 0;
    *(undefined4 *)((int)this + 0x88) = 0;
    *(undefined4 *)((int)this + 0x8c) = 0;
    *(undefined4 *)((int)this + 0x90) = 0;
    *(undefined4 *)((int)this + 0x94) = 0;
  }
  else {
    *(undefined4 *)((int)this + 0x44) = *(undefined4 *)(param_1 + 0x44);
    **(undefined4 **)((int)this + 0x40) = **(undefined4 **)(param_1 + 0x40);
    *(undefined4 *)(*(int *)((int)this + 0x40) + 4) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
    *(undefined4 *)(*(int *)((int)this + 0x40) + 8) = *(undefined4 *)(*(int *)(param_1 + 0x40) + 8);
    *(undefined4 *)(*(int *)((int)this + 0x40) + 0x10) =
         *(undefined4 *)(*(int *)(param_1 + 0x40) + 4);
    *(undefined4 *)(*(int *)((int)this + 0x40) + 0xc) =
         *(undefined4 *)(*(int *)(param_1 + 0x40) + 8);
    *(undefined1 *)((int)this + 0x18) = *(undefined1 *)(param_1 + 0x18);
    *(undefined4 *)((int)this + 0x24) = *(undefined4 *)(param_1 + 0x24);
    *(undefined4 *)((int)this + 0x34) = *(undefined4 *)(param_1 + 0x34);
    *(undefined4 *)((int)this + 0x38) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)((int)this + 0x3c) = *(undefined4 *)(param_1 + 0x3c);
    *(undefined2 *)((int)this + 0x1a) = *(undefined2 *)(param_1 + 0x1a);
    *(undefined2 *)((int)this + 0x1c) = *(undefined2 *)(param_1 + 0x1c);
    *(undefined4 *)((int)this + 0x48) = 1;
    *(int *)((int)this + 0x54) = param_1;
    *(undefined4 *)((int)this + 0x74) = *(undefined4 *)(param_1 + 0x74);
    *(undefined4 *)((int)this + 0x84) = *(undefined4 *)(param_1 + 0x84);
    *(undefined4 *)((int)this + 0x88) = *(undefined4 *)(param_1 + 0x88);
    *(undefined4 *)((int)this + 0x8c) = *(undefined4 *)(param_1 + 0x8c);
    *(undefined4 *)((int)this + 0x90) = *(undefined4 *)(param_1 + 0x90);
    *(undefined4 *)((int)this + 0x94) = *(undefined4 *)(param_1 + 0x94);
  }
  Surface_Reset((int)this);
  SetRect((LPRECT)((int)this + 100),0,0,(uint)*(ushort *)((int)this + 0x1a),
          (uint)*(ushort *)((int)this + 0x1c));
  *(undefined4 *)((int)this + 0x5c) = 0;
  *(undefined4 *)((int)this + 0x60) = 0;
  *(undefined4 *)((int)this + 0x58) = 1;
  return;
}

