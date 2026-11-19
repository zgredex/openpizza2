// rea decompile_all
// name: Surface_InitPixelFormat
// address: 0x537e00
// body: available
// range: 0x537e00-0x537f1d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Surface_InitPixelFormat(void *this,int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint local_20 [4];
  undefined4 uStack_10;
  
                    /* Depth-1 proposal batch 3/4. */
  *param_1 = 0;
  if ((param_2 != 0) && (FUN_00537f20((int)this), *param_1 != 0)) {
    return;
  }
  puVar3 = local_20;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }
  local_20[0] = 0x20;
  piVar1 = *(int **)(*(int *)((int)this + 0x40) + 4);
  iVar2 = (**(code **)(*piVar1 + 0x54))(piVar1,local_20);
  if (iVar2 != 0) {
    if (iVar2 == -0x7ff8ffa9) {
      *param_1 = 0x106;
      return;
    }
    if (iVar2 == -0x7789ff7e) {
      *param_1 = 0x105;
      return;
    }
    *param_1 = (-(uint)(iVar2 != -0x7789fdb0) & 0xfc) + 0x107;
    return;
  }
  *param_1 = 0;
  if (local_20[2] == 0xf800) {
    *(undefined1 *)((int)this + 0x18) = 1;
  }
  else {
    *(undefined1 *)((int)this + 0x18) = 0;
  }
  local_20[1] = local_20[1] & 0xff;
  *(uint *)((int)this + 0x24) = local_20[1];
  if ((local_20[1] == 0xf) || (local_20[1] == 0x10)) {
    *(undefined4 *)((int)this + 0x34) = uStack_10;
    *(uint *)((int)this + 0x38) = local_20[3];
    *(uint *)((int)this + 0x3c) = local_20[2];
    return;
  }
  *(undefined4 *)((int)this + 0x34) = 0x1f;
  *(undefined4 *)((int)this + 0x38) = 0x3e0;
  *(undefined4 *)((int)this + 0x3c) = 0x7c00;
  return;
}

