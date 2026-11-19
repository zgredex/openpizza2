// rea decompile_all
// name: FUN_0050c0f0
// address: 0x50c0f0
// body: available
// range: 0x50c0f0-0x50c2d2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_0050c0f0(void *this,undefined4 param_1,int param_2)

{
  int *piVar1;
  void *this_00;
  void *this_01;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar1 = *(int **)((int)this + 200);
  uVar4 = 0;
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  FUN_00534370((void *)piVar1[0x16],*piVar1,&local_c,&local_4);
  this_00 = (void *)FUN_004017f0((void *)((int)DAT_0057c670 + 0x3c),param_2,(int *)0x0);
  if (this_00 == (void *)0x0) {
    return 1;
  }
  if (*(int *)((int)this_00 + 0x74) == 0) {
    return 1;
  }
  if (((*(int *)((int)this + 0x30) == 0x17) || (*(int *)((int)this + 0x30) == 0x1d)) &&
     (*(int *)((int)this_00 + 0xa4) == -1)) {
    return 1;
  }
  if (*(int *)((int)this_00 + 0x38) == 0x38) {
    return 1;
  }
  piVar1 = *(int **)((int)this_00 + 200);
  if (piVar1 == (int *)0x0) {
    iVar2 = -1;
    this_01 = (void *)0x0;
  }
  else {
    iVar2 = *piVar1;
    this_01 = (void *)piVar1[0x16];
  }
  FUN_00534370(this_01,iVar2,&local_10,&local_8);
  if (((local_10 - local_c) * (local_10 - local_c) + (local_8 - local_4) * (local_8 - local_4) * 4 <
       0xe10) && (*(int *)((int)this_00 + 0xa4) != -1)) {
    if ((*(int *)((int)this_00 + 0x110) != -1) &&
       (iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)this_00 + 0x110)),
       *(int *)((int)this_00 + 0x30) == 0x1f)) {
      if (*(int *)((int)this_00 + 0xa4) == 0x11) {
        *(int *)(iVar2 + 0x90) = *(int *)(iVar2 + 0x90) + 1;
      }
      if (*(int *)((int)this + 0x30) == 0xd) {
        *(int *)(iVar2 + 0x84) = *(int *)(iVar2 + 0x84) + 1;
      }
    }
    if (*(int *)((int)this + 0x30) == 0xd) {
      iVar2 = 0x38;
    }
    else {
      if ((*(int *)((int)this_00 + 0x30) == 0x1f) &&
         (iVar2 = FUN_00488be0(DAT_0057c670,*(int *)((int)this + 0x110)), iVar2 != 0)) {
        iVar2 = FUN_004ddcc0(iVar2);
        *(int *)(iVar2 + 0x38) = *(int *)(iVar2 + 0x38) + 1;
      }
      iVar2 = 0x2a;
    }
    FUN_0050e890(this_00,iVar2);
    iVar2 = *(int *)((int)this_00 + 200);
    uVar4 = 1;
    if (iVar2 == 0) {
      uVar3 = 0xffffffff;
    }
    else {
      uVar3 = *(uint *)(iVar2 + 0xc);
    }
    uVar3 = uVar3 & 0x80000007;
    if ((int)uVar3 < 0) {
      uVar3 = (uVar3 - 1 | 0xfffffff8) + 1;
    }
    *(uint *)((int)this_00 + 0x88) = uVar3;
    if (*(short *)(iVar2 + 0x28) == -1) {
      FUN_005090e0((int)this_00);
      FUN_0050e850(this_00,0xffffffff);
      return 1;
    }
    FUN_00507a80((int)this_00);
    FUN_0050e850(this_00,0xffffffff);
  }
  return uVar4;
}

