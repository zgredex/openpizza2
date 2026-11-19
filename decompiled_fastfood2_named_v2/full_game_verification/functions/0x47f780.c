// rea decompile_all
// name: Branch_UpgradeSize
// address: 0x47f780
// body: available
// range: 0x47f780-0x47fa3c inclusive
// non_contiguous: false
// provider: Ghidra 12.2 (ghidra)
// analysis_profile: aae5fcbbec95ac3047ec86f28609da356814b1c85770f2c09803aad3607b988d
// limitations: The session serves operations only after Ghidra reports default auto-analysis complete; incomplete analysis does not expose partial results.; Ghidra Program checkpoint mode is disabled: closing discards metadata edits; original executable bytes are unchanged. For stock ELF/PE/Mach-O on Linux/macOS, set REA_GHIDRA_CHECKPOINT_DIR to a private absolute directory before starting REA (restart MCP after changing its startup environment).; Cancelling an active Ghidra request terminates its ephemeral database and discards session annotations. The selected target remains open; the next provider query imports the original artifact again.; Default-space addresses use lowercase 0x-prefixed hexadecimal; other address spaces use <percent-encoded-space>:0x<hex>.; This session uses Ghidra 12.2. The bridge is verified against 12.1.4; other 12.x (>=12.1) builds are accepted and the observed version is reported.; Pseudocode is Ghidra decompiler output, not original source and not text-equivalent to Hopper output.; External functions and functions without an analyzable body return null; other decompiler failures remain explicit.
// pseudocode: provider-specific; not original source


void __fastcall Branch_UpgradeSize(void *param_1)

{
  int *piVar1;
  void *pvVar2;
  char *pcVar3;
  char *this;
  int iVar4;
  void *local_c;
  undefined1 *puStack_8;
  undefined4 local_4;
  
                    /* Upgrades a branch to its next size. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_005580a6;
  local_c = ExceptionList;
  if (*(int *)((int)param_1 + 0x38) == 2) {
    return;
  }
  ExceptionList = &local_c;
  Branch_ClearInteriorObjects(param_1,0);
  Branch_ClearConstructionSites(param_1);
  this = *(char **)((int)param_1 + 0x1514);
  iVar4 = 0;
  if (0 < (int)this) {
    do {
      piVar1 = (int *)IDMap_Lookup((void *)((int)param_1 + 0x1500),iVar4,(int *)0x0);
      pvVar2 = (void *)Game_GetRecordByField814(*piVar1);
      if ((*(char *)(*piVar1 + 0x824) == '\x03') && (*(int *)((int)pvVar2 + 0xa4) == 4)) {
        Object_SetFieldA4Locked(pvVar2,0xffffffff);
        Object_SetDestinationAndTarget(pvVar2,3,*(int *)((int)pvVar2 + 0xcc));
        Object_SetChildField2C(pvVar2,0);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)this);
  }
  *(undefined1 *)((int)param_1 + 0x16f5) = 1;
  if (*(int *)((int)DAT_0057c670 + 0x2fc) == *(int *)((int)param_1 + 0x14e0)) {
    Game_SetLockedField2FC(DAT_0057c670,0);
    if (*(int *)((int)param_1 + 0x38) == 0) {
      pcVar3 = s_BAUHINTERGRUND_MITTEL_tga_00567cdc;
    }
    else if (*(int *)((int)param_1 + 0x38) == 1) {
      pcVar3 = s_BAUHINTERGRUND_GROSS_tga_00567cf8;
    }
    else {
      pcVar3 = this;
    }
    Game_LoadBackgroundImage(DAT_0057c670,pcVar3);
  }
  Array_ClearStride34((int)param_1);
  if (*(int *)((int)param_1 + 0x38) == 0) {
    pvVar2 = operator_new(0x10178);
    local_4 = 0;
    if (pvVar2 != (void *)0x0) {
      this = (char *)IsoMap_Construct(pvVar2,(int)DAT_0057c5cc);
      local_4 = 0xffffffff;
      goto LAB_0047f909;
    }
  }
  else {
    if (*(int *)((int)param_1 + 0x38) != 1) goto LAB_0047f909;
    pvVar2 = operator_new(0x10178);
    local_4 = 1;
    if (pvVar2 != (void *)0x0) {
      this = (char *)IsoMap_Construct(pvVar2,(int)DAT_0057c5cc);
      local_4 = 0xffffffff;
      goto LAB_0047f909;
    }
  }
  local_4 = 0xffffffff;
  this = (char *)0x0;
LAB_0047f909:
  iVar4 = Object_GetBufferCount(this,(undefined4 *)0x1);
  if (iVar4 == 0) {
    Grid_RebuildStreetNodes(this,(int)param_1);
  }
  Game_RegisterWorldObject(DAT_0057c5cc,this,-1);
  Game_AcquireStateLock(DAT_0057c670,0);
  *(int *)((int)param_1 + 0x38) = *(int *)((int)param_1 + 0x38) + 1;
  IDMap_RemoveByKey((void *)((int)DAT_0057c5cc + 0x2c3f8),*(int *)((int)param_1 + 0x14e0));
  if (*(undefined4 **)((int)param_1 + 0x14e0) != (undefined4 *)0x0) {
    (**(code **)**(undefined4 **)((int)param_1 + 0x14e0))(1);
  }
  *(char **)((int)param_1 + 0x14e0) = this;
  if (((*(int *)((int)DAT_0057c670 + 0x290) == 4) && (*(int *)((int)DAT_0057c670 + 0x2fc) == 0)) &&
     (*(void **)((int)DAT_0057c670 + 0x9c) == param_1)) {
    Game_SetLockedField2FC(DAT_0057c670,this);
  }
  Game_GetSizeName(param_1,4);
  Branch_ApplyBuildingStyleVariant(param_1,4);
  Game_SetHQLevel(*(void **)(*(int *)((int)param_1 + 0x16f0) + 0x74),
                  *(undefined4 *)((int)param_1 + 0x38));
  Window_UnlockState((int)DAT_0057c670);
  Map_CollectType351ToList((int)param_1);
  pvVar2 = (void *)IDMap_Lookup((void *)((int)DAT_0057c670 + 4),*(int *)((int)param_1 + 0x34),
                                (int *)0x0);
  MapObject_SpawnByKind
            (pvVar2,*(void **)((int)param_1 + 0x16f0),1,*(int *)((int)param_1 + 0x30),
             (void *)0xffffffff,-1);
  Game_ClearObjectFlag20((int)param_1);
  Game_ToggleObjectFlag2(param_1);
  Game_UpdateObjectList2((int)param_1);
  Game_CheckObjectUpgrade(param_1);
  Stats_ResetAverages(param_1);
  *(undefined4 *)(*(int *)((int)param_1 + 0x14e0) + 0xf4) = 1;
  ExceptionList = local_c;
  return;
}

