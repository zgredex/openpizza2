// rea decompile_all
// name: Branch_UpdateConstruction
// address: 0x506d60
// body: available
// range: 0x506d60-0x50712c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __thiscall Branch_UpdateConstruction(void *this,int param_1)

{
  undefined1 uVar1;
  void *this_00;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar2;
  int iVar3;
  char cVar4;
  int iVar5;
  longlong lVar6;
  
                    /* Advances branch construction and completion stages. */
  this_00 = (void *)Game_GetPlayerSubmapValue
                              (DAT_0057c670,*(int *)(*(int *)((int)this + 0xf4) + 8),
                               *(int *)(*(int *)((int)this + 0xf4) + 0x2c));
  if ((param_1 % 10 == 0) && (0 < *(int *)((int)this + 0x44))) {
    *(int *)((int)this + 0x44) = *(int *)((int)this + 0x44) + -1;
  }
  iVar5 = *(int *)((int)this + 0x30);
  if ((((-1 < iVar5) && (iVar5 < 8)) || (iVar5 == 0xb)) || ((iVar5 == 0xf || (iVar5 == 0x21)))) {
    switch(*(undefined2 *)((int)this + 0x40)) {
    case 2:
      if (*(int *)((int)this + 0x44) == 0) {
        UI_SetChildState(this,3);
        *(short *)((int)this_00 + 0x16d2) = *(short *)((int)this_00 + 0x16d2) + 1;
        Game_GetTimeByMode(this,7);
        Object_SetState(this,9);
        UI_DetachChildRecord((int)this);
        Object_SyncChildState(this,(int)this_00,0x14);
        *(undefined4 *)((int)this + *(int *)((int)this_00 + 0x30) * 4 + 0xac) = 0x14;
        iVar5 = *(int *)((int)this_00 + 0x30);
        iVar3 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
        if (iVar5 == iVar3) {
          UI_AppendCommandIfActive(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x23,1);
          BuildingProject_AdvanceStep
                    (*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x23,0x14);
          return;
        }
      }
      else {
        lVar6 = Math_RoundFloat((float)*(int *)((int)this + 0x44) /
                                ((float)*(int *)((int)this + 0x48) * 0.0625));
        iVar5 = 0x4f - (int)lVar6;
        if (0x4e < iVar5) {
          iVar5 = 0x4e;
        }
        Object_SetChildShort8(this,iVar5);
        uVar1 = Game_GetHourlyValue(this_00,0x28);
        if (CONCAT31(extraout_var,uVar1) == 0) {
          UI_DetachChildRecord((int)this);
          Object_SetState(this,9);
          UI_SetChildState(this,0xffff);
          return;
        }
      }
      break;
    case 3:
    case 8:
    case 0xb:
      if (*(int *)((int)this + 0x44) == 0) {
        UI_SetChildState(this,0xffff);
        return;
      }
      break;
    case 5:
      if (*(int *)((int)this + 0x44) == 0) {
        UI_SetChildState(this,6);
        *(short *)((int)this_00 + 0x16d2) = *(short *)((int)this_00 + 0x16d2) + 1;
        UI_DetachChildRecord((int)this);
        Game_GetTimeByMode(this,7);
        Object_SetState(this,9);
        Object_SyncChildState(this,(int)this_00,0x14);
        *(undefined4 *)((int)this + *(int *)((int)this_00 + 0x30) * 4 + 0xac) = 0x14;
        iVar5 = *(int *)((int)this_00 + 0x30);
        iVar3 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
        if (iVar5 == iVar3) {
          UI_AppendCommandIfActive(*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x23,1);
          BuildingProject_AdvanceStep
                    (*(void **)(*(int *)((int)DAT_0057c670 + 0x224) + 0xa8),0x23,0x14);
          return;
        }
      }
      else {
        lVar6 = Math_RoundFloat((float)*(int *)((int)this + 0x44) /
                                ((float)*(int *)((int)this + 0x48) * 0.0625));
        iVar5 = 0x60 - (int)lVar6;
        if (0x5f < iVar5) {
          iVar5 = 0x5f;
        }
        Object_SetChildShort8(this,iVar5);
        uVar1 = Game_GetHourlyValue(this_00,0xf);
        if (CONCAT31(extraout_var_00,uVar1) == 0) {
          UI_DetachChildRecord((int)this);
          UI_SetChildState(this,0xffff);
          Object_SetState(this,9);
          return;
        }
      }
      break;
    case 9:
      if (*(int *)((int)this + 0x44) == 0) {
        piVar2 = (int *)Game_ApplyObjectEvent((int)this);
        if ((*(int *)((int)this + 0x30) == 0xb) &&
           (iVar5 = *(int *)((int)this + 0x98), iVar3 = Game_GetDateField0C((int)DAT_0057c670),
           iVar3 - iVar5 < 0x18)) {
          Object_SetState(this,0xd);
          UI_DetachChildRecord((int)this);
          UI_SetChildState(this,2);
          Game_GetTimeByMode(this,3);
          UI_SetChildRecordVariant(this,*(int *)((int)this + 0x84) + 0x10);
          return;
        }
        Object_SetState(this,9);
        UI_DetachChildRecord((int)this);
        UI_SetChildState(this,8);
        Game_GetTimeByMode(this,5);
      }
      else {
        lVar6 = Math_RoundFloat((float)*(int *)((int)this + 0x44) /
                                ((float)*(int *)((int)this + 0x48) * 0.11111111));
        iVar5 = 9 - (int)lVar6;
        if (8 < iVar5) {
          iVar5 = 8;
        }
        piVar2 = (int *)Map_GetObjectNeighborCell
                                  (*(void **)((int)this + 0xc4),*(int *)((int)this + 200),
                                   *(int *)((int)this + 0x88));
        cVar4 = (char)iVar5;
        switch(*(undefined4 *)(*(int *)((int)this + 200) + 0xc)) {
        case 0x14:
          *(char *)(piVar2[2] + 0x2c) = cVar4 + '(';
          break;
        case 0x15:
          *(char *)(piVar2[2] + 0x2d) = cVar4 + '\x1e';
          break;
        case 0x16:
          *(char *)(piVar2[2] + 0x2e) = cVar4 + '\x14';
          break;
        case 0x17:
          *(char *)(piVar2[2] + 0x2f) = cVar4 + '\n';
        }
      }
      if (piVar2 != (int *)0x0) {
        UI_DrawCenteredSelectionRect(*(void **)((int)this + 0xc4),piVar2);
      }
    }
  }
  return;
}

