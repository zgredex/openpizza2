// rea decompile_all
// name: FUN_00484270
// address: 0x484270
// body: available
// range: 0x484270-0x484493 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __fastcall FUN_00484270(void *param_1)

{
  int iVar1;
  void *pvVar2;
  void *local_4;
  
  *(undefined4 *)((int)param_1 + 0x2d8) = 0;
  local_4 = param_1;
  if (*(int *)((int)param_1 + 0x268) != 0) {
    Game_CloseSelectionDialog((int)param_1);
  }
  switch(*(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x290) * 4 + 0x298)) {
  case 1:
    pvVar2 = FUN_0040f1d0((int *)&local_4);
    FUN_00491ea0(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 2:
    pvVar2 = FUN_004132a0((int *)&local_4);
    FUN_00493110(pvVar2,'\0','\0');
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 3:
    pvVar2 = FUN_0040daa0((int *)&local_4);
    FUN_00490b00(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 4:
    pvVar2 = FUN_00417590((int *)&local_4);
    FUN_004962e0(pvVar2,'\x01');
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 5:
    pvVar2 = SubMenu_BuildBranchBalance((int *)&local_4);
    FinanceScreen_UpdateStatement(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 6:
    pvVar2 = FUN_00418d60((int *)&local_4);
    FUN_00497180(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 7:
    pvVar2 = FUN_00410740((int *)&local_4);
    FUN_00492440(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 8:
    pvVar2 = FUN_00411b90((int *)&local_4);
    FUN_00492b20(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  case 9:
    break;
  case 10:
    local_4 = (void *)FUN_00483740(param_1,*(undefined4 *)((int)param_1 + 0x2e4));
    iVar1 = FUN_00528040(DAT_0057c5e0,(int)local_4,(int *)0x0);
    *(int *)((int)param_1 + 0x264) = iVar1;
    return local_4;
  case 0xb:
    pvVar2 = FUN_00415620((int *)&local_4);
    FUN_004951f0(pvVar2,0);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  default:
    *(void **)((int)param_1 + 0x264) = local_4;
    return local_4;
  }
  if (*(char *)(*(int *)((int)param_1 + 0x9c) + 0x16f5) == '\0') {
    pvVar2 = FUN_0040bc50((int *)&local_4);
    FUN_0048f860(pvVar2);
    *(void **)((int)param_1 + 0x264) = pvVar2;
    return local_4;
  }
  pvVar2 = SubMenu_BuildConstructionInfo((int *)&local_4);
  *(undefined4 *)((int)param_1 + 0x218) = *(undefined4 *)(*(int *)((int)param_1 + 0x9c) + 0x16f0);
  ConstructionMenu_Fill(pvVar2);
  *(void **)((int)param_1 + 0x264) = pvVar2;
  return local_4;
}

