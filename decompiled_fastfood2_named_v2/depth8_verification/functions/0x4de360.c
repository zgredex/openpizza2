// rea decompile_all
// name: FUN_004de360
// address: 0x4de360
// body: available
// range: 0x4de360-0x4de469 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


float10 __thiscall FUN_004de360(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 fVar6;
  float local_14;
  float local_10;
  int local_c;
  uint local_8;
  
  local_14 = 0.0;
  uVar1 = *(ushort *)(*(int *)(DAT_0057c670 + 0x94) + 10);
  local_8 = (uint)uVar1;
  if (100 < uVar1) {
    local_8 = 100;
  }
  local_c = 0;
  if (local_8 == 0) {
    return (float10)0.0;
  }
  do {
    if (param_2 == 0) {
      iVar4 = *(int *)(param_1 + 0x15c);
      iVar5 = 0;
      do {
        iVar3 = 0;
        local_10 = 0.0;
        if (0 < iVar4) {
          do {
            iVar2 = FUN_004017f0((void *)(param_1 + 0x148),iVar3,(int *)0x0);
            fVar6 = FUN_00477fe0(iVar2,iVar5,-1,local_c);
            iVar3 = iVar3 + 1;
            local_10 = (float)(fVar6 + (float10)local_10);
          } while (iVar3 < iVar4);
        }
        if (local_14 < local_10) {
          local_14 = local_10;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < 9);
    }
    else {
      iVar4 = 0;
      do {
        fVar6 = FUN_00477fe0(param_2,iVar4,-1,local_c);
        if ((float10)local_14 < fVar6) {
          local_14 = (float)fVar6;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 9);
    }
    local_c = local_c + 1;
  } while (local_c < (int)local_8);
  return (float10)local_14;
}

