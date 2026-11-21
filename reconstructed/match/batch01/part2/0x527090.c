extern "C" char *strcpy(char *, const char *);
extern "C" char *strcat(char *, const char *);
extern "C" char *strrchr(const char *, int);
#pragma intrinsic(strcpy)
#pragma intrinsic(strcat)
extern "C" char DAT_005742a4[];

struct UI {
  unsigned int LoadFontByName(char *param_1);
  void MakeKey(char *, unsigned int *);
  unsigned int *FindFontByName(unsigned int *);
  unsigned int *LoadFont(char *);
};

unsigned int UI::LoadFontByName(char *param_1)
{
  char local_208[260];
  unsigned int local_104[65];
  char *pcVar2;
  unsigned int *puVar3;

  strcpy(local_208, param_1);
  pcVar2 = strrchr(local_208, '.');
  if (pcVar2 != 0) {
    *pcVar2 = 0;
  }
  strcat(local_208, DAT_005742a4);
  MakeKey(local_208, local_104);
  puVar3 = FindFontByName(local_104);
  if (puVar3 == 0) {
    puVar3 = LoadFont(local_208);
  }
  if (puVar3 != 0) {
    puVar3[0x42] = puVar3[0x42] + 1;
    return puVar3[0x41];
  }
  return 0;
}
