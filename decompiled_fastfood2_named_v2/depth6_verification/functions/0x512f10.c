// rea decompile_all
// name: FUN_00512f10
// address: 0x512f10
// body: available
// range: 0x512f10-0x5130ff inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall FUN_00512f10(void *param_1)

{
  undefined4 *this;
  char *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  float fVar5;
  int iVar6;
  longlong lVar7;
  int *local_14;
  int local_10;
  int local_c;
  int local_8;
  float local_4;
  
  local_c = 0;
  local_14 = (int *)((int)param_1 + 100);
  *(undefined4 *)((int)param_1 + 0x25c) = 0;
  *(undefined4 *)((int)param_1 + 0x260) = 0;
  *(undefined4 *)((int)param_1 + 600) = 0;
  *(undefined4 *)((int)param_1 + 0x248) = 0;
  local_4 = 0.0;
  do {
    fVar5 = local_4;
    if (*local_14 != 0) {
      local_8 = 0;
      do {
        iVar2 = local_8;
        this = FUN_00512750(param_1,SUB41(fVar5,0),(char)local_8,&local_10);
        if ((local_10 < 0x14) && (local_10 != 0)) {
          local_c = local_c + (int)this[5] / 2;
          if (0 < (int)this[5]) {
            do {
              pcVar1 = (char *)FUN_004017f0(this,0,(int *)0x0);
              iVar2 = FUN_00512860(this,(int)pcVar1);
              if (iVar2 != 0) {
                *(int *)((int)param_1 + 0x25c) = *(int *)((int)param_1 + 0x25c) + 1;
                FUN_00512c40(param_1,pcVar1,iVar2);
                iVar2 = FUN_00512820(this,iVar2);
                FUN_004016b0(this,iVar2);
              }
              FUN_004016b0(this,0);
            } while (0 < (int)this[5]);
            iVar2 = local_8;
            fVar5 = local_4;
          }
          if (this != (undefined4 *)0x0) {
            (**(code **)*this)(1);
          }
        }
        else if (this != (undefined4 *)0x0) {
          (**(code **)*this)(1);
        }
        local_8 = iVar2 + 1;
      } while (local_8 < 4);
    }
    local_4 = (float)((int)fVar5 + 1);
    local_14 = local_14 + 1;
  } while ((int)local_4 < 0x56);
  iVar2 = *(int *)((int)param_1 + 0x25c);
  iVar3 = 5;
  local_10 = 0;
  if (0 < iVar2) {
    iVar4 = iVar2;
    do {
      iVar6 = *(int *)((int)param_1 + 0x248) + iVar3;
      iVar3 = iVar3 + 5;
      *(int *)((int)param_1 + 0x248) = iVar6;
      if (0x14 < iVar3) {
        iVar3 = 0x14;
      }
      iVar4 = iVar4 + -1;
      local_10 = iVar2;
    } while (iVar4 != 0);
  }
  iVar2 = *(int *)((int)param_1 + 0x248) + (iVar2 - local_c) * 10;
  *(int *)((int)param_1 + 0x248) = iVar2;
  if (100 < iVar2) {
    *(undefined4 *)((int)param_1 + 0x248) = 100;
  }
  if (*(int *)((int)param_1 + 0x248) < 0) {
    *(undefined4 *)((int)param_1 + 0x248) = 0;
  }
  if (*(int *)((int)param_1 + 0x260) < 1) {
    local_4 = 0.0;
  }
  else {
    local_4 = (float)*(int *)((int)param_1 + 600) / (float)*(int *)((int)param_1 + 0x260);
  }
  lVar7 = FUN_00403850(local_4);
  iVar2 = (int)lVar7 * 100;
  *(int *)((int)param_1 + 600) = iVar2;
  if (100 < iVar2) {
    *(undefined4 *)((int)param_1 + 600) = 100;
  }
  if (*(int *)((int)param_1 + 600) < 0) {
    *(undefined4 *)((int)param_1 + 600) = 0;
  }
  return;
}

