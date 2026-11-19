// rea decompile_all
// name: FUN_005016c0
// address: 0x5016c0
// body: available
// range: 0x5016c0-0x5018fe inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_005016c0(void *this,uint param_1)

{
  short sVar1;
  short sVar2;
  uint uVar3;
  uint uVar4;
  char cVar5;
  char *pcVar6;
  int iVar7;
  void *pvVar8;
  undefined3 extraout_var;
  int iVar9;
  int iVar10;
  int unaff_ESI;
  int unaff_EDI;
  int *piVar11;
  undefined8 uVar12;
  
  uVar4 = param_1;
  iVar10 = 0;
  iVar9 = 0;
  if (DAT_00572490 == 1) {
    DAT_00572490 = 0;
    piVar11 = &DAT_00580a64;
    do {
      pcVar6 = FUN_00501580(iVar10);
      iVar7 = FUN_00403750(pcVar6);
      *piVar11 = iVar7;
      piVar11 = piVar11 + 1;
      iVar10 = iVar10 + 1;
    } while ((int)piVar11 < 0x580ac8);
  }
  iVar10 = *(int *)((int)this + param_1 * 0x168 + 0x74);
  uVar3 = *(uint *)((int)this + param_1 * 0x168 + 0x80);
  if (iVar10 < 0) {
    pvVar8 = (void *)0x0;
  }
  else {
    pvVar8 = (void *)FUN_00489820(DAT_0057c670,*(int *)((int)this + param_1 * 0x168 + 0x40),iVar10);
    if (pvVar8 == (void *)0x0) {
      param_1 = 2;
      goto LAB_00501766;
    }
  }
  if (uVar3 == 0) {
    return;
  }
  param_1 = uVar3;
  if (uVar3 == 0x18) {
    return;
  }
LAB_00501766:
  FUN_00403790((&DAT_00580a64)[param_1]);
  switch(param_1) {
  case 1:
    cVar5 = FUN_004ffa60(this,uVar4);
    iVar9 = CONCAT31(extraout_var,cVar5);
    break;
  case 5:
    iVar9 = FUN_004f7ed0(this,uVar4);
    break;
  case 7:
    if (pvVar8 != (void *)0x0) {
      iVar9 = FUN_004f7c30(this,pvVar8);
    }
    break;
  case 8:
    iVar9 = FUN_004fb660(uVar4,(int)pvVar8,(void *)0xffffffff,-1,-1,(undefined4 *)0xffffffff,
                         unaff_EDI,unaff_ESI);
    break;
  case 9:
    iVar9 = FUN_004febb0(this,uVar4,pvVar8);
    break;
  case 10:
    iVar9 = FUN_004fc0f0(this,uVar4,pvVar8);
    break;
  case 0xb:
    iVar9 = FUN_004fc630(this,uVar4);
    break;
  case 0xc:
    iVar9 = FUN_004fd190(this,uVar4);
    break;
  case 0xd:
    iVar9 = FUN_004fe040(this,uVar4);
    break;
  case 0x10:
    iVar9 = FUN_004fd610(this,uVar4);
    break;
  case 0x11:
    iVar9 = FUN_004ff8b0(this,uVar4);
    break;
  case 0x13:
    iVar9 = FUN_004fe570(this,uVar4);
    break;
  case 0x14:
    iVar9 = FUN_004ffad0(this,uVar4);
    break;
  case 0x15:
    FUN_004f8bf0(this,uVar4);
  case 2:
    iVar9 = 1;
    break;
  case 0x16:
    uVar12 = FUN_004fce20(this,uVar4);
    iVar9 = (int)uVar12;
    break;
  case 0x17:
    iVar9 = FUN_004fecc0(this,uVar4);
  }
  FUN_004037d0((&DAT_00580a64)[param_1]);
  switch(iVar9) {
  case 0:
    FUN_00500fd0(this,uVar4,0);
    FUN_00500f40(this,uVar4,1,-1,-1);
    return;
  case 1:
  case 5:
  case 7:
    FUN_00501040(this,uVar4,param_1,iVar10);
    return;
  case 2:
    FUN_00501040(this,uVar4,param_1,iVar10);
    return;
  case 3:
    sVar2 = *(short *)((int)this + uVar4 * 0x168 + 0x7e);
    sVar1 = sVar2 + -1;
    *(short *)((int)this + uVar4 * 0x168 + 0x7e) = sVar1;
    if ((sVar2 != 0) && (sVar1 < 1)) {
      FUN_00501040(this,uVar4,param_1,iVar10);
    }
  }
  return;
}

