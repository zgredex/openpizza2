// rea decompile_all
// name: FUN_004844c0
// address: 0x4844c0
// body: available
// range: 0x4844c0-0x484627 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_004844c0(int param_1)

{
  void *pvVar1;
  int local_4;
  
  *(undefined4 *)(param_1 + 0x2d8) = 0;
  local_4 = param_1;
  if (*(int *)(param_1 + 0x268) != 0) {
    FUN_00482890(param_1);
  }
  switch(*(undefined4 *)(param_1 + 0x298 + *(int *)(param_1 + 0x290) * 4)) {
  case 1:
    pvVar1 = FUN_00447310(&local_4);
    FUN_004b83f0(pvVar1,'\0');
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 2:
    pvVar1 = FUN_00449a80(&local_4);
    FUN_004b8da0(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 3:
    pvVar1 = FUN_00445c80(&local_4);
    FUN_004b81e0(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 4:
    pvVar1 = FUN_0044b5a0(&local_4);
    FUN_004b9a40(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 5:
    pvVar1 = FUN_0044cc90(&local_4);
    FUN_004b9c90(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 6:
    pvVar1 = FUN_00443ab0(&local_4);
    FUN_004b63f0(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 7:
    pvVar1 = FUN_00444ee0(&local_4);
    FUN_004b7a00(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  case 8:
    pvVar1 = FUN_00448650(&local_4);
    FUN_004b8870(pvVar1);
    *(void **)(param_1 + 0x264) = pvVar1;
    return local_4;
  default:
    *(int *)(param_1 + 0x264) = local_4;
    return local_4;
  }
}

