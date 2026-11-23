// City_ConstructFromName: ported from Pizza Connection 2 at 0x4d44e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d44e0
#include "pc2_port.h"


uint32_t * __thiscall
City_ConstructFromName
          (void *self,char *arg1,uint32_t arg2,char *arg3,uint32_t arg4,int arg5,
          uint32_t arg6,char *arg7,uint32_t arg8,int arg9,uint32_t arg10,
          char *arg11,uint32_t arg12,int arg13,uint32_t arg14,char *arg15,
          uint32_t arg16,int arg17,uint32_t arg18,char *arg19,uint32_t arg20,
          int arg21,uint32_t arg22,char *arg23,uint32_t arg24,int arg25,
          uint32_t arg26,char *arg27,uint32_t arg28,int arg29,uint32_t arg30,
          char *arg31,uint32_t arg32,int arg33,uint32_t arg34,char *arg35,
          uint32_t arg36,int arg37,uint32_t arg38,char *arg39,uint32_t arg40,
          int arg41,uint32_t arg42,char *arg43,uint32_t arg44,int arg45)

{
  char cVar1;
  uint32_t *uptr2;
  void *pvVar3;
  uint32_t uvalue4;
  int value5;
  int unaff_EBX;
  uint32_t unaff_EBP;
  uint32_t unaff_ESI;
  uint32_t *uptr6;
  uint32_t *uptr7;
  uint8_t *unaff_EDI;
  char *cptr8;
  uint32_t *uptr9;
  int value10;
  uint32_t unaff_retaddr;
  char acStack_1bc [128];
  char *cptr11;
  char *cptr12;
  uint32_t in_stack_fffffee8;
  uint8_t *uptr13;
  uint32_t in_stack_fffffef0;
  int in_stack_fffffef4;
  uint32_t in_stack_fffffef8;
  char *in_stack_fffffefc;
  uint32_t in_stack_ffffff00;
  int in_stack_ffffff04;
  uint32_t in_stack_ffffff08;
  char *in_stack_ffffff0c;
  uint32_t in_stack_ffffff10;
  int in_stack_ffffff14;
  uint32_t in_stack_ffffff18;
  char *in_stack_ffffff1c;
  uint32_t in_stack_ffffff20;
  int in_stack_ffffff24;
  uint32_t in_stack_ffffff28;
  char *in_stack_ffffff2c;
  uint32_t in_stack_ffffff30;
  int in_stack_ffffff34;
  uint32_t in_stack_ffffff38;
  char *in_stack_ffffff3c;
  uint32_t in_stack_ffffff40;
  int in_stack_ffffff44;
  uint32_t in_stack_ffffff48;
  char *in_stack_ffffff4c;
  uint32_t in_stack_ffffff50;
  int in_stack_ffffff54;
  uint32_t in_stack_ffffff58;
  char *in_stack_ffffff5c;
  uint32_t in_stack_ffffff60;
  int in_stack_ffffff64;
  uint32_t in_stack_ffffff68;
  char *in_stack_ffffff6c;
  uint32_t in_stack_ffffff70;
  int in_stack_ffffff74;
  uint32_t in_stack_ffffff78;
  char *in_stack_ffffff7c;
  uint32_t in_stack_ffffff80;
  int in_stack_ffffff84;
  uint32_t in_stack_ffffff88;
  char *in_stack_ffffff8c;
  uint32_t in_stack_ffffff90;
  int in_stack_ffffff94;
  uint32_t in_stack_ffffff98;
  char *in_stack_ffffff9c;
  uint32_t in_stack_ffffffa0;
  int in_stack_ffffffa4;
  uint32_t in_stack_ffffffa8;
  uint8_t *in_stack_ffffffac;
  uint32_t in_stack_ffffffb0;
  int in_stack_ffffffb4;
  uint32_t in_stack_ffffffb8;
  char *in_stack_ffffffbc;
  uint32_t in_stack_ffffffc0;
  int in_stack_ffffffc4;
  uint32_t in_stack_ffffffc8;
  uint8_t *in_stack_ffffffcc;
  uint32_t in_stack_ffffffd0;
  int in_stack_ffffffd4;
  uint32_t in_stack_ffffffd8;
  char *in_stack_ffffffdc;
  uint32_t in_stack_ffffffe0;
  int in_stack_ffffffe4;
  uint32_t in_stack_ffffffe8;
  char *in_stack_ffffffec;
  uint32_t in_stack_fffffff0;
  void *pvVar14;
  uint8_t *uptr15;
  uint32_t uvalue16;
  char *cptr17;
  
                    /* Constructs a city from its ini, map, and sprite resources. */
  uptr15 = &LAB_00558dfe;
  pvVar14 = ExceptionList;
  ExceptionList = (void *)((intptr_t)register0x00000010 + -0xc);
  uptr13 = self;
  List_Construct((void *)((intptr_t)self + 0xfac),0);
  uvalue16 = 0;
  List_Construct((void *)((intptr_t)self + 0xfc8),0);
  uvalue4 = 0xffffffff;
  *(uint8_t ***)self = &PTR_City_Delete_0055c500;
  cptr17 = (char *)CONCAT31((int3)((uint32_t)uvalue16 >> 8),1);
  cptr8 = arg1;
  do {
    if (uvalue4 == 0) break;
    uvalue4 = uvalue4 - 1;
    cVar1 = *cptr8;
    cptr8 = cptr8 + 1;
  } while (cVar1 != '\0');
  for (value5 = ~uvalue4 - 2; (-1 < value5 && (arg1[value5] < '!')); value5 = value5 + -1) {
    arg1[value5] = '\0';
  }
  cptr8 = acStack_1bc + 0xac;
  cptr11 = s__s_ini_0056b380;
  cptr12 = arg1;
  String_Format(cptr8,(uint8_t *)s__s_ini_0056b380,arg1);
  uptr2 = CityDefinition_ParseIni
                     (DAT_0057c5d8,acStack_1bc + 0xac,cptr8,cptr11,(intptr_t)cptr12,unaff_ESI,
                      unaff_EDI,unaff_EBP,unaff_EBX,in_stack_fffffee8,uptr13,in_stack_fffffef0,
                      in_stack_fffffef4,in_stack_fffffef8,in_stack_fffffefc,in_stack_ffffff00,
                      in_stack_ffffff04,in_stack_ffffff08,in_stack_ffffff0c,in_stack_ffffff10,
                      in_stack_ffffff14,in_stack_ffffff18,in_stack_ffffff1c,in_stack_ffffff20,
                      in_stack_ffffff24,in_stack_ffffff28,in_stack_ffffff2c,in_stack_ffffff30,
                      in_stack_ffffff34,in_stack_ffffff38,in_stack_ffffff3c,in_stack_ffffff40,
                      in_stack_ffffff44,in_stack_ffffff48,in_stack_ffffff4c,in_stack_ffffff50,
                      in_stack_ffffff54,in_stack_ffffff58,in_stack_ffffff5c,in_stack_ffffff60,
                      in_stack_ffffff64,in_stack_ffffff68,in_stack_ffffff6c,in_stack_ffffff70,
                      in_stack_ffffff74,in_stack_ffffff78,in_stack_ffffff7c,in_stack_ffffff80,
                      in_stack_ffffff84,in_stack_ffffff88,in_stack_ffffff8c,in_stack_ffffff90,
                      in_stack_ffffff94,in_stack_ffffff98,in_stack_ffffff9c,in_stack_ffffffa0,
                      in_stack_ffffffa4,in_stack_ffffffa8,in_stack_ffffffac,in_stack_ffffffb0,
                      in_stack_ffffffb4,in_stack_ffffffb8,in_stack_ffffffbc,in_stack_ffffffc0,
                      in_stack_ffffffc4,in_stack_ffffffc8,in_stack_ffffffcc,in_stack_ffffffd0,
                      in_stack_ffffffd4,in_stack_ffffffd8,in_stack_ffffffdc,in_stack_ffffffe0,
                      in_stack_ffffffe4,in_stack_ffffffe8,in_stack_ffffffec,in_stack_fffffff0,
                      (intptr_t)pvVar14,uptr15,cptr17,unaff_retaddr,(intptr_t)arg1,arg2,arg3,
                      arg4,arg5,arg6,arg7,arg8,arg9,arg10,arg11,arg12,
                      arg13,arg14,arg15,arg16,arg17,arg18,arg19,arg20,
                      arg21,arg22,arg23,arg24,arg25,arg26,arg27,arg28,
                      arg29,arg30,arg31,arg32,arg33,arg34,arg35,arg36,
                      arg37,arg38,arg39,arg40,arg41,arg42,arg43,arg44,
                      arg45);
  if (uptr2 != (uint32_t *)0x0) {
    if (self == (void *)0x0) {
      uptr9 = (uint32_t *)0x0;
    }
    else {
      uptr9 = (uint32_t *)((intptr_t)self + 4);
    }
    uptr6 = uptr2;
    for (value5 = 0x306; value5 != 0; value5 = value5 + -1) {
      *uptr9 = *uptr6;
      uptr6 = uptr6 + 1;
      uptr9 = uptr9 + 1;
    }
  }
  Mem_Free(uptr2);
  *(uint32_t *)((intptr_t)self + 0x10ac) = 0;
  *(uint32_t *)((intptr_t)self + 0x10b0) = 0;
  *(uint32_t *)((intptr_t)self + 0x10b4) = 0;
  *(uint32_t *)((intptr_t)self + 0x10b8) = 0;
  *(uint32_t *)((intptr_t)self + 0x10c4) = 0;
  uvalue4 = Random_RangeFast(0x30,0xc0);
  *(uint32_t *)((intptr_t)self + 0x10c8) = uvalue4;
  uvalue4 = Random_RangeFast(0x18,0x60);
  *(uint32_t *)((intptr_t)self + 0x10cc) = uvalue4;
  *(uint32_t *)((intptr_t)self + 0x1148) = 0;
  *(uint32_t *)((intptr_t)self + 0x114c) = 0;
  *(uint32_t *)((intptr_t)self + 0x1154) = 0;
  *(uint32_t *)((intptr_t)self + 0x1150) = 0;
  *(uint32_t *)((intptr_t)self + 0x10bc) = 0xffffffff;
  Weather_SelectRandomState((intptr_t)self);
  *(uint32_t *)((intptr_t)self + 0xdc4) = 0;
  *(uint32_t *)((intptr_t)self + 0x10a4) = 0;
  uptr2 = (uint32_t *)((intptr_t)self + 0xcb0);
  uptr9 = (uint32_t *)((intptr_t)self + 0xc3c);
  value5 = 6;
  do {
    uptr9[-1] = 100;
    *uptr9 = 100;
    uptr9[1] = 100;
    uptr9[2] = 100;
    uptr2[-6] = 100;
    *uptr2 = 0;
    uptr2[6] = 0x3c;
    uptr2[0x24] = 100;
    uptr2 = uptr2 + 1;
    uptr9 = uptr9 + 4;
    value5 = value5 + -1;
  } while (value5 != 0);
  uptr2 = (uint32_t *)((intptr_t)self + 0xdac);
  for (value5 = 6; value5 != 0; value5 = value5 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0xd58);
  for (value5 = 0xc; value5 != 0; value5 = value5 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0xd88);
  for (value5 = 9; value5 != 0; value5 = value5 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0xce0);
  for (value5 = 0x18; value5 != 0; value5 = value5 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  uptr2 = (uint32_t *)((intptr_t)self + 0x10d4);
  value5 = 5;
  do {
    uptr2[-1] = 0xffffffff;
    *uptr2 = 0xffffffff;
    uptr2[1] = 0xffffffff;
    uptr2[3] = 0;
    uptr2[2] = 0;
    *(uint8_t *)(uptr2 + 4) = 0;
    *(uint8_t *)((intptr_t)uptr2 + 0x11) = 0;
    uptr2 = uptr2 + 6;
    value5 = value5 + -1;
  } while (value5 != 0);
  uptr7 = (uint32_t *)((intptr_t)self + 0xfe4);
  value5 = 8;
  do {
    value10 = 6;
    do {
      uvalue4 = Random_RangeFast(0,0x55);
      *uptr7 = uvalue4;
      uptr7 = uptr7 + 1;
      value10 = value10 + -1;
    } while (value10 != 0);
    value5 = value5 + -1;
  } while (value5 != 0);
  uptr2 = (uint32_t *)((intptr_t)self + 0xc20);
  for (value5 = 6; value5 != 0; value5 = value5 + -1) {
    *uptr2 = 0;
    uptr2 = uptr2 + 1;
  }
  String_Format(acStack_1bc + 0xac,(uint8_t *)s__s_iso_0056cd0c,arg1);
  pvVar3 = operator_new(0x10178);
  if (pvVar3 == (void *)0x0) {
    uptr2 = (uint32_t *)0x0;
  }
  else {
    uptr2 = IsoMap_Construct(pvVar3,(intptr_t)DAT_0057c5cc);
  }
  *(uint32_t **)((intptr_t)self + 0xfa8) = uptr2;
  Game_RegisterWorldObject(DAT_0057c5cc,uptr2,-1);
  if (DAT_0057ba10 != (uint32_t *)0x0) {
    (**(code **)*DAT_0057ba10)(1);
  }
  String_Format(acStack_1bc + 0xac,(uint8_t *)s_names__s_txt_00568358,(intptr_t)self + 0x44);
  pvVar3 = operator_new(0x18);
  if (pvVar3 == (void *)0x0) {
    DAT_0057ba10 = (uint32_t *)0x0;
  }
  else {
    DAT_0057ba10 = FileObject_Open(pvVar3,DAT_0057c5d8,acStack_1bc + 0xac,(uint32_t *)0x0);
  }
  Map_LoadMapSprite((intptr_t)self);
  ExceptionList = pvVar14;
  return self;
}
