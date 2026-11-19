// rea decompile_all
// name: FUN_004784e0
// address: 0x4784e0
// body: available
// range: 0x4784e0-0x4787e1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_004784e0(int param_1)

{
  int iVar1;
  void *this;
  void *this_00;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  float10 fVar6;
  longlong lVar7;
  uint uVar8;
  float local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  void *local_68;
  int local_64;
  int local_60 [8];
  int local_40 [16];
  
  iVar4 = 0;
  local_40[0] = 4;
  local_40[1] = 7;
  local_40[2] = 9;
  local_40[3] = 5;
  local_40[4] = 10;
  local_40[5] = 3;
  local_40[6] = 6;
  local_40[7] = 8;
  local_7c = 0.0;
  local_78 = 0;
  iVar1 = FUN_004017f0((void *)((int)DAT_0057c670 + 4),*(int *)(param_1 + 0x34),(int *)0x0);
  this = (void *)FUN_00488be0(DAT_0057c670,*(int *)(param_1 + 0x30));
  local_68 = this;
  FUN_00489070(iVar1,0);
  lVar7 = __ftol();
  local_60[0] = (int)lVar7;
  FUN_00489070(iVar1,1);
  lVar7 = __ftol();
  local_60[1] = (int)lVar7;
  FUN_00489070(iVar1,2);
  lVar7 = __ftol();
  local_60[2] = (int)lVar7;
  FUN_00489070(iVar1,3);
  lVar7 = __ftol();
  local_60[3] = (int)lVar7;
  FUN_00489070(iVar1,4);
  lVar7 = __ftol();
  local_60[4] = (int)lVar7;
  FUN_00489070(iVar1,5);
  lVar7 = __ftol();
  local_60[5] = (int)lVar7;
  FUN_00489070(iVar1,6);
  lVar7 = __ftol();
  local_60[6] = (int)lVar7;
  FUN_00489070(iVar1,7);
  lVar7 = __ftol();
  local_60[7] = (int)lVar7;
  *(undefined4 *)(param_1 + 0x1714) = 1;
  piVar5 = local_40 + 8;
  for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar5 = 0;
    piVar5 = piVar5 + 1;
  }
  local_70 = 0;
  iVar1 = FUN_004ddde0((int)this);
  if (-1 < iVar1) {
    do {
      if (iVar4 == 0) {
        this_00 = *(void **)(param_1 + 0x14dc);
      }
      else {
        this_00 = (void *)FUN_004dde30(this,iVar4 + -1);
      }
      if (this_00 != (void *)0x0) {
        fVar6 = FUN_00513bf0((int)this_00,param_1,-999);
        local_78 = local_78 + 1;
        uVar3 = 0;
        local_7c = (float)(fVar6 + (float10)local_7c);
        piVar5 = local_40 + 8;
        do {
          fVar6 = FUN_00513bf0((int)this_00,param_1,-999);
          local_6c = FUN_00513b00(this_00,param_1,uVar3,(float)fVar6);
          uVar8 = uVar3;
          fVar6 = FUN_00513bf0((int)this_00,param_1,-999);
          local_64 = FUN_005139e0(this_00,param_1,(float)fVar6,uVar8);
          uVar3 = uVar3 + 1;
          *piVar5 = *piVar5 + local_6c;
          piVar5 = piVar5 + 1;
        } while ((int)uVar3 < 8);
        this = local_68;
        iVar4 = local_70;
      }
      iVar4 = iVar4 + 1;
      local_70 = iVar4;
      iVar1 = FUN_004ddde0((int)this);
    } while (iVar4 <= iVar1);
  }
  piVar5 = local_40 + 8;
  iVar4 = 8;
  do {
    if (local_78 < 1) {
      *piVar5 = 0;
    }
    else {
      *piVar5 = *piVar5 / local_78;
      FUN_00477100(piVar5);
    }
    piVar5 = piVar5 + 1;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  if (local_78 < 1) {
    local_7c = 200.0;
  }
  else {
    local_7c = local_7c / (float)local_78;
  }
  piVar5 = (int *)(param_1 + 0x177c);
  iVar4 = 0;
  do {
    if (local_7c <= (float)*(int *)((int)local_60 + iVar4)) {
      iVar1 = 100;
    }
    else {
      lVar7 = __ftol();
      iVar1 = 100 - (int)lVar7;
    }
    iVar2 = *(int *)((int)local_40 + iVar4);
    piVar5[8] = iVar1;
    if (local_78 < iVar2) {
      iVar2 = iVar2 - local_78;
      iVar2 = iVar2 * iVar2;
      local_74 = 100 - iVar2 * iVar2;
      FUN_00477100(&local_74);
    }
    else {
      local_74 = 100;
    }
    iVar2 = *(int *)((int)local_40 + iVar4 + 0x20) + local_74 >> 1;
    if (iVar1 < iVar2) {
      iVar2 = iVar1;
    }
    *piVar5 = iVar2;
    FUN_00477100(piVar5);
    iVar4 = iVar4 + 4;
    piVar5 = piVar5 + 1;
  } while (iVar4 < 0x20);
  return;
}

