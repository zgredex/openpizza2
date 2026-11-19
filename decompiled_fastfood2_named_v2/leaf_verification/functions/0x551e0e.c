// rea decompile_all
// name: FUN_00551e0e
// address: 0x551e0e
// body: available
// range: 0x551e0e-0x551f45 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int * __cdecl FUN_00551e0e(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint *puVar4;
  
  if (param_1 == (int *)0x0) {
    piVar1 = _malloc((size_t)param_2);
  }
  else {
    if (param_2 == (uint *)0x0) {
      FUN_00551005(param_1);
    }
    else {
      do {
        if (param_2 < (uint *)0xffffffe1) {
          FUN_0055395d(9);
          puVar2 = (uint *)Heap_FindBlock((int)param_1);
          if (puVar2 == (uint *)0x0) {
            CS_LeaveIndexed(9);
            if (param_2 == (uint *)0x0) {
              param_2 = (uint *)0x1;
            }
            param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
            piVar1 = HeapReAlloc(DAT_00585be0,0,param_1,(SIZE_T)param_2);
          }
          else {
            if (DAT_00577168 < param_2) {
LAB_00551ead:
              if (param_2 == (uint *)0x0) {
                param_2 = (uint *)0x1;
              }
              param_2 = (uint *)((int)param_2 + 0xfU & 0xfffffff0);
              piVar1 = HeapAlloc(DAT_00585be0,0,(SIZE_T)param_2);
              if (piVar1 != (int *)0x0) {
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                _memmove_2(piVar1,param_1,(uint)puVar4);
                FUN_00554912(puVar2,(uint)param_1);
              }
            }
            else {
              iVar3 = CRT_HeapFreeBlock(puVar2,(int)param_1,(int)param_2);
              if (iVar3 == 0) {
                piVar1 = FUN_00554c3d(param_2);
                if (piVar1 == (int *)0x0) goto LAB_00551ead;
                puVar4 = (uint *)(param_1[-1] - 1U);
                if (param_2 <= (uint *)(param_1[-1] - 1U)) {
                  puVar4 = param_2;
                }
                _memmove_2(piVar1,param_1,(uint)puVar4);
                FUN_00554912(puVar2,(uint)param_1);
              }
              else {
                piVar1 = param_1;
              }
              if (piVar1 == (int *)0x0) goto LAB_00551ead;
            }
            CS_LeaveIndexed(9);
          }
          if (piVar1 != (int *)0x0) {
            return piVar1;
          }
        }
        if (DAT_005858f8 == 0) {
          return (int *)0x0;
        }
        iVar3 = FUN_00555d41(param_2);
      } while (iVar3 != 0);
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}

