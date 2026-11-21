extern void *DAT_0057c670;

struct Map {
  int CountObjectsByState(int);
  void *Lookup(int, int *);
};

struct Game {
  void AbortOrderForTarget(void *, int, int);
};

struct GameRoot {
  void AbortOrdersTargetingObject(int param_1, int param_2, void *param_3);
};

void GameRoot::AbortOrdersTargetingObject(int param_1, int param_2, void *param_3)
{
  int iVar1;
  int iVar3;
  void *pvVar2;

  iVar3 = 0;
  iVar1 = ((Map *)DAT_0057c670)->CountObjectsByState(-1);
  if (0 < iVar1) {
    do {
      pvVar2 = ((Map *)((char *)DAT_0057c670 + 0x3c))->Lookup(iVar3, 0);
      if (pvVar2 != param_3) {
        switch (*(unsigned int *)((char *)pvVar2 + 0x30)) {
        case 0xd:
        case 0x16:
        case 0x17:
        case 0x1f:
          if (param_2 != 0)
            ((Game *)this)->AbortOrderForTarget(pvVar2, param_1, param_2);
          break;
        case 0x1d:
        case 0x1e:
          ((Game *)this)->AbortOrderForTarget(pvVar2, param_1, param_2);
        }
      }
      iVar3 = iVar3 + 1;
      iVar1 = ((Map *)DAT_0057c670)->CountObjectsByState(-1);
    } while (iVar3 < iVar1);
  }
  return;
}
