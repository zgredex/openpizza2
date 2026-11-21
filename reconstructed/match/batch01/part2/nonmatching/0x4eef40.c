extern "C" void *operator_new(unsigned int);
extern "C" int rand(void);

struct MapData {
  int GetRecordChild14(int);
  void *GetNestedArrayEntry(int, int);
};

struct RecordList {
  int FindFreeSlot(int);
  void SelectVariant(int, int);
  void SetIndex48(int, int);
};

struct Map {
  void BuildElementAnimationList(int param_1, int param_2);
};

void Map::BuildElementAnimationList(int param_1, int param_2)
{
  int *piVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  int iVar8;
  void *pvVar5;
  unsigned int uVar6;
  unsigned int uVar7;

  iVar3 = param_1;
  iVar4 = ((MapData *)*(void **)((char *)this + 4))->GetRecordChild14(param_1);
  iVar8 = 0;
  *(int *)(param_2 + 4) = iVar4;
  if (iVar4 < 1) {
    *(unsigned int *)(param_2 + 8) = 0;
  }
  else {
    pvVar5 = operator_new(iVar4 * 0xc);
    *(void **)(param_2 + 8) = pvVar5;
    param_1 = 0;
    if (0 < *(int *)(param_2 + 4)) {
      do {
        uVar6 = (unsigned int)((MapData *)*(void **)((char *)this + 4))->GetNestedArrayEntry(iVar3, param_1);
        *(unsigned int *)(iVar8 + 8 + *(int *)(param_2 + 8)) = uVar6;
        *(unsigned int *)(iVar8 + 4 + *(int *)(param_2 + 8)) = 0;
        pcVar2 = *(char **)(iVar8 + 8 + *(int *)(param_2 + 8));
        if ((((unsigned char)pcVar2[3] <= *(unsigned char *)(*(int *)((char *)this + 4) + 0x2bf48)) &&
             (*pcVar2 == 1)) && (pcVar2[1] == 1)) {
          *(unsigned int *)(iVar8 + *(int *)(param_2 + 8) + 4) = 1;
        }
        uVar6 = (unsigned int)((MapData *)*(void **)((char *)this + 4))->GetNestedArrayEntry(iVar3, param_1);
        *(unsigned int *)(iVar8 + 8 + *(int *)(param_2 + 8)) = uVar6;
        iVar4 = ((RecordList *)(*(int *)(iVar8 + 8 + *(int *)(param_2 + 8)) + 0x48))->FindFreeSlot(-1);
        *(int *)(iVar8 + *(int *)(param_2 + 8)) = iVar4;
        piVar1 = (int *)(iVar8 + *(int *)(param_2 + 8));
        if (*(int *)(iVar8 + 4 + *(int *)(param_2 + 8)) != 0) {
          ((RecordList *)(piVar1[2] + 0x48))->SelectVariant(*piVar1, -1);
          if ((0x64b < iVar3) && (iVar3 < 0x66e)) {
            piVar1 = (int *)(iVar8 + *(int *)(param_2 + 8));
            iVar4 = rand();
            ((RecordList *)(piVar1[2] + 0x48))->SetIndex48(*piVar1, iVar4 % 0xc);
          }
          if (iVar3 == 0x6a2) {
            piVar1 = (int *)(iVar8 + *(int *)(param_2 + 8));
            uVar7 = rand();
            ((RecordList *)(piVar1[2] + 0x48))->SetIndex48(*piVar1, uVar7 & 0x1f);
          }
        }
        param_1 = param_1 + 1;
        iVar8 = iVar8 + 0xc;
      } while (param_1 < *(int *)(param_2 + 4));
      return;
    }
  }
  return;
}
