extern "C" void *DAT_0057c670;
extern "C" void *DAT_0057d290;
extern "C" int DAT_0057d284;
extern "C" void *DAT_0057d288;
extern "C" int DAT_0057d280;
extern "C" int *DAT_0057d28c;
extern "C" void *DAT_0057d27c;
extern "C" void __cdecl UI_Group_Create(void *, int, int, int, int);
extern "C" void __cdecl BuildingMarket_BuildSortedIndex(int);
extern "C" void __cdecl UI_DrawNeighborhoodCustomerIcons(void *, int);
extern "C" void __cdecl BuildingMarket_ShowSelectedBuildingInfo(void *);

struct LookupMap {
  void *Lookup(int, int *);
};

struct VObj {
  virtual void f(int);
};

struct UI {
  void SetPosition(void *, int);
  void SetChildVisibleByID(int, int);
};

struct Button {
  void Button_SetState(int, int);
};

struct Collector {
  void *CollectBranchBuildings();
  void *CollectBusinessBuildings();
};

void __cdecl BauenPage_UpdateBuildingMarket(void *param_1, char param_2)
{
  void *puVar1;
  void *puVar2;
  void *value;
  int iVar3;

  DAT_0057d290 = ((LookupMap *)((char *)DAT_0057c670 + 4))->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
  DAT_0057d284 = 0;
  ((UI *)param_1)->SetPosition((void *)0x4a6f80, 0);
  if (DAT_0057d288 != 0) {
    ((VObj *)DAT_0057d288)->f(1);
    DAT_0057d288 = 0;
  }
  if (param_2 != 0) {
    UI_Group_Create(param_1, 0, 2, 0x4ef, 0x4f0);
    if (*(int *)((char *)DAT_0057c670 + 0x218) == 0) {
      puVar1 = ((Collector *)DAT_0057d290)->CollectBranchBuildings();
      DAT_0057d280 = (unsigned int)(*(int *)((char *)puVar1 + 0x14) <= 0);
      if (puVar1 != 0) {
        ((VObj *)puVar1)->f(1);
      }
    }
    else {
      iVar3 = *(int *)(*(int *)((char *)DAT_0057c670 + 0x218) + 4);
      if ((iVar3 < 0x14) || (DAT_0057d280 = 0, 0x16 < iVar3)) {
        DAT_0057d280 = 1;
      }
    }
  }
  ((Button *)param_1)->Button_SetState(DAT_0057d280 + 0x4ef, 1);
  if (DAT_0057d280 == 0) {
    DAT_0057d288 = ((Collector *)DAT_0057d290)->CollectBranchBuildings();
  }
  else {
    DAT_0057d288 = ((Collector *)DAT_0057d290)->CollectBusinessBuildings();
  }
  iVar3 = *(int *)((char *)DAT_0057d288 + 0x14);
  BuildingMarket_BuildSortedIndex(iVar3);
  puVar2 = ((Collector *)DAT_0057d290)->CollectBranchBuildings();
  ((UI *)param_1)->SetChildVisibleByID(0x4ef, (unsigned int)(0 < *(int *)((char *)puVar2 + 0x14)));
  if (puVar2 != 0) {
    ((VObj *)puVar2)->f(1);
  }
  puVar2 = ((Collector *)DAT_0057d290)->CollectBusinessBuildings();
  ((UI *)param_1)->SetChildVisibleByID(0x4f0, (unsigned int)(0 < *(int *)((char *)puVar2 + 0x14)));
  if (puVar2 != 0) {
    ((VObj *)puVar2)->f(1);
  }
  if (0 < iVar3) {
    puVar1 = *(void **)((char *)DAT_0057c670 + 0x218);
    if (puVar1 == 0) {
      puVar1 = ((LookupMap *)DAT_0057d288)->Lookup(*DAT_0057d28c, 0);
    }
    value = puVar1;
    DAT_0057d27c = value;
    if (*(int *)((char *)puVar1 + 0x4c) == 0) {
      value = ((LookupMap *)DAT_0057d288)->Lookup(*DAT_0057d28c, 0);
      DAT_0057d27c = value;
    }
  }
  else {
    value = DAT_0057d27c;
  }
  *(void **)((char *)DAT_0057c670 + 0x218) = value;
  UI_DrawNeighborhoodCustomerIcons(param_1, 0x1f43);
  BuildingMarket_ShowSelectedBuildingInfo(param_1);
  return;
}
