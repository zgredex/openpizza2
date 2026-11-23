// MapList_LoadAllMapDefinitions: ported from Pizza Connection 2 at 0x4cd960.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cd960
#include "pc2_port.h"

void __cdecl MapList_LoadAllMapDefinitions(void *arg1)

{
  HANDLE hFindFile;
  BOOL BVar1;
  int value2;
  char *cptr3;
  uint8_t *unaff_EBX;
  uint8_t *unaff_ESI;
  uint32_t unaff_EDI;
  char acStackY_2f0 [128];
  int in_stack_fffffda4;
  int in_stack_fffffda8;
  char *in_stack_fffffdac;
  char *in_stack_fffffdb0;
  int in_stack_fffffdb4;
  int in_stack_fffffdb8;
  char *in_stack_fffffdbc;
  char *in_stack_fffffdc0;
  int in_stack_fffffdc4;
  int in_stack_fffffdc8;
  char *in_stack_fffffdcc;
  char *in_stack_fffffdd0;
  int in_stack_fffffdd4;
  int in_stack_fffffdd8;
  char *in_stack_fffffddc;
  char *in_stack_fffffde0;
  int in_stack_fffffde4;
  int in_stack_fffffde8;
  char *in_stack_fffffdec;
  char *in_stack_fffffdf0;
  int in_stack_fffffdf4;
  int in_stack_fffffdf8;
  char *in_stack_fffffdfc;
  char *in_stack_fffffe00;
  int in_stack_fffffe04;
  int in_stack_fffffe08;
  char *in_stack_fffffe0c;
  char *in_stack_fffffe10;
  int in_stack_fffffe14;
  int in_stack_fffffe18;
  char *in_stack_fffffe1c;
  char *in_stack_fffffe20;
  int in_stack_fffffe24;
  int in_stack_fffffe28;
  char *in_stack_fffffe2c;
  char *in_stack_fffffe30;
  int in_stack_fffffe34;
  int in_stack_fffffe38;
  char *in_stack_fffffe3c;
  char *in_stack_fffffe40;
  int in_stack_fffffe44;
  int in_stack_fffffe48;
  char *in_stack_fffffe4c;
  char *in_stack_fffffe50;
  int in_stack_fffffe54;
  int in_stack_fffffe58;
  uint8_t *in_stack_fffffe5c;
  uint8_t *in_stack_fffffe60;
  int in_stack_fffffe64;
  int in_stack_fffffe68;
  char *in_stack_fffffe6c;
  char *in_stack_fffffe70;
  int in_stack_fffffe74;
  int in_stack_fffffe78;
  uint8_t *in_stack_fffffe7c;
  uint8_t *in_stack_fffffe80;
  int in_stack_fffffe84;
  int in_stack_fffffe88;
  char *in_stack_fffffe8c;
  char *in_stack_fffffe90;
  int in_stack_fffffe94;
  int in_stack_fffffe98;
  char *in_stack_fffffe9c;
  char *in_stack_fffffea0;
  int in_stack_fffffea4;
  int in_stack_fffffea8;
  char *in_stack_fffffeac;
  char *in_stack_fffffeb0;
  int in_stack_fffffeb4;
  int in_stack_fffffeb8;
  char *in_stack_fffffebc;
  char *in_stack_fffffec0;
  DWORD in_stack_fffffec4;
  DWORD in_stack_fffffec8;
  char *in_stack_fffffecc;
  char *in_stack_fffffed0;
  DWORD in_stack_fffffed4;
  DWORD in_stack_fffffed8;
  char *in_stack_fffffedc;
  char *in_stack_fffffee0;
  DWORD in_stack_fffffee4;
  DWORD in_stack_fffffee8;
  char *in_stack_fffffeec;
  char *in_stack_fffffef0;
  int in_stack_fffffef4;
  int in_stack_fffffef8;
  char *in_stack_fffffefc;
  char *in_stack_ffffff00;
  int in_stack_ffffff04;
  int in_stack_ffffff08;
  char *in_stack_ffffff0c;
  char *in_stack_ffffff10;
  int in_stack_ffffff14;
  int in_stack_ffffff18;
  char *in_stack_ffffff1c;
  char *in_stack_ffffff20;
  int in_stack_ffffff24;
  int in_stack_ffffff28;
  char *in_stack_ffffff2c;
  char *in_stack_ffffff30;
  int in_stack_ffffff34;
  int in_stack_ffffff38;
  char *in_stack_ffffff3c;
  char *in_stack_ffffff40;
  int in_stack_ffffff44;
  int in_stack_ffffff48;
  char *in_stack_ffffff4c;
  char *in_stack_ffffff50;
  int in_stack_ffffff54;
  int in_stack_ffffff58;
  char *in_stack_ffffff5c;
  char *in_stack_ffffff60;
  int in_stack_ffffff64;
  int in_stack_ffffff68;
  uint8_t auStack_92 [146];
  
  List_Node_Reset((intptr_t)arg1);
  hFindFile = FindFirstFileA(s_daten___ini_0056b344,
                             (LPWIN32_FIND_DATAA)((intptr_t)register0x00000010 + -0x140));
  if (hFindFile != (HANDLE)0xffffffff) {
    do {
      MapList_AddIniRecord
                (arg1,(intptr_t)register0x00000010 + -0x114,unaff_EDI,unaff_ESI,unaff_EBX,
                 in_stack_fffffda4,in_stack_fffffda8,in_stack_fffffdac,in_stack_fffffdb0,
                 in_stack_fffffdb4,in_stack_fffffdb8,in_stack_fffffdbc,in_stack_fffffdc0,
                 in_stack_fffffdc4,in_stack_fffffdc8,in_stack_fffffdcc,in_stack_fffffdd0,
                 in_stack_fffffdd4,in_stack_fffffdd8,in_stack_fffffddc,in_stack_fffffde0,
                 in_stack_fffffde4,in_stack_fffffde8,in_stack_fffffdec,in_stack_fffffdf0,
                 in_stack_fffffdf4,in_stack_fffffdf8,in_stack_fffffdfc,in_stack_fffffe00,
                 in_stack_fffffe04,in_stack_fffffe08,in_stack_fffffe0c,in_stack_fffffe10,
                 in_stack_fffffe14,in_stack_fffffe18,in_stack_fffffe1c,in_stack_fffffe20,
                 in_stack_fffffe24,in_stack_fffffe28,in_stack_fffffe2c,in_stack_fffffe30,
                 in_stack_fffffe34,in_stack_fffffe38,in_stack_fffffe3c,in_stack_fffffe40,
                 in_stack_fffffe44,in_stack_fffffe48,in_stack_fffffe4c,in_stack_fffffe50,
                 in_stack_fffffe54,in_stack_fffffe58,in_stack_fffffe5c,in_stack_fffffe60,
                 in_stack_fffffe64,in_stack_fffffe68,in_stack_fffffe6c,in_stack_fffffe70,
                 in_stack_fffffe74,in_stack_fffffe78,in_stack_fffffe7c,in_stack_fffffe80,
                 in_stack_fffffe84,in_stack_fffffe88,in_stack_fffffe8c,in_stack_fffffe90,
                 in_stack_fffffe94,in_stack_fffffe98,in_stack_fffffe9c,in_stack_fffffea0,
                 in_stack_fffffea4,in_stack_fffffea8,in_stack_fffffeac,in_stack_fffffeb0,
                 in_stack_fffffeb4,in_stack_fffffeb8,in_stack_fffffebc,in_stack_fffffec0,
                 in_stack_fffffec4,in_stack_fffffec8,in_stack_fffffecc,in_stack_fffffed0,
                 in_stack_fffffed4,in_stack_fffffed8,in_stack_fffffedc,in_stack_fffffee0,
                 in_stack_fffffee4,in_stack_fffffee8,in_stack_fffffeec,in_stack_fffffef0,
                 in_stack_fffffef4,in_stack_fffffef8,in_stack_fffffefc,in_stack_ffffff00,
                 in_stack_ffffff04,in_stack_ffffff08,in_stack_ffffff0c,in_stack_ffffff10,
                 in_stack_ffffff14,in_stack_ffffff18,in_stack_ffffff1c,in_stack_ffffff20,
                 in_stack_ffffff24,in_stack_ffffff28,in_stack_ffffff2c,in_stack_ffffff30,
                 in_stack_ffffff34,in_stack_ffffff38,in_stack_ffffff3c,in_stack_ffffff40,
                 in_stack_ffffff44,in_stack_ffffff48,in_stack_ffffff4c,in_stack_ffffff50,
                 in_stack_ffffff54,in_stack_ffffff58,in_stack_ffffff5c,in_stack_ffffff60,
                 in_stack_ffffff64);
      BVar1 = FindNextFileA(hFindFile,(LPWIN32_FIND_DATAA)((intptr_t)register0x00000010 + -0x140));
    } while (BVar1 != 0);
  }
  value2 = ResourceIterator_Init(DAT_0057c5d8,acStackY_2f0 + 0x94);
  while (value2 != 0) {
    value2 = _strncmp(acStackY_2f0 + 0x94,s_daten__00563b14,6);
    if ((value2 == 0) && (cptr3 = _strstr(acStackY_2f0 + 0x94,&DAT_0056b33c), cptr3 != (char *)0x0)
       ) {
      MapList_AddIniRecord
                (arg1,acStackY_2f0 + 0x9a,unaff_ESI,unaff_EBX,in_stack_fffffda4,in_stack_fffffda8
                 ,in_stack_fffffdac,in_stack_fffffdb0,in_stack_fffffdb4,in_stack_fffffdb8,
                 in_stack_fffffdbc,in_stack_fffffdc0,in_stack_fffffdc4,in_stack_fffffdc8,
                 in_stack_fffffdcc,in_stack_fffffdd0,in_stack_fffffdd4,in_stack_fffffdd8,
                 in_stack_fffffddc,in_stack_fffffde0,in_stack_fffffde4,in_stack_fffffde8,
                 in_stack_fffffdec,in_stack_fffffdf0,in_stack_fffffdf4,in_stack_fffffdf8,
                 in_stack_fffffdfc,in_stack_fffffe00,in_stack_fffffe04,in_stack_fffffe08,
                 in_stack_fffffe0c,in_stack_fffffe10,in_stack_fffffe14,in_stack_fffffe18,
                 in_stack_fffffe1c,in_stack_fffffe20,in_stack_fffffe24,in_stack_fffffe28,
                 in_stack_fffffe2c,in_stack_fffffe30,in_stack_fffffe34,in_stack_fffffe38,
                 in_stack_fffffe3c,in_stack_fffffe40,in_stack_fffffe44,in_stack_fffffe48,
                 in_stack_fffffe4c,in_stack_fffffe50,in_stack_fffffe54,in_stack_fffffe58,
                 in_stack_fffffe5c,in_stack_fffffe60,in_stack_fffffe64,in_stack_fffffe68,
                 in_stack_fffffe6c,in_stack_fffffe70,in_stack_fffffe74,in_stack_fffffe78,
                 in_stack_fffffe7c,in_stack_fffffe80,in_stack_fffffe84,in_stack_fffffe88,
                 in_stack_fffffe8c,in_stack_fffffe90,in_stack_fffffe94,in_stack_fffffe98,
                 in_stack_fffffe9c,in_stack_fffffea0,in_stack_fffffea4,in_stack_fffffea8,
                 in_stack_fffffeac,in_stack_fffffeb0,in_stack_fffffeb4,in_stack_fffffeb8,
                 in_stack_fffffebc,in_stack_fffffec0,in_stack_fffffec4,in_stack_fffffec8,
                 in_stack_fffffecc,in_stack_fffffed0,in_stack_fffffed4,in_stack_fffffed8,
                 in_stack_fffffedc,in_stack_fffffee0,in_stack_fffffee4,in_stack_fffffee8,
                 in_stack_fffffeec,in_stack_fffffef0,in_stack_fffffef4,in_stack_fffffef8,
                 in_stack_fffffefc,in_stack_ffffff00,in_stack_ffffff04,in_stack_ffffff08,
                 in_stack_ffffff0c,in_stack_ffffff10,in_stack_ffffff14,in_stack_ffffff18,
                 in_stack_ffffff1c,in_stack_ffffff20,in_stack_ffffff24,in_stack_ffffff28,
                 in_stack_ffffff2c,in_stack_ffffff30,in_stack_ffffff34,in_stack_ffffff38,
                 in_stack_ffffff3c,in_stack_ffffff40,in_stack_ffffff44,in_stack_ffffff48,
                 in_stack_ffffff4c,in_stack_ffffff50,in_stack_ffffff54,in_stack_ffffff58,
                 in_stack_ffffff5c,in_stack_ffffff60,in_stack_ffffff64,in_stack_ffffff68);
    }
    value2 = ResourceIterator_Next(DAT_0057c5d8,acStackY_2f0 + 0x94);
  }
  return;
}
