// rea decompile_all
// name: FUN_00538fa0
// address: 0x538fa0
// body: available
// range: 0x538fa0-0x5390a0 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00538fa0(void *this,int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_6c [2];
  undefined2 uStack_64;
  undefined2 uStack_60;
  int iStack_5c;
  undefined4 uStack_48;
  
  iVar3 = 0;
  if ((DAT_00584504 != 0) && (DAT_005844fc == 0)) {
    puVar4 = local_6c;
    for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    local_6c[0] = 0x6c;
    while( true ) {
      if (param_1 == 0) {
        piVar1 = *(int **)(*(int *)((int)this + 0x40) + 0x10);
      }
      else {
        piVar1 = *(int **)(*(int *)((int)this + 0x40) + 0xc);
      }
      iVar2 = (**(code **)(*piVar1 + 100))(piVar1,0,local_6c,1,0);
      if (iVar2 == 0) {
        *(undefined2 *)((int)this + 0x1a) = uStack_60;
        *(undefined2 *)((int)this + 0x1c) = uStack_64;
        *(undefined4 *)((int)this + 0x28) = uStack_48;
        *(int *)((int)this + 0x20) = iStack_5c >> 1;
        Surface_Reset((int)this);
        SetRect((LPRECT)((int)this + 100),0,0,(uint)*(ushort *)((int)this + 0x1a),
                (uint)*(ushort *)((int)this + 0x1c));
        *(undefined4 *)((int)this + 0x14) = 1;
        *(int *)((int)this + 0x28) =
             *(int *)((int)this + 0x28) +
             (*(int *)((int)this + 0x7c) * *(int *)((int)this + 0x20) + *(int *)((int)this + 0x78))
             * 2;
        return 1;
      }
      if ((0 < iVar3) || (iVar3 = iVar3 + 1, iVar2 != -0x7789fe3e)) break;
      Thread_WaitForExit((int)this);
      Sleep(1);
    }
  }
  return 0;
}

