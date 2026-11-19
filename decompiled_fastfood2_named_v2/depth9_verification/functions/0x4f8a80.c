// rea decompile_all
// name: FUN_004f8a80
// address: 0x4f8a80
// body: available
// range: 0x4f8a80-0x4f8be7 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_004f8a80(void *this,int param_1,int param_2,int param_3,void *param_4)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  void *pvVar4;
  int iVar5;
  int unaff_ESI;
  int unaff_EDI;
  int local_8;
  int local_4;
  
  iVar2 = param_1;
  iVar1 = *(int *)((int)this + param_1 * 0x168 + 0x70);
  iVar5 = param_1 * 0x168;
  pvVar3 = (void *)FUN_004017f0((void *)(DAT_0057c670 + 4),*(int *)(DAT_0057c670 + 0x2f4),(int *)0x0
                               );
  if (pvVar3 == (void *)0x0) {
    return 0;
  }
  pvVar4 = (void *)AI_FindBestBranchSite(this,iVar2,pvVar3,param_3,&local_4);
  if (pvVar4 == (void *)0x0) {
    return 0;
  }
  if (param_2 == -1) {
    param_2 = 0;
  }
  FUN_004d5dd0(pvVar3,(int)pvVar4,1,&param_1,&local_8,*(int *)((int)this + iVar5 + 0x40),(int *)0x0)
  ;
  iVar5 = FUN_004f7420(this,*(int *)((int)pvVar3 + 0xc1c),pvVar4,iVar2,param_2,1);
  pvVar3 = (void *)FUN_004017f0((void *)(iVar1 + 0x148),iVar5,(int *)0x0);
  if (param_3 == 0) {
    *(undefined1 *)((int)pvVar3 + 0x16f4) = 0;
    *(int *)((int)pvVar3 + 0x14b0) = param_1;
    DebugConsole_Printf(DAT_0057c1e0,0xff,(byte *)s_Start_Filiale___s__gemietet__00571f04,
                        (int)pvVar3 + 4);
  }
  else {
    *(undefined1 *)((int)pvVar3 + 0x16f4) = 1;
    *(int *)((int)pvVar3 + 0x14b0) = param_1 >> 2;
    *(int *)((int)pvVar4 + 0x3c) = local_8;
    DebugConsole_Printf(DAT_0057c1e0,0xff,(byte *)s_Start_Filiale___s__gekauft__00571f24,
                        (int)pvVar3 + 4);
  }
  FUN_004fb660(iVar2,(int)pvVar3,param_4,-1,-1,(undefined4 *)0xffffffff,unaff_EDI,unaff_ESI);
  FUN_004f7c30(this,pvVar3);
  return 1;
}

