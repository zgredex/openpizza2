extern "C" void *DAT_0057c5cc;
extern "C" void *DAT_0057c670;
extern "C" int DAT_00571958;
extern "C" int DAT_0057195c;
extern "C" int __cdecl Random_RangeFast(int, int);

struct RecSet {
  void GetBounds48(int, int *, int *, int *, int *);
  void GetScreenRect48(int, int *, int *);
  void SetRect48(int, double, double);
  void SelectVariant(int, int);
};

struct Map {
  void SpawnAdvertisingZeppelin(unsigned int param_1);
};

void Map::SpawnAdvertisingZeppelin(unsigned int param_1)
{
  void *this_00;
  int iVar1;
  int iVar2;
  int iVar3;
  unsigned int uVar4;
  unsigned int uVar5;
  unsigned int local_18;
  unsigned int local_14;
  unsigned int local_10;
  int local_c;
  int local_8;
  int local_4;

  this_00 = *(void **)((char *)DAT_0057c5cc + 0x2c3d4);
  iVar1 = *(int *)((char *)DAT_0057c5cc + 0x2c41c + param_1 * 4);
  local_4 = iVar1;
  ((RecSet *)this_00)->GetBounds48(iVar1, &local_c, &local_8, (int *)&local_14, (int *)&local_10);
  ((RecSet *)this_00)->GetScreenRect48(iVar1, (int *)&local_14, (int *)&local_10);
  uVar4 = Random_RangeFast(0, 3);
  switch (uVar4) {
  case 0:
    iVar1 = *(int *)((char *)this + 0xfa8);
    iVar3 = *(int *)(iVar1 + 0x30);
    local_18 = (*(int *)(iVar1 + 0x2c) - local_c) - local_14;
    uVar4 = *(int *)(iVar1 + 0x38) + DAT_0057195c;
    uVar5 = Random_RangeFast(iVar3, uVar4);
    *(unsigned int *)((char *)DAT_0057c670 + 0x36c + param_1 * 4) = 4;
    uVar4 = (((int)uVar5 <= (int)(uVar4 - iVar3) / 2 + iVar3) - 1 & 2) + 2;
    param_1 = uVar5;
    break;
  case 1:
    iVar1 = *(int *)((char *)this + 0xfa8);
    iVar3 = *(int *)(iVar1 + 0x30);
    local_18 = *(int *)(iVar1 + 0x34) + DAT_00571958;
    uVar4 = *(int *)(iVar1 + 0x38) + DAT_0057195c;
    uVar5 = Random_RangeFast(iVar3, uVar4);
    *(unsigned int *)((char *)DAT_0057c670 + 0x36c + param_1 * 4) = 3;
    uVar4 = ((int)uVar5 <= (int)(uVar4 - iVar3) / 2 + iVar3) - 1 & 6;
    param_1 = uVar5;
    break;
  case 2:
    iVar1 = *(int *)((char *)this + 0xfa8);
    iVar3 = *(int *)(iVar1 + 0x30);
    iVar2 = *(int *)(iVar1 + 0x2c);
    uVar4 = *(int *)(iVar1 + 0x34) + DAT_00571958;
    local_18 = Random_RangeFast(iVar2, uVar4);
    *(unsigned int *)((char *)DAT_0057c670 + 0x36c + param_1 * 4) = 1;
    uVar4 = (((int)local_18 <= (int)(uVar4 - iVar2) / 2 + iVar2) - 1 & 0xfffffffe) + 2;
    param_1 = (iVar3 - local_8) - local_10;
    break;
  case 3:
    iVar1 = *(int *)((char *)this + 0xfa8);
    iVar3 = *(int *)(iVar1 + 0x2c);
    uVar5 = *(int *)(iVar1 + 0x38) + DAT_0057195c;
    uVar4 = *(int *)(iVar1 + 0x34) + DAT_00571958;
    local_18 = Random_RangeFast(iVar3, uVar4);
    *(unsigned int *)((char *)DAT_0057c670 + 0x36c + param_1 * 4) = 2;
    uVar4 = (((int)local_18 <= (int)(uVar4 - iVar3) / 2 + iVar3) - 1 & 2) + 4;
    param_1 = uVar5;
    break;
  default:
    uVar4 = param_1;
  }
  iVar1 = local_4;
  ((RecSet *)this_00)->SetRect48(iVar1, (double)(int)local_18, (double)(int)param_1);
  ((RecSet *)this_00)->SelectVariant(iVar1, uVar4);
  return;
}
