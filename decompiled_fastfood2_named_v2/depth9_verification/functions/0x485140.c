// rea decompile_all
// name: FUN_00485140
// address: 0x485140
// body: available
// range: 0x485140-0x4856f1 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __fastcall FUN_00485140(void *param_1)

{
  void *pvVar1;
  DWORD DVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  float10 extraout_ST0;
  float10 fVar11;
  longlong lVar12;
  longlong lVar13;
  undefined4 local_38;
  LARGE_INTEGER local_28;
  LARGE_INTEGER local_20;
  tagRECT local_18;
  
  if ((DAT_0057c634 & 1) == 0) {
    DAT_0057c634 = DAT_0057c634 | 1;
    DVar2 = timeGetTime();
    DAT_0057c654 = DVar2 + 10000;
  }
  FUN_00401320(*(int *)((int)param_1 + 0x240));
  if (DAT_0057c5e8 != 0) {
    QueryPerformanceCounter(&local_20);
  }
  if (*(int *)((int)param_1 + 0x1508) == 0) {
    FUN_004ead00((int)DAT_0057c5cc);
  }
  if ((*(int *)((int)param_1 + 0x300) != 0) && (DAT_0057c674 != (void *)0x0)) {
    iVar3 = FUN_0052ff20(DAT_0057c674,0x2a);
    if (iVar3 != 0) {
      iVar3 = FUN_00531cf0(DAT_0057c674,0x2a);
      FUN_00521b30(iVar3);
      uVar4 = FUN_00521b10(iVar3);
      FUN_005374e0(*(void **)((int)param_1 + 0x300),uVar4,0,0,-9999,-9999,0,0);
      SetEvent(DAT_0057c5ac);
    }
    FUN_00401340(*(int *)((int)param_1 + 0x240));
    return 1;
  }
  pvVar1 = *(void **)((int)param_1 + 0x2fc);
  if (pvVar1 == (void *)0x0) goto LAB_004855e5;
  iVar3 = *(int *)((int)param_1 + 0x2da0);
  bVar10 = iVar3 != DAT_00580a50;
  if (bVar10) {
    iVar7 = *(int *)((int)pvVar1 + 0x24);
    iVar5 = *(int *)((int)pvVar1 + 0x28);
    iVar9 = (int)DAT_00571950 >> 1;
    iVar8 = (int)DAT_00571954 >> 1;
    DAT_00571954 = DAT_0057195c << ((byte)iVar3 & 0x1f);
    DAT_00571950 = DAT_00571958 << ((byte)iVar3 & 0x1f);
    DAT_00580a50 = iVar3;
    Game_ResizeZoomSurfaces(DAT_0057c5cc,DAT_0057c5c8,DAT_00571950,DAT_00571954,0,0,0);
    FUN_004ed0a0(pvVar1);
    FUN_0048b8a0(param_1,pvVar1,(iVar9 + iVar7) - ((int)DAT_00571950 >> 1),
                 (iVar8 + iVar5) - ((int)DAT_00571954 >> 1));
  }
  bVar6 = (byte)DAT_00580a50;
  if (*(int *)((int)param_1 + 0x2d98) == 2) {
    DVar2 = timeGetTime();
    iVar3 = *(int *)((int)pvVar1 + 0x28);
    iVar7 = *(int *)((int)pvVar1 + 0x24);
    if ((float)(DVar2 - DAT_0057c630) <= 0.0) {
      bVar6 = (byte)DAT_00580a50;
    }
    else {
      _DAT_0057c648 = (float)DAT_0057c660 * (float)(DVar2 - DAT_0057c630) * 0.001 + _DAT_0057c648;
      lVar12 = __ftol();
      lVar13 = __ftol();
      _DAT_0057c648 = _DAT_0057c648 - (float)(int)lVar12;
      _DAT_0057c64c = (float)(extraout_ST0 - (float10)(int)lVar13);
      FUN_0048b8a0(param_1,pvVar1,((int)lVar12 << ((byte)DAT_00580a50 & 0x1f)) + iVar7,
                   ((int)lVar13 << ((byte)DAT_00580a50 & 0x1f)) + iVar3);
      bVar6 = (byte)DAT_00580a50;
      DAT_0057c630 = DVar2;
    }
  }
  if (*(int *)((int)param_1 + 0x2d98) == 1) {
    if (DAT_0057ba08 == 0) {
      iVar3 = (DAT_0057c660 << (bVar6 & 0x1f)) + *(int *)((int)pvVar1 + 0x24);
      iVar7 = (DAT_0057c664 << (bVar6 & 0x1f)) + *(int *)((int)pvVar1 + 0x28);
    }
    else {
      iVar3 = *(int *)((int)pvVar1 + 0x24) - (DAT_0057c660 << (bVar6 & 0x1f));
      iVar7 = *(int *)((int)pvVar1 + 0x28) - (DAT_0057c664 << (bVar6 & 0x1f));
    }
    FUN_0048b8a0(param_1,pvVar1,iVar3,iVar7);
    DAT_0057c664 = 0;
    DAT_0057c660 = 0;
  }
  iVar3 = *(int *)((int)param_1 + 0x21c);
  if ((iVar3 != 0) && (*(int *)((int)param_1 + 0x2da8) != 0)) {
    if (*(int *)(iVar3 + 0x74) == 0) {
      iVar7 = FUN_004017f0((void *)((int)param_1 + 4),*(int *)((int)param_1 + 0x2f4),(int *)0x0);
      if (*(void **)(iVar7 + 0xfa8) != pvVar1) {
        *(int *)((int)param_1 + 0x21c) = iVar3;
        *(undefined4 *)((int)param_1 + 0x2da8) = 1;
        if (*(int *)((int)param_1 + 0x2dc) != 1) {
          iVar3 = -0x18607;
          goto LAB_0048550c;
        }
      }
    }
    else {
      iVar7 = *(int *)(iVar3 + 0xf4);
      iVar5 = *(int *)(iVar7 + 0x2c);
      iVar8 = FUN_00489820(param_1,*(int *)(iVar7 + 8),iVar5);
      if (*(void **)(iVar8 + 0x14e0) != pvVar1) {
        iVar7 = FUN_00489820(param_1,*(int *)(iVar7 + 8),iVar5);
        *(int *)((int)param_1 + 0x9c) = iVar7;
        FUN_00547e70(DAT_0057ba0c);
        iVar7 = *(int *)(iVar7 + 0x30);
        iVar5 = FUN_00482820((int)param_1);
        if (iVar7 == iVar5) {
          *(undefined4 *)((int)param_1 + 0x2c8) = *(undefined4 *)((int)param_1 + 0x2a8);
        }
        else {
          *(undefined4 *)((int)param_1 + 0x2c8) = *(undefined4 *)((int)param_1 + 0x2a8);
        }
        *(undefined4 *)((int)param_1 + 0x2a8) = 1;
        *(int *)((int)param_1 + 0x21c) = iVar3;
        *(undefined4 *)((int)param_1 + 0x2da8) = 1;
        if (*(int *)((int)param_1 + 0x2dc) != 4) {
          iVar3 = -0x18608;
LAB_0048550c:
          FUN_00528190(DAT_0057c5e0,iVar3,0);
        }
      }
    }
    FUN_00508070(*(void **)((int)param_1 + 0x21c));
  }
  iVar3 = FUN_00485820(param_1,(int)pvVar1);
  if (iVar3 != 0) {
    *(undefined4 *)((int)pvVar1 + 0xf4) = 1;
  }
  SetRect(&local_18,0,0,DAT_00571950,DAT_00571954);
  FUN_004ef9e0(pvVar1,DAT_0057c5d0,(int *)0x0,0,&local_18.left);
  if ((bVar10) &&
     (((iVar3 = *(int *)((int)param_1 + 0x290), iVar3 == 1 || (iVar3 == 2)) || (iVar3 == 3)))) {
    pvVar1 = *(void **)((int)param_1 + 0x25c);
    FUN_005316f0(pvVar1,0x1f4e,(uint)(DAT_00580a50 == 2));
    FUN_005316f0(pvVar1,0x1f4f,(uint)(DAT_00580a50 == 2));
  }
  FUN_00526dc0(DAT_0057c5e0,&local_18.left);
  DAT_0057c678 = DAT_0057c678 + 1;
LAB_004855e5:
  FUN_00401340(*(int *)((int)param_1 + 0x240));
  if (DAT_0057c5e8 != 0) {
    QueryPerformanceCounter(&local_28);
    fVar11 = FUN_00527dc0((int)DAT_0057c5e0,local_20.s.LowPart,local_20.s.HighPart,
                          local_28.s.LowPart,local_28.s.HighPart);
    _DAT_0057c680 = (double)(fVar11 + (float10)_DAT_0057c680);
    DVar2 = timeGetTime();
    if (DAT_0057c654 < DVar2) {
      DAT_0057c654 = DAT_0057c654 + 10000;
      local_38 = SUB84((double)((float)DAT_0057c678 * 0.1),0);
      DebugConsole_Printf(DAT_0057c1e0,0x80,(byte *)s_Iso_fps___1f___1f_d___2f_005680f4,local_38);
      DAT_0057c678 = 0;
      _DAT_0057c680 = 0.0;
    }
  }
  SetEvent(DAT_0057c5ac);
  return 1;
}

