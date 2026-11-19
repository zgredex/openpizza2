// rea decompile_all
// name: FUN_004da480
// address: 0x4da480
// body: available
// range: 0x4da480-0x4da54a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004da480(void *this,int param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  FUN_004da2a0(this);
  Game_ChargeQuarterlyBribes((int)this);
  FUN_004da390((int)this);
  FUN_004da110(this);
  if (param_1 != 0) {
    FUN_004d9780((int)this);
  }
  iVar6 = *(int *)((int)this + 0xfdc);
  while (iVar6 = iVar6 + -1, -1 < iVar6) {
    piVar2 = (int *)FUN_004017f0((void *)((int)this + 0xfc8),iVar6,(int *)0x0);
    iVar4 = *piVar2;
    iVar1 = *(int *)(iVar4 + 0x38);
    if ((0x3c < iVar1) &&
       ((uVar3 = _rand(), (uVar3 & 7) == 0 ||
        (uVar3 = FUN_004034d0(0,100), (int)uVar3 < (iVar1 * 5 + -300) * 4)))) {
      FUN_004d6c10(this,iVar4);
      FUN_0054dd78(piVar2);
      FUN_004d3e30(iVar4);
    }
  }
  iVar6 = 5;
  puVar5 = (undefined4 *)((int)this + 0xddc);
  do {
    puVar7 = puVar5;
    puVar8 = puVar5 + 6;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar8 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar8 = puVar8 + 1;
    }
    iVar6 = iVar6 + -1;
    puVar7 = puVar5;
    for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = 0;
      puVar7 = puVar7 + 1;
    }
    puVar5 = puVar5 + 0x18;
  } while (iVar6 != 0);
  return;
}

