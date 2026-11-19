// rea decompile_all
// name: JobMarketPanel_Update
// address: 0x4b81e0
// body: available
// range: 0x4b81e0-0x4b8392 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl JobMarketPanel_Update(void *param_1)

{
  void *pvVar1;
  int iVar2;
  int iVar3;
  uint extraout_EDX;
  longlong lVar4;
  undefined4 uVar5;
  int iVar6;
  undefined1 local_20 [32];
  
                    /* Fills the job-market applicant counts and rating rows. */
  pvVar1 = *(void **)((int)DAT_0057c670 + 0x9c);
  iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)pvVar1 + 0x30));
  FUN_0052f9b0(param_1,0x51b,iVar2 + 8);
  FUN_0052fd00(param_1,0x529,0,100,1);
  Personnel_SetEmployeePhotoByKey(param_1,0x1f42,iVar2);
  iVar2 = FUN_004d2ae0(*(void **)((int)pvVar1 + 0x16f0),0x1a);
  FUN_0054dd83(local_20,&DAT_005686f4,iVar2);
  FUN_0052f9b0(param_1,0x524,local_20);
  iVar2 = FUN_004d2ae0(*(void **)((int)pvVar1 + 0x16f0),0x1b);
  FUN_0054dd83(local_20,&DAT_005686f4,iVar2);
  FUN_0052f9b0(param_1,0x525,local_20);
  iVar2 = FUN_004d2ae0(*(void **)((int)pvVar1 + 0x16f0),0x1c);
  FUN_0054dd83(local_20,&DAT_005686f4,iVar2);
  FUN_0052f9b0(param_1,0x526,local_20);
  if (*(int *)((int)pvVar1 + 0x14d8) < 0) {
    uVar5 = DAT_00582afc;
  }
  else {
    uVar5 = (&DAT_0058374c)[*(int *)((int)pvVar1 + 0x14d8)];
  }
  FUN_0052f9b0(param_1,0x528,uVar5);
  iVar2 = FUN_00478140(pvVar1);
  if (iVar2 < 0x14) {
    FUN_0052fd70(param_1,0x529,(iVar2 * 5 + -0x32) * 2,0);
    iVar2 = 0;
  }
  else {
    FUN_0052fd70(param_1,0x529,0,0);
    iVar2 = (iVar2 * 5 + -100) * 2;
  }
  FUN_0052fd70(param_1,0x52a,iVar2,0);
  iVar2 = FUN_004781b0((int)pvVar1);
  FUN_0052fd70(param_1,0x52b,iVar2,0);
  lVar4 = thunk_FUN_00479db0((int)pvVar1,extraout_EDX);
  FUN_0052fd70(param_1,0x52c,(int)lVar4,0);
  iVar2 = 0;
  do {
    iVar6 = DAT_00582320;
    iVar3 = FUN_00478be0(pvVar1,DAT_00582320,iVar2);
    Rating_UpdateBarByKey(param_1,0x5be,iVar2,iVar3,iVar6);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 8);
  return;
}

