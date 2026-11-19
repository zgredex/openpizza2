// rea decompile_all
// name: Surface_SaveTga
// address: 0x5377f0
// body: available
// range: 0x5377f0-0x537bf2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4
Surface_SaveTga(uint *param_1,undefined4 param_2,uint param_3,uint *param_4,char param_5,
               undefined4 param_6,undefined2 param_7,undefined2 param_8,char param_9,int param_10,
               int param_11,uint param_12,undefined1 param_13,undefined1 param_14)

{
  ushort uVar1;
  uint uVar2;
  FILE *pFVar3;
  int extraout_ECX;
  int iVar4;
  uint *puVar5;
  uint *puVar6;
  int iVar7;
  int iVar8;
  undefined1 local_res0;
  undefined1 uStack00000015;
  char cStack00000016;
  undefined1 uStack00000017;
  undefined2 uStack0000001e;
  undefined2 uStack00000022;
  undefined1 uStack00000025;
  int in_stack_00010034;
  int in_stack_00010038;
  LPCSTR in_stack_0001003c;
  
  __chkstk(local_res0);
  param_11 = 0;
  pFVar3 = (FILE *)CRT_Fopen(in_stack_0001003c,&DAT_00563114);
  if (pFVar3 == (FILE *)0x0) {
    return 0;
  }
  param_4 = *(uint **)(extraout_ECX + 0x18);
  if (((*(char *)(extraout_ECX + 0x10) == '\x10') && (in_stack_00010034 != 0)) &&
     (*(char *)(in_stack_00010034 + 0x18) != '\0')) {
    iVar7 = *(int *)(extraout_ECX + 8) * *(int *)(extraout_ECX + 4);
    param_4 = operator_new(iVar7 * 2);
    iVar4 = 0;
    if (0 < iVar7) {
      do {
        uVar1 = *(ushort *)(*(int *)(extraout_ECX + 0x18) + iVar4 * 2);
        *(ushort *)((int)param_4 + iVar4 * 2) = uVar1 >> 1 & 0x7fe0 | uVar1 & 0x1f;
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar7);
    }
    param_11 = 1;
  }
  param_9 = *(char *)(extraout_ECX + 0x10);
  param_5 = '\0';
  if (param_9 != '\b') {
    param_6._1_2_ = 0;
    param_6._3_1_ = 0;
    cStack00000016 = (-(in_stack_00010038 != 0) & 8U) + 2;
  }
  else {
    param_6._1_2_ = 0x100;
    param_6._3_1_ = 0x18;
    cStack00000016 = (-(in_stack_00010038 != 0) & 8U) + 1;
  }
  uStack00000015 = param_9 == '\b';
  param_8 = *(undefined2 *)(extraout_ECX + 4);
  uStack00000022 = *(undefined2 *)(extraout_ECX + 8);
  uStack00000017 = 0;
  param_6._0_1_ = 0;
  param_7 = 0;
  uStack0000001e = 0;
  uStack00000025 = 0x20;
  CRT_FwriteLocked(&param_5,1,0x12,(int *)pFVar3);
  if (*(char *)(extraout_ECX + 0x10) == '\b') {
    Palette_WriteToStream(*(void **)(extraout_ECX + 0x14),(int *)pFVar3);
  }
  param_1 = param_4;
  if (-1 < *(int *)(extraout_ECX + 8) + -1) {
    puVar6 = param_4;
    param_10 = *(int *)(extraout_ECX + 8);
    do {
      iVar4 = 0;
      if (0 < *(int *)(extraout_ECX + 4)) {
        param_1 = &param_12;
        puVar5 = puVar6;
        do {
          puVar6 = puVar5;
          switch(*(byte *)(extraout_ECX + 0x10)) {
          case 8:
            param_3 = (uint)(byte)*puVar5;
            puVar6 = (uint *)((int)puVar5 + 1);
            break;
          case 0xf:
          case 0x10:
            param_3 = (uint)(ushort)*puVar5;
            puVar6 = (uint *)((int)puVar5 + 2);
            break;
          case 0x18:
            puVar6 = (uint *)((int)puVar5 + 3);
            param_3 = (uint)(uint3)*puVar5;
            break;
          case 0x20:
            param_3 = *puVar5;
            puVar6 = puVar5 + 1;
          }
          if (in_stack_00010038 == 0) {
            CRT_FwriteLocked(&local_res0,1,(int)(*(byte *)(extraout_ECX + 0x10) + 1) >> 3,
                             (int *)pFVar3);
          }
          else {
            *param_1 = param_3;
          }
          iVar4 = iVar4 + 1;
          param_1 = param_1 + 1;
          puVar5 = puVar6;
        } while (iVar4 < *(int *)(extraout_ECX + 4));
        param_1 = puVar6;
      }
      if (in_stack_00010038 != 0) {
        iVar4 = *(int *)(extraout_ECX + 4);
        iVar7 = 0;
        if (0 < iVar4) {
          do {
            iVar8 = iVar7 + 1;
            if (iVar8 < iVar4) {
              if (iVar7 + 2 < iVar4) {
                uVar2 = (&param_12)[iVar7];
                if ((uVar2 == *(uint *)(&param_13 + iVar7 * 4)) &&
                   (uVar2 == *(uint *)(&param_14 + iVar7 * 4))) {
                  if (iVar8 < iVar4) {
                    puVar6 = &param_12 + iVar8;
                    do {
                      if ((iVar7 + 0x80 <= iVar8) || (*puVar6 != uVar2)) break;
                      iVar8 = iVar8 + 1;
                      puVar6 = puVar6 + 1;
                    } while (iVar8 < iVar4);
                  }
                  CRT_Fputc((iVar8 - iVar7) - 1U | 0x80,(int *)pFVar3);
                  CRT_FwriteLocked(&local_res0,1,(int)(*(byte *)(extraout_ECX + 0x10) + 1) >> 3,
                                   (int *)pFVar3);
                  iVar7 = iVar8;
                }
                else {
                  if (iVar8 < iVar4) {
                    puVar6 = &param_12 + iVar8;
                    do {
                      if ((iVar7 + 0x80 <= iVar8) ||
                         ((*puVar6 == puVar6[1] && (*puVar6 == puVar6[2])))) break;
                      iVar8 = iVar8 + 1;
                      puVar6 = puVar6 + 1;
                    } while (iVar8 < iVar4);
                  }
                  iVar4 = iVar8 - iVar7;
                  CRT_Fputc(iVar4 - 1,(int *)pFVar3);
                  if (iVar7 < iVar8) {
                    iVar7 = iVar7 + iVar4;
                    do {
                      CRT_FwriteLocked(&local_res0,1,(int)(*(byte *)(extraout_ECX + 0x10) + 1) >> 3,
                                       (int *)pFVar3);
                      iVar4 = iVar4 + -1;
                    } while (iVar4 != 0);
                  }
                }
                puVar6 = param_1;
              }
              else {
                CRT_Fputc(1,(int *)pFVar3);
                CRT_FwriteLocked(&local_res0,1,(int)(*(byte *)(extraout_ECX + 0x10) + 1) >> 3,
                                 (int *)pFVar3);
                CRT_FwriteLocked(&local_res0,1,(int)(*(byte *)(extraout_ECX + 0x10) + 1) >> 3,
                                 (int *)pFVar3);
                iVar7 = *(int *)(extraout_ECX + 4);
              }
            }
            else {
              CRT_Fputc(0,(int *)pFVar3);
              CRT_FwriteLocked(&local_res0,1,(int)(*(byte *)(extraout_ECX + 0x10) + 1) >> 3,
                               (int *)pFVar3);
              iVar7 = *(int *)(extraout_ECX + 4);
            }
            iVar4 = *(int *)(extraout_ECX + 4);
          } while (iVar7 < iVar4);
        }
      }
      param_10 = param_10 + -1;
    } while (param_10 != 0);
    param_10 = 0;
  }
  CRT_Fclose(pFVar3);
  if (param_11 != 0) {
    Mem_Free(param_4);
  }
  return 1;
}

