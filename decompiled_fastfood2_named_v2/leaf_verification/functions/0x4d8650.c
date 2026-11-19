// rea decompile_all
// name: FUN_004d8650
// address: 0x4d8650
// body: available
// range: 0x4d8650-0x4d8770 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004d8650(void *param_1)

{
  int iVar1;
  undefined4 *this;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  this = FUN_004d59c0(param_1,0x13,0,'\0');
  iVar5 = 0;
  iVar1 = this[5];
  if (0 < iVar1) {
    piVar4 = (int *)((int)param_1 + 0xdcc);
    do {
      iVar2 = IDMap_Lookup(this,iVar5,(int *)0x0);
      iVar6 = *(int *)(iVar2 + 0x20) + -0x959 >> 2;
      uVar3 = FUN_004034d0(0,0x46);
      piVar4[-1] = (uVar3 - 0x46) + *(int *)(&DAT_0056c9d8 + iVar6 * 4);
      uVar3 = FUN_004034d0(0,7);
      *piVar4 = (uVar3 - 7) + *(int *)(&DAT_0056c9ec + iVar6 * 4);
      uVar3 = FUN_004034d0(0,0xf);
      piVar4[1] = (int)((float)(int)(uVar3 - 0xf) * 0.001 + *(float *)(&DAT_0056ca00 + iVar6 * 4));
      uVar3 = FUN_004034d0(0,5);
      piVar4[2] = (int)((float)(int)uVar3 * 0.01 + *(float *)(&DAT_0056ca14 + iVar6 * 4));
      piVar4[3] = *(int *)(iVar2 + 0x24);
      piVar7 = piVar4 + 4;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
      }
      piVar7 = piVar4 + 10;
      for (iVar2 = 6; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar7 = 0;
        piVar7 = piVar7 + 1;
      }
      uVar3 = FUN_004034d0(0,2);
      FUN_0054dd83((undefined1 *)(piVar4 + 0x10),&DAT_005630d0,
                   *(undefined4 *)(&DAT_0058325c + (uVar3 + iVar6 * 3) * 4));
      iVar5 = iVar5 + 1;
      piVar4 = piVar4 + 0x18;
    } while (iVar5 < iVar1);
  }
  if (this != (undefined4 *)0x0) {
    (**(code **)*this)(1);
  }
  return;
}

