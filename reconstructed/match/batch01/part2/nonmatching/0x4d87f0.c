void *operator new(unsigned int);
extern "C" void *DAT_0057c670;
extern "C" char *DAT_005840d4[];
extern "C" char *DAT_00582158;
extern "C" char *DAT_005821b0;
extern "C" char *DAT_00584144;
extern "C" char s__s___s_0056cd9c[];
extern "C" char s__s___s__0056c954[];
extern "C" void __cdecl String_Format(char *, const char *, ...);
extern "C" void __cdecl List_Add(void *, void *);

struct LookupMap { void *Lookup(int, int *); };
struct GameMap {
  int GetCurrentPlayerCompanyName();
  int GetPlayerBySlot(int);
  int GetPlayerSubmapValue(int, unsigned int);
};
struct PlayerRec { int FindRecordByField34(void *); };
struct Sub { int GetSubobject4(); };
struct Palette { void Free(); };

struct EntryWithValue {
  char pad[0x58];
  EntryWithValue(char *text, void *rec, unsigned int val) { Construct(text, rec, val); }
  void Construct(char *, void *, unsigned int);
};
struct Entry {
  char pad[0x58];
  Entry(char *text, void *rec) { Construct(text, rec); }
  void Construct(char *, void *);
};

struct City {
  void BuildObjectListEntries(void *param_1);
};

void City::BuildObjectListEntries(void *param_1)
{
  int uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  char *pcVar6;
  int iVar7;
  unsigned int uVar8;
  int local_114;
  char local_10c[256];

  local_114 = 0;
  if (0 < *(int *)((char *)this + 0xfc0)) {
    do {
      iVar2 = (int)((LookupMap *)((char *)this + 0xfac))->Lookup(local_114, 0);
      iVar7 = 0;
      switch (*(int *)(iVar2 + 4)) {
      case 0x10:
        iVar4 = *(int *)(iVar2 + 8);
        iVar7 = iVar4 * 10000 + 18000;
        iVar3 = ((GameMap *)DAT_0057c670)->GetCurrentPlayerCompanyName();
        if (iVar4 != iVar3) break;
        pvVar5 = (void *)((GameMap *)DAT_0057c670)->GetPlayerBySlot(iVar4);
        iVar4 = ((PlayerRec *)pvVar5)->FindRecordByField34((void *)iVar2);
        if (iVar4 == 0) break;
        uVar8 = 0;
        if (pvVar5 != 0) {
          uVar8 = *(unsigned int *)((char *)pvVar5 + 0x1dc);
        }
        ((Sub *)iVar4)->GetSubobject4();
        String_Format(local_10c, s__s___s_0056cd9c, DAT_00582158);
        pcVar6 = (char *)new EntryWithValue(local_10c, (void *)iVar2, uVar8);
        break;
      case 0x1a:
        iVar4 = *(int *)(iVar2 + 8);
        iVar7 = iVar4 * 10000 + 19000;
        if (*(int *)(iVar2 + 0x30) == 0x1c) {
          iVar7 = iVar4 * 10000 + 0x2774;
          iVar4 = ((GameMap *)DAT_0057c670)->GetPlayerBySlot(iVar4);
          uVar8 = 0;
          if (iVar4 != 0) {
            uVar8 = *(unsigned int *)(iVar4 + 0x1dc);
          }
          String_Format(local_10c, s__s___s__0056c954, DAT_00584144);
          pcVar6 = (char *)new EntryWithValue(local_10c, (void *)iVar2, uVar8);
          *(int *)(pcVar6 + 0x50) = *(int *)(iVar2 + 4) + 10000;
          break;
        }
        iVar3 = ((GameMap *)DAT_0057c670)->GetCurrentPlayerCompanyName();
        if (iVar4 != iVar3) break;
        iVar4 = ((GameMap *)DAT_0057c670)->GetPlayerBySlot(iVar4);
        if (iVar4 == 0) {
          uVar8 = 0;
        }
        else {
          uVar8 = *(unsigned int *)(iVar4 + 0x1dc);
        }
        String_Format(local_10c, s__s___s__0056c954, DAT_005821b0);
        pcVar6 = (char *)new EntryWithValue(local_10c, (void *)iVar2, uVar8);
        break;
      case 0x17:
        iVar7 = 1;
      case 0x18:
        iVar7 = iVar7 + 1;
      case 0x19:
        if (*(int *)(iVar2 + 0x54) != -1) {
          pcVar6 = (char *)new Entry(DAT_005840d4[*(int *)(iVar2 + 4)], (void *)iVar2);
        }
        else {
          pcVar6 = 0;
        }
        break;
      case 0x1c:
        iVar7 = 1;
      case 0xf:
        uVar1 = *(unsigned int *)(iVar2 + 0x2c);
        iVar4 = *(int *)(iVar2 + 8);
        iVar3 = ((GameMap *)DAT_0057c670)->GetPlayerSubmapValue(iVar4, uVar1);
        if (iVar7 == 0) {
          iVar7 = iVar4 * 10000 + 0x2774 + (uVar1 & 0x7f);
        }
        else {
          iVar7 = iVar4 * 10000 + 0x2774;
        }
        iVar4 = ((GameMap *)DAT_0057c670)->GetPlayerBySlot(iVar4);
        uVar8 = 0;
        if (iVar4 != 0) {
          uVar8 = *(unsigned int *)(iVar4 + 0x1dc);
        }
        if (iVar3 == 0) {
          pcVar6 = (char *)new EntryWithValue(DAT_005840d4[*(int *)(iVar2 + 4)], (void *)iVar2, uVar8);
          *(int *)(pcVar6 + 0x50) = *(int *)(iVar2 + 4) + 10000;
        }
        else {
          pcVar6 = (char *)new EntryWithValue((char *)(iVar3 + 4), (void *)iVar2, uVar8);
        }
        break;
      default:
        break;
      }
      if (pcVar6 != 0) {
        *(int *)(pcVar6 + 0x50) = iVar7;
        List_Add(param_1, pcVar6);
      }
      local_114 = local_114 + 1;
    } while (local_114 < *(int *)((char *)this + 0xfc0));
  }
  return;
}
