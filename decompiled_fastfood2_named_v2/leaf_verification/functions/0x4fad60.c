// rea decompile_all
// name: FUN_004fad60
// address: 0x4fad60
// body: available
// range: 0x4fad60-0x4fb056 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void FUN_004fad60(int *param_1)

{
  char cVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  undefined2 uVar8;
  undefined2 uVar9;
  uint local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  piVar2 = param_1;
  local_c = FUN_004f9a20(1,*(int *)(*param_1 + 0x24),(int)param_1,&local_24,&local_28,-1,-1);
  local_10 = FUN_004f9a20(2,*(int *)(*param_1 + 0x24),(int)param_1,&local_24,&local_28,4,4);
  if (local_10 == -1) {
    NoOp_Stub();
  }
  FUN_004f9a20(5,*(int *)(*param_1 + 0x24),(int)param_1,&local_24,&local_28,-1,-1);
  Object_GetRect100((void *)param_1[4],&local_14,&local_20,&local_18,&local_1c);
  param_1 = local_18;
  if ((int)local_18 < local_1c) {
    piVar6 = piVar2 + -10;
    do {
      iVar7 = 0;
      iVar5 = local_14;
      if (local_14 < local_20) {
        do {
          cVar1 = *(char *)(iVar7 + 0x50 + (int)piVar6);
          uVar8 = (undefined2)iVar5;
          uVar9 = SUB42(param_1,0);
          if (cVar1 == 'd') {
            iVar4 = FUN_004f9a20(4,*(int *)(*piVar2 + 0x24),(int)piVar2,&local_24,&local_28,1,1);
            FUN_004f9df0(piVar2,iVar4,uVar8,uVar9,2,1,0);
          }
          else if (cVar1 == 's') {
            if (((*(char *)(iVar7 + 0x51 + (int)piVar6) == 's') &&
                (*(char *)(iVar7 + 0xa0 + (int)piVar6) == 's')) &&
               (*(char *)(iVar7 + 0xa1 + (int)piVar6) == 's')) {
              uVar3 = FUN_0054f9e3((int)*(char *)(iVar7 + 0x52 + (int)piVar6));
              if (uVar3 == 0x54) {
LAB_004faee6:
                uVar3 = 1;
              }
              else {
                uVar3 = FUN_0054f9e3((int)*(char *)(iVar7 + 0xf0 + (int)piVar6));
                if (uVar3 == 0x54) {
LAB_004faf06:
                  uVar3 = 0;
                }
                else {
                  uVar3 = FUN_0054f9e3((int)*(char *)(iVar7 + 0x4f + (int)piVar6));
                  if (uVar3 == 0x54) {
LAB_004faf1d:
                    uVar3 = 3;
                  }
                  else {
                    uVar3 = FUN_0054f9e3((int)*(char *)(iVar7 + (int)piVar6));
                    if (((uVar3 == 0x54) || (*(char *)(iVar7 + (int)piVar6) == 'W')) ||
                       (*(char *)(iVar7 + (int)piVar6) == '@')) {
                      uVar3 = 2;
                    }
                    else {
                      if ((*(char *)(iVar7 + 0xf0 + (int)piVar6) == 'W') ||
                         (*(char *)(iVar7 + 0xa0 + (int)piVar6) == '@')) goto LAB_004faf06;
                      if ((*(char *)(iVar7 + 0x52 + (int)piVar6) == 'W') ||
                         (*(char *)(iVar7 + 0x51 + (int)piVar6) == '@')) goto LAB_004faf1d;
                      cVar1 = *(char *)(iVar7 + 0x4f + (int)piVar6);
                      if ((cVar1 == 'W') || (cVar1 == '@')) goto LAB_004faee6;
                      uVar3 = _rand();
                      uVar3 = uVar3 & 3;
                    }
                  }
                }
              }
              FUN_004f9c90(local_c,&local_8,&local_4);
              if (-1 < local_8) {
                iVar4 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),local_8,(int *)0x0);
                FUN_004f9df0(piVar2,(int)*(short *)(iVar4 + (uVar3 + (local_4 * 3 + 0x1e) * 2) * 2),
                             uVar8,uVar9,2,1,1);
              }
            }
          }
          else if (((((cVar1 == 't') && (*(char *)(iVar7 + 0xa0 + (int)piVar6) == 't')) &&
                    (*(char *)(iVar7 + (int)piVar6) == 't')) &&
                   ((*(char *)(iVar7 + -0x50 + (int)piVar6) == 't' &&
                    (*(char *)(iVar7 + 0x51 + (int)piVar6) == 't')))) &&
                  ((*(char *)(iVar7 + 0x4f + (int)piVar6) == 't' &&
                   (*(char *)(iVar7 + 0x4e + (int)piVar6) == 't')))) {
            FUN_004f9df0(piVar2,local_10,uVar8,uVar9,2,1,1);
          }
          iVar7 = iVar7 + 1;
          iVar5 = iVar5 + 1;
        } while (iVar5 < local_20);
      }
      piVar6 = piVar6 + 0x14;
      param_1 = (int *)((int)param_1 + 1);
    } while ((int)param_1 < local_1c);
  }
  return;
}

