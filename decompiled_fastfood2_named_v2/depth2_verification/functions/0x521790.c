// rea decompile_all
// name: UI_DrawLine
// address: 0x521790
// body: available
// range: 0x521790-0x521992 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall
UI_DrawLine(void *this,uint *param_1,int param_2,uint *param_3,int param_4,int *param_5)

{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  
                    /* Depth-2 proposal batch 3. */
  puVar6 = param_1;
  if ((param_5 != (int *)0x0) && ((*param_5 != 1 || (param_5[1] != 0)))) {
    if (param_1 == param_3) {
      iVar7 = *(int *)((int)this + 0x68);
      if ((*(int *)(iVar7 + 4) <= (int)param_1) && ((int)param_1 < *(int *)(iVar7 + 8))) {
        iVar3 = param_4;
        if (param_4 < param_2) {
          iVar3 = param_2;
          param_2 = param_4;
        }
        iVar4 = *(int *)(iVar7 + 0xc);
        if ((iVar4 <= iVar3) && (iVar7 = *(int *)(iVar7 + 0x10), param_2 < iVar7)) {
          if (param_2 < iVar4) {
            param_2 = iVar4;
          }
          if (iVar7 <= iVar3) {
            iVar3 = iVar7 + -1;
          }
          for (; param_2 < iVar3; param_2 = param_2 + 1) {
            FUN_00521dd0(this,param_1,param_2,param_5);
          }
          FUN_00521dd0(this,param_1,param_2,param_5);
          return;
        }
      }
    }
    else if (param_2 == param_4) {
      iVar7 = *(int *)((int)this + 0x68);
      if ((*(int *)(iVar7 + 0xc) <= param_2) && (param_2 < *(int *)(iVar7 + 0x10))) {
        puVar6 = param_3;
        if ((int)param_3 < (int)param_1) {
          puVar6 = param_1;
          param_1 = param_3;
        }
        puVar1 = *(uint **)(iVar7 + 4);
        if (((int)puVar1 <= (int)puVar6) && (iVar7 = *(int *)(iVar7 + 8), (int)param_1 < iVar7)) {
          if ((int)param_1 < (int)puVar1) {
            param_1 = puVar1;
          }
          if (iVar7 <= (int)puVar6) {
            puVar6 = (uint *)(iVar7 + -1);
          }
          for (; (int)param_1 < (int)puVar6; param_1 = (uint *)((int)param_1 + 1)) {
            FUN_00521dd0(this,param_1,param_2,param_5);
          }
          FUN_00521dd0(this,param_1,param_2,param_5);
          return;
        }
      }
    }
    else {
      uVar5 = (int)param_3 - (int)param_1 >> 0x1f;
      iVar7 = ((int)param_3 - (int)param_1 ^ uVar5) - uVar5;
      uVar5 = param_4 - param_2 >> 0x1f;
      iVar3 = (param_4 - param_2 ^ uVar5) - uVar5;
      if ((int)param_1 < (int)param_3) {
        param_1 = (uint *)0x1;
      }
      else {
        param_1 = (uint *)(((int)param_1 <= (int)param_3) - 1);
      }
      if (param_2 < param_4) {
        param_4 = 1;
      }
      else {
        param_4 = (param_2 <= param_4) - 1;
      }
      bVar2 = iVar3 <= iVar7;
      iVar4 = iVar3;
      if (!bVar2) {
        iVar4 = iVar7;
        iVar7 = iVar3;
      }
      iVar3 = -iVar7;
      FUN_00521dd0(this,puVar6,param_2,param_5);
      iVar8 = iVar7;
      if (0 < iVar7) {
        do {
          iVar3 = iVar4 * 2 + iVar3;
          if (-1 < iVar3) {
            if (bVar2) {
              param_2 = param_2 + param_4;
            }
            else {
              puVar6 = (uint *)((int)puVar6 + (int)param_1);
            }
            iVar3 = iVar3 + iVar7 * -2;
          }
          if (bVar2) {
            puVar6 = (uint *)((int)puVar6 + (int)param_1);
          }
          else {
            param_2 = param_2 + param_4;
          }
          FUN_00521dd0(this,puVar6,param_2,param_5);
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
  }
  return;
}

