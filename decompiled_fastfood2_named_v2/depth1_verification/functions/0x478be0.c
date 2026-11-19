// rea decompile_all
// name: FUN_00478be0
// address: 0x478be0
// body: available
// range: 0x478be0-0x478daa inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


int __fastcall FUN_00478be0(void *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int *piVar3;
  int iVar4;
  int iVar5;
  ulonglong uVar6;
  longlong lVar7;
  
  if (*(int *)((int)param_1 + 0x1718) == 0) {
    FUN_00478db0();
    param_2 = extraout_EDX;
  }
  uVar6 = FUN_0047c8a0((int)param_1,param_2);
  lVar7 = FUN_00479db0((int)param_1,(uint)(uVar6 >> 0x20));
  iVar5 = 0;
  iVar4 = 0;
  piVar3 = (int *)((int)param_1 + 0x17fc);
  do {
    if ((param_3 == -1) || (iVar4 == param_3)) {
      Game_InitStatBaselines(param_1,iVar4,'\0');
      iVar1 = (int)(((uint)uVar6 & 0xff) - (&DAT_005677f8)[iVar4]) >> 3;
      iVar2 = (int)lVar7 - (&DAT_00567818)[iVar4];
      if (iVar2 < 0) {
        iVar1 = iVar1 + (iVar2 >> 1);
      }
      iVar2 = iVar1 + *piVar3;
      if (piVar3[-8] < iVar1 + *piVar3) {
        iVar2 = piVar3[-8];
      }
      iVar5 = iVar5 + (piVar3[8] + iVar2 * 3 >> 2) + *(int *)((int)param_1 + 0x187c) * -10;
    }
    iVar4 = iVar4 + 1;
    piVar3 = piVar3 + 1;
  } while (iVar4 < 8);
  if (param_3 == -1) {
    iVar5 = iVar5 >> 3;
  }
  iVar4 = *(int *)((int)param_1 + 0x30);
  iVar1 = FUN_00482820((int)DAT_0057c670);
  if (iVar4 == iVar1) {
    iVar1 = *(int *)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8);
    if (*(int *)(iVar1 + 0x1c8) != 0) {
      iVar5 = (iVar5 * 0x5f) / 100;
    }
    if (*(int *)(iVar1 + 0xe4) != 0) {
      iVar5 = (iVar5 * 0x6e) / 100;
    }
  }
  iVar4 = FUN_00488be0(DAT_0057c670,iVar4);
  iVar4 = FUN_004ddcc0(iVar4);
  iVar5 = (((*(int *)(iVar4 + 0x5c) + *(int *)(iVar4 + 0x44)) * -3 + 100) * iVar5) / 100;
  iVar4 = FUN_00482820((int)DAT_0057c670);
  if (*(int *)((int)param_1 + 0x30) == iVar4) {
    iVar4 = 0;
    piVar3 = *(int **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xac);
    do {
      piVar3 = piVar3 + 1;
      if (*piVar3 == 0xf) {
        iVar1 = *(int *)((int)param_1 + 0x1a04);
        if (iVar1 == 0) {
          return 0;
        }
        if (iVar1 == 4) {
          return 0;
        }
        if (iVar1 == 2) {
          return 0;
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
  }
  if (iVar5 < 0) {
    return 0;
  }
  iVar4 = 100;
  if (iVar5 < 0x65) {
    iVar4 = iVar5;
  }
  return iVar4;
}

