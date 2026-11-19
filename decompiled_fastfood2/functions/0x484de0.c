// rea decompile_all
// name: FUN_00484de0
// address: 0x484de0
// body: available
// range: 0x484de0-0x484f32 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void * __fastcall FUN_00484de0(void *param_1)

{
  void *pvVar1;
  int iVar2;
  void *local_4;
  
  local_4 = param_1;
  if (*(int *)((int)param_1 + 0x268) != 0) {
    FUN_00482890((int)param_1);
  }
  switch(*(undefined4 *)((int)param_1 + *(int *)((int)param_1 + 0x290) * 4 + 0x298)) {
  case 1:
    pvVar1 = FUN_00433790((int *)&local_4);
    FUN_004ad9a0(pvVar1,'\x01');
    break;
  case 2:
    pvVar1 = FUN_0043edb0((int *)&local_4);
    FUN_004b2240(pvVar1);
    break;
  case 3:
    pvVar1 = FUN_00442870((int *)&local_4);
    FUN_004b3fb0(pvVar1,'\x01');
    break;
  case 4:
    pvVar1 = FUN_00430fd0((int *)&local_4);
    FUN_004ab970(pvVar1);
    break;
  case 5:
    pvVar1 = FUN_0043e430((int *)&local_4);
    FUN_004b0090(pvVar1);
    break;
  case 6:
    switch(*(undefined4 *)((int)param_1 + 0x2e8)) {
    case 0:
      pvVar1 = FUN_0043cee0((int *)&local_4);
      FUN_004afd10(pvVar1);
      break;
    case 1:
      pvVar1 = FUN_0043b940((int *)&local_4);
      FUN_004aef90(pvVar1);
      break;
    case 2:
      pvVar1 = FUN_0043aca0((int *)&local_4);
      FUN_004aeac0(pvVar1);
      break;
    case 3:
      pvVar1 = FUN_0043c7e0((int *)&local_4);
      FUN_004af370(pvVar1);
      break;
    default:
      goto switchD_00484e0b_default;
    }
    break;
  default:
switchD_00484e0b_default:
    pvVar1 = local_4;
  }
  *(void **)((int)param_1 + 0x264) = pvVar1;
  iVar2 = FUN_005260e0(*(int *)((int)param_1 + 0x260));
  FUN_00527f80(DAT_0057c5e0,iVar2);
  return local_4;
}

