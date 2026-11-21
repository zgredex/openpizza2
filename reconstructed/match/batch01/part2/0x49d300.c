extern "C" int DAT_00568af4;
extern "C" void *DAT_0057cac8;
extern "C" int DAT_0057cacc;
extern "C" int DAT_00582094;
extern "C" int DAT_0058175c;
extern "C" int DAT_00582004;
extern "C" int DAT_00582568;
extern "C" char s__0_2f___005688b0[];
extern "C" char DAT_00568930[];
extern "C" char DAT_005630d0[];
extern "C" double DAT_0055c428;
extern "C" void __cdecl String_Format(char *, const char *, ...);

struct LookupMap {
  void *Lookup(int, int *);
};

struct UI {
  void SetChildVisibleByID(int, int);
  void SetText(int, char *);
};

void __cdecl ContestRecipePage_FillIngredientDetails(void *param_1, int param_2)
{
  int iVar1;
  int iVar3;
  int iVar4;
  float fVar;
  double dVar;
  char local_40[64];

  iVar3 = 0;
  iVar4 = 1;
  iVar1 = DAT_00568af4;
  if (((DAT_00568af4 < 0) && (iVar1 = param_2, param_2 < 0)) ||
      (iVar3 = (int)((LookupMap *)DAT_0057cac8)->Lookup(iVar1, 0), iVar3 == 0)) {
    iVar4 = 0;
  }
  ((UI *)param_1)->SetChildVisibleByID(0x4fa, iVar4);
  ((UI *)param_1)->SetChildVisibleByID(0x4f9, iVar4);
  ((UI *)param_1)->SetChildVisibleByID(0x4e9, iVar4);
  ((UI *)param_1)->SetChildVisibleByID(0x4ea, iVar4);
  ((UI *)param_1)->SetChildVisibleByID(0x449, iVar4);
  ((UI *)param_1)->SetChildVisibleByID(0x44c, iVar4);
  if (iVar3 == 0) {
    return;
  }
  fVar = (float)*(int *)(iVar3 + 0xac + DAT_0057cacc * 4);
  ((UI *)param_1)->SetText(0x4fa, (char *)(iVar3 + 0x88));
  dVar = *(double *)(iVar3 + 0xc0);
  String_Format(local_40, s__0_2f___005688b0,
                dVar * (double)fVar * DAT_0055c428);
  ((UI *)param_1)->SetText(0x4e9, local_40);
  String_Format(local_40, DAT_00568930, (int)fVar);
  ((UI *)param_1)->SetText(0x4ea, local_40);
  switch (DAT_0057cacc) {
  case 0:
    String_Format(local_40, DAT_005630d0, DAT_00582094);
    break;
  case 1:
    String_Format(local_40, DAT_005630d0, DAT_0058175c);
    break;
  case 2:
    String_Format(local_40, DAT_005630d0, DAT_00582004);
    break;
  case 3:
    String_Format(local_40, DAT_005630d0, DAT_00582568);
    break;
  }
  ((UI *)param_1)->SetText(0x4f9, local_40);
  return;
}
