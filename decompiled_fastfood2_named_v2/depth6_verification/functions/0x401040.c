// rea decompile_all
// name: FUN_00401040
// address: 0x401040
// body: available
// range: 0x401040-0x4010ee inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall FUN_00401040(void *this,undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 unaff_EDI;
  undefined4 *puVar5;
  
  *(undefined ***)this = &PTR_FUN_0055c2e0;
  iVar4 = 0;
  puVar5 = (undefined4 *)((int)this + 0x78);
  for (iVar2 = 0x19; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  puVar5 = (undefined4 *)((int)this + 0x10);
  for (iVar2 = 0x1a; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = 0;
    puVar5 = puVar5 + 1;
  }
  iVar2 = *(int *)(param_3 + 0x15c);
  if (0 < iVar2) {
    puVar3 = (undefined1 *)((int)this + 0xdc);
    do {
      iVar1 = FUN_004017f0((void *)(param_3 + 0x148),iVar4,(int *)0x0);
      FUN_0054dd83(puVar3,&DAT_005630d0,iVar1 + 4);
      iVar4 = iVar4 + 1;
      puVar3 = puVar3 + 0x20;
    } while (iVar4 < iVar2);
  }
  if (iVar2 < 0x14) {
    iVar4 = 0x14 - iVar2;
    puVar3 = (undefined1 *)(iVar2 * 0x20 + 0xdc + (int)this);
    do {
      FUN_0054dd83(puVar3,DAT_00582e4c,unaff_EDI);
      puVar3 = puVar3 + 0x20;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *(int *)((int)this + 0xc) = iVar2;
  *(undefined4 *)((int)this + 8) = param_2;
  *(undefined4 *)((int)this + 4) = param_1;
  return this;
}

