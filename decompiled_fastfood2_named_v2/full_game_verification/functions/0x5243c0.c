// rea decompile_all
// name: Window_RenderFrame
// address: 0x5243c0
// body: available
// range: 0x5243c0-0x5246d2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Window_RenderFrame(void *param_1)

{
  LPRECT lprc;
  void *this;
  ushort *puVar1;
  DWORD DVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  HWND pHVar6;
  uint uVar7;
  HDC pHVar8;
  ushort *puVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  
  DVar2 = WaitForSingleObject(DAT_0057c0d8,0);
  if (DVar2 == 0) {
    return;
  }
  lprc = (LPRECT)((int)param_1 + 0x83d0);
  SetRect(lprc,0,0,0,0);
  CS_Enter(*(int *)((int)param_1 + 0x1c8));
  if (*(int *)((int)param_1 + 0x284) == 0) {
    CS_Leave(*(int *)((int)param_1 + 0x1c8));
    return;
  }
  iVar3 = UI_RenderScene((int)param_1);
  if (iVar3 == 0) {
    CS_Leave(*(int *)((int)param_1 + 0x1c8));
    return;
  }
  if (*(int *)((int)param_1 + 8) != 0) {
    if (*(int *)((int)param_1 + 0x1b4) == 0) {
      if (*(int *)((int)param_1 + 0x1bc) == 0) {
        Sprite_ClearBuffers(*(int **)((int)param_1 + 0x1c0));
        iVar3 = UI_RenderScene((int)param_1);
        if (iVar3 == 0) {
          CS_Leave(*(int *)((int)param_1 + 0x1c8));
          return;
        }
      }
      else {
        Surface_Clear(*(int *)((int)param_1 + 0x1bc));
      }
    }
    else {
      Surface_ClearRows(*(int *)((int)param_1 + 0xc));
    }
  }
  this = *(void **)((int)param_1 + 0x83ac);
  if ((this == (void *)0x0) || (*(int *)((int)this + 8) == 0)) {
    UI_ProcessChildEvent(param_1,*(void **)((int)param_1 + 0xc));
  }
  else {
    Screen_AnimateTileWipe(this,*(uint *)((int)param_1 + 0xc));
    SetRect(lprc,0,0,800,600);
  }
  if (*(int *)((int)param_1 + 0x83b8) != 0) {
    if (*(void **)((int)param_1 + 0x83ac) != (void *)0x0) {
      Screen_BeginTileWipeTransition
                (*(void **)((int)param_1 + 0x83ac),*(uint *)((int)param_1 + 0xc),500);
    }
    UI_QueueChildCommand(param_1,0x20,0);
    *(undefined4 *)((int)param_1 + 0x83b8) = 0;
  }
  if (DAT_00584504 == 0) goto LAB_005246b9;
  if (*(int *)((int)param_1 + 0x1b4) == 0) {
    if (*(int *)((int)param_1 + 0x83a8) != 0) {
      Sprite_Draw(*(void **)((int)param_1 + 0x839c),*(int *)((int)param_1 + 0xc),
                  *(uint **)((int)param_1 + 0x83a0),*(int *)((int)param_1 + 0x83a4));
    }
    iVar3 = *(int *)((int)param_1 + 0x1bc);
    if (iVar3 != 0) {
      uVar7 = lprc->left;
      iVar4 = *(int *)(iVar3 + 4);
      puVar1 = *(ushort **)(iVar3 + 8);
      if (uVar7 == 0xfffffc19) {
        iVar3 = *(int *)(iVar3 + 0x18);
        pHVar6 = *(HWND *)((int)param_1 + 0x8320);
        pHVar8 = (HDC)0x0;
        uVar7 = 0;
        iVar5 = iVar4;
        puVar9 = puVar1;
      }
      else {
        pHVar8 = *(HDC *)((int)param_1 + 0x83d4);
        iVar3 = *(int *)(iVar3 + 0x18);
        pHVar6 = *(HWND *)((int)param_1 + 0x8320);
        iVar5 = *(int *)((int)param_1 + 0x83d8) - uVar7;
        puVar9 = (ushort *)(*(int *)((int)param_1 + 0x83dc) - (int)pHVar8);
      }
      Gfx_BlitClipped16(DAT_0057c5c8,pHVar6,iVar3,uVar7,pHVar8,iVar5,(int)puVar9,iVar4,puVar1,
                        (HDC)0x0,-1,(ushort *)0xffffffff);
      if (*(int *)((int)param_1 + 0x83bc) != 0) {
        Gfx_BlitClipped16(DAT_0057c5c8,*(HWND *)((int)param_1 + 0x8320),
                          *(int *)(*(int *)((int)param_1 + 0x1bc) + 0x18),
                          *(uint *)((int)param_1 + 0x83c0),*(HDC *)((int)param_1 + 0x83c4),
                          *(int *)((int)param_1 + 0x83c8) - *(uint *)((int)param_1 + 0x83c0),
                          *(int *)((int)param_1 + 0x83cc) - (int)*(HDC *)((int)param_1 + 0x83c4),
                          iVar4,puVar1,(HDC)0x0,-1,(ushort *)0xffffffff);
      }
      goto LAB_005246b9;
    }
    iVar3 = lprc->left;
    if (iVar3 == -999) {
      iVar12 = *(int *)((int)param_1 + 0x1c0);
      iVar4 = *(int *)((int)param_1 + 0x274);
      iVar5 = *(int *)((int)param_1 + 0x270);
      iVar11 = 0;
      goto LAB_005246ad;
    }
    iVar12 = *(int *)((int)param_1 + 0x1c0);
    iVar10 = *(int *)((int)param_1 + 0x83d4);
    iVar4 = *(int *)((int)param_1 + 0x83dc) - iVar10;
    iVar11 = 0;
    iVar5 = *(int *)((int)param_1 + 0x83d8) - iVar3;
  }
  else {
    if (*(int *)((int)param_1 + 0x83a8) != 0) {
      Sprite_Draw(*(void **)((int)param_1 + 0x839c),*(int *)((int)param_1 + 0xc),
                  *(uint **)((int)param_1 + 0x83a0),*(int *)((int)param_1 + 0x83a4));
    }
    Renderer_FlipPrimarySurface(*(int *)((int)param_1 + 0xc));
    iVar3 = lprc->left;
    if (iVar3 == -999) {
      iVar4 = *(int *)((int)param_1 + 0x274);
      iVar5 = *(int *)((int)param_1 + 0x270);
      iVar12 = 0;
      iVar11 = 1;
LAB_005246ad:
      iVar10 = 0;
      iVar3 = 0;
    }
    else {
      iVar10 = *(int *)((int)param_1 + 0x83d4);
      iVar12 = 0;
      iVar4 = *(int *)((int)param_1 + 0x83dc) - iVar10;
      iVar11 = 1;
      iVar5 = *(int *)((int)param_1 + 0x83d8) - iVar3;
    }
  }
  Surface_BlitRectRetry(*(void **)((int)param_1 + 0xc),iVar3,iVar10,iVar5,iVar4,iVar11,iVar12);
LAB_005246b9:
  *(undefined4 *)((int)param_1 + 0x234) = 0;
  CS_Leave(*(int *)((int)param_1 + 0x1c8));
  return;
}

