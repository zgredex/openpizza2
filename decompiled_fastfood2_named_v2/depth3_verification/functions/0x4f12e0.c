// rea decompile_all
// name: FUN_004f12e0
// address: 0x4f12e0
// body: available
// range: 0x4f12e0-0x4f1369 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f12e0(void *this,void *param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_4;
  
  iVar5 = 0;
  local_4 = 0;
  if (0 < *(int *)((int)this + 0xa4)) {
    iVar4 = 0;
    do {
      iVar2 = iVar4 + *(int *)((int)this + 0x9c);
      if (((iVar2 != param_2) &&
          (uVar1 = *(int *)(iVar2 + 0xc) - *(int *)(param_2 + 0xc), uVar3 = (int)uVar1 >> 0x1f,
          -1 < (int)(param_4 - ((uVar1 ^ uVar3) - uVar3)))) &&
         (uVar1 = *(int *)(iVar2 + 0x10) - *(int *)(param_2 + 0x10), uVar3 = (int)uVar1 >> 0x1f,
         -1 < (int)(param_4 - ((uVar1 ^ uVar3) - uVar3)))) {
        FUN_004014b0(param_1,(uint)*(ushort *)(iVar2 + 4));
        local_4 = local_4 + 1;
        if (param_3 <= local_4) {
          return;
        }
      }
      iVar5 = iVar5 + 1;
      iVar4 = iVar4 + 0x28;
    } while (iVar5 < *(int *)((int)this + 0xa4));
  }
  return;
}

