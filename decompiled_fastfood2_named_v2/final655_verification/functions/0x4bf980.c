// rea decompile_all
// name: CriminalsPage_FillRecruitOptions
// address: 0x4bf980
// body: available
// range: 0x4bf980-0x4bfd94 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl CriminalsPage_FillRecruitOptions(void *param_1)

{
  int iVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  
                    /* Fills the criminal recruitment costs and counts. */
  DAT_0057d704 = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  iVar1 = FUN_004ddcc0((int)DAT_0057d704);
  iVar4 = (10 - *(int *)(iVar1 + 0x58)) - *(int *)(iVar1 + 0x40);
  iVar1 = *(int *)((int)DAT_0057d704 + 0x48);
  iVar2 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                       (int *)0x0);
  iVar1 = *(int *)(iVar2 + 0xc20 + iVar1 * 4);
  iVar5 = (iVar4 * 50000) / 100;
  iVar2 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
  if (*(int *)(iVar2 + 0x8c) == 0) {
    if (*(int *)(iVar2 + 0x170) != 0) {
      iVar5 = (iVar5 * 0xf) / 10;
    }
  }
  else {
    iVar5 = 0;
  }
  FUN_0052f080(param_1,0x1f85,&DAT_005683a4,iVar5);
  iVar2 = FUN_00486b80(DAT_0057c670,0x1f,'\x01');
  FUN_0052f910(param_1,0x1f98,0);
  FUN_0052f080(param_1,0x1f98,&DAT_005686f4,iVar2);
  UI_SetChildVisibleByID(param_1,0x1f86,(uint)(0 < iVar2));
  if (iVar1 < 4) {
    FUN_00531740(param_1,0x1fa0);
    FUN_00531740(param_1,0x1fa3);
    FUN_00531740(param_1,0x1fa2);
    FUN_00531740(param_1,0x1fa1);
    FUN_00531740(param_1,0x1fa5);
    FUN_00531740(param_1,0x1fa4);
  }
  else {
    iVar5 = (iVar4 * 100000) / 100;
    iVar2 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(iVar2 + 0x90) == 0) {
      if (*(int *)(iVar2 + 0x174) != 0) {
        iVar5 = (iVar5 * 0xf) / 10;
      }
    }
    else {
      iVar5 = 0;
    }
    FUN_0052f080(param_1,0x1fa2,&DAT_005683a4,iVar5);
    iVar2 = FUN_00486b80(DAT_0057c670,0x1e,'\x01');
    UI_SetChildVisibleByID(param_1,0x1fa3,(uint)(0 < iVar2));
    FUN_0052f910(param_1,0x1fa5,0);
    FUN_0052f080(param_1,0x1fa5,&DAT_005686f4,iVar2);
  }
  if (iVar1 < 5) {
    FUN_00531740(param_1,0x1f9a);
    FUN_00531740(param_1,0x1f9d);
    FUN_00531740(param_1,0x1f9b);
    FUN_00531740(param_1,0x1f9c);
    FUN_00531740(param_1,0x1f9f);
    FUN_00531740(param_1,0x1f9e);
  }
  else {
    iVar2 = (iVar4 * 200000) / 100;
    iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(iVar1 + 0x94) == 0) {
      if (*(int *)(iVar1 + 0x178) != 0) {
        iVar2 = (iVar2 * 0xf) / 10;
      }
    }
    else {
      iVar2 = 0;
    }
    FUN_0052f080(param_1,0x1f9c,&DAT_005683a4,iVar2);
    iVar1 = FUN_00486b80(DAT_0057c670,0x1d,'\x01');
    UI_SetChildVisibleByID(param_1,0x1f9d,(uint)(0 < iVar1));
    FUN_0052f910(param_1,0x1f9f,0);
    FUN_0052f080(param_1,0x1f9f,&DAT_005686f4,iVar1);
  }
  puVar3 = FUN_004e25b0(DAT_0057d704,0x1e,0);
  FUN_0052f080(param_1,0x1f77,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(DAT_0057d704,0x1e,1);
  FUN_0052f080(param_1,0x1f76,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(DAT_0057d704,0x1e,2);
  FUN_0052f080(param_1,0x1f78,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(DAT_0057d704,0x1d,0);
  FUN_0052f080(param_1,0x1f7d,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(DAT_0057d704,0x1d,1);
  FUN_0052f080(param_1,0x1f7c,&DAT_005686f4,puVar3);
  puVar3 = FUN_004e25b0(DAT_0057d704,0x1d,2);
  FUN_0052f080(param_1,0x1f7e,&DAT_005686f4,puVar3);
  FUN_004bf730(param_1);
  return;
}

