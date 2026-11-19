// rea decompile_all
// name: Sound_ADPCMDecode
// address: 0x53ea00
// body: available
// range: 0x53ea00-0x53ec50 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl Sound_ADPCMDecode(char *param_1,undefined2 *param_2,uint param_3,short *param_4)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  char cVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  int iVar7;
  int local_18;
  int local_14;
  int local_10;
  char *local_c;
  uint local_8;
  int local_4;
  
                    /* Leaf reversal proposal batch 1. */
  cVar4 = (char)param_4[1];
  local_14 = (int)cVar4;
  local_18 = (int)(char)param_4[3];
  local_c = param_1;
  local_10 = (int)(short)(&DAT_00574a64)[local_14];
  param_1 = (char *)(int)param_4[2];
  local_8 = 0;
  local_4 = (int)(short)(&DAT_00574a64)[local_18];
  param_3 = param_3 >> 3;
  puVar6 = (undefined2 *)(int)*param_4;
  if (param_3 != 0) {
    puVar6 = param_2;
    param_2 = (undefined2 *)(int)*param_4;
    do {
      bVar1 = false;
      iVar7 = 8;
      puVar5 = puVar6;
      do {
        if (bVar1) {
          uVar2 = (int)local_8 >> 4;
        }
        else {
          uVar2 = (uint)*local_c;
          local_c = local_c + 1;
          local_8 = uVar2;
        }
        bVar1 = !bVar1;
        local_14 = local_14 + *(int *)(&DAT_00574a24 + (uVar2 & 0xf) * 4);
        if (local_14 < 0) {
          local_14 = 0;
        }
        else if (0x58 < local_14) {
          local_14 = 0x58;
        }
        iVar3 = 0;
        if ((uVar2 & 4) != 0) {
          iVar3 = local_10;
        }
        if ((uVar2 & 2) != 0) {
          iVar3 = iVar3 + (local_10 >> 1);
        }
        if ((uVar2 & 1) != 0) {
          iVar3 = iVar3 + (local_10 >> 2);
        }
        iVar3 = iVar3 + (local_10 >> 3);
        if ((uVar2 & 8) != 0) {
          iVar3 = -iVar3;
        }
        param_2 = (undefined2 *)((int)param_2 + iVar3);
        if ((int)param_2 < 0x8000) {
          if ((int)param_2 < -0x8000) {
            param_2 = (undefined2 *)0xffff8000;
          }
        }
        else {
          param_2 = (undefined2 *)0x7fff;
        }
        iVar7 = iVar7 + -1;
        local_10 = (int)(short)(&DAT_00574a64)[local_14];
        *puVar5 = (short)param_2;
        puVar5 = puVar5 + 2;
      } while (iVar7 != 0);
      bVar1 = false;
      iVar7 = 8;
      puVar5 = puVar6 + 1;
      do {
        puVar6 = puVar5;
        if (bVar1) {
          uVar2 = (int)local_8 >> 4;
        }
        else {
          uVar2 = (uint)*local_c;
          local_c = local_c + 1;
          local_8 = uVar2;
        }
        bVar1 = !bVar1;
        local_18 = local_18 + *(int *)(&DAT_00574a24 + (uVar2 & 0xf) * 4);
        if (local_18 < 0) {
          local_18 = 0;
        }
        else if (0x58 < local_18) {
          local_18 = 0x58;
        }
        iVar3 = 0;
        if ((uVar2 & 4) != 0) {
          iVar3 = local_4;
        }
        if ((uVar2 & 2) != 0) {
          iVar3 = iVar3 + (local_4 >> 1);
        }
        if ((uVar2 & 1) != 0) {
          iVar3 = iVar3 + (local_4 >> 2);
        }
        iVar3 = iVar3 + (local_4 >> 3);
        if ((uVar2 & 8) != 0) {
          iVar3 = -iVar3;
        }
        param_1 = param_1 + iVar3;
        if ((int)param_1 < 0x8000) {
          if ((int)param_1 < -0x8000) {
            param_1 = (char *)0xffff8000;
          }
        }
        else {
          param_1 = (char *)0x7fff;
        }
        local_4 = (int)(short)(&DAT_00574a64)[local_18];
        *puVar6 = (short)param_1;
        iVar7 = iVar7 + -1;
        puVar5 = puVar6 + 2;
      } while (iVar7 != 0);
      param_3 = param_3 - 1;
      puVar6 = puVar6 + 1;
    } while (param_3 != 0);
    cVar4 = (char)local_14;
    puVar6 = param_2;
  }
  param_2 = puVar6;
  *(char *)(param_4 + 1) = cVar4;
  *(char *)(param_4 + 3) = (char)local_18;
  *param_4 = (short)param_2;
  param_4[2] = (short)param_1;
  return;
}

