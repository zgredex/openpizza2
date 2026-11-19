// rea decompile_all
// name: Player_MissionState_Tick
// address: 0x50efe0
// body: available
// range: 0x50efe0-0x50f4ba inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Player_MissionState_Tick(void *this,int param_1)

{
  void *this_00;
  undefined4 uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  int iVar5;
  undefined4 unaff_EBX;
  undefined4 unaff_EDI;
  bool bVar6;
  longlong lVar7;
  byte local_200 [512];
  
                    /* Ticks a player's mission goals, timers, and briefings. */
  this_00 = (void *)((int)DAT_0057c670 + 0x304);
  if (*(void **)((int)this + 0xac) != (void *)0x0) {
    Mission_TickGoalDeadline(*(void **)((int)this + 0xac),param_1);
  }
  if (*(void **)((int)this + 0xa8) != (void *)0x0) {
    MissionGoal_Evaluate(*(void **)((int)this + 0xa8),param_1);
    pvVar3 = *(void **)((int)this + 0xa8);
    if (*(char *)((int)pvVar3 + 4) == '\0') {
      iVar5 = *(int *)((int)this + 0xac);
      if (((*(char *)(iVar5 + 0xcc) == '\0') && (DAT_0057bb3c._2_1_ == '\x01')) &&
         ((*(int *)(iVar5 + 0xd0) != 0 || (9 < *(int *)(iVar5 + 0xd4))))) {
        if (*(int *)((int)pvVar3 + 0x5c) == 0) {
          AI_InitActionPlan(pvVar3,0xffffffff,0xffffffff,-1,-1,-1,-1,-1);
          uVar1 = UI_Briefing_AddPinnedMessage
                            (this_00,0x21,1,-1,-1,0,DAT_00580d60,DAT_00582e4c,unaff_EDI);
          *(undefined4 *)(*(int *)((int)this + 0xa8) + 100) = uVar1;
          *(undefined1 *)(*(int *)((int)this + 0xa8) + 4) = 1;
        }
        else {
          iVar5 = *(int *)((int)pvVar3 + 0x5c) + -1;
          *(int *)((int)pvVar3 + 0x5c) = iVar5;
          if (iVar5 < 0) {
            *(undefined4 *)((int)pvVar3 + 0x5c) = 0;
          }
        }
      }
    }
    else {
      iVar5 = *(int *)((int)pvVar3 + 0x4c) + -1;
      *(int *)((int)pvVar3 + 0x4c) = iVar5;
      if (iVar5 == 0) {
        if (*(int *)(*(int *)((int)this + 0xa8) + 0x48) == 0x23) {
          UI_AppendCommandIfActive(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x23,-1);
          MissionGoal_HandleEvent(*(void **)((int)this + 0xa8),0x23,-1,-1);
        }
        else {
          Sound_GetChannelObject(this_00,*(int *)(*(int *)((int)this + 0xa8) + 100),1);
          *(undefined1 *)(*(int *)((int)this + 0xa8) + 4) = 0;
          if ((*(int *)((int)DAT_0057c670 + 0x268) != 0) &&
             (*(int *)((int)DAT_0057c670 + 0x278) == 0x11d7)) {
            Game_CloseSelectionDialog((int)DAT_0057c670);
          }
          if (*(char *)(*(int *)((int)this + 0xa8) + 0x60) != '\0') {
            MissionGoal_ApplyFailureEffects(*(int *)((int)this + 0xa8));
            UI_Briefing_AddMessage
                      (this_00,0x24,0,-1,-1,0,DAT_00581c14,(byte *)s__s__s_005729bc,DAT_00582968);
          }
          BuildingProject_ResetState(*(int *)((int)this + 0xa8));
          uVar2 = Random_RangeFast(0x13,0x1d);
          *(uint *)(*(int *)((int)this + 0xa8) + 0x5c) = uVar2;
        }
      }
    }
  }
  pvVar3 = (void *)Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)this + 8));
  bVar6 = pvVar3 == *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  if ((*(int *)((int)this + 0x6c) < 4) &&
     (iVar5 = *(int *)(&DAT_00573054 + *(int *)((int)this + 0x6c) * 4),
     iVar4 = Player_CountObjectsByType(pvVar3,0xffffffff), iVar5 <= iVar4)) {
    iVar5 = *(int *)((int)this + 0x6c) + 1;
    *(int *)((int)this + 0x54) = *(int *)((int)this + 0x54) + 1;
    *(int *)((int)this + 0x6c) = iVar5;
    String_Format(local_200,(byte *)s__s__s_005729bc,*(undefined4 *)(&DAT_00583044 + iVar5 * 4));
    if (bVar6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
    }
  }
  if ((*(int *)((int)this + 0x70) < 4) &&
     (iVar5 = *(int *)(&DAT_00573064 + *(int *)((int)this + 0x70) * 4),
     iVar4 = Game_GetPlayerTotalValue((int)this), iVar5 <= iVar4)) {
    iVar5 = *(int *)((int)this + 0x70) + 1;
    *(int *)((int)this + 0x58) = *(int *)((int)this + 0x58) + 1;
    *(int *)((int)this + 0x70) = iVar5;
    String_Format(local_200,(byte *)s__s__s_005729bc,*(undefined4 *)(&DAT_00583034 + iVar5 * 4));
    if (bVar6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
    }
  }
  iVar5 = *(int *)((int)this + 0x74);
  if ((iVar5 < 4) && (*(int *)(&DAT_00573074 + iVar5 * 4) <= *(int *)((int)this + 0xa0))) {
    *(int *)((int)this + 0x5c) = *(int *)((int)this + 0x5c) + 1;
    *(int *)((int)this + 0x74) = iVar5 + 1;
    String_Format(local_200,(byte *)s__s__s_005729bc,
                  *(undefined4 *)(&DAT_00583004 + (iVar5 + 1) * 4));
    if (bVar6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
    }
  }
  iVar5 = *(int *)((int)this + 0x78);
  if ((iVar5 < 4) && (*(int *)(&DAT_00573084 + iVar5 * 4) <= *(int *)((int)pvVar3 + 0x15c))) {
    *(int *)((int)this + 0x60) = *(int *)((int)this + 0x60) + 1;
    *(int *)((int)this + 0x78) = iVar5 + 1;
    String_Format(local_200,(byte *)s__s__s_005729bc,
                  *(undefined4 *)(&DAT_00582ff4 + (iVar5 + 1) * 4));
    if (bVar6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
    }
  }
  if (*(int *)((int)this + 0x7c) < 4) {
    iVar5 = *(int *)(&DAT_00573094 + *(int *)((int)this + 0x7c) * 4);
    Stats_SumRecordFloatsByType
              ((int)pvVar3,-1,(uint)*(ushort *)(*(int *)((int)DAT_0057c670 + 0x94) + 10));
    lVar7 = __ftol();
    if (iVar5 <= (int)lVar7) {
      iVar5 = *(int *)((int)this + 0x7c) + 1;
      *(int *)((int)this + 100) = *(int *)((int)this + 100) + 1;
      *(int *)((int)this + 0x7c) = iVar5;
      String_Format(local_200,(byte *)s__s__s_005729bc,*(undefined4 *)(&DAT_00583024 + iVar5 * 4));
      if (bVar6) {
        UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EBX);
      }
    }
  }
  iVar5 = *(int *)((int)this + 0x80);
  if ((iVar5 < 4) && (*(int *)(&DAT_005730a4 + iVar5 * 4) <= *(int *)((int)this + 0x38))) {
    *(int *)((int)this + 0x68) = *(int *)((int)this + 0x68) + 1;
    *(int *)((int)this + 0x80) = iVar5 + 1;
    String_Format(local_200,(byte *)s__s__s_005729bc,
                  *(undefined4 *)(&DAT_00583014 + (iVar5 + 1) * 4));
    if (bVar6) {
      UI_Briefing_AddMessage(this_00,0x15,0,1,2,0,DAT_00580bc0,local_200,unaff_EDI);
    }
  }
  return;
}

