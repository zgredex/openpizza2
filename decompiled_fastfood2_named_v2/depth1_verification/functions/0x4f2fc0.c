// rea decompile_all
// name: FUN_004f2fc0
// address: 0x4f2fc0
// body: available
// range: 0x4f2fc0-0x4f31f3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall FUN_004f2fc0(void *this,int param_1,void *param_2)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  short *psVar5;
  char *pcVar6;
  int iVar7;
  int *piVar8;
  short *psVar9;
  int local_28;
  int local_20 [4];
  undefined4 local_10;
  int local_c;
  int local_8;
  int local_4;
  
  local_20[0] = 1;
  local_10 = 0xffffffff;
  local_20[2] = *(int *)((int)this + 0x1c);
  local_20[1] = local_20[2] + 1;
  local_20[3] = local_20[2] + -1;
  local_c = -1 - local_20[2];
  local_4 = 1 - local_20[2];
  local_8 = -local_20[2];
  EnterCriticalSection((LPCRITICAL_SECTION)((int)this + 0xc0));
  if (param_1 == 0) {
    iVar3 = 0;
    if (0 < *(int *)((int)param_2 + 0x14)) {
      do {
        iVar4 = FUN_004017f0(param_2,iVar3,(int *)0x0);
        sVar1 = *(short *)(*(int *)(iVar4 + 8) + 0x24);
        if ((sVar1 != -1) && (pcVar6 = (char *)FUN_004f0cc0(this,1,(int)sVar1), *pcVar6 != '\x01'))
        {
          *(undefined4 *)(*(int *)(iVar4 + 8) + 0x28) = 1;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)((int)param_2 + 0x14));
    }
    param_1 = 0;
    if (0 < *(int *)((int)param_2 + 0x14)) {
      do {
        iVar3 = FUN_004017f0(param_2,param_1,(int *)0x0);
        sVar1 = *(short *)(*(int *)(iVar3 + 8) + 0x24);
        if ((sVar1 != -1) && (pcVar6 = (char *)FUN_004f0cc0(this,1,(int)sVar1), *pcVar6 != '\x01'))
        {
          piVar8 = local_20;
          local_28 = 8;
          do {
            iVar4 = *(int *)((int)this + 0x4c);
            iVar7 = **(int **)(iVar3 + 8) + *piVar8;
            iVar2 = *(int *)(iVar4 + 8 + iVar7 * 0xc);
            if ((*(int *)(iVar2 + 0x28) != 0) &&
               (pcVar6 = (char *)FUN_004f0cc0(this,1,(int)*(short *)(iVar2 + 0x24)),
               *pcVar6 != '\x01')) {
              Map_LinkCells(this,1,(int)*(short *)(*(int *)(iVar3 + 8) + 0x24),
                            (int)*(short *)(*(int *)(iVar4 + iVar7 * 0xc + 8) + 0x24));
            }
            piVar8 = piVar8 + 1;
            local_28 = local_28 + -1;
          } while (local_28 != 0);
        }
        param_1 = param_1 + 1;
      } while (param_1 < *(int *)((int)param_2 + 0x14));
    }
  }
  else {
    param_1 = 0;
    if (0 < *(int *)((int)param_2 + 0x14)) {
      do {
        iVar3 = FUN_004017f0(param_2,param_1,(int *)0x0);
        sVar1 = *(short *)(*(int *)(iVar3 + 8) + 0x24);
        if (sVar1 != -1) {
          iVar4 = FUN_004f0cc0(this,1,(int)sVar1);
          psVar9 = (short *)(iVar4 + 0x14);
          local_28 = 8;
          *(undefined4 *)(*(int *)(iVar3 + 8) + 0x28) = 0;
          do {
            if (*psVar9 != -1) {
              iVar4 = FUN_004f0cc0(this,1,(int)*psVar9);
              psVar5 = (short *)(iVar4 + 0x14);
              iVar4 = 8;
              do {
                if (*psVar5 == *(short *)(*(int *)(iVar3 + 8) + 0x24)) {
                  *psVar5 = -1;
                }
                psVar5 = psVar5 + 1;
                iVar4 = iVar4 + -1;
              } while (iVar4 != 0);
            }
            *psVar9 = -1;
            psVar9 = psVar9 + 1;
            local_28 = local_28 + -1;
          } while (local_28 != 0);
        }
        param_1 = param_1 + 1;
      } while (param_1 < *(int *)((int)param_2 + 0x14));
    }
  }
  LeaveCriticalSection((LPCRITICAL_SECTION)((int)this + 0xc0));
  return;
}

