// rea decompile_all
// name: AI_SelectRandomAction
// address: 0x5024f0
// body: available
// range: 0x5024f0-0x50260c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __fastcall AI_SelectRandomAction(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint local_8;
  
                    /* Depth-1 proposal batch 1. */
  uVar5 = 0;
  local_8 = 2;
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  iVar3 = FUN_00482820((int)DAT_0057c670);
  if (*(int *)(iVar2 + 0xc20 + iVar3 * 4) == 6) {
    if (*(int *)(param_1 + 0x44) != 0) goto LAB_0050258d;
    *(undefined4 *)(param_1 + 0x44) = 1;
  }
  if (*(int *)(param_1 + 0x44) == 0) {
    iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                         (int *)0x0);
    uVar5 = (uint)(4 < *(int *)(iVar2 + 0x10c4));
    if (*(int *)(*(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200) +
                0x1d8) != 0) {
      local_8 = 1;
    }
  }
LAB_0050258d:
  if (*(int *)(param_1 + 0x44) == 2) {
    uVar5 = 1;
    iVar2 = 0;
    do {
      iVar3 = FUN_00488be0(DAT_0057c670,iVar2);
      if (((iVar3 != 0) &&
          (iVar1 = *(int *)(iVar3 + 0x48), iVar4 = FUN_00482820((int)DAT_0057c670), iVar1 != iVar4))
         && (0 < *(int *)(iVar3 + 0x194))) goto LAB_005025d8;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 6);
    uVar5 = 1;
  }
LAB_005025d8:
  FUN_004034d0(uVar5,local_8);
  uVar5 = FUN_004034d0(uVar5,local_8);
  iVar2 = (*(int *)(param_1 + 0x44) + uVar5 * 4) * 4;
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(&DAT_0057270c + iVar2);
  return *(undefined4 *)(&DAT_005726dc + iVar2);
}

