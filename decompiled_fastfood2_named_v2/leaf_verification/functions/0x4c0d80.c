// rea decompile_all
// name: FUN_004c0d80
// address: 0x4c0d80
// body: available
// range: 0x4c0d80-0x4c0fe8 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c0d80(void *param_1)

{
  void *this;
  void *this_00;
  int iVar1;
  int *piVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  float10 fVar6;
  longlong lVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float local_c;
  
  this = param_1;
  iVar3 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  local_c = 0.0;
  this_00 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4)
                                 ,(int *)0x0);
  iVar5 = 0;
  do {
    iVar1 = Array_GetStride60(this_00,iVar5);
    fVar6 = FUN_004e2410(iVar3,this_00,iVar1);
    if ((float10)local_c < fVar6) {
      local_c = (float)fVar6;
    }
    iVar5 = iVar5 + 1;
  } while (iVar5 < 5);
  DAT_0057d714 = *(int *)(DAT_0057d718 + 0x30);
  piVar2 = (int *)Array_GetStride60(this_00,DAT_0057d714);
  FUN_004e2410(iVar3,this_00,(int)piVar2);
  if (piVar2 == (int *)0x0) {
    FUN_0052f9b0(param_1,0x1f41,DAT_00581a2c);
    FUN_0052fd70(param_1,0x54e,0,0);
    uVar9 = 0;
    uVar8 = 0;
  }
  else {
    FUN_0052f9b0(param_1,0x1f41,piVar2 + 0x11);
    FUN_0052fd70(param_1,0x54e,*piVar2 / 10,0);
    uVar9 = 0;
    lVar7 = __ftol();
    uVar8 = (undefined4)lVar7;
  }
  FUN_0052fd70(param_1,0x54f,uVar8,uVar9);
  iVar3 = Get_Field2C(DAT_0057d718);
  if (iVar3 == 0) {
    pvVar4 = (void *)0x21;
    param_1 = (void *)0x1e;
  }
  else if (iVar3 == 1) {
    pvVar4 = (void *)0x42;
    param_1 = (void *)0x3c;
  }
  else if (iVar3 == 2) {
    param_1 = (void *)0x5f;
    pvVar4 = (void *)0x64;
  }
  else {
    pvVar4 = param_1;
  }
  iVar3 = FUN_005144a0(DAT_0057d718);
  iVar5 = FUN_005144f0(DAT_0057d718);
  FUN_0052fd70(this,0x544,pvVar4,0);
  FUN_0052fd70(this,0x545,param_1,0);
  FUN_0052fd70(this,0x548,iVar3,0);
  FUN_0052fd70(this,0x549,iVar5,0);
  if (DAT_0057d718 != 0) {
    iVar5 = Get_Subobject4(DAT_0057d718);
    FUN_0052f830(this,0x53c,iVar5);
  }
  if (*(char *)(DAT_0057d718 + 0x3c) == '\0') {
    FUN_005316b0(this,0x53f);
    uVar8 = *(undefined4 *)(DAT_0057d718 + 0x40);
  }
  else {
    FUN_00531740(this,0x53f);
    iVar5 = *(int *)(DAT_0057d718 + 0x34);
    iVar1 = Get_Field2C(DAT_0057d718);
    lVar7 = FUN_004d6260(this_00,iVar5,iVar1);
    uVar8 = (undefined4)lVar7;
  }
  FUN_0052f080(this,0x540,&DAT_005683a4,uVar8);
  iVar5 = 0;
  do {
    if (piVar2 == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_0048c7b0(DAT_0057c670,iVar5,iVar3);
    }
    FUN_004a80e0(this,0x23af,iVar5,iVar1,DAT_00581048);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 8);
  return;
}

