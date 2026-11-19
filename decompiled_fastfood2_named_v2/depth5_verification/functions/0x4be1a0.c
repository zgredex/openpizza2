// rea decompile_all
// name: FUN_004be1a0
// address: 0x4be1a0
// body: available
// range: 0x4be1a0-0x4be489 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004be1a0(void *param_1)

{
  void *this;
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  float10 fVar7;
  longlong lVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float local_4;
  
  local_4 = 0.0;
  this = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),
                              (int *)0x0);
  iVar1 = FUN_00488be0(DAT_0057c670,*(int *)(DAT_0057d700 + 0x24));
  iVar6 = 0;
  do {
    iVar2 = FUN_004da630(this,iVar6);
    fVar7 = FUN_004e2410(iVar1,this,iVar2);
    if ((float10)local_4 < fVar7) {
      local_4 = (float)fVar7;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  iVar6 = FUN_005144f0(DAT_0057d700);
  FUN_0052fd70(param_1,0x443,iVar6,0);
  iVar6 = FUN_00513fd0(DAT_0057d700);
  if (iVar6 == 0) {
    pvVar3 = (void *)0x1e;
  }
  else if (iVar6 == 1) {
    pvVar3 = (void *)0x3c;
  }
  else if (iVar6 == 2) {
    pvVar3 = (void *)0x5f;
  }
  else {
    pvVar3 = param_1;
  }
  FUN_0052fd70(param_1,0x444,pvVar3,0);
  iVar6 = FUN_00514240(DAT_0057d700);
  FUN_0052f080(param_1,0x50d,&DAT_005686f4,iVar6);
  piVar4 = (int *)FUN_004da630(this,*(int *)(DAT_0057d700 + 0x30));
  FUN_004e2410(iVar1,this,(int)piVar4);
  if (piVar4 == (int *)0x0) {
    FUN_0052f9b0(param_1,0x50e,DAT_00581a2c);
    FUN_0052fd70(param_1,0x441,0,0);
    uVar9 = 0;
    uVar10 = 0;
  }
  else {
    FUN_0052f9b0(param_1,0x50e,piVar4 + 0x11);
    FUN_0052fd70(param_1,0x441,*piVar4 / 10,0);
    uVar9 = 0;
    lVar8 = __ftol();
    uVar10 = (undefined4)lVar8;
  }
  FUN_0052fd70(param_1,0x442,uVar10,uVar9);
  iVar1 = *(int *)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  iVar6 = FUN_004e2280(iVar1);
  uVar5 = (uint)(5 < iVar6);
  FUN_005316f0(param_1,0x1f5d,uVar5);
  FUN_005316f0(param_1,0x1f5e,uVar5);
  FUN_005316f0(param_1,0x1f4c,uVar5);
  FUN_005316f0(param_1,0x1f4b,uVar5);
  FUN_005316f0(param_1,0x1f44,uVar5);
  FUN_005316f0(param_1,0x1f54,uVar5);
  FUN_005316f0(param_1,0x1f58,uVar5);
  FUN_005316f0(param_1,0x1f59,uVar5);
  FUN_005316f0(param_1,0x1f5b,uVar5);
  FUN_005316f0(param_1,0x1f55,uVar5);
  FUN_005316f0(param_1,0x1f5f,uVar5);
  if (5 < iVar6) {
    iVar1 = FUN_004d2ae0(*(void **)(iVar1 + 0x1d8),0x1f);
    if (iVar1 == 0) {
      uVar10 = 0xff;
    }
    else {
      uVar10 = 0;
    }
    FUN_0052f910(param_1,0x1f4b,uVar10);
    FUN_0052f080(param_1,0x1f4b,&DAT_005686f4,iVar1);
    iVar1 = *(int *)((int)DAT_0057c670 + 0x218);
    iVar6 = FUN_00482820((int)DAT_0057c670);
    iVar6 = FUN_0048a090(DAT_0057c670,0x1d,0x1f,iVar1,iVar6);
    FUN_0052f080(param_1,0x1f55,&DAT_005686f4,iVar6);
    iVar6 = FUN_00482820((int)DAT_0057c670);
    iVar1 = FUN_0048a130(DAT_0057c670,0x1d,0x1f,iVar1,iVar6);
    FUN_0052f080(param_1,0x1f5b,&DAT_005686f4,iVar1);
  }
  return;
}

