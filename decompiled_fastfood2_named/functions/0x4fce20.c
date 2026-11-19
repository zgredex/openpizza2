// rea decompile_all
// name: FUN_004fce20
// address: 0x4fce20
// body: available
// range: 0x4fce20-0x4fd09a inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined8 __thiscall FUN_004fce20(void *this,int param_1)

{
  int iVar1;
  int iVar2;
  void *this_00;
  int iVar3;
  void *pvVar4;
  int iVar5;
  void *pvVar6;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 extraout_EDX_02;
  undefined4 extraout_EDX_03;
  undefined4 extraout_EDX_04;
  undefined4 extraout_EDX_05;
  undefined4 uVar7;
  int iVar8;
  longlong lVar9;
  longlong lVar10;
  int local_1c;
  int local_4;
  
  iVar2 = param_1;
  iVar1 = *(int *)((int)this + param_1 * 0x168 + 0x40);
  this_00 = (void *)FUN_00488be0(DAT_0057c670,iVar1);
  iVar8 = 0;
  pvVar6 = *(void **)((int)this_00 + 0x1d8);
  if (((pvVar6 == (void *)0x0) || (uVar7 = extraout_EDX, *(int *)((int)pvVar6 + 0x38) == 0)) &&
     (iVar3 = FUN_00482720((int)DAT_0057c670), uVar7 = extraout_EDX_00, 1 < iVar3)) {
    local_1c = 0;
    if (0 < iVar3) {
      do {
        pvVar4 = (void *)FUN_00488be0(DAT_0057c670,iVar8);
        if ((pvVar4 != this_00) && (iVar5 = FUN_004e2280((int)pvVar4), local_1c <= iVar5)) {
          local_1c = FUN_004e2280((int)pvVar4);
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < iVar3);
    }
    iVar8 = *(int *)((int)this + iVar2 * 0x168 + 0x134);
    iVar3 = FUN_004e2280((int)this_00);
    pvVar4 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),
                                  *(int *)((int)DAT_0057c670 + 0x2f4),(int *)0x0);
    uVar7 = extraout_EDX_01;
    if (iVar3 != DAT_0057bb38) {
      if ((pvVar6 == (void *)0x0) || (iVar3 == 0)) {
        pvVar6 = (void *)FUN_004f88c0(*(int *)((int)this_00 + 0x48),pvVar4,0);
        if (pvVar6 == (void *)0x0) {
          return CONCAT44(extraout_EDX_03,3);
        }
        FUN_004d5dd0(pvVar4,(int)pvVar6,4,&local_4,&param_1,iVar1,(int *)0x0);
        iVar1 = param_1;
        if (local_1c < 2) {
          lVar10 = CONCAT44(extraout_EDX_04,param_1 * 2);
        }
        else {
          lVar10 = __ftol();
        }
        param_1 = (int)lVar10;
        if (iVar8 < param_1) {
          return CONCAT44((int)((ulonglong)lVar10 >> 0x20),2);
        }
        FUN_004e0b60(this_00,3,(float)iVar1,'\0',0xffffffff);
        FUN_004fd0f0(*(int *)((int)this + iVar2 * 0x168 + 0x40),pvVar4,pvVar6,0,0);
        *(int *)((int)pvVar6 + 0x3c) = iVar1;
        uVar7 = extraout_EDX_05;
      }
      else if ((0 < iVar3) && (iVar3 < 7)) {
        lVar9 = FUN_004d6390(4,iVar3);
        param_1 = (int)lVar9;
        lVar10 = __ftol();
        param_1 = (int)lVar10;
        if (iVar3 + 1 < local_1c) {
          lVar10 = __ftol();
          param_1 = (int)lVar10;
        }
        if (iVar8 < (int)lVar10) {
          return CONCAT44((int)((ulonglong)lVar10 >> 0x20),2);
        }
        FUN_004e0b60(this_00,3,(float)(int)lVar9,'\0',0xffffffff);
        *(int *)((int)pvVar6 + 0x3c) = param_1;
        FUN_004d77b0(pvVar4,pvVar6,4,iVar1,(void *)0xffffffff,-1);
        return CONCAT44(extraout_EDX_02,1);
      }
    }
  }
  return CONCAT44(uVar7,1);
}

