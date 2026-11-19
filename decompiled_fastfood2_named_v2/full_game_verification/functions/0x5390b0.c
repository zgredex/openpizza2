// rea decompile_all
// name: Surface_GetDescription
// address: 0x5390b0
// body: available
// range: 0x5390b0-0x53917d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall Surface_GetDescription(void *this,int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_6c [2];
  undefined2 uStack_64;
  undefined2 uStack_60;
  int iStack_5c;
  undefined4 uStack_48;
  
  iVar2 = 0;
  puVar3 = local_6c;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_6c[0] = 0x6c;
  while( true ) {
    if (DAT_005844fc != 0) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 100))(param_1,0,local_6c,1,0);
    if (iVar1 == 0) break;
    if (iVar1 == -0x7789fe3e) {
      Thread_WaitForExit((int)this);
    }
    Sleep(1);
    iVar2 = iVar2 + 1;
    if (200 < iVar2) {
      return 0;
    }
  }
  *param_2 = iStack_5c;
  *(undefined2 *)((int)this + 0x1a) = uStack_60;
  *(undefined4 *)((int)this + 0x28) = uStack_48;
  *(undefined2 *)((int)this + 0x1c) = uStack_64;
  *(int *)((int)this + 0x20) = iStack_5c >> 1;
  Surface_Reset((int)this);
  SetRect((LPRECT)((int)this + 100),0,0,(uint)*(ushort *)((int)this + 0x1a),
          (uint)*(ushort *)((int)this + 0x1c));
  return uStack_48;
}

