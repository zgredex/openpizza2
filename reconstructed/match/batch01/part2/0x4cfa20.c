extern "C" void *DAT_0057c670;
extern "C" void __cdecl UI_Group_Create(void *, int, int, int, int, int, int, int, int, int, int, int);

struct LookupMap {
  void *Lookup(int, int *);
};

struct GameMap {
  int GetCurrentPlayerCompanyName();
};

struct ObjectList {
  int CountObjectsByType(int);
};

struct UI {
  void Group_ClearAll();
  void Button_SetState(int, int);
  void ToggleObjectActive(int, int);
  void SetChildVisibleByID(int, int);
};

void __cdecl BranchScreen_UpdateTabButtons(void *param_1)
{
  int iVar1;
  void *count;
  int iVar2;
  int iVar3;
  unsigned int uVar4;

  iVar1 = *(int *)((char *)DAT_0057c670 + 0x298 + *(int *)((char *)DAT_0057c670 + 0x290) * 4);
  iVar2 = (int)((LookupMap *)((char *)DAT_0057c670 + 4))->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
  iVar3 = ((GameMap *)DAT_0057c670)->GetCurrentPlayerCompanyName();
  iVar2 = *(int *)(iVar2 + 0xc20 + iVar3 * 4);
  ((UI *)param_1)->Group_ClearAll();
  UI_Group_Create(param_1, 0, 9, 0x3f4, 0x3f5, 0x3f6, 0x3f7, 0x3fe, 0x3ff, 0x400, 0x401, 0x3fd);
  ((UI *)param_1)->Button_SetState(0x3f4, (unsigned int)(iVar1 == 1));
  ((UI *)param_1)->ToggleObjectActive(0x3f4, (unsigned int)(iVar1 == 1));
  ((UI *)param_1)->Button_SetState(0x3f5, (unsigned int)(iVar1 == 2));
  ((UI *)param_1)->ToggleObjectActive(0x3f5, (unsigned int)(iVar1 == 2));
  ((UI *)param_1)->Button_SetState(0x3f6, (unsigned int)(iVar1 == 3));
  ((UI *)param_1)->ToggleObjectActive(0x3f6, (unsigned int)(iVar1 == 3));
  ((UI *)param_1)->Button_SetState(0x3f7, (unsigned int)(iVar1 == 4));
  ((UI *)param_1)->ToggleObjectActive(0x3f7, (unsigned int)(iVar1 == 4));
  ((UI *)param_1)->Button_SetState(0x3fe, (unsigned int)(iVar1 == 5));
  ((UI *)param_1)->ToggleObjectActive(0x3fe, (unsigned int)(iVar1 == 5));
  ((UI *)param_1)->SetChildVisibleByID(0x3fe, (unsigned int)(0 < iVar2));
  ((UI *)param_1)->Button_SetState(0x3ff, (unsigned int)(iVar1 == 6));
  ((UI *)param_1)->ToggleObjectActive(0x3ff, (unsigned int)(iVar1 == 6));
  ((UI *)param_1)->SetChildVisibleByID(0x3ff, (unsigned int)(1 < iVar2));
  ((UI *)param_1)->Button_SetState(0x400, (unsigned int)(iVar1 == 7));
  ((UI *)param_1)->ToggleObjectActive(0x400, (unsigned int)(iVar1 == 7));
  ((UI *)param_1)->SetChildVisibleByID(0x400, (unsigned int)(3 < iVar2));
  if (*(void **)((char *)DAT_0057c670 + 0x9c) != 0) {
    count = (void *)((ObjectList *)*(void **)((char *)DAT_0057c670 + 0x9c))->CountObjectsByType(1);
  }
  else {
    count = 0;
  }
  ((UI *)param_1)->Button_SetState(0x401, (unsigned int)(iVar1 == 8));
  ((UI *)param_1)->ToggleObjectActive(0x401, (unsigned int)(iVar1 == 8));
  if ((iVar2 <= 2) || ((int)count <= 0)) {
    iVar2 = 0;
  }
  else {
    iVar2 = 1;
  }
  ((UI *)param_1)->SetChildVisibleByID(0x401, iVar2);
  uVar4 = (unsigned int)(iVar1 == 10);
  ((UI *)param_1)->Button_SetState(0x3fd, uVar4);
  ((UI *)param_1)->ToggleObjectActive(0x3fd, uVar4);
  ((UI *)param_1)->SetChildVisibleByID(0x3fd, uVar4);
  return;
}
