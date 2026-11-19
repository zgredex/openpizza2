// rea decompile_all
// name: UI_Manager_Construct
// address: 0x523100
// body: available
// range: 0x523100-0x52358b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 * __thiscall
UI_Manager_Construct
          (void *this,void *param_1,void *param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  DWORD DVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  HANDLE pvVar4;
  int iVar5;
  undefined4 unaff_EDI;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Constructs the global UI manager and its tables and locks. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a688;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  NamedLockable_Construct((void *)((int)this + 0x1cc),(char *)0x0);
  local_4 = 0;
  FUN_00522e80((void *)((int)this + 0x8324),0);
  *(undefined ***)this = &PTR_UI_Manager_ScalarDeletingDestructor_0055c778;
  *(undefined4 *)((int)this + 0x83e0) = 4000;
  *(undefined4 *)((int)this + 0x83a8) = 0;
  *(undefined4 *)((int)this + 0x83a4) = 0xffffd8f1;
  *(undefined4 *)((int)this + 0x83a0) = 0xffffd8f1;
  *(undefined4 *)((int)this + 0x839c) = 0;
  *(undefined4 *)((int)this + 0x284) = 0;
  local_4._0_1_ = 1;
  *(undefined4 *)((int)this + 0x8318) = 0;
  DVar1 = GetCurrentThreadId();
  *(DWORD *)((int)this + 0x830c) = DVar1;
  *(undefined4 *)((int)this + 0x1c8) = 0;
  *(undefined4 *)((int)this + 0x1b8) = 0;
  *(undefined4 *)((int)this + 0x1c4) = 0;
  *(undefined4 *)((int)this + 0x1bc) = 0;
  *(undefined4 *)((int)this + 0x224) = 0;
  *(undefined4 *)((int)this + 0x22c) = 0;
  *(undefined4 *)((int)this + 0x230) = 0;
  *(undefined4 *)((int)this + 0x234) = 1;
  *(undefined4 *)((int)this + 0x238) = 1;
  *(undefined4 *)((int)this + 0x240) = 0;
  *(void **)((int)this + 0x8320) = param_2;
  *(undefined4 *)((int)this + 0x278) = 0;
  *(undefined4 *)((int)this + 0x32b4) = 0;
  *(undefined4 *)((int)this + 0x32b8) = 0;
  *(undefined4 *)((int)this + 0x82bc) = 0;
  *(undefined4 *)((int)this + 0x82c0) = 0;
  *(undefined4 *)((int)this + 0x228) = 0;
  *(undefined4 *)((int)this + 0x270) = param_4;
  *(undefined4 *)((int)this + 0x274) = param_5;
  *(undefined4 *)((int)this + 0x82c4) = 0;
  *(undefined4 *)((int)this + 0x82c8) = 0;
  *(undefined4 *)((int)this + 0x82cc) = 0;
  *(undefined4 *)((int)this + 0x82d4) = 0;
  *(undefined4 *)((int)this + 0x82d8) = 0;
  *(undefined4 *)((int)this + 0x82e0) = 0;
  *(undefined4 *)((int)this + 0x82e4) = 0;
  *(undefined4 *)((int)this + 0x82e8) = 0x18;
  *(undefined4 *)((int)this + 0x82dc) = 0;
  *(undefined4 *)((int)this + 0x82d0) = 0;
  *(undefined4 *)((int)this + 0x82ec) = 1;
  *(undefined4 *)((int)this + 0x82f4) = 500;
  *(undefined4 *)((int)this + 0x82f8) = 0;
  *(undefined4 *)((int)this + 0x82fc) = 0;
  *(undefined4 *)((int)this + 0x8300) = 0;
  *(undefined4 *)((int)this + 0x8304) = 0;
  *(undefined4 *)((int)this + 0x8308) = 0;
  *(undefined4 *)((int)this + 0x248) = 0;
  *(undefined4 *)((int)this + 0x24c) = 0;
  *(undefined4 *)((int)this + 0x831c) = 0;
  *(undefined4 *)((int)this + 0x8338) = 0;
  *(undefined4 *)((int)this + 0x833c) = 0;
  *(undefined4 *)((int)this + 0x8348) = 0;
  *(undefined4 *)((int)this + 0x8340) = 500;
  *(undefined4 *)((int)this + 0x8344) = 0x32;
  *(undefined4 *)((int)this + 0x8350) = 0;
  *(undefined4 *)((int)this + 0x834c) = 0;
  *(undefined4 *)((int)this + 0x1c0) = 0;
  *(undefined4 *)((int)this + 0x8358) = param_6;
  *(undefined4 *)((int)this + 0x83ac) = 0;
  *(undefined4 *)((int)this + 0x83b8) = 0;
  *(undefined4 *)((int)this + 0x1a4) = 0xfffffc19;
  *(undefined4 *)((int)this + 0x83e4) = 0;
  QueryPerformanceFrequency((LARGE_INTEGER *)((int)this + 0x83b0));
  puVar2 = (undefined4 *)((int)this + 0x250);
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  SetWindowLongA(*(HWND *)((int)this + 0x8320),-0x15,(LONG)this);
  puVar2 = (undefined4 *)((int)this + 0x14);
  for (iVar5 = 100; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  puVar2 = (undefined4 *)((int)this + 0x250);
  for (iVar5 = 8; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  *(undefined4 *)((int)this + 0x10) = param_3;
  puVar2 = FUN_00539ea0(param_1);
  *(undefined4 **)((int)this + 0xc) = puVar2;
  *(undefined4 *)((int)this + 0x1b4) = 1;
  if (*(int *)((int)param_1 + 0x98) == 0) {
    *(undefined4 *)((int)this + 0x1b4) = 0;
    if (*(int *)((int)this + 0x8358) == 0) {
      iVar5 = FUN_00539f00((int)param_1);
      if (iVar5 == 2) {
        if (*(int *)((int)param_1 + 0x40) == 0) {
          *(undefined4 *)((int)this + 0x1c0) = 0;
        }
        else {
          *(undefined4 *)((int)this + 0x1c0) = *(undefined4 *)(*(int *)((int)param_1 + 0x40) + 8);
        }
      }
      else {
        uVar3 = FUN_00538af0(param_1,*(undefined4 *)((int)this + 0x270),
                             *(undefined4 *)((int)this + 0x274),(int *)&param_2,0,0x2800);
        *(undefined4 *)((int)this + 0x1c0) = uVar3;
        if (param_2 != (void *)0x0) {
          FUN_0048e0a0();
        }
      }
      FUN_00539f90(param_1,*(HWND *)((int)this + 0x8320));
      FUN_0053a060(*(int **)((int)this + 0x1c0));
    }
    else {
      param_2 = operator_new(0x11c);
      local_4._0_1_ = 2;
      if (param_2 == (void *)0x0) {
        puVar2 = (undefined4 *)0x0;
      }
      else {
        puVar2 = FUN_00537230(param_2,*(int *)((int)this + 0x270),*(int *)((int)this + 0x274),2);
      }
      local_4._0_1_ = 1;
      *(undefined4 **)((int)this + 0x1bc) = puVar2;
      FUN_005374b0((int)puVar2);
    }
  }
  param_2 = operator_new(0x58);
  local_4._0_1_ = 3;
  if (param_2 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = NamedLockable_Construct(param_2,s_MenuCriticalSection_00574050);
  }
  local_4._0_1_ = 1;
  *(undefined4 **)((int)this + 0x1c8) = puVar2;
  *(undefined4 *)((int)this + 0x8314) = 0;
  param_2 = operator_new(0x28);
  local_4._0_1_ = 4;
  if (param_2 == (void *)0x0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0051e9d0(param_2,this);
  }
  *(undefined4 *)((int)this + 0x8310) = uVar3;
  *(undefined4 *)((int)this + 0x23c) = 0;
  *(undefined4 *)((int)this + 0x288) = 0;
  *(undefined4 *)((int)this + 0x298) = 0xffffff;
  *(undefined4 *)((int)this + 0x29c) = 0;
  *(undefined4 *)((int)this + 0x2a0) = 0xff000000;
  *(undefined4 *)((int)this + 0x2a4) = 0xff000000;
  *(undefined4 *)((int)this + 0x2a8) = 0xff000000;
  *(undefined4 *)((int)this + 0x28c) = 0xc0c0c0;
  *(undefined4 *)((int)this + 0x290) = 0xffffff;
  *(undefined4 *)((int)this + 0x294) = 0xff0000;
  *(char **)((int)this + 0x2ac) = s_cancel_00574048;
  *(undefined **)((int)this + 0x2b0) = &DAT_00574044;
  local_4._0_1_ = 1;
  FUN_0054a660(DAT_0057c1e0,0xff0000,(byte *)s_menu_ready_00574038,unaff_EDI);
  *(undefined4 *)((int)this + 8) = 0;
  *(undefined4 *)((int)this + 0x1a4) = 0xfffffc19;
  *(undefined4 *)((int)this + 0x284) = 1;
  param_2 = operator_new(0x50);
  local_4._0_1_ = 5;
  if (param_2 == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_0052e4b0(param_2,param_1,this);
  }
  local_4 = CONCAT31(local_4._1_3_,1);
  *(undefined4 **)((int)this + 0x244) = puVar2;
  FUN_00526480(this,s_REQUEST_OUTL_00574028);
  pvVar4 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,1,1,s_MouseSetEvent_00574018);
  *(HANDLE *)((int)this + 0x8354) = pvVar4;
  ExceptionList = local_c;
  return this;
}

