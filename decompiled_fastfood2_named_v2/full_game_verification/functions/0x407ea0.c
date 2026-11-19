// rea decompile_all
// name: Customer_UpdateMovement
// address: 0x407ea0
// body: available
// range: 0x407ea0-0x4080b2 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __thiscall Customer_UpdateMovement(void *this,void *param_1,void *param_2)

{
  void *this_00;
  undefined1 uVar1;
  undefined3 extraout_var;
  int iVar2;
  void *local_4;
  
                    /* Updates a store customer's movement states. */
  this_00 = param_2;
  local_4 = this;
  uVar1 = Object_IsVisibleThisFrame((int)param_2);
  iVar2 = *(int *)((int)this_00 + 0x38);
  if (CONCAT31(extraout_var,uVar1) == 0) {
    switch(iVar2) {
    case 5:
      while( true ) {
        if (*(int *)((int)this_00 + 200) == 0) {
          iVar2 = 0;
        }
        else {
          iVar2 = *(int *)(*(int *)((int)this_00 + 200) + 0x20);
        }
        iVar2 = Game_FindNearestRecordAndAngle(param_1,iVar2,(int *)&local_4,(uint *)&param_2);
        if (iVar2 == 0) break;
        *(int *)((int)this_00 + 0x88) = (int)param_2 + 0x10;
        *(void **)((int)this_00 + 0x8c) = local_4;
        _DAT_0057c610 = Person_WalkToCellOrAbort(this_00,iVar2);
        if (_DAT_0057c610 != 0) {
          Object_SetState(this_00,8);
          *(undefined1 *)((int)this_00 + 0x81) = 0;
          return;
        }
        iVar2 = UI_FindObjectByField20(param_1,*(int *)((int)this_00 + 0x8c));
        if (iVar2 != 0) {
          Game_RemoveMapObjectAtPoint(param_1,iVar2);
        }
      }
      if (*(void **)((int)this + 0x9c) == param_1) {
        Sound_ProcessEvent(DAT_0057ba0c,0xe,0xf,'\x01');
      }
      Object_SetState(this_00,6);
      _DAT_0057c610 = 0;
      Object_SetState(this_00,6);
      *(undefined1 *)((int)this_00 + 0x81) = 1;
      return;
    case 6:
      iVar2 = Array_GetRandomRecord28(*(int *)((int)this_00 + 0xc4));
      if (iVar2 != 0) {
        Person_AdvanceRoute(this_00,iVar2);
        Object_SetState(this_00,7);
        return;
      }
      break;
    case 7:
      UI_ShiftChildRect((int)this_00);
      Object_SetState(this_00,0x2e);
      *(undefined4 *)((int)this + 0x368) = 1;
      return;
    case 8:
      iVar2 = *(int *)((int)this_00 + 0x88);
      Object_SetState(this_00,0x33);
      Object_SetFrame5(this_00,6);
      UI_SetChildRecordVariant(this_00,iVar2);
      Sound_HandleEvent(DAT_0057ba0c,(int)param_1,0x2f);
      return;
    default:
      Person_ResumeRouteOrDetach(this_00);
      return;
    case 0x14:
      Object_SetState(this_00,6);
      return;
    }
  }
  else if (iVar2 == 8) {
    Person_ProcessMoveEvent(this_00);
  }
  else if (((iVar2 == 0x33) && (iVar2 = Person_ProcessMoveEvent(this_00), iVar2 == 0)) &&
          (iVar2 = *(int *)((int)this_00 + 0x94) + -1, *(int *)((int)this_00 + 0x94) = iVar2,
          iVar2 == 0)) {
    iVar2 = UI_FindObjectByField20(param_1,*(int *)((int)this_00 + 0x8c));
    if (iVar2 != 0) {
      Game_RemoveMapObjectAtPoint(param_1,iVar2);
    }
    Object_SetFrame5(this_00,-1);
    UI_DetachChildRecord((int)this_00);
    Object_SetState(this_00,5);
    return;
  }
  return;
}

