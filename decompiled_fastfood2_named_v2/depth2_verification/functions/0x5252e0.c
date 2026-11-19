// rea decompile_all
// name: FUN_005252e0
// address: 0x5252e0
// body: available
// range: 0x5252e0-0x5257de inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


LRESULT __thiscall FUN_005252e0(void *this,HWND param_1,uint param_2,WPARAM param_3,HCURSOR param_4)

{
  ushort *puVar1;
  HDC pHVar2;
  BOOL BVar3;
  uint uVar4;
  HMENU hMenu;
  LRESULT LVar5;
  undefined4 *puVar6;
  int iVar7;
  tagRECT local_60;
  tagRECT local_50;
  tagPAINTSTRUCT local_40;
  
  if (param_2 < 0x105) {
    if (param_2 == 0x104) {
      if ((param_3 == 0x58) || (param_3 == 0x73)) {
        FUN_00525cf0(this,1,0x104,param_3,(uint)param_4);
        return 0;
      }
      LVar5 = DefWindowProcA(param_1,0x104,param_3,(LPARAM)param_4);
      return LVar5;
    }
    if (param_2 < 0x15) {
      if (param_2 == 0x14) {
        return 1;
      }
      switch(param_2) {
      case 2:
        UI_SetBackgroundSurfaceEnabled(this,0);
        SetWindowLongA(*(HWND *)((int)this + 0x8320),-0x15,0);
        *(undefined4 *)((int)this + 0x8320) = 0;
        SetEvent(DAT_0057c0d8);
        PostQuitMessage(0);
        return 0;
      case 3:
        goto switchD_00525321_caseD_3;
      default:
        goto switchD_00525321_caseD_4;
      case 0xf:
        GetUpdateRect(param_1,&local_50,0);
        pHVar2 = BeginPaint(param_1,&local_40);
        if ((local_50.left != 0) || (local_50.right != 0)) {
          Window_BlitToDC(this,(uint *)&local_50,pHVar2);
        }
        EndPaint(param_1,&local_40);
        return 0;
      case 0x10:
        DestroyWindow(param_1);
        return 0;
      }
    }
    switch(param_2) {
    case 0x1c:
      if (DAT_00584504 == 1) {
        FUN_0053a110(*(int *)((int)this + 0xc));
        FUN_00526e50(this);
        return 0;
      }
      break;
    default:
      goto switchD_00525321_caseD_4;
    case 0x7e:
switchD_00525321_caseD_3:
      BVar3 = IsIconic(param_1);
      if (BVar3 == 0) {
        local_60.left = BVar3;
        local_60.top = BVar3;
        ClientToScreen(param_1,(LPPOINT)&local_60);
        Window_SetRectAndUpdateChildren(DAT_0057c5c8,local_60.left,local_60.top);
      }
      if (param_2 == 3) {
        GetWindowRect(param_1,(LPRECT)&DAT_00573d38);
        return 0;
      }
      break;
    case 0x100:
      iVar7 = 0;
      if ((short)DAT_00573cc8 != 0) {
        puVar6 = &DAT_00573cc8;
        uVar4 = DAT_00573cc8;
        do {
          if ((short)uVar4 == (short)param_3) {
            FUN_00525cf0(this,1,param_2,(int)*(short *)((int)&DAT_00573cc8 + iVar7 * 4 + 2),0);
            return 0;
          }
          puVar1 = (ushort *)(puVar6 + 1);
          uVar4 = (uint)*puVar1;
          puVar6 = puVar6 + 1;
          iVar7 = iVar7 + 1;
        } while (*puVar1 != 0);
      }
      LVar5 = DefWindowProcA(param_1,param_2,param_3,(LPARAM)param_4);
      return LVar5;
    case 0x102:
      FUN_00525cf0(this,1,param_2,param_3,(uint)param_4);
      return 0;
    }
    return 0;
  }
  if (0x204 < param_2) {
    if (param_2 == 0x205) {
      FUN_00525cf0(this,1,0x205,param_3,(uint)param_4);
      return 0;
    }
    if (param_2 == 0x20a) {
      FUN_00525cf0(this,1,0x20a,param_3,(uint)param_4);
      return 1;
    }
    if (param_2 == 0x400) {
      SetClassLongA(*(HWND *)((int)this + 0x8320),-0xc,(LONG)param_4);
      SetCursor(param_4);
      SetEvent(*(HANDLE *)((int)this + 0x8354));
      return 0;
    }
switchD_00525321_caseD_4:
    LVar5 = DefWindowProcA(param_1,param_2,param_3,(LPARAM)param_4);
    return LVar5;
  }
  if (param_2 == 0x204) {
    FUN_00525cf0(this,0,0x204,param_3,(uint)param_4);
    return 0;
  }
  switch(param_2) {
  case 0x112:
    uVar4 = param_3 & 0xfff0;
    if (uVar4 < 0x4301) {
      if (uVar4 == 0x4300) {
        hMenu = GetSystemMenu(param_1,0);
        if (*(int *)((int)this + 8) == 0) {
          CheckMenuItem(hMenu,0x4300,8);
          FUN_00526d10(this,1);
          return 0;
        }
        CheckMenuItem(hMenu,0x4300,0);
        FUN_00526d10(this,0);
        return 0;
      }
      if (uVar4 == 0x4200) {
        FUN_0054a7b0(DAT_0057c1e0);
        return 0;
      }
      if (uVar4 == 0x4210) {
        FUN_0054a7d0((int)DAT_0057c1e0);
        return 0;
      }
    }
    else if (uVar4 == 0x4310) {
      GetWindowRect(param_1,&local_60);
      MoveWindow(param_1,0,0,local_60.right - local_60.left,local_60.bottom - local_60.top,1);
      FUN_0054a820((int)DAT_0057c1e0);
      return 0;
    }
    LVar5 = DefWindowProcA(param_1,param_2,param_3,(LPARAM)param_4);
    return LVar5;
  default:
    goto switchD_00525321_caseD_4;
  case 0x200:
    if (DAT_00584230 != 0) {
      DAT_00584230 = 0;
      FUN_00525cf0(this,0,param_2,param_3,(uint)param_4);
      return 0;
    }
    break;
  case 0x201:
    SetCapture(param_1);
    break;
  case 0x202:
    ReleaseCapture();
    FUN_00525cf0(this,1,param_2,param_3,(uint)param_4);
    return 0;
  }
  FUN_00525cf0(this,0,param_2,param_3,(uint)param_4);
  return 0;
}

