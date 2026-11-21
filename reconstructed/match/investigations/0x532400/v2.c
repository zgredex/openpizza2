void *operator new(unsigned int);

struct Array {
  char pad[0x14];
  void Construct(int);
  int InsertGrow(void *);
};

struct SelectionGroup {
  int field0;
  Array members;
  SelectionGroup() { members.Construct(0); }
};

struct UI {
  int AddSelectionGroup(int param_1, int param_2, int *param_3);
  void Group_ApplyMemberSelection(void *, int);
};

int UI::AddSelectionGroup(int param_1, int param_2, int *param_3)
{
  SelectionGroup *piVar1 = new SelectionGroup;
  int iVar2;
  int iVar3;
  iVar3 = 0;
  iVar2 = -1;
  if (0 < param_2) {
    if (0 < param_2) {
      do {
        if (*param_3 == -1) break;
        piVar1->members.InsertGrow((void *)*param_3);
        iVar3 = iVar3 + 1;
        param_3 = param_3 + 1;
      } while (iVar3 < param_2);
    }
    piVar1->field0 = param_1;
    iVar2 = ((Array *)((char *)this + 0x148))->InsertGrow(piVar1);
    Group_ApplyMemberSelection(piVar1, -1);
  }
  return iVar2;
}
