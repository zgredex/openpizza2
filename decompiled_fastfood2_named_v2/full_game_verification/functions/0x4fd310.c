// rea decompile_all
// name: AI_EnsureBranchStorage
// address: 0x4fd310
// body: available
// range: 0x4fd310-0x4fd51b inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


undefined4 __thiscall AI_EnsureBranchStorage(void *this,uint param_1,int param_2)

{
  void *this_00;
  void *pvVar1;
  int iVar2;
  void *this_01;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  bool bVar7;
  longlong lVar8;
  int local_c;
  int local_8;
  int local_4;
  
                    /* Ensures a branch has a storage/supplier building. */
  iVar4 = *(int *)((int)this + param_1 * 0x168 + 0x40);
  this_00 = (void *)Game_GetPlayerBySlot(DAT_0057c670,iVar4);
  if (*(int *)((int)this_00 + 0x194) < 1) {
    local_8 = *(int *)(param_2 + 0x34);
    pvVar1 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),local_8,(int *)0x0);
    pvVar5 = (void *)AI_FindNearestHouse(iVar4,pvVar1);
    bVar7 = pvVar5 == (void *)0x0;
    if (bVar7) {
      pvVar5 = (void *)AI_FindCheapestShop(iVar4,pvVar1,1);
    }
    param_1 = (uint)!bVar7;
    if (pvVar5 == (void *)0x0) {
      return 3;
    }
    Game_ComputeTradeOffers(pvVar1,(int)pvVar5,3,&local_c,&local_4,iVar4,(int *)0x0);
    iVar4 = Player_BuildStorage(local_8,pvVar5,iVar4,0,param_1);
    iVar4 = IDMap_Lookup((void *)((int)this_00 + 0x180),iVar4,(int *)0x0);
    if (param_1 == 0) {
      *(undefined1 *)(iVar4 + 0x3c) = 1;
      lVar8 = __ftol();
      *(int *)(iVar4 + 0x40) = (int)lVar8;
      iVar4 = 2;
      local_c = local_4;
    }
    else {
      *(undefined1 *)(iVar4 + 0x3c) = 0;
      *(int *)(iVar4 + 0x40) = local_c;
      iVar4 = 0;
    }
    Game_CanAffordWithCurrency(this_00,iVar4,(float)local_c,'\0',0xffffffff);
  }
  else {
    pvVar1 = (void *)IDMap_Lookup((void *)((int)this_00 + 0x180),0,(int *)0x0);
    if (pvVar1 != (void *)0x0) {
      iVar6 = *(int *)((int)this_00 + 0x15c) >> 2;
      if (2 < iVar6) {
        iVar6 = 2;
      }
      iVar2 = Get_Field2C((int)pvVar1);
      if ((iVar2 < iVar6) &&
         (pvVar5 = *(void **)((int)pvVar1 + 0x34), *(int *)((int)pvVar5 + 0x38) == 0)) {
        this_01 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)pvVar5 + 0x28),
                                       (int *)0x0);
        iVar6 = Get_Field2C((int)pvVar1);
        lVar8 = Stats_GetCombinedValue(3,iVar6);
        uVar3 = Game_CanAffordWithCurrency(this_00,2,(float)(int)lVar8,'\x01',0xffffffff);
        if ((char)uVar3 != '\0') {
          *(int *)((int)pvVar5 + 0x3c) = (int)lVar8;
          MapObject_SpawnByKind(this_01,pvVar5,3,iVar4,(void *)0xffffffff,-1);
        }
      }
      iVar4 = Storage_GetFillPercent((int)pvVar1);
      if (0 < iVar4) {
        Game_CompleteStaffAssignment(this_00,param_2,pvVar1);
      }
    }
  }
  *(uint *)(param_2 + 0x28) = *(uint *)(param_2 + 0x28) | 8;
  return 1;
}

