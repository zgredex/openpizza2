// rea decompile_all
// name: FUN_004ecb30
// address: 0x4ecb30
// body: available
// range: 0x4ecb30-0x4ecd6d inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004ecb30(void *param_1,int *param_2)

{
  void *this;
  int *piVar1;
  char cVar2;
  int iVar3;
  void **ppvVar4;
  longlong lVar5;
  undefined4 uVar6;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10 [2];
  undefined4 local_8 [2];
  
  piVar1 = param_2;
  this = param_1;
  iVar3 = *param_2;
  if ((iVar3 < 0) || (*(int *)(param_2[0x16] + 0x48) <= iVar3)) {
    cVar2 = '\0';
  }
  else {
    cVar2 = *(char *)(*(int *)(param_2[0x16] + 0x4c) + 0x3e + iVar3 * 0x48);
  }
  param_2 = (int *)CONCAT31(param_2._1_3_,cVar2 == '\x01');
  FUN_0054cc2b(param_1,&param_2,1);
  Record_GetTwoFloats48((void *)piVar1[0x16],*piVar1,&param_1,&local_1c);
  FUN_0054cc2b(this,&param_1,4);
  FUN_0054cc2b(this,&local_1c,4);
  FUN_00534830((void *)piVar1[0x16],*piVar1,local_10,local_8);
  lVar5 = __ftol();
  param_1 = (void *)lVar5;
  lVar5 = __ftol();
  local_1c = (undefined4)lVar5;
  FUN_0054cc2b(this,&param_1,4);
  FUN_0054cc2b(this,&local_1c,4);
  FUN_0054cc2b(this,piVar1 + 2,2);
  FUN_0054cc2b(this,(int)piVar1 + 10,2);
  FUN_0054cc2b(this,piVar1 + 3,4);
  FUN_0054cc2b(this,piVar1 + 4,1);
  local_14 = (int)(short)piVar1[10];
  FUN_0054cc2b(this,&local_14,4);
  FUN_0054cc2b(this,piVar1 + 0xb,4);
  FUN_0054cc2b(this,piVar1 + 0xc,8);
  FUN_0054cc2b(this,piVar1 + 0xe,8);
  FUN_0054cc2b(this,piVar1 + 0x10,4);
  FUN_0054cc2b(this,piVar1 + 0x11,8);
  FUN_0054cc2b(this,piVar1 + 0x15,4);
  FUN_0054cc2b(this,piVar1 + 0x13,8);
  local_18 = piVar1[6];
  FUN_0054cc2b(this,&local_18,4);
  param_1 = (void *)0x0;
  if (0 < local_18) {
    do {
      uVar6 = 2;
      iVar3 = FUN_0054b440(piVar1 + 5,(int)param_1);
      FUN_0054cc2b(this,iVar3 + 2,uVar6);
      param_1 = (void *)((int)param_1 + 1);
    } while ((int)param_1 < local_18);
  }
  if (piVar1[8] == 0) {
    ppvVar4 = &param_1;
    uVar6 = 4;
    param_1 = (void *)0x0;
  }
  else {
    param_1 = (void *)0x1;
    FUN_0054cc2b(this,&param_1,4);
    uVar6 = 2;
    ppvVar4 = (void **)(piVar1[8] + 2);
  }
  FUN_0054cc2b(this,ppvVar4,uVar6);
  if (piVar1[9] == 0) {
    param_1 = (void *)0x0;
    FUN_0054cc2b(this,&param_1,4);
    return;
  }
  param_1 = (void *)0x1;
  FUN_0054cc2b(this,&param_1,4);
  FUN_0054cc2b(this,piVar1[9] + 2,2);
  return;
}

