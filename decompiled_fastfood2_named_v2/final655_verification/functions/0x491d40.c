// rea decompile_all
// name: BranchStats_UpdateRatingPage
// address: 0x491d40
// body: available
// range: 0x491d40-0x491e98 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl BranchStats_UpdateRatingPage(void *param_1)

{
  void *this;
  void *pvVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  longlong lVar5;
  
                    /* Refreshes the branch statistics and rating page. */
  this = *(void **)(DAT_0057c670 + 0x9c);
  iVar3 = 0;
  piVar4 = &DAT_00568628;
  do {
    FUN_0052ff50(param_1,iVar3 + 0x42c,(uint)(*piVar4 == 1));
    piVar4 = piVar4 + 1;
    iVar3 = iVar3 + 1;
  } while ((int)piVar4 < 0x568638);
  if (*(char *)((int)this + 0x16f4) == '\0') {
    UI_ShowChildByID(param_1,0x44d);
    UI_ShowChildByID(param_1,0x4eb);
    FUN_0052f080(param_1,0x4eb,&DAT_005683a4,*(undefined4 *)((int)this + 0x14b0));
    FUN_0052f830(param_1,0x44f,DAT_00581278);
  }
  else {
    FUN_00531740(param_1,0x44d);
    FUN_0052f830(param_1,0x44f,DAT_00582624);
    iVar3 = *(int *)((int)this + 0x38);
    iVar2 = *(int *)((int)this + 0x16f0);
    pvVar1 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),
                                  (int *)0x0);
    lVar5 = FUN_004d6260(pvVar1,iVar2,iVar3);
    FUN_0052f080(param_1,0x4eb,&DAT_005683a4,(int)lVar5);
  }
  FUN_0052f830(param_1,0x4ec,DAT_00582198);
  FUN_004919f0(param_1,0x4ed,DAT_0057c6b0,this,7.945979e-39);
  pvVar1 = this;
  iVar3 = FUN_00482820(DAT_0057c670);
  FUN_00491c80(param_1,0x429,iVar3,(int)pvVar1);
  iVar3 = 0;
  do {
    iVar2 = FUN_0047a3b0(this,iVar3,1);
    Rating_UpdateBarByKey(param_1,0x4e2,iVar3,iVar2,DAT_00582998);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  return;
}

