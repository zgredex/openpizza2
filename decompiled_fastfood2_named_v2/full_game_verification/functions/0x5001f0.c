// rea decompile_all
// name: Branch_AddAdvertisingPlan
// address: 0x5001f0
// body: available
// range: 0x5001f0-0x5003d4 inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall
Branch_AddAdvertisingPlan(void *this,int param_1,void *param_2,undefined4 param_3)

{
  int iVar1;
  void *this_00;
  int iVar2;
  void *pvVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 *local_4;
  
                    /* Creates and starts an advertising plan for a branch. */
  local_4 = (undefined4 *)0xffffffff;
  puStack_8 = &LAB_0055a1cb;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)param_2 + 0x28),(int *)0x0);
  iVar1 = *(int *)((int)param_2 + 8);
  this_00 = *(void **)((int)this + param_1 * 0x168 + 0x70);
  if (iVar1 != -1) {
    if (iVar1 == *(int *)((int)this + param_1 * 0x168 + 0x40)) {
      ExceptionList = local_c;
      return 1;
    }
    iVar2 = Game_GetCurrentPlayerCompanyName((int)DAT_0057c670);
    if (iVar1 != iVar2) {
      ExceptionList = local_c;
      return 0;
    }
    pvVar3 = (void *)Game_GetPlayerBySlot(DAT_0057c670,iVar1);
    puVar4 = (undefined4 *)Game_FindPlanByTarget(pvVar3,(int)param_2);
    uVar5 = Game_CanAffordWithCurrency(this_00,0x17,(float)(int)puVar4[8] * 10.0,'\x01',0xffffffff);
    if ((char)uVar5 == '\0') {
      ExceptionList = local_c;
      return 0;
    }
    Object_AdjustShortPercent(this,param_1,0x14);
    Company_DeactivatePlanEntry(pvVar3,puVar4,0);
  }
  pvVar3 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)param_2 + 0x28),
                                (int *)0x0);
  puVar4 = (undefined4 *)Game_FindPlanByTarget(this_00,(int)param_2);
  if (puVar4 == (undefined4 *)0x0) {
    puVar6 = operator_new(0x30);
    if (puVar6 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      local_4 = puVar4;
      puVar4 = (undefined4 *)GamePlan_Construct(puVar6);
    }
    local_4 = (undefined4 *)0xffffffff;
    Game_SetDifficulty(puVar4,3);
    puVar4[0xb] = *(undefined4 *)((int)param_2 + 0x24);
    puVar4[3] = param_3;
  }
  GamePlan_Optimize(this,param_1,puVar4);
  iVar1 = *(int *)((int)param_2 + 0x74);
  puVar4[8] = 0xdac;
  GamePlan_SetActiveEffect(puVar4,1,*(int *)((int)this + param_1 * 0x168 + 0x40));
  List_Add((void *)((int)this_00 + 300),puVar4);
  Game_PlaceObjectInPlayerCity(pvVar3,param_2,*(int *)((int)this + param_1 * 0x168 + 0x40));
  Object_SetFacadeAndLogoVariant(pvVar3,1,(int)param_2,(int)this_00);
  *(undefined4 *)(iVar1 + 8) = 0x4b;
  if ((*(void **)((int)DAT_0057c670 + 0x218) == param_2) &&
     (*(void **)((int)DAT_0057c670 + 0x25c) != (void *)0x0)) {
    UI_QueueControlCommand(*(void **)((int)DAT_0057c670 + 0x25c),-0x1868e,0x23,1);
  }
  ExceptionList = local_c;
  return 1;
}

