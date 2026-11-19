// rea decompile_all
// name: PosterAdvertisingPage_Update
// address: 0x4c3a40
// body: available
// range: 0x4c3a40-0x4c3c66 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __cdecl PosterAdvertisingPage_Update(void *param_1)

{
  void *this;
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_2c [32];
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Refreshes the poster-advertising page. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558afb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  StringTable_SortIndexArray(&DAT_0057d740,&DAT_0057d8a8);
  iVar2 = *(int *)((int)DAT_0057c670 + 0x218);
  this = *(void **)((int)DAT_0057c670 + *(int *)((int)DAT_0057c670 + 0x2ec) * 4 + 0x200);
  DAT_0057da10 = Game_FindNearestObjectByPosition(this,iVar2);
  DAT_0057da18 = *(undefined4 *)(DAT_0057da10 + 0x3c);
  Gadget_SetText(param_1,0x1f44,DAT_0057da10 + 4);
  DAT_0057da14 = (void *)Game_FindPlanByTarget(this,iVar2);
  if (DAT_0057da14 == (void *)0x0) {
    puVar1 = operator_new(0x30);
    local_4 = 0;
    if (puVar1 == (undefined4 *)0x0) {
      DAT_0057da14 = (void *)0x0;
    }
    else {
      DAT_0057da14 = (void *)GamePlan_Construct(puVar1);
    }
    local_4 = 0xffffffff;
    Game_SetDifficulty(DAT_0057da14,3);
    *(undefined4 *)((int)DAT_0057da14 + 0x2c) = *(undefined4 *)(iVar2 + 0x24);
    *(undefined4 *)((int)DAT_0057da14 + 0xc) = *(undefined4 *)(DAT_0057da10 + 0x3c);
    Gadget_SetText(param_1,0x519,DAT_00582978);
  }
  Gadget_SetText(param_1,0x512,
                 *(undefined4 *)
                  (&DAT_00583504 + (&DAT_0057d8a8)[*(int *)((int)DAT_0057da14 + 0x10)] * 4));
  Window_GadgetNotify_Button_SetState(param_1,0x43a,*(uint *)((int)DAT_0057da14 + 0x14) & 8);
  Window_GadgetNotify_Button_SetState(param_1,0x43b,*(uint *)((int)DAT_0057da14 + 0x14) & 4);
  Window_GadgetNotify_Button_SetState(param_1,0x43c,*(uint *)((int)DAT_0057da14 + 0x14) & 2);
  Window_GadgetNotify_Button_SetState(param_1,0x43d,*(uint *)((int)DAT_0057da14 + 0x14) & 1);
  if (*(int *)((int)DAT_0057da14 + 0x18) == 0) {
    uVar3 = DAT_00580f68;
  }
  else {
    DAT_0057da1c = Lookup_BytePlusOne(*(int *)((int)DAT_0057da14 + 0x18));
    uVar3 = *(undefined4 *)(&DAT_00583540 + *(int *)((int)DAT_0057da14 + 0x18) * 4);
  }
  Gadget_SetText(param_1,0x514,uVar3);
  if (*(int *)((int)DAT_0057da14 + 0x1c) == -1) {
    iVar2 = DAT_00582634;
  }
  else {
    iVar2 = Game_GetPlayerBySlot(DAT_0057c670,*(int *)((int)DAT_0057da14 + 0x1c));
    iVar2 = iVar2 + 8;
  }
  Gadget_SetText(param_1,0x517,iVar2);
  String_Format(local_2c,&DAT_005683a4,0xdac);
  Window_GadgetNotify_Text_SetText(param_1,0x51b,local_2c);
  GamePlan_UpdateEffectBars(param_1,(int)this);
  ExceptionList = local_c;
  return;
}

