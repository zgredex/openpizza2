// rea decompile_all
// name: FUN_00512620
// address: 0x512620
// body: available
// range: 0x512620-0x5126f5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_00512620(void *this,int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int extraout_EDX;
  int unaff_EDI;
  undefined4 *puVar6;
  
  puVar6 = (undefined4 *)((int)this + 0x1e0);
  for (iVar5 = 0x18; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar6 = 0;
    puVar6 = puVar6 + 1;
  }
  iVar5 = 0;
  if (0 < *(int *)((int)this + 0x5c)) {
    do {
      iVar4 = FUN_004017f0((void *)((int)this + 0x48),iVar5,(int *)0x0);
      iVar3 = *(int *)(DAT_0057c670 + 0xa8 + (uint)*(byte *)(iVar4 + 4) * 4);
      iVar1 = (uint)*(byte *)(iVar4 + 0x10) + (uint)*(byte *)(iVar4 + 6) * 8;
      sVar2 = *(short *)(iVar3 + 0x48 + iVar1 * 2);
      *(int *)(iVar4 + 0x14) = ((int)*(short *)(iVar3 + 8 + iVar1 * 2) >> 1) + *(int *)(iVar4 + 8);
      *(int *)(iVar4 + 0x18) = ((int)sVar2 >> 1) + *(int *)(iVar4 + 0xc);
      FUN_005123f0(this,iVar4,*(int *)(*(int *)(DAT_0057c670 + 0xa0) + 0x18));
      iVar5 = iVar5 + 1;
    } while (iVar5 < *(int *)((int)this + 0x5c));
  }
  FUN_00512ca0(this);
  FUN_0050fec0((int)this);
  FUN_00512e50((int)this);
  FUN_00512f10(this);
  Stats_ComputeWeightedAverages(this,unaff_EDI);
  FUN_00513270((int)this);
  FUN_005133c0((int)this);
  FUN_00513590(this,extraout_EDX);
  FUN_005136c0(this,param_1);
  return;
}

