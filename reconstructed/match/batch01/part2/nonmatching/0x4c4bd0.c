extern "C" void *DAT_0057dcf4;
extern "C" void *DAT_0057dcf8;
extern "C" void *DAT_0057c670;
extern "C" char s__d____00568834[];
extern "C" char DAT_005686f4[];
extern "C" char DAT_005683a4[];
extern "C" double DAT_0055c420;
extern "C" void __cdecl Gadget_SetTextf(void *, int, char *, int);
extern "C" long __ftol();

struct Game {
  int GetPlayerSupplyScore(int);
  int ComputeRatingShare(int);
  int ComputeCompanyValue(int *, int *, int *);
};

struct GameMap {
  int GetPlayerBySlot(int);
};

struct UI {
  void Slider_SetValue(int, int, int);
  void RemoveObjectByKey(int);
  void ShowChildByID(int);
};

void __cdecl PolicePage_FillContributionStats(void *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int total;
  int local_c[3];
  float denom;

  iVar3 = 0;
  local_c[0] = 0;
  local_c[1] = 0;
  local_c[2] = 0;
  iVar4 = 0;
  iVar1 = ((Game *)DAT_0057dcf4)->GetPlayerSupplyScore(*(int *)((char *)DAT_0057dcf8 + 0x48));
  ((UI *)param_1)->Slider_SetValue(0x1fe5, iVar1, 0);
  iVar1 = ((Game *)DAT_0057dcf4)->ComputeRatingShare(*(int *)((char *)DAT_0057dcf8 + 0x48));
  Gadget_SetTextf(param_1, 0x1fe9, s__d____00568834, iVar1);
  Gadget_SetTextf(param_1, 0x1fb8, DAT_005686f4, *(int *)((char *)DAT_0057dcf4 + 0x10ac));
  Gadget_SetTextf(param_1, 0x1fb9, DAT_005686f4, *(int *)((char *)DAT_0057dcf4 + 0x10b0));
  Gadget_SetTextf(param_1, 0x1ff4, DAT_005686f4, *(int *)((char *)DAT_0057dcf4 + 0x10b4));
  Gadget_SetTextf(param_1, 0x1ff5, DAT_005686f4, *(int *)((char *)DAT_0057dcf4 + 0x10b8));
  iVar1 = 0;
  do {
    iVar2 = ((GameMap *)DAT_0057c670)->GetPlayerBySlot(iVar1);
    if (iVar2 != 0) {
      iVar4 = iVar4 + *(int *)((char *)DAT_0057dcf4 + *(int *)(iVar2 + 0x48) * 4 + 0xcb0);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  Gadget_SetTextf(param_1, 0x1fed, DAT_005683a4,
                  *(int *)((char *)DAT_0057dcf4 + *(int *)((char *)DAT_0057dcf8 + 0x48) * 4 + 0xcb0));
  Gadget_SetTextf(param_1, 0x1ff1, DAT_005683a4, iVar4);
  piVar5 = (int *)0x56aeb8;
  total = *(int *)((char *)DAT_0057dcf4 + 0x10c4);
  do {
    ((UI *)param_1)->RemoveObjectByKey(*piVar5);
    ((UI *)param_1)->RemoveObjectByKey(*piVar5 - 1);
    if (iVar3 < total) {
      iVar4 = iVar4 - 1000;
      if (iVar4 < 0) {
        iVar2 = *piVar5;
      }
      else {
        iVar2 = *piVar5 - 1;
      }
      ((UI *)param_1)->ShowChildByID(iVar2);
    }
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + 1;
  } while ((int)piVar5 < 0x56aecc);
  iVar1 = ((Game *)DAT_0057dcf4)->ComputeCompanyValue(local_c, local_c + 1, local_c + 2);
  iVar3 = 0;
  piVar5 = (int *)0x56aecc;
  do {
    if (iVar3 < iVar1) {
      ((UI *)param_1)->ShowChildByID(*piVar5);
    }
    else {
      ((UI *)param_1)->RemoveObjectByKey(*piVar5);
    }
    piVar5 = piVar5 + 1;
    iVar3 = iVar3 + 1;
  } while ((int)piVar5 < 0x56aef4);
  denom = (float)total;
  Gadget_SetTextf(param_1, 0x1fcf, s__d____00568834, (int)((float)local_c[0] * DAT_0055c420 / denom));
  Gadget_SetTextf(param_1, 0x1fd1, s__d____00568834, (int)((float)local_c[1] * DAT_0055c420 / denom));
  Gadget_SetTextf(param_1, 0x1fd0, s__d____00568834, (int)((float)local_c[2] * DAT_0055c420 / denom));
  return;
}
