// rea decompile_all
// name: FUN_004e45e0
// address: 0x4e45e0
// body: available
// range: 0x4e45e0-0x4e466e inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004e45e0(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)(param_1 + 0xc));
  iVar2 = FUN_004ddcc0(iVar1);
  iVar1 = *(int *)(iVar2 + 0xa0);
  if (0 < iVar1) {
    do {
      iVar3 = FUN_004017f0((void *)(iVar2 + 0x8c),iVar6,(int *)0x0);
      iVar5 = ((uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 4) -
              (uint)*(ushort *)(iVar3 + 8)) + 1;
      if ((0 < iVar5) && (iVar5 < 4)) {
        iVar3 = *(int *)(iVar3 + 4);
        if (iVar3 == 0) {
          uVar4 = 0x1e;
        }
        else if (iVar3 == 1) {
          uVar4 = 0x28;
        }
        else {
          if (iVar3 != 2) goto LAB_004e4665;
          uVar4 = 0x14;
        }
        *(int *)(param_1 + 0x18) =
             *(int *)(param_1 + 0x18) + (int)((longlong)(ulonglong)uVar4 / (longlong)iVar5);
      }
LAB_004e4665:
      iVar6 = iVar6 + 1;
    } while (iVar6 < iVar1);
  }
  return;
}

