// rea decompile_all
// name: FUN_004fb170
// address: 0x4fb170
// body: available
// range: 0x4fb170-0x4fb5c3 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4
FUN_004fb170(undefined4 param_1,char *param_2,char *param_3,char *param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,undefined4 param_8,int param_9,int param_10,
            int param_11,int param_12,int param_13,int param_14)

{
  void *pvVar1;
  void *this;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int iVar9;
  int iStack000000f4;
  void *in_stack_000019f4;
  int *in_stack_00001a04;
  char cVar10;
  undefined1 uVar11;
  undefined1 uStack_9;
  undefined1 *local_8;
  int local_4;
  
  pvVar1 = ExceptionList;
  local_4 = -1;
  local_8 = &LAB_0055a12e;
  uVar11 = SUB41(ExceptionList,0);
  ExceptionList = (void *)((int)register0x00000010 + -0xc);
  __chkstk(uVar11);
  in_stack_00001a04[4] = *(int *)(*in_stack_00001a04 + 0x14e0);
  in_stack_00001a04[1] = *(int *)(*in_stack_00001a04 + 0x38);
  this = operator_new(0x1c);
  if (this == (void *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    puVar2 = FUN_004013a0(this,0x28);
  }
  in_stack_00001a04[3] = (int)puVar2;
  Game_GetPlayerBySlot(DAT_0057c670,*(int *)(*in_stack_00001a04 + 0x30));
  FUN_004f96e0((int)in_stack_00001a04);
  iVar9 = 0;
  do {
    piVar7 = in_stack_00001a04 + 10;
    piVar8 = &iStack000000f4;
    for (iVar5 = 0x640; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar8 = *piVar7;
      piVar7 = piVar7 + 1;
      piVar8 = piVar8 + 1;
    }
    iVar5 = FUN_00500830((int)in_stack_00001a04);
    if (iVar5 == 0) {
      ExceptionList = in_stack_000019f4;
      return 3;
    }
    if (in_stack_00001a04[2] == 0) break;
    local_4 = 0;
    piVar7 = in_stack_00001a04 + 10;
    iVar5 = 0x50;
    do {
      iVar6 = 0;
      do {
        switch(*(undefined1 *)((int)piVar7 + iVar6)) {
        case 0x53:
        case 0x73:
          break;
        case 0x54:
        case 0x74:
          local_4 = local_4 + 1;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < 0x50);
      piVar7 = piVar7 + 0x14;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
    if (in_stack_00001a04[1] * 6 + 10 <= local_4) break;
    if (iVar9 < 0x13) {
      piVar7 = &iStack000000f4;
      piVar8 = in_stack_00001a04 + 10;
      for (iVar5 = 0x640; iVar5 != 0; iVar5 = iVar5 + -1) {
        *piVar8 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar8 = piVar8 + 1;
      }
    }
    iVar9 = iVar9 + 1;
  } while (iVar9 < 0x14);
  Object_GetRect100((void *)in_stack_00001a04[4],&param_8,&param_7,&param_6,&param_5);
  if (in_stack_00001a04[2] != 0) {
    iVar9 = 1;
    if (in_stack_00001a04[1] == 2) {
      iVar9 = 2;
    }
    FUN_004fab10(in_stack_00001a04,5,'-',iVar9);
    if (in_stack_00001a04[2] != 0) {
      FUN_004fad60(in_stack_00001a04);
      uVar3 = FUN_0047c830(*in_stack_00001a04);
      FUN_004facb0(in_stack_00001a04,uVar3);
      FUN_004fb060(in_stack_00001a04,*(int *)(*in_stack_00001a04 + 0x24));
      iVar9 = *(int *)(*in_stack_00001a04 + 0x24);
      if (iVar9 == 0) {
        uVar3 = FUN_004034b0(10);
        if (0 < (int)uVar3) {
          do {
            iVar9 = FUN_004f9a20(3,4,(int)in_stack_00001a04,(int *)&local_8,
                                 (uint *)((int)register0x00000010 + -0xc),2,2);
            if (iVar9 != -1) {
              piVar7 = &param_10;
              piVar8 = &param_9;
              uVar4 = FUN_004034b0((uint)pvVar1);
              FUN_004897c0(DAT_0057c670,(int)local_8,uVar4,piVar8,piVar7);
              FUN_004f9ee0(in_stack_00001a04,6,4,(int *)s_aa_aa_00572154,(int)&param_9,1,1,' ');
            }
            uVar3 = uVar3 - 1;
          } while (uVar3 != 0);
        }
      }
      else if (iVar9 == 2) {
        param_2 = s_bb_bb_aaa_aaacc_aaacc_bb_bb_005720f0;
        param_3 = s_cc_cc_aaa_aaacc_aaacc_bb_bb_0057208c;
        param_4 = s_bb_bb_ccaaa_ccaaa_aaa_cc_cc_00572028;
        uVar3 = _rand();
        iVar9 = (uVar3 & 1) + 1;
        if (iVar9 != 0) {
          do {
            FUN_004f9a20(4,4,(int)in_stack_00001a04,(int *)&local_8,
                         (uint *)((int)register0x00000010 + -0xc),3,3);
            piVar7 = &param_10;
            piVar8 = &param_9;
            uVar3 = FUN_004034b0((uint)pvVar1);
            FUN_004897c0(DAT_0057c670,(int)local_8,uVar3,piVar8,piVar7);
            FUN_004f9a20(3,4,(int)in_stack_00001a04,(int *)&local_8,
                         (uint *)((int)register0x00000010 + -0xc),2,2);
            piVar7 = &param_12;
            piVar8 = &param_11;
            uVar3 = FUN_004034b0((uint)pvVar1);
            FUN_004897c0(DAT_0057c670,(int)local_8,uVar3,piVar8,piVar7);
            FUN_004f9a20(3,4,(int)in_stack_00001a04,(int *)&local_8,
                         (uint *)((int)register0x00000010 + -0xc),2,2);
            piVar7 = &param_14;
            piVar8 = &param_13;
            uVar3 = FUN_004034b0((uint)pvVar1);
            FUN_004897c0(DAT_0057c670,(int)local_8,uVar3,piVar8,piVar7);
            cVar10 = ' ';
            iVar6 = 1;
            piVar7 = &param_9;
            iVar5 = 0;
            uVar3 = FUN_004034b0(3);
            FUN_004f9ee0(in_stack_00001a04,9,0xb,(int *)(&param_2)[uVar3],(int)piVar7,iVar5,iVar6,
                         cVar10);
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
      else if (iVar9 == 3) {
        uVar3 = _rand();
        iVar9 = (uVar3 & 1) + 1;
        if (iVar9 != 0) {
          do {
            FUN_004f9a20(4,3,(int)in_stack_00001a04,(int *)&local_8,
                         (uint *)((int)register0x00000010 + -0xc),3,3);
            piVar7 = &param_10;
            piVar8 = &param_9;
            uVar3 = FUN_004034b0((uint)pvVar1);
            FUN_004897c0(DAT_0057c670,(int)local_8,uVar3,piVar8,piVar7);
            FUN_004f9a20(3,4,(int)in_stack_00001a04,(int *)&local_8,
                         (uint *)((int)register0x00000010 + -0xc),2,2);
            piVar7 = &param_12;
            piVar8 = &param_11;
            uVar3 = FUN_004034b0((uint)pvVar1);
            FUN_004897c0(DAT_0057c670,(int)local_8,uVar3,piVar8,piVar7);
            FUN_004f9ee0(in_stack_00001a04,0xb,7,(int *)s_bbaaa_bbaaabb_aaabb_00571fd8,(int)&param_9
                         ,0,1,' ');
            iVar9 = iVar9 + -1;
          } while (iVar9 != 0);
        }
      }
    }
  }
  ExceptionList = in_stack_000019f4;
  return 1;
}

