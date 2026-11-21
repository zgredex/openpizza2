extern void *DAT_0057c670;

struct GameMap {
  int GetPlayerBySlot(int);
};

struct PlayerRecord {
  int FindRecordByField4(unsigned int);
};

struct BranchRecord {
  int FindRecordByType(int);
  float SumFilteredFloats(int, int, unsigned int);
  void RemoveStaffMember(void *, int);
};

struct BranchMap {
  void *Lookup(int, int *);
};

struct Branch {
  void ApplyStatsToOwner();
};

void Branch::ApplyStatsToOwner()
{
  void *this_;
  int iVar1;
  int iVar2;
  int iVar5;
  int diff;
  int *piVar3;
  float *pfVar4;

  unsigned short field;
  this_ = (void *)((GameMap *)DAT_0057c670)->GetPlayerBySlot(*(int *)((char *)this + 0x30));
  field = *(unsigned short *)(*(int *)((char *)DAT_0057c670 + 0x94) + 0xa);
  iVar1 = ((PlayerRecord *)this_)->FindRecordByField4(field);
  iVar2 = ((BranchRecord *)this)->FindRecordByType(-1);
  if (iVar2 != 0) {
    iVar5 = 0x19;
    pfVar4 = (float *)(iVar1 + 0x78);
    diff = iVar2 - iVar1;
    do {
      iVar5 = iVar5 + -1;
      *pfVar4 = *(float *)(diff + (int)pfVar4) + *pfVar4;
      pfVar4 = pfVar4 + 1;
    } while (iVar5 != 0);
  }
  field = *(unsigned short *)(*(int *)((char *)DAT_0057c670 + 0x94) + 0xa);
  *(float *)(iVar1 + 0x60) = ((BranchRecord *)this)->SumFilteredFloats(-1, -1, field) + *(float *)(iVar1 + 0x60);
  if (0 < *(int *)((char *)this + 0x1514)) {
    do {
      iVar1 = 0;
      ((BranchRecord *)this)->RemoveStaffMember(((BranchMap *)((char *)this + 0x1500))->Lookup(0, 0), iVar1);
    } while (0 < *(int *)((char *)this + 0x1514));
  }
  return;
}
