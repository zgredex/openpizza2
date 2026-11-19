// rea decompile_all
// name: FUN_00538da0
// address: 0x538da0
// body: available
// range: 0x538da0-0x538f5b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
FUN_00538da0(void *this,int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int local_28;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  tagRECT local_10;
  
  local_28 = 0;
  local_20 = param_1;
  local_1c = param_2;
  if (param_2 < 0) {
    local_1c = 0;
  }
  if (param_1 < 0) {
    local_20 = 0;
  }
  local_18 = param_1 + param_3;
  if ((int)(uint)*(ushort *)((int)this + 0x1a) < param_1 + param_3) {
    local_18 = (uint)*(ushort *)((int)this + 0x1a);
  }
  local_14 = param_2 + param_4;
  if ((int)(uint)*(ushort *)((int)this + 0x1c) < param_2 + param_4) {
    local_14 = (uint)*(ushort *)((int)this + 0x1c);
  }
  if (((int)(local_18 - local_20) < 1) || ((int)(local_14 - local_1c) < 1)) {
    return 1;
  }
  if (param_6 == 0) {
    if (param_5 == 0) {
      param_6 = *(int *)(*(int *)((int)this + 0x40) + 8);
    }
    else {
      param_6 = *(int *)(*(int *)((int)this + 0x40) + 4);
    }
  }
  while( true ) {
    if (DAT_005844fc != 0) {
      return 0;
    }
    if (*(int *)((int)this + 0x94) == 0) {
      if (param_5 == 0) {
        piVar2 = *(int **)(*(int *)((int)this + 0x40) + 4);
      }
      else {
        piVar2 = *(int **)(*(int *)((int)this + 0x40) + 8);
      }
      iVar1 = (**(code **)(*piVar2 + 0x1c))(piVar2,local_20,local_1c,param_6,&local_20,0x10);
    }
    else {
      SetRect(&local_10,*(int *)((int)this + 0x84) + local_20,*(int *)((int)this + 0x88) + local_1c,
              *(int *)((int)this + 0x84) + local_18,local_14 + *(int *)((int)this + 0x88));
      if (param_5 == 0) {
        piVar2 = *(int **)(*(int *)((int)this + 0x40) + 4);
      }
      else {
        piVar2 = *(int **)(*(int *)((int)this + 0x40) + 8);
      }
      iVar1 = (**(code **)(*piVar2 + 0x14))(piVar2,&local_10,param_6,&local_20,0x1000000,0);
    }
    if (iVar1 == 0) break;
    if ((((-0x7789ff6a < iVar1) && (iVar1 < -0x7789fde3)) && (iVar1 != -0x7789fde4)) &&
       ((iVar1 != -0x7789fe52 && (iVar1 == -0x7789fe3e)))) {
      Thread_WaitForExit((int)this);
    }
    Sleep(10);
    local_28 = local_28 + 1;
    if (200 < local_28) {
      return 0;
    }
  }
  return 1;
}

