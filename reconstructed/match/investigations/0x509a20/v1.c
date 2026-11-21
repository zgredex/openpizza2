extern "C" void *DAT_0057c670;

struct Building {
  int CountFreeBuildingsByType(int);
};

struct Branch {
  int ComputeBuildingRating(int);
  int Stats_GetAverage8(int);
  void InitStatBaselines(int, int);
  int City_HasRoomForBuilding();
  int Index_Map8To5(int);
};

struct GameMap {
  int GetCurrentPlayerCompanyName();
};

struct Command {
  void AppendCommandIfActive(int, int);
  void HandleEvent(int, int, int);
};

struct Advisor {
  void ComputeAdvisorTipId(void *branch_, void *param_4, int param_5);
};

void Advisor::ComputeAdvisorTipId(void *branch_, void *param_4, int param_5)
{
  int iVar1;
  int iVar2;

  iVar2 = *(int *)((char *)this + 0x34);
  if ((*(void **)((char *)branch_ + 0x16f0) != 0) &&
      (iVar1 = ((Building *)*(void **)((char *)branch_ + 0x16f0))->CountFreeBuildingsByType(0x16), 0 < iVar1)) {
    if (iVar2 == 0) {
      if (iVar1 < 3) goto after;
    }
    else if (iVar2 == 1) {
      goto after;
    }
    else if (iVar2 == 2) {
      if (iVar1 < 4) goto after;
    }
    else if (iVar2 == 3) {
      if (iVar1 < 5) goto after;
    }
    *(int *)((char *)this + 0x9c) = 100;
    return;
  }
after:
  iVar1 = ((Branch *)branch_)->ComputeBuildingRating(iVar2);
  if (iVar1 < 0x1e) {
    *(int *)((char *)this + 0x9c) = 0x66;
    return;
  }
  iVar1 = ((Branch *)branch_)->Stats_GetAverage8(iVar2);
  if (iVar1 < 0x14) {
    *(int *)((char *)this + 0x9c) = 0x68;
    return;
  }
  iVar1 = ((Branch *)param_4)->Index_Map8To5(iVar2);
  if (iVar1 < 0x1e) {
    *(int *)((char *)this + 0x9c) = 0x65;
    return;
  }
  ((Branch *)branch_)->InitStatBaselines(iVar2, 1);
  if (*(int *)((char *)branch_ + iVar2 * 4 + 0x181c) < 0x14) {
    *(int *)((char *)this + 0x9c) = 0x67;
    return;
  }
  ((Branch *)branch_)->InitStatBaselines(iVar2, 0);
  iVar2 = ((Branch *)branch_)->City_HasRoomForBuilding();
  if (iVar2 != 0) {
    *(int *)((char *)this + 0x9c) = 0x6a;
    return;
  }
  if (param_5 < 0x55) {
    if (param_5 < 0x46) {
      if (param_5 < 0x37) {
        if (param_5 < 0x2d) {
          if (param_5 < 0x1e) {
            if (param_5 < 0xf) {
              *(int *)((char *)this + 0x9c) = 0x72;
            }
            else {
              *(int *)((char *)this + 0x9c) = 0x6d;
            }
          }
          else {
            *(int *)((char *)this + 0x9c) = 0x71;
          }
        }
        else {
          *(int *)((char *)this + 0x9c) = 0x70;
        }
      }
      else {
        *(int *)((char *)this + 0x9c) = 0x6f;
      }
    }
    else {
      *(int *)((char *)this + 0x9c) = 0x6e;
    }
  }
  else {
    *(int *)((char *)this + 0x9c) = 0x6d;
  }
  if ((0x45 < param_5) &&
      (iVar2 = *(int *)((char *)branch_ + 0x30),
       iVar1 = ((GameMap *)DAT_0057c670)->GetCurrentPlayerCompanyName(),
       iVar2 == iVar1)) {
    ((Command *)(*(int *)((char *)DAT_0057c670 + 0x224) + 0xa8))->AppendCommandIfActive(0x1d, 1);
    ((Command *)(*(int *)((char *)DAT_0057c670 + 0x224) + 0xa8))->HandleEvent(0x1d, -1, -1);
  }
  return;
}
