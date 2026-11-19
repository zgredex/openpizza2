// rea decompile_all
// name: FUN_004f0d00
// address: 0x4f0d00
// body: available
// range: 0x4f0d00-0x4f0e18 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004f0d00(void *this,int *param_1,int param_2,int param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  short *psVar4;
  int *piVar5;
  
  iVar2 = *(int *)((int)this + 0xb4);
  iVar1 = FUN_004f0bd0(this,param_1,param_2,param_3);
  if (param_4 != (uint *)0x0) {
    *param_4 = (uint)(iVar1 != 0);
  }
  if (iVar1 == 0) {
    piVar3 = param_1;
  }
  else {
    piVar3 = (int *)(uint)*(ushort *)(iVar1 + 2);
  }
  if (*(int *)((int)this + 0xb4) == 0) {
    piVar5 = param_1;
  }
  else {
    piVar5 = (int *)(uint)*(ushort *)(*(int *)((int)this + 0xb4) + 2);
  }
  if (iVar1 == 0) {
    iVar1 = FUN_004f0e30(this,param_1,param_2,param_3);
    *(int *)((int)this + 0xb4) = iVar1;
  }
  else {
    iVar1 = FUN_004f0c60(this,param_1,(uint)piVar3);
    *(int *)((int)this + 0xb4) = iVar1;
  }
  if ((iVar2 != 0) && (iVar2 = FUN_004f0c60(this,param_1,(uint)piVar5), iVar2 != 0)) {
    iVar1 = 0;
    psVar4 = (short *)(iVar2 + 0x14);
    do {
      if (*psVar4 == -1) {
        *(undefined2 *)(iVar2 + 0x14 + iVar1 * 2) = *(undefined2 *)(*(int *)((int)this + 0xb4) + 4);
        break;
      }
      iVar1 = iVar1 + 1;
      psVar4 = psVar4 + 1;
    } while (iVar1 < 8);
    if (param_1 == (int *)0x1) {
      iVar1 = 0;
      psVar4 = (short *)(*(int *)((int)this + 0xb4) + 0x14);
      do {
        if (*psVar4 == -1) {
          *(undefined2 *)(*(int *)((int)this + 0xb4) + 0x14 + iVar1 * 2) =
               *(undefined2 *)(iVar2 + 4);
          break;
        }
        iVar1 = iVar1 + 1;
        psVar4 = psVar4 + 1;
      } while (iVar1 < 8);
    }
  }
  NoOp_2();
  return *(undefined4 *)((int)this + 0xb4);
}

