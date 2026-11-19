// rea decompile_all
// name: FUN_00488110
// address: 0x488110
// body: available
// range: 0x488110-0x488a01 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall FUN_00488110(void *this,int *param_1,undefined4 *param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_14;
  int local_10;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005582ad;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(undefined4 *)((int)this + 0x2e24) = 0;
  *param_2 = s_begin_005682e4;
  FUN_00487310((int)this);
  FUN_0054cbc1(param_1,&local_2c,0x20);
  if (local_10 != 0) {
    FUN_0054cbc1(param_1,&DAT_0057c668,4);
    *param_2 = s_version_conflict_005682d0;
    if (0x28 < DAT_0057c668) {
      *param_2 = s_gamedata_005682c4;
      FUN_0054cbc1(param_1,&DAT_0057bb20,0x5b8);
      FUN_0054cbc1(param_1,(int)this + 0x298,0x20);
      FUN_0054cbc1(param_1,(int)this + 0x2b8,0x20);
      FUN_0054cbc1(param_1,(int)this + 0x2d8,4);
      FUN_0054cbc1(param_1,(int)this + 0x2dc,4);
      FUN_0054cbc1(param_1,(int)this + 0x2ec,4);
      FUN_0054cbc1(param_1,(int)this + 0x2f0,4);
      FUN_0054cbc1(param_1,(int)this + 0x2f4,4);
      FUN_0054cbc1(param_1,(int)this + 0x2e8,4);
      FUN_0054cbc1(param_1,(int)this + 0x2f8,4);
      FUN_0054cbc1(param_1,(int)this + 0x33c,4);
      FUN_0054cbc1(param_1,(int)this + 0x348,4);
      FUN_0054cbc1(param_1,(int)this + 0x34c,4);
      FUN_0054cbc1(param_1,(int)this + 0x350,4);
      FUN_0054cbc1(param_1,(int)this + 0x344,4);
      FUN_0054cbc1(param_1,(int)this + 0x354,4);
      FUN_0054cbc1(param_1,(int)this + 0x340,4);
      FUN_0054cbc1(param_1,(int)this + 0x364,4);
      FUN_0054cbc1(param_1,(int)this + 0x368,4);
      FUN_0054cbc1(param_1,(int)this + 0x360,4);
      FUN_0054cbc1(param_1,(int)this + 0x358,4);
      FUN_0054cbc1(param_1,(int)this + 0x35c,4);
      FUN_0054cbc1(param_1,(int)this + 0x2d90,4);
      FUN_00499570(param_1);
      FUN_00498100(param_1);
      FUN_0049acd0(param_1);
      FUN_0049b460(param_1);
      FUN_004b3ca0(param_1);
      FUN_004aa6c0(param_1);
      FUN_004ac3c0(param_1);
      FUN_004b0d40(param_1);
      FUN_004919b0(param_1);
      FUN_00492230(param_1);
      FUN_004900a0(param_1);
      FUN_004c0d40(param_1);
      *(undefined4 *)((int)this + 0x2e24) = 1;
      FUN_004dd590(*(void **)((int)this + 0x94),param_1);
      FUN_0054b230((void *)((int)this + 0x304),param_1);
      FUN_004eab00(DAT_0057c5cc,param_1);
      FUN_0054cbc1(param_1,&local_3c,4);
      local_40 = 0;
      if (0 < local_3c) {
        do {
          FUN_0054cbc1(param_1,&local_38,4);
          pvVar1 = operator_new(0x10178);
          local_4 = 0;
          if (pvVar1 == (void *)0x0) {
            puVar2 = (undefined4 *)0x0;
          }
          else {
            puVar2 = FUN_004eb280(pvVar1,DAT_0057c5cc,param_1);
          }
          local_4 = 0xffffffff;
          Game_RegisterWorldObject(DAT_0057c5cc,puVar2,local_38);
          FUN_004880c0(param_1,local_10);
          local_40 = local_40 + 1;
        } while (local_40 < local_3c);
      }
      *param_2 = s_Fehler_beim_Laden__Character__005682a0;
      iVar3 = Stream_GetReadPosition(param_1);
      if (((local_28 == iVar3) && (FUN_0054cbc1(param_1,&local_3c,4), local_3c < 1000000)) &&
         (-1 < local_3c)) {
        local_40 = 0;
        if (0 < local_3c) {
          do {
            FUN_0054cbc1(param_1,&local_38,4);
            pvVar1 = operator_new(0x828);
            local_4 = 1;
            if (pvVar1 == (void *)0x0) {
              puVar2 = (undefined4 *)0x0;
            }
            else {
              puVar2 = FUN_004d36f0(pvVar1,param_1);
            }
            local_4 = 0xffffffff;
            FUN_004015b0((void *)((int)this + 0x20),puVar2,local_38);
            if ((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0) {
              ExceptionList = local_c;
              return 0;
            }
            FUN_004880c0(param_1,local_10);
            local_40 = local_40 + 1;
          } while (local_40 < local_3c);
        }
        iVar3 = Stream_GetReadPosition(param_1);
        if (local_24 == iVar3) {
          *param_2 = s_Fehler_beim_Laden__City__00568284;
          FUN_0054cbc1(param_1,&local_3c,4);
          local_40 = 0;
          if (0 < local_3c) {
            do {
              pvVar1 = operator_new(0x1158);
              local_4 = 2;
              if (pvVar1 == (void *)0x0) {
                puVar2 = (undefined4 *)0x0;
              }
              else {
                puVar2 = FUN_004d4800(pvVar1,param_1);
              }
              local_4 = 0xffffffff;
              FUN_004014b0((void *)((int)this + 4),puVar2);
              if ((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0) {
                ExceptionList = local_c;
                return 0;
              }
              FUN_004880c0(param_1,local_10);
              local_40 = local_40 + 1;
            } while (local_40 < local_3c);
          }
          iVar3 = Stream_GetReadPosition(param_1);
          if (local_2c == iVar3) {
            *param_2 = s_Fehler_beim_Laden__Person__00568264;
            FUN_0054cbc1(param_1,&local_3c,4);
            if ((local_3c < 0x186a1) && (-1 < local_3c)) {
              local_40 = 0;
              if (0 < local_3c) {
                do {
                  FUN_0054cbc1(param_1,&local_38,4);
                  pvVar1 = operator_new(0x16c);
                  local_4 = 3;
                  if (pvVar1 == (void *)0x0) {
                    puVar2 = (undefined4 *)0x0;
                  }
                  else {
                    puVar2 = FUN_005049a0(pvVar1,param_1);
                  }
                  local_4 = 0xffffffff;
                  FUN_004015b0((void *)((int)this + 0x3c),puVar2,local_38);
                  puVar2[0x59] = local_38;
                  if ((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0) {
                    ExceptionList = local_c;
                    return 0;
                  }
                  FUN_004880c0(param_1,local_10);
                  local_40 = local_40 + 1;
                } while (local_40 < local_3c);
              }
              iVar3 = Stream_GetReadPosition(param_1);
              if (local_14 == iVar3) {
                *param_2 = s_Fehler_beim_Laden__Car__00568248;
                FUN_0054cbc1(param_1,&local_3c,4);
                if ((local_3c < 0x186a1) && (-1 < local_3c)) {
                  local_40 = 0;
                  if (0 < local_3c) {
                    do {
                      FUN_0054cbc1(param_1,&local_38,4);
                      pvVar1 = operator_new(0x14);
                      local_4 = 4;
                      if (pvVar1 == (void *)0x0) {
                        puVar2 = (undefined4 *)0x0;
                      }
                      else {
                        puVar2 = FUN_004d3260(pvVar1,param_1);
                      }
                      local_4 = 0xffffffff;
                      FUN_004015b0((void *)((int)this + 0x58),puVar2,local_38);
                      if ((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0) {
                        ExceptionList = local_c;
                        return 0;
                      }
                      local_40 = local_40 + 1;
                    } while (local_40 < local_3c);
                  }
                  FUN_004880c0(param_1,local_10);
                  iVar3 = Stream_GetReadPosition(param_1);
                  if (local_1c == iVar3) {
                    *param_2 = s_Player_00568240;
                    local_40 = 0;
                    do {
                      FUN_0054cbc1(param_1,&local_34,4);
                      if (local_34 == 0) {
                        *(undefined4 *)((int)this + local_40 * 4 + 0x224) = 0;
                      }
                      else {
                        pvVar1 = operator_new(0xb0);
                        local_4 = 5;
                        if (pvVar1 == (void *)0x0) {
                          puVar2 = (undefined4 *)0x0;
                        }
                        else {
                          puVar2 = FUN_0050e8e0(pvVar1,param_1);
                        }
                        local_4 = 0xffffffff;
                        *(undefined4 **)((int)this + local_40 * 4 + 0x224) = puVar2;
                      }
                      if ((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0) {
                        ExceptionList = local_c;
                        return 0;
                      }
                      FUN_004880c0(param_1,local_10);
                      local_40 = local_40 + 1;
                    } while (local_40 < 6);
                    iVar3 = Stream_GetReadPosition(param_1);
                    if (local_20 == iVar3) {
                      local_40 = 0;
                      *param_2 = s_Fehler_beim_Laden__Company__00568220;
                      do {
                        FUN_0054cbc1(param_1,&local_34,4);
                        if (local_34 == 1) {
                          pvVar1 = operator_new(0x1f0);
                          local_4 = 6;
                          if (pvVar1 == (void *)0x0) {
                            puVar2 = (undefined4 *)0x0;
                          }
                          else {
                            puVar2 = FUN_004ddab0(pvVar1,param_1);
                          }
                          local_4 = 0xffffffff;
                          *(undefined4 **)((int)this + local_40 * 4 + 0x200) = puVar2;
                        }
                        else {
                          *(undefined4 *)((int)this + local_40 * 4 + 0x200) = 0;
                        }
                        if ((*(byte *)(*(int *)(*param_1 + 4) + 8 + (int)param_1) & 6) != 0) {
                          ExceptionList = local_c;
                          return 0;
                        }
                        FUN_004880c0(param_1,local_10);
                        local_40 = local_40 + 1;
                      } while (local_40 < 6);
                      *param_2 = s_Fehler_beim_Laden__Ki__00568204;
                      FUN_004f6dd0(*(void **)((int)this + 0x90),param_1);
                      FUN_0054cbc1(param_1,&local_38,4);
                      if (local_38 == 1) {
                        FUN_0054cbc1(param_1,&local_38,4);
                        FUN_0054cbc1(param_1,&local_40,4);
                        iVar3 = local_40;
                        iVar4 = FUN_00488be0(this,local_38);
                        uVar5 = FUN_004017f0((void *)(iVar4 + 0x148),iVar3,(int *)0x0);
                        *(undefined4 *)((int)this + 0x9c) = uVar5;
                      }
                      else {
                        *(undefined4 *)((int)this + 0x9c) = 0;
                      }
                      FUN_00487a30(this,param_1);
                      FUN_0054cbc1(param_1,&local_30,4);
                      FUN_004880c0(param_1,local_10);
                      if (local_30 == 0x2a) {
                        local_40 = 0;
                        do {
                          iVar3 = FUN_00488be0(this,local_40);
                          if (iVar3 != 0) {
                            iVar4 = 0;
                            if (0 < *(int *)(iVar3 + 0x15c)) {
                              do {
                                pvVar1 = (void *)FUN_004017f0((void *)(iVar3 + 0x148),iVar4,
                                                              (int *)0x0);
                                FUN_00480e30((int)pvVar1);
                                FUN_0047edc0((int)pvVar1);
                                FUN_0047ec70(pvVar1);
                                FUN_0047ed20((int)pvVar1);
                                FUN_0047f100(pvVar1);
                                FUN_004805d0(pvVar1);
                                iVar4 = iVar4 + 1;
                              } while (iVar4 < *(int *)(iVar3 + 0x15c));
                            }
                            FUN_004e3b70(iVar3);
                          }
                          local_40 = local_40 + 1;
                        } while (local_40 < 6);
                        if (*(int *)(*(int *)(*(int *)((int)this + 0x224) + 0xac) + 0xd0) == 0) {
                          FUN_00482f40(this,'\x01');
                        }
                        else {
                          FUN_004830e0((int)this);
                        }
                        FUN_004f6fb0(*(int *)((int)this + 0x90));
                        Sound_InitSpeechVoice(DAT_0057ba0c);
                        FUN_0048cb30((int)this);
                        FUN_0048b600(this);
                        iVar3 = FUN_004017f0((void *)((int)this + 4),*(int *)((int)this + 0x2f4),
                                             (int *)0x0);
                        FUN_004dd090(iVar3);
                        ExceptionList = local_c;
                        return 1;
                      }
                      *param_2 = s_Fehler_beim_Laden__wrong_file_si_005681dc;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  ExceptionList = local_c;
  return 0;
}

