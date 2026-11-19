// rea decompile_all
// name: FUN_0050e310
// address: 0x50e310
// body: available
// range: 0x50e310-0x50e462 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_0050e310(void *param_1,uint param_2,int param_3)

{
  int iVar1;
  uint extraout_EDX;
  uint extraout_EDX_00;
  void *pvVar2;
  
  pvVar2 = (void *)0x0;
  if ((param_3 != 0) && (iVar1 = *(int *)((int)param_1 + 0xf4), iVar1 != 0)) {
    pvVar2 = (void *)Game_GetPlayerSubmapValue
                               (DAT_0057c670,*(int *)(iVar1 + 8),*(int *)(iVar1 + 0x2c));
    param_2 = extraout_EDX;
  }
  if (*(int *)((int)param_1 + 0xa0) == 0) {
    switch(*(undefined4 *)((int)param_1 + 0x30)) {
    case 10:
      Object_SetFieldA4Locked(param_1,0xffffffff);
      *(undefined4 *)((int)param_1 + 0x108) = 0xffffffff;
      if ((param_3 != 0) && (pvVar2 != (void *)0x0)) {
        *(undefined1 *)(*(int *)((int)param_1 + 0x10c) + 0x1880 + (int)pvVar2) = 0;
        FUN_00507fd0(param_1);
        return;
      }
      break;
    default:
      goto switchD_0050e39d_caseD_b;
    case 0xd:
    case 0x16:
    case 0x17:
    case 0x1d:
    case 0x1e:
    case 0x1f:
      FUN_0050bc40(param_1);
      return;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
      if (param_3 != 0) {
        FUN_0050e2a0((int)param_1,param_2,(int)pvVar2,'\x01');
      }
      FUN_00507e20(param_1,3,*(int *)((int)param_1 + 0xcc));
      return;
    case 0x14:
      if (param_3 != 0) {
        if (pvVar2 != (void *)0x0) {
          FUN_0050bbf0(param_1,pvVar2);
          param_2 = extraout_EDX_00;
        }
        FUN_0050e2a0((int)param_1,param_2,(int)pvVar2,'\x01');
      }
      Object_SetFieldA4Locked(param_1,0xffffffff);
      FUN_0050e4c0(param_1,0);
      FUN_00507e20(param_1,3,*(int *)((int)param_1 + 0xcc));
      return;
    case 0x18:
    case 0x20:
      Object_SetFieldA4Locked(param_1,0xffffffff);
    }
  }
  else if (param_3 != 0) {
    Game_GetTimeByMode(param_1,0);
    *(undefined4 *)((int)param_1 + 0x4c) = 0;
    *(undefined4 *)((int)param_1 + 0x54) = 0;
    UI_SetChildState(param_1,0xffff);
    FUN_0050e890(param_1,2);
    FUN_00507fd0(param_1);
    return;
  }
  FUN_00507fd0(param_1);
switchD_0050e39d_caseD_b:
  return;
}

