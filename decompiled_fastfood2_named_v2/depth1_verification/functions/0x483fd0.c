// rea decompile_all
// name: FUN_00483fd0
// address: 0x483fd0
// body: available
// range: 0x483fd0-0x484245 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00483fd0(void *this,int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  
  iVar2 = param_2;
  iVar1 = param_1;
  if ((param_1 == 0) || (param_1 != *(int *)((int)this + 0x218))) {
    if (((param_4 != 0) || ((param_2 == 0 || (param_2 != *(int *)((int)this + 0x21c))))) &&
       ((param_3 == 0 || (param_3 != *(int *)((int)this + 0x220))))) {
      FUN_00482860((undefined4 *)((int)this + 0x264));
      if (iVar1 == 0) {
        iVar3 = param_3;
      }
      else {
        iVar3 = UI_GetActionDuration(this,iVar1);
        *(int *)((int)this + 0x218) = iVar1;
        *(undefined4 *)((int)this + 0x21c) = 0;
        *(undefined4 *)((int)this + 0x2da8) = 1;
        *(undefined4 *)((int)this + 0x220) = 0;
      }
      if (iVar2 != 0) {
        iVar3 = FUN_00483d10(this,iVar2);
        *(int *)((int)this + 0x21c) = iVar2;
        *(undefined4 *)((int)this + 0x2da8) = 1;
        *(undefined4 *)((int)this + 0x218) = 0;
        *(undefined4 *)((int)this + 0x220) = 0;
      }
      switch(*(undefined4 *)((int)this + 0x290)) {
      case 1:
        *(undefined4 *)((int)this + 700) = *(undefined4 *)((int)this + 0x29c);
        *(undefined4 *)((int)this + 0x29c) = 10;
        FUN_004cec60(*(void **)((int)this + 0x260));
        break;
      case 2:
      case 3:
        FUN_00482860((undefined4 *)((int)this + 0x260));
        *(undefined4 *)((int)this + 700) = *(undefined4 *)((int)this + 0x29c);
        *(undefined4 *)((int)this + 0x29c) = 10;
        pvVar4 = UI_CreateInfoPanel(&param_1);
        *(undefined4 *)((int)this + 0x260) = pvVar4;
        FUN_004cec60(pvVar4);
        break;
      case 4:
        *(undefined4 *)((int)this + 0x2c8) = *(undefined4 *)((int)this + 0x2a8);
        *(undefined4 *)((int)this + 0x2a8) = 10;
      }
      iVar1 = param_3;
      if (param_3 != 0) {
        iVar3 = FUN_00483fa0(param_3);
        *(int *)((int)this + 0x220) = iVar1;
        *(undefined4 *)((int)this + 0x21c) = 0;
        *(undefined4 *)((int)this + 0x2da8) = 1;
        *(undefined4 *)((int)this + 0x218) = 0;
      }
      pvVar4 = *(void **)((int)this + 0x260);
      FUN_0052ff50(pvVar4,0x3fd,1);
      Array_ToggleObjectActive(pvVar4,0x3fd,1);
      FUN_005316f0(pvVar4,0x3fd,1);
      *(int *)((int)this + 0x2e4) = iVar3;
      switch(*(undefined4 *)((int)this + 0x290)) {
      case 1:
        pvVar4 = FUN_00484650(this,(int *)0x0);
        FUN_00523d60(DAT_0057c5e0,(int)pvVar4);
        return 0;
      case 2:
        *(undefined4 *)((int)this + 0x290) = 1;
        pvVar4 = FUN_00484650(this,(int *)0x0);
        FUN_00523d60(DAT_0057c5e0,(int)pvVar4);
        FUN_00523d60(DAT_0057c5e0,param_1);
        return 0;
      case 3:
        *(undefined4 *)((int)this + 0x290) = 1;
        pvVar4 = FUN_00484650(this,(int *)0x0);
        FUN_00523d60(DAT_0057c5e0,(int)pvVar4);
        FUN_00523d60(DAT_0057c5e0,param_1);
        break;
      case 4:
        pvVar4 = FUN_00484270(this);
        FUN_00523d60(DAT_0057c5e0,(int)pvVar4);
        return 0;
      }
    }
  }
  else if (*(int *)(param_1 + 4) == 0xf) {
    return 0xf;
  }
  return 0;
}

