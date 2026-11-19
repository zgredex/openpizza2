// rea decompile_all
// name: FUN_004c03c0
// address: 0x4c03c0
// body: available
// range: 0x4c03c0-0x4c072b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl FUN_004c03c0(void *param_1)

{
  int iVar1;
  int iVar2;
  void *this;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  longlong lVar8;
  undefined1 local_80 [128];
  
  DAT_0057d708 = *(int *)((int)DAT_0057c670 + 0x218);
  iVar7 = 0;
  if ((*(int *)(DAT_0057d708 + 8) == -1) || (*(int *)(DAT_0057d708 + 4) == 0x11)) {
    iVar2 = -1;
  }
  else {
    iVar7 = FUN_00488be0(DAT_0057c670,*(int *)(DAT_0057d708 + 8));
    iVar2 = FUN_004e2250(iVar7);
    iVar2 = iVar2 + 1;
  }
  switch(*(undefined4 *)(DAT_0057d708 + 0x30)) {
  case 0xf:
    iVar3 = *(int *)(DAT_0057d708 + 0x48);
    if ((-1 < iVar3) && (iVar3 < 4)) {
      iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
    }
    iVar3 = iVar3 + 0x858;
    uVar4 = DAT_005820a4;
    break;
  case 0x10:
    iVar3 = DAT_0057d708;
    this = (void *)FUN_00488be0(DAT_0057c670,*(int *)(DAT_0057d708 + 8));
    iVar3 = FUN_004e2330(this,iVar3);
    if (iVar3 == 0) {
      iVar3 = *(int *)(DAT_0057d708 + 0x48);
      if ((-1 < iVar3) && (iVar3 < 4)) {
        iVar3 = *(int *)(&DAT_00568188 + iVar3 * 4);
      }
      iVar3 = iVar3 + 0x834;
    }
    else {
      iVar1 = *(int *)(DAT_0057d708 + 0x48);
      if ((iVar1 < 0) || (3 < iVar1)) {
        iVar3 = FUN_00513fd0(iVar3);
        iVar3 = iVar1 + 0x838 + iVar3 * 4;
      }
      else {
        iVar1 = *(int *)(&DAT_00568188 + iVar1 * 4);
        iVar3 = FUN_00513fd0(iVar3);
        iVar3 = iVar1 + 0x838 + iVar3 * 4;
      }
    }
    uVar4 = DAT_00582158;
    break;
  case 0x11:
    iVar3 = *(int *)(DAT_0057d708 + 0x34);
    iVar2 = -1;
    uVar4 = DAT_00582134;
    break;
  default:
    iVar3 = *(int *)(DAT_0057d708 + 0x34);
    uVar4 = DAT_00582e4c;
    break;
  case 0x1c:
    iVar3 = *(int *)(DAT_0057d708 + 0x34);
    FUN_004e2280(iVar7);
    String_Format(local_80,(byte *)s__s__s_d_0056acc0,DAT_0058223c);
    goto LAB_004c053b;
  }
  String_Format(local_80,&DAT_005630d0,uVar4);
LAB_004c053b:
  FUN_0052f9b0(param_1,0x1f55,local_80);
  FUN_004bf120(param_1,iVar3,1,0x1f54,iVar2,DAT_0057d708);
  if (iVar7 == 0) {
    FUN_0052f9b0(param_1,0x41b,DAT_00580d40);
  }
  else {
    FUN_0052f080(param_1,0x41b,&DAT_005630d0,iVar7 + 8);
  }
  FUN_004c0390(param_1);
  uVar5 = (uint)*(byte *)(*(int *)((int)DAT_0057c670 + 0x94) + 8);
  iVar2 = (uint)*(byte *)(*(int *)((int)DAT_0057c670 + 0x94) + 7) + *(int *)(DAT_0057d708 + 0x38);
  if (0x18 < iVar2) {
    uVar6 = (iVar2 - 1U) / 0x18;
    do {
      uVar5 = uVar5 + 1;
      if (3 < (int)uVar5) {
        uVar5 = 0;
      }
      uVar6 = uVar6 - 1;
    } while (uVar6 != 0);
  }
  FUN_0052f080(param_1,0x41a,(byte *)s__d__d_00568ef8,uVar5 + 1);
  if (iVar7 == 0) {
    FUN_00531740(param_1,0x419);
    FUN_00531740(param_1,0x40f);
    goto LAB_004c0713;
  }
  if (*(int *)(DAT_0057d708 + 0x30) == 0xf) {
    iVar7 = *(int *)(DAT_0057d708 + 0x34) + -0x858 >> 2;
    if (iVar7 == 1) {
      IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    }
    else {
      if (iVar7 != 2) goto LAB_004c0619;
      IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    }
LAB_004c06e0:
    lVar8 = __ftol();
    uVar4 = (undefined4)lVar8;
  }
  else {
    if (*(int *)(DAT_0057d708 + 0x30) == 0x10) {
      iVar7 = *(int *)(DAT_0057d708 + 0x34) + -0x834 >> 2;
      if (iVar7 == 1) {
        IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0)
        ;
      }
      else {
        if (iVar7 != 2) goto LAB_004c0619;
        IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0)
        ;
      }
      goto LAB_004c06e0;
    }
LAB_004c0619:
    uVar4 = *(undefined4 *)(DAT_0057d708 + 0x3c);
  }
  FUN_0052f080(param_1,0x419,&DAT_005683a4,uVar4);
LAB_004c0713:
  FUN_004a53e0(param_1,0x1f42);
  return;
}

