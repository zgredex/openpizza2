// rea decompile_all
// name: FUN_005311a0
// address: 0x5311a0
// body: available
// range: 0x5311a0-0x5312d5 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __thiscall FUN_005311a0(void *this,int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  FUN_00401320(*(int *)(*(int *)((int)this + 0x134) + 0x1c8));
  UI_PurgeChildFromLists(this,param_1);
  iVar5 = FUN_00531330(this,param_1,'\0');
  if (iVar5 == -1) {
    FUN_00401340(*(int *)(*(int *)((int)this + 0x134) + 0x1c8));
  }
  else {
    UI_ClearDestroyedObjectReferences
              (*(void **)((int)this + 0x134),*(int *)(*(int *)((int)this + 0xe8) + iVar5 * 8));
    iVar2 = *(int *)((int)this + 0xf0);
    iVar7 = 0;
    if (0 < iVar2) {
      piVar3 = *(int **)((int)this + 0xec);
      piVar6 = piVar3;
      do {
        if (*piVar6 == *(int *)(*(int *)((int)this + 0xe8) + iVar5 * 8)) {
          uVar1 = (iVar2 - iVar7) * 8 - 8;
          if (0 < (int)uVar1) {
            FUN_0054e230(piVar3 + iVar7 * 2,piVar3 + iVar7 * 2 + 2,uVar1);
          }
          break;
        }
        iVar7 = iVar7 + 1;
        piVar6 = piVar6 + 2;
      } while (iVar7 < iVar2);
    }
    FUN_00521b30(*(int *)(*(int *)((int)this + 0xe8) + iVar5 * 8));
    puVar4 = *(undefined4 **)(*(int *)((int)this + 0xe8) + iVar5 * 8);
    if (puVar4 != (undefined4 *)0x0) {
      (**(code **)*puVar4)(1);
    }
    uVar1 = (*(int *)((int)this + 0xf0) - iVar5) * 8 - 8;
    if (0 < (int)uVar1) {
      FUN_0054e230((undefined4 *)(*(int *)((int)this + 0xe8) + iVar5 * 8),
                   (undefined4 *)(*(int *)((int)this + 0xe8) + 8 + iVar5 * 8),uVar1);
    }
    *(undefined4 *)((int)this + 0xe0) = 1;
    *(int *)((int)this + 0xf0) = *(int *)((int)this + 0xf0) + -1;
    FUN_00401340(*(int *)(*(int *)((int)this + 0x134) + 0x1c8));
    if (iVar7 <= *(int *)((int)this + 0xf0)) {
      return iVar7;
    }
  }
  return -1;
}

