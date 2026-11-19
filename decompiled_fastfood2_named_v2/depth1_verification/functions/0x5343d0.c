// rea decompile_all
// name: FUN_005343d0
// address: 0x5343d0
// body: available
// range: 0x5343d0-0x5344db inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005343d0(void *this,int param_1,int param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  longlong lVar5;
  byte *pbVar6;
  int iVar7;
  
  if ((-1 < param_2) && (param_2 < *(int *)((int)this + 0x48))) {
    FUN_00401320(0x5842a0);
    piVar2 = (int *)(*(int *)((int)this + 0x4c) + param_2 * 0x48);
    if ((*piVar2 != -1) &&
       ((sVar1 = *(short *)((int)piVar2 + 0x32), (int)sVar1 < *(int *)((int)this + 0x68) &&
        (-1 < sVar1)))) {
      if (*(char *)((int)this + 0x35) == '\0') {
        RecordList_EnsureLoaded((int)this);
      }
      iVar4 = param_2 * 0x48 + *(int *)((int)this + 0x4c);
      iVar7 = -1;
      pbVar6 = (byte *)0xffffffff;
      *(undefined2 *)((int)this + 6) =
           *(undefined2 *)(*(int *)((int)this + 0x20) + *(short *)(iVar4 + 0x32) * 2);
      *(undefined2 *)((int)this + 8) =
           *(undefined2 *)(*(int *)((int)this + 0x24) + *(short *)(iVar4 + 0x32) * 2);
      *(undefined2 *)((int)this + 10) =
           *(undefined2 *)(*(int *)((int)this + 0x28) + *(short *)(iVar4 + 0x32) * 2);
      *(undefined2 *)((int)this + 0xc) =
           *(undefined2 *)(*(int *)((int)this + 0x2c) + *(short *)(iVar4 + 0x32) * 2);
      lVar5 = __ftol();
      iVar3 = (int)lVar5;
      lVar5 = __ftol();
      FUN_0053a780(this,param_1,
                   *(uint **)(*(int *)((int)this + 0x80) + *(short *)(iVar4 + 0x32) * 4),
                   *(int *)((int)this + 0x7c),(uint *)lVar5,iVar3,pbVar6,iVar7);
      FUN_00401340(0x5842a0);
      return;
    }
    FUN_00401340(0x5842a0);
  }
  return;
}

