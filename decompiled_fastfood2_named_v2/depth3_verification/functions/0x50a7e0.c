// rea decompile_all
// name: FUN_0050a7e0
// address: 0x50a7e0
// body: available
// range: 0x50a7e0-0x50a91d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0050a7e0(void *param_1)

{
  int iVar1;
  void *this;
  int iVar2;
  void *pvVar3;
  undefined4 unaff_EDI;
  
  if (*(int *)((int)param_1 + 0x30) == 0xc) {
    FUN_0050e4c0(param_1,0);
    pvVar3 = (void *)FUN_00489850(DAT_0057c670,*(int *)(*(int *)((int)param_1 + 0xfc) + 8),
                                  *(int *)(*(int *)((int)param_1 + 0xfc) + 0x2c));
    if (pvVar3 != (void *)0x0) {
      FUN_00514330(pvVar3);
    }
    FUN_00507e20(param_1,10,*(int *)((int)param_1 + 0xcc));
  }
  else if (*(int *)((int)param_1 + 0x30) == 0x1f) {
    iVar1 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x110));
    pvVar3 = *(void **)((int)param_1 + 0xfc);
    this = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                                (int *)0x0);
    FUN_004d5160(this,3,0x2e,pvVar3);
    FUN_0048c220(*(int *)((int)param_1 + 0xfc),1,param_1);
    *(undefined4 *)(*(int *)((int)param_1 + 0xfc) + 0x94) = 1;
    *(undefined4 *)(*(int *)((int)param_1 + 0xfc) + 0xc) = 0x12378d6;
    FUN_0050a080(param_1,*(int *)(iVar1 + 0x1d8));
    FUN_0050e4c0(param_1,0);
    iVar1 = *(int *)((int)pvVar3 + 8);
    iVar2 = FUN_00482820((int)DAT_0057c670);
    if (iVar1 == iVar2) {
      iVar1 = Game_HasKeyedRecordEntry(DAT_0057c670,7,(int)pvVar3);
      if (iVar1 == 0) {
        iVar1 = FUN_0048bf90((int)DAT_0057c670,5,4,-1,-1,(int)pvVar3,DAT_005828a8,DAT_00582188,
                             unaff_EDI);
        FUN_0048c040(DAT_0057c670,iVar1,7);
        return;
      }
    }
  }
  return;
}

