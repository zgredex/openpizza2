extern "C" void *DAT_0057c670;
extern "C" void __cdecl UI_Group_Create(void *, int, int, int, int, int, int, int, int, int, int, int);

struct LookupMap {
  void *Lookup(int, int *);
};

struct GameMap {
  int GetCurrentPlayerCompanyName();
  int GetPlayerBySlot(int);
};

struct VObj {
  virtual void f(int);
};

struct Collector {
  void *CollectBranchBuildings();
  void *CollectBusinessBuildings();
};

struct PlayerField {
  int GetField2C();
};

struct UI {
  void Group_ClearAll();
  void Button_SetState(int, int);
  void ToggleObjectActive(int, int);
  void SetChildVisibleByID(int, int);
  void RemoveObjectByKey(int);
  void EnsureChildInitialized(int);
};

void __cdecl SubMenu_UpdateButtonStatesVariant1(void *param_1)
{
  volatile int count;
  int iVar1;
  int iVar2;
  void *puVar3;
  int iVar4;
  int iVar5;
  unsigned int uVar6;

  iVar5 = *(int *)((char *)DAT_0057c670 + 0x298 + *(int *)((char *)DAT_0057c670 + 0x290) * 4);
  iVar1 = (int)((LookupMap *)((char *)DAT_0057c670 + 4))->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
  iVar2 = ((GameMap *)DAT_0057c670)->GetCurrentPlayerCompanyName();
  count = *(int *)(iVar1 + 0xc20 + iVar2 * 4);
  ((UI *)param_1)->Group_ClearAll();
  UI_Group_Create(param_1, 0, 9, 0x3f4, 0x3fe, 0x402, 0x401, 0x3f8, 0x3f9, 0x3fd, 0x403, 0x404);
  ((UI *)param_1)->Button_SetState(0x3f4, (unsigned int)(iVar5 == 1));
  ((UI *)param_1)->ToggleObjectActive(0x3f4, (unsigned int)(iVar5 == 1));
  ((UI *)param_1)->Button_SetState(0x3fe, (unsigned int)(iVar5 == 2));
  ((UI *)param_1)->ToggleObjectActive(0x3fe, (unsigned int)(iVar5 == 2));
  iVar2 = (int)((LookupMap *)((char *)DAT_0057c670 + 4))->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
  puVar3 = ((Collector *)iVar2)->CollectBranchBuildings();
  iVar2 = *(int *)((char *)puVar3 + 0x14);
  if (puVar3 != 0) {
    ((VObj *)puVar3)->f(1);
  }
  iVar4 = (int)((LookupMap *)((char *)DAT_0057c670 + 4))->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
  puVar3 = ((Collector *)iVar4)->CollectBusinessBuildings();
  iVar4 = *(int *)((char *)puVar3 + 0x14);
  if (puVar3 != 0) {
    ((VObj *)puVar3)->f(1);
  }
  ((UI *)param_1)->Button_SetState(0x402, (unsigned int)(iVar5 == 0xb));
  ((UI *)param_1)->ToggleObjectActive(0x402, (unsigned int)(iVar5 == 0xb));
  ((UI *)param_1)->SetChildVisibleByID(0x402, (unsigned int)(0 < iVar2 + iVar4));
  ((UI *)param_1)->Button_SetState(0x401, (unsigned int)(iVar5 == 4));
  ((UI *)param_1)->ToggleObjectActive(0x401, (unsigned int)(iVar5 == 4));
  ((UI *)param_1)->Button_SetState(0x3f8, (unsigned int)(iVar5 == 5));
  ((UI *)param_1)->ToggleObjectActive(0x3f8, (unsigned int)(iVar5 == 5));
  uVar6 = (unsigned int)(0 < count);
  ((UI *)param_1)->SetChildVisibleByID(0x3f8, uVar6);
  iVar1 = ((GameMap *)DAT_0057c670)->GetPlayerBySlot(*(int *)((char *)DAT_0057c670 + 0x200 + *(int *)((char *)DAT_0057c670 + 0x2ec) * 4));
  if (iVar1 < 3) {
    ((UI *)param_1)->Button_SetState(0x3f9, 0);
    ((UI *)param_1)->RemoveObjectByKey(0x3f9);
  }
  else {
    ((UI *)param_1)->Button_SetState(0x3f9, (unsigned int)(iVar5 == 6));
    ((UI *)param_1)->ToggleObjectActive(0x3f9, (unsigned int)(iVar5 == 6));
    ((UI *)param_1)->SetChildVisibleByID(0x3f9, uVar6);
  }
  uVar6 = (unsigned int)(iVar5 == 10);
  ((UI *)param_1)->Button_SetState(0x3fd, uVar6);
  ((UI *)param_1)->ToggleObjectActive(0x3fd, uVar6);
  ((UI *)param_1)->SetChildVisibleByID(0x3fd, uVar6);
  iVar1 = *(int *)((char *)DAT_0057c670 + 0x218);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 4) == 0x10)) && (*(int *)(iVar1 + 0x38) == 0)) {
    iVar2 = *(int *)(iVar1 + 8);
    iVar4 = ((GameMap *)DAT_0057c670)->GetCurrentPlayerCompanyName();
    if (iVar2 == iVar4) {
      ((UI *)param_1)->Button_SetState(0x404, (unsigned int)(iVar5 == 7));
      ((UI *)param_1)->ToggleObjectActive(0x404, (unsigned int)(iVar5 == 7));
      ((UI *)param_1)->SetChildVisibleByID(0x404, 1);
      iVar2 = ((GameMap *)DAT_0057c670)->GetPlayerBySlot(*(int *)(iVar1 + 8));
      iVar1 = (int)((LookupMap *)(iVar2 + 0x180))->Lookup(*(int *)(iVar1 + 0x2c), 0);
      ((UI *)param_1)->Button_SetState(0x403, (unsigned int)(iVar5 == 8));
      ((UI *)param_1)->ToggleObjectActive(0x403, (unsigned int)(iVar5 == 8));
      iVar5 = ((PlayerField *)iVar1)->GetField2C();
      ((UI *)param_1)->SetChildVisibleByID(0x403, (unsigned int)(iVar5 < 2));
      ((UI *)param_1)->SetChildVisibleByID(0x3fd, 1);
      return;
    }
  }
  ((UI *)param_1)->EnsureChildInitialized(0x403);
  ((UI *)param_1)->SetChildVisibleByID(0x403, 0);
  ((UI *)param_1)->EnsureChildInitialized(0x404);
  ((UI *)param_1)->SetChildVisibleByID(0x404, 0);
  ((UI *)param_1)->SetChildVisibleByID(0x3fd, uVar6);
  return;
}
