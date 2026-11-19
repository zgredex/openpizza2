// rea decompile_all
// name: FUN_00526200
// address: 0x526200
// body: available
// range: 0x526200-0x526470 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00526200(void *param_1)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  void *local_20;
  tagRECT local_1c;
  void *pvStack_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a77b;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  UI_SetBackgroundSurfaceEnabled(param_1,0);
  FUN_00401320(*(int *)((int)param_1 + 0x1c8));
  iVar3 = FUN_00539f00((int)DAT_0057c5c8);
  if (iVar3 == 0) {
LAB_00526252:
    bVar2 = true;
  }
  else {
    iVar3 = FUN_00539f00((int)DAT_0057c5c8);
    if (iVar3 == 2) goto LAB_00526252;
    bVar2 = false;
  }
  if (bVar2) {
    *(undefined4 *)((int)param_1 + 0x1b4) = 0;
    FUN_00538780(DAT_0057c5c8);
    SetWindowLongA(*(HWND *)((int)param_1 + 0x8320),-0x10,-0x79360000);
    ShowWindow(*(HWND *)((int)param_1 + 0x8320),1);
    MoveWindow(*(HWND *)((int)param_1 + 0x8320),0,0,*(int *)((int)param_1 + 0x270),
               *(int *)((int)param_1 + 0x274),1);
    GetClientRect(*(HWND *)((int)param_1 + 0x8320),&local_1c);
    MoveWindow(*(HWND *)((int)param_1 + 0x8320),0,0,
               *(int *)((int)param_1 + 0x270) * 2 - local_1c.right,
               *(int *)((int)param_1 + 0x274) * 2 - local_1c.bottom,1);
    if (*(int *)((int)param_1 + 0x8358) == 0) {
      uVar5 = FUN_00538af0(DAT_0057c5c8,*(undefined4 *)((int)param_1 + 0x270),
                           *(undefined4 *)((int)param_1 + 0x274),(int *)&local_20,0,0x2800);
      *(undefined4 *)((int)param_1 + 0x1c0) = uVar5;
      if (local_20 != (void *)0x0) {
        FUN_0048e0a0();
      }
      Renderer_InitForWindow(DAT_0057c5c8,*(HWND *)((int)param_1 + 0x8320));
      FUN_0053a060(*(int **)((int)param_1 + 0x1c0));
    }
    else {
      local_20 = operator_new(0x11c);
      local_4 = 0;
      if (local_20 == (void *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        puVar4 = FUN_00537230(local_20,*(int *)((int)param_1 + 0x270),*(int *)((int)param_1 + 0x274)
                              ,2);
      }
      local_4 = 0xffffffff;
      *(undefined4 **)((int)param_1 + 0x1bc) = puVar4;
      FUN_005374b0((int)puVar4);
    }
  }
  else {
    piVar1 = *(int **)((int)param_1 + 0x1c0);
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    *(undefined4 *)((int)param_1 + 0x1c0) = 0;
    if (*(undefined4 **)((int)param_1 + 0x1bc) != (undefined4 *)0x0) {
      (**(code **)**(undefined4 **)((int)param_1 + 0x1bc))(1);
    }
    *(undefined4 *)((int)param_1 + 0x1bc) = 0;
    SetWindowLongA(*(HWND *)((int)param_1 + 0x8320),-0x10,-0x6a000000);
    FUN_00538780(DAT_0057c5c8);
    SetWindowPos(*(HWND *)((int)param_1 + 0x8320),(HWND)0xffffffff,0,0,0,0,0x43);
  }
  iVar3 = FUN_00539f00((int)DAT_0057c5c8);
  if (iVar3 != 0) {
    iVar3 = FUN_00539f00((int)DAT_0057c5c8);
    if (iVar3 != 2) {
      uVar5 = 0;
      goto LAB_0052643f;
    }
  }
  uVar5 = 1;
LAB_0052643f:
  *(undefined4 *)((int)param_1 + 0x1b4) = uVar5;
  FUN_00526e50(param_1);
  FUN_00401340(*(int *)((int)param_1 + 0x1c8));
  UI_SetBackgroundSurfaceEnabled(param_1,1);
  ExceptionList = pvStack_c;
  return;
}

