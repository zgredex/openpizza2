// rea decompile_all
// name: Branch_HandleBuildCommand
// address: 0x47f470
// body: available
// range: 0x47f470-0x47f59f inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Branch_HandleBuildCommand(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int unaff_EDI;
  int iVar4;
  void *pvVar5;
  int iVar6;
  undefined4 *puVar7;
  
                    /* Executes a branch construction menu command. */
  uVar1 = *(undefined4 *)((int)param_1 + 0x2c);
  FUN_004810a0(param_1,0);
  switch(uVar1) {
  case 1:
    Branch_ClearInteriorObjects(param_1,0);
    break;
  case 2:
    CityMap_TryPlaceBuilding();
    break;
  case 3:
    iVar4 = *(int *)((int)DAT_0057c670 + 0x90);
    iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x30));
    FUN_004f7020(iVar4);
    Branch_ClearInteriorObjects(param_1,0);
    iVar3 = *(int *)(iVar2 + 0x4c);
    puVar7 = (undefined4 *)0xffffffff;
    iVar2 = -1;
    iVar6 = -1;
    pvVar5 = (void *)0xffffffff;
    goto LAB_0047f53f;
  case 4:
    iVar4 = *(int *)((int)DAT_0057c670 + 0x90);
    iVar3 = FUN_00488be0(DAT_0057c670,*(int *)((int)param_1 + 0x30));
    FUN_004f7020(iVar4);
    Branch_ClearInteriorObjects(param_1,0);
    puVar7 = *(undefined4 **)((int)param_1 + 0x1a30);
    iVar2 = *(int *)((int)param_1 + 0x1a38);
    iVar6 = *(int *)((int)param_1 + 0x1a34);
    pvVar5 = *(void **)((int)param_1 + 0x1a2c);
    iVar3 = *(int *)(iVar3 + 0x4c);
LAB_0047f53f:
    Customer_VisitBranch(iVar3,(int)param_1,pvVar5,iVar6,iVar2,puVar7,unaff_EDI,unaff_ESI);
    FUN_004f7080(iVar4);
    break;
  case 5:
    Branch_UpgradeSize(param_1);
  }
  FUN_004808a0(param_1,0);
  if (param_1 == *(void **)((int)DAT_0057c670 + 0x9c)) {
    if (*(void **)((int)DAT_0057c670 + 0x260) != (void *)0x0) {
      FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x260),-0x1860b,0x23,0);
    }
    if (*(void **)((int)DAT_0057c670 + 0x264) != (void *)0x0) {
      FUN_005301c0(*(void **)((int)DAT_0057c670 + 0x264),-0x18606,0x23,0);
    }
  }
  return;
}

