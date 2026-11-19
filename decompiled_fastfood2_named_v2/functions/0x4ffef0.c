// rea decompile_all
// name: FUN_004ffef0
// address: 0x4ffef0
// body: available
// range: 0x4ffef0-0x500028 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004ffef0(void *this,void *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar2 = *(int *)((int)param_1 + 0x30);
  iVar1 = FUN_00482820((int)DAT_0057c670);
  if (iVar2 == iVar1) {
    FUN_0048bf90((int)DAT_0057c670,-1,4,4,2,*(int *)((int)param_1 + 0x16f0),DAT_005828a8,
                 DAT_0058190c,param_2 + 1);
  }
  iVar2 = FUN_00488be0(DAT_0057c670,iVar2);
  if (iVar2 != 0) {
    iVar2 = *(int *)(iVar2 + 0x4c);
    FUN_004fcc30(this,iVar2,0x19);
    iVar1 = FUN_0047aac0(param_1,0xffffffff);
    iVar5 = 0;
    if (0 < iVar1) {
      do {
        piVar3 = (int *)IDMap_Lookup((void *)((int)param_1 + 0x1500),iVar5,(int *)0x0);
        piVar4 = (int *)FUN_004d3910(*piVar3);
        if (piVar4 == param_2) break;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar1);
      param_2 = piVar3;
    }
    if ((iVar5 != iVar1) && (param_2 != (int *)0x0)) {
      FUN_0047a9d0(param_1,param_2,0);
      iVar1 = IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                           (int *)0x0);
      *(int *)(iVar1 + 0x10b4) = *(int *)(iVar1 + 0x10b4) + 1;
      if (*(int *)((int)this + iVar2 * 0x168 + 0x114) != 0) {
        iVar2 = param_2[1];
        piVar3 = FUN_004f7dd0(param_1,(uint)*(byte *)(*param_2 + 0x824));
        if (piVar3 != (int *)0x0) {
          piVar3[1] = iVar2;
        }
      }
    }
  }
  return;
}

