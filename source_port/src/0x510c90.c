// Recipe_CreateGenerated: ported from Pizza Connection 2 at 0x510c90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510c90
#include "pc2_port.h"


uint8_t * __thiscall
Recipe_CreateGenerated(void *self,int arg1,uint32_t arg2,int arg3,float arg4,int arg5)

{
  float fVar1;
  uint8_t flag2;
  int *ptr3;
  uint32_t uvalue4;
  uint32_t uvalue5;
  int value6;
  int value7;
  int value8;
  char cVar9;
  char *cptr10;
  char *cptr11;
  char *cptr12;
  float *fptr13;
  uint32_t *uptr14;
  double fVar15;
  int64_t lvalue16;
  int64_t lvalue17;
  uint64_t uvalue18;
  float *fptr19;
  uint8_t flag20;
  uint32_t uvalue21;
  uint32_t uvalue22;
  int value23;
  uint32_t local_5c;
  uint32_t local_58;
  void *local_54;
  uint32_t local_50;
  float *local_4c;
  void *local_48;
  float local_44 [7];
  float local_28 [7];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055a47b;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  local_48 = self;
  List_Construct((void *)((intptr_t)self + 0x48),0);
  local_4 = 0;
  *(uint8_t ***)self = &PTR_Recipe_Delete_0055c698;
  *(uint32_t *)((intptr_t)self + 0x304) = 0;
  *(uint8_t *)((intptr_t)self + 0x1dc) = 0;
  *(uint8_t *)((intptr_t)self + 0x1dd) = 0;
  *(uint32_t *)((intptr_t)self + 0x308) = arg2;
  cptr12 = self;
  if (arg5 == 1) {
    cptr10 = DAT_00582788;
LAB_00510d4c:
    uvalue4 = 0xffffffff;
    do {
      cptr11 = cptr10;
      if (uvalue4 == 0) break;
      uvalue4 = uvalue4 - 1;
      cptr11 = cptr10 + 1;
      cVar9 = *cptr10;
      cptr10 = cptr11;
    } while (cVar9 != '\0');
    uvalue4 = ~uvalue4;
    cptr10 = cptr11 + -uvalue4;
    for (uvalue5 = uvalue4 >> 2; cptr12 = cptr12 + 4, uvalue5 != 0; uvalue5 = uvalue5 - 1) {
      *(uint32_t *)cptr12 = *(uint32_t *)cptr10;
      cptr10 = cptr10 + 4;
    }
LAB_00510d64:
    for (uvalue4 = uvalue4 & 3; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
      *cptr12 = *cptr10;
      cptr10 = cptr10 + 1;
      cptr12 = cptr12 + 1;
    }
  }
  else {
    if (arg5 == 2) {
      uvalue4 = 0xffffffff;
      cptr10 = DAT_005828ec;
      do {
        cptr11 = cptr10;
        if (uvalue4 == 0) break;
        uvalue4 = uvalue4 - 1;
        cptr11 = cptr10 + 1;
        cVar9 = *cptr10;
        cptr10 = cptr11;
      } while (cVar9 != '\0');
      uvalue4 = ~uvalue4;
      cptr10 = cptr11 + -uvalue4;
      for (uvalue5 = uvalue4 >> 2; cptr12 = cptr12 + 4, uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *(uint32_t *)cptr12 = *(uint32_t *)cptr10;
        cptr10 = cptr10 + 4;
      }
      goto LAB_00510d64;
    }
    if (arg5 == 3) {
      cptr10 = DAT_0058207c;
      goto LAB_00510d4c;
    }
    String_Format((uint8_t *)((intptr_t)self + 4),(uint8_t *)s__s__s_00563314,DAT_005827a0);
  }
  Company_GenerateUniqueName(arg1,self,(char *)((intptr_t)self + 4));
  uptr14 = (uint32_t *)((intptr_t)self + 100);
  for (value6 = 0x56; value6 != 0; value6 = value6 + -1) {
    *uptr14 = 0;
    uptr14 = uptr14 + 1;
  }
  uptr14 = (uint32_t *)((intptr_t)self + 0x1e0);
  for (value6 = 0x18; value6 != 0; value6 = value6 + -1) {
    *uptr14 = 0;
    uptr14 = uptr14 + 1;
  }
  uptr14 = (uint32_t *)((intptr_t)self + 0x1bc);
  for (value6 = 7; value6 != 0; value6 = value6 + -1) {
    *uptr14 = 0;
    uptr14 = uptr14 + 1;
  }
  Game_ResetStats((intptr_t)self);
  local_54 = (void *)IDMap_Lookup((void *)((intptr_t)DAT_0057c670 + 4),(intptr_t)arg4,(int *)0x0);
  Game_GetPlayerBySlot(DAT_0057c670,arg1);
  if (arg3 == 0) {
    value6 = 0x14;
  }
  else if (arg3 == 1) {
    value6 = 0x32;
  }
  else {
    value6 = 100;
  }
  ptr3 = Resource_Open(DAT_0057c5d8,s_Ingredients_tab_00573ae0,0);
  *(int **)((intptr_t)self + 0x310) = ptr3;
  fptr13 = local_44;
  for (value7 = 7; value7 != 0; value7 = value7 + -1) {
    *fptr13 = 0.0;
    fptr13 = fptr13 + 1;
  }
  fptr13 = local_28;
  for (value7 = 7; value7 != 0; value7 = value7 + -1) {
    *fptr13 = 0.0;
    fptr13 = fptr13 + 1;
  }
  if (arg5 != -1) {
    Output_StorePair(&local_58,&local_5c,0x43160000,0x43480000);
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    uvalue4 = Random_RangeFast((intptr_t)lvalue16,uvalue4);
    arg4 = (float)(intptr_t)uvalue4;
    if (arg5 == 1) {
      Output_StorePair(local_28 + 3,local_44 + 3,0,0);
      Output_StorePair(local_28 + 2,local_44 + 2,0x42200000,0x425c0000);
      Output_StorePair(local_28 + 6,local_44 + 6,0,0x41200000);
      Output_StorePair(local_28 + 1,local_44 + 1,0x41c80000,0x42200000);
      uvalue22 = 0;
      goto LAB_00511774;
    }
    if ((arg5 < 2) || (3 < arg5)) goto switchD_00510e54_default;
    Output_StorePair(local_28 + 3,local_44 + 3,0x41f00000,0x42200000);
    Output_StorePair(local_28 + 2,local_44 + 2,0x41a00000,0x41f00000);
    Output_StorePair(local_28 + 6,local_44 + 6,0,0x41200000);
    Output_StorePair(local_28 + 1,local_44 + 1,0x41a00000,0x41f00000);
    uvalue22 = 0;
    uvalue21 = 0;
    goto LAB_00511780;
  }
  uvalue4 = Random_RangeFast(1,10);
  if ((intptr_t)uvalue4 < 5) {
    cVar9 = ((intptr_t)uvalue4 < 3) + '\x01';
  }
  else {
    cVar9 = '\0';
  }
  switch(arg2) {
  case 0:
    Output_StorePair(&local_58,&local_5c,0x43490000,0x43fa0000);
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    uvalue4 = Random_RangeFast((intptr_t)lvalue16,uvalue4);
    if (cVar9 == '\0') {
      uvalue21 = 0x41f00000;
      fptr13 = local_44 + 3;
      uvalue22 = 0x41300000;
      fptr19 = local_28 + 3;
LAB_0051106f:
      Output_StorePair(fptr19,fptr13,uvalue22,uvalue21);
    }
    else {
      if (cVar9 == '\x01') {
        uvalue21 = 0x41f00000;
        fptr13 = local_44 + 4;
        uvalue22 = 0x41300000;
        fptr19 = local_28 + 4;
        goto LAB_0051106f;
      }
      if (cVar9 == '\x02') {
        Output_StorePair(local_28 + 3,local_44 + 3,0x40c00000,0x41a00000);
        uvalue21 = 0x41200000;
        fptr13 = local_44 + 4;
        uvalue22 = 0x40a00000;
        fptr19 = local_28 + 4;
        goto LAB_0051106f;
      }
    }
    uvalue21 = 0x425c0000;
    uvalue22 = 0x41f80000;
    goto LAB_00511080;
  case 1:
    Output_StorePair(&local_58,&local_5c,0x43490000,0x43fa0000);
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    uvalue4 = Random_RangeFast((intptr_t)lvalue16,uvalue4);
    if (cVar9 == '\0') {
      uvalue21 = 0x41f00000;
      fptr13 = local_44 + 3;
      uvalue22 = 0x41300000;
      fptr19 = local_28 + 3;
LAB_00511164:
      Output_StorePair(fptr19,fptr13,uvalue22,uvalue21);
    }
    else {
      if (cVar9 == '\x01') {
        uvalue21 = 0x41f00000;
        fptr13 = local_44 + 4;
        uvalue22 = 0x41300000;
        fptr19 = local_28 + 4;
        goto LAB_00511164;
      }
      if (cVar9 == '\x02') {
        Output_StorePair(local_28 + 3,local_44 + 3,0x40c00000,0x41a00000);
        uvalue21 = 0x41200000;
        fptr13 = local_44 + 4;
        uvalue22 = 0x40a00000;
        fptr19 = local_28 + 4;
        goto LAB_00511164;
      }
    }
    Output_StorePair(local_28 + 2,local_44 + 2,0x41f80000,0x420c0000);
    Output_StorePair(local_28 + 6,local_44 + 6,0,0x40a00000);
    uvalue21 = 0x41200000;
    uvalue22 = 0x41000000;
    goto LAB_00511454;
  case 2:
    Output_StorePair(&local_58,&local_5c,0x43160000,0x43fa0000);
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    uvalue4 = Random_RangeFast((intptr_t)lvalue16,uvalue4);
    arg4 = (float)(intptr_t)uvalue4;
    if (cVar9 == '\0') {
      uvalue22 = 0x41200000;
      fptr13 = local_44 + 3;
      fptr19 = local_28 + 3;
LAB_0051124d:
      Output_StorePair(fptr19,fptr13,0,uvalue22);
    }
    else {
      if (cVar9 == '\x01') {
        uvalue22 = 0x41200000;
        fptr13 = local_44 + 4;
        fptr19 = local_28 + 4;
        goto LAB_0051124d;
      }
      if (cVar9 == '\x02') {
        Output_StorePair(local_28 + 3,local_44 + 3,0,0x40a00000);
        uvalue22 = 0x40a00000;
        fptr13 = local_44 + 4;
        fptr19 = local_28 + 4;
        goto LAB_0051124d;
      }
    }
    Output_StorePair(local_28 + 2,local_44 + 2,0x41300000,0x41700000);
    Output_StorePair(local_28 + 6,local_44 + 6,0,0x40a00000);
    Output_StorePair(local_28 + 1,local_44 + 1,0x41f80000,0x420c0000);
    uvalue22 = 0x42340000;
    uvalue21 = 0x41f80000;
    break;
  case 3:
    Output_StorePair(&local_58,&local_5c,0x43968000,0x43fa0000);
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    uvalue4 = Random_RangeFast((intptr_t)lvalue16,uvalue4);
    if (cVar9 == '\0') {
      uvalue21 = 0x425c0000;
      fptr13 = local_44 + 3;
      uvalue22 = 0x41f80000;
      fptr19 = local_28 + 3;
LAB_0051135d:
      Output_StorePair(fptr19,fptr13,uvalue22,uvalue21);
    }
    else {
      if (cVar9 == '\x01') {
        uvalue21 = 0x425c0000;
        fptr13 = local_44 + 4;
        uvalue22 = 0x41f80000;
        fptr19 = local_28 + 4;
        goto LAB_0051135d;
      }
      if (cVar9 == '\x02') {
        Output_StorePair(local_28 + 3,local_44 + 3,0x41a00000,0x41f00000);
        uvalue21 = 0x41c80000;
        fptr13 = local_44 + 4;
        uvalue22 = 0x41300000;
        fptr19 = local_28 + 4;
        goto LAB_0051135d;
      }
    }
    uvalue21 = 0x41f00000;
    uvalue22 = 0x41300000;
LAB_00511080:
    Output_StorePair(local_28 + 2,local_44 + 2,uvalue22,uvalue21);
    Output_StorePair(local_28 + 6,local_44 + 6,0,0x40a00000);
    uvalue21 = 0x41200000;
    uvalue22 = 0x41000000;
LAB_00511662:
    arg4 = (float)(intptr_t)uvalue4;
    Output_StorePair(local_28 + 1,local_44 + 1,uvalue22,uvalue21);
    uvalue22 = 0x41200000;
LAB_00511774:
    uvalue21 = 0;
    break;
  case 4:
    Output_StorePair(&local_58,&local_5c,0x43160000,0x43960000);
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    uvalue4 = Random_RangeFast((intptr_t)lvalue16,uvalue4);
    if (cVar9 == '\0') {
      uvalue22 = 0x41700000;
      fptr13 = local_44 + 3;
      fptr19 = local_28 + 3;
LAB_00511413:
      Output_StorePair(fptr19,fptr13,0,uvalue22);
    }
    else {
      if (cVar9 == '\x01') {
        uvalue22 = 0x41700000;
        fptr13 = local_44 + 4;
        fptr19 = local_28 + 4;
        goto LAB_00511413;
      }
      if (cVar9 == '\x02') {
        Output_StorePair(local_28 + 3,local_44 + 3,0,0x41200000);
        uvalue22 = 0x40a00000;
        fptr13 = local_44 + 4;
        fptr19 = local_28 + 4;
        goto LAB_00511413;
      }
    }
    Output_StorePair(local_28 + 2,local_44 + 2,0,0x41200000);
    Output_StorePair(local_28 + 6,local_44 + 6,0,0x40a00000);
    uvalue21 = 0x42200000;
    uvalue22 = 0x41f80000;
LAB_00511454:
    arg4 = (float)(intptr_t)uvalue4;
    Output_StorePair(local_28 + 1,local_44 + 1,uvalue22,uvalue21);
    uvalue22 = 0x42200000;
    uvalue21 = 0x41800000;
    break;
  case 5:
    Output_StorePair(&local_58,&local_5c,0x43160000,0x43480000);
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    uvalue4 = Random_RangeFast((intptr_t)lvalue16,uvalue4);
    arg4 = (float)(intptr_t)uvalue4;
    if (cVar9 == '\0') {
      uvalue22 = 0x41200000;
      fptr13 = local_44 + 3;
      fptr19 = local_28 + 3;
LAB_00511514:
      Output_StorePair(fptr19,fptr13,0,uvalue22);
    }
    else {
      if (cVar9 == '\x01') {
        uvalue22 = 0x41200000;
        fptr13 = local_44 + 4;
        fptr19 = local_28 + 4;
        goto LAB_00511514;
      }
      if (cVar9 == '\x02') {
        Output_StorePair(local_28 + 3,local_44 + 3,0,0x40a00000);
        uvalue22 = 0x40a00000;
        fptr13 = local_44 + 4;
        fptr19 = local_28 + 4;
        goto LAB_00511514;
      }
    }
    Output_StorePair(local_28 + 2,local_44 + 2,0,0x41200000);
    Output_StorePair(local_28 + 6,local_44 + 6,0,0x40a00000);
    Output_StorePair(local_28 + 1,local_44 + 1,0x41800000,0x420c0000);
    uvalue22 = 0x425c0000;
    uvalue21 = 0x41f80000;
    break;
  case 6:
    Output_StorePair(&local_58,&local_5c,0x43160000,0x43960000);
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    uvalue4 = Random_RangeFast((intptr_t)lvalue16,uvalue4);
    if (cVar9 == '\0') {
      uvalue21 = 0x42700000;
      fptr13 = local_44 + 3;
      uvalue22 = 0x41f80000;
      fptr19 = local_28 + 3;
LAB_00511621:
      Output_StorePair(fptr19,fptr13,uvalue22,uvalue21);
    }
    else {
      if (cVar9 == '\x01') {
        uvalue21 = 0x42700000;
        fptr13 = local_44 + 4;
        uvalue22 = 0x41f80000;
        fptr19 = local_28 + 4;
        goto LAB_00511621;
      }
      if (cVar9 == '\x02') {
        Output_StorePair(local_28 + 3,local_44 + 3,0x41a00000,0x41f00000);
        uvalue21 = 0x41f00000;
        fptr13 = local_44 + 4;
        uvalue22 = 0x41300000;
        fptr19 = local_28 + 4;
        goto LAB_00511621;
      }
    }
    Output_StorePair(local_28 + 2,local_44 + 2,0,0x41200000);
    Output_StorePair(local_28 + 6,local_44 + 6,0,0x40a00000);
    uvalue21 = 0x41f00000;
    uvalue22 = 0x41200000;
    goto LAB_00511662;
  case 7:
    Output_StorePair(&local_58,&local_5c,0x43160000,0x43fa0000);
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    uvalue4 = Random_RangeFast((intptr_t)lvalue16,uvalue4);
    arg4 = (float)(intptr_t)uvalue4;
    if (cVar9 == '\0') {
      uvalue22 = 0x420c0000;
      fptr13 = local_44 + 3;
      fptr19 = local_28 + 3;
LAB_0051171d:
      Output_StorePair(fptr19,fptr13,0,uvalue22);
    }
    else {
      if (cVar9 == '\x01') {
        uvalue22 = 0x420c0000;
        fptr13 = local_44 + 4;
        fptr19 = local_28 + 4;
        goto LAB_0051171d;
      }
      if (cVar9 == '\x02') {
        Output_StorePair(local_28 + 3,local_44 + 3,0,0x41a00000);
        uvalue22 = 0x41700000;
        fptr13 = local_44 + 4;
        fptr19 = local_28 + 4;
        goto LAB_0051171d;
      }
    }
    Output_StorePair(local_28 + 2,local_44 + 2,0,0x41f00000);
    Output_StorePair(local_28 + 6,local_44 + 6,0,0x40a00000);
    Output_StorePair(local_28 + 1,local_44 + 1,0x41200000,0x420c0000);
    uvalue22 = 0x420c0000;
    goto LAB_00511774;
  default:
    goto switchD_00510e54_default;
  }
LAB_00511780:
  Output_StorePair(local_28 + 5,local_44 + 5,uvalue21,uvalue22);
switchD_00510e54_default:
  local_4c = (float *)((100 - value6) * 2);
  local_50 = Random_RangeFast(0,(intptr_t)local_4c / 2);
  value7 = 0;
  fVar1 = ((float)(intptr_t)local_50 + arg4) - (float)(intptr_t)local_4c;
  uptr14 = (uint32_t *)((intptr_t)self + 0x314);
  for (value8 = 7; value8 != 0; value8 = value8 + -1) {
    *uptr14 = 0;
    uptr14 = uptr14 + 1;
  }
  do {
    value8 = value7 + 4;
    *(float *)((intptr_t)local_28 + value7) = *(float *)((intptr_t)local_28 + value7) * 0.01 * fVar1;
    *(float *)((intptr_t)local_44 + value7) = *(float *)((intptr_t)local_44 + value7) * 0.01 * fVar1;
    value7 = value8;
  } while (value8 < 0x1c);
  value7 = 1;
  value8 = 0;
  while (value8 = value8 + 1, value8 < 0x3e9) {
    lvalue16 = __ftol();
    uvalue4 = (uint32_t)lvalue16;
    lvalue16 = __ftol();
    local_4c = (float *)Random_RangeFast((intptr_t)lvalue16,uvalue4);
    fVar1 = (float)(intptr_t)local_4c + *(float *)((intptr_t)self + value7 * 4 + 0x314);
    *(float *)((intptr_t)self + value7 * 4 + 0x314) = fVar1;
    if (local_44[value7] < fVar1) {
      *(float *)((intptr_t)self + value7 * 4 + 0x314) = local_44[value7];
    }
    lvalue16 = __ftol();
    lvalue17 = __ftol();
    if ((intptr_t)lvalue17 <= (intptr_t)lvalue16) break;
    value7 = value7 + 1;
    if (6 < value7) {
      value7 = 1;
    }
  }
  value7 = *(int *)((intptr_t)DAT_0057c670 + 0xa8);
  flag2 = Game_GetMaxIndex4(value7);
  uvalue18 = __ftol();
  uvalue4 = (intptr_t)uvalue18 >> 0x1f;
  value8 = (intptr_t)((int64_t)((uint64_t)uvalue4 << 0x20 | uvalue18 & 0xffffffff) /
               (int64_t)*(int *)(value7 + 0xac + (uint32_t)flag2 * 4));
  if (value8 < 0x18) {
    flag2 = 3;
    value8 = (intptr_t)((int64_t)((uint64_t)uvalue4 << 0x20 | uvalue18 & 0xffffffff) /
                 (int64_t)*(int *)(value7 + 0xb8));
  }
  if (0xf < value8) {
    value23 = 0x10;
    local_4c = (float *)((intptr_t)self + (uint32_t)*(uint8_t *)(value7 + 0xa8) * 4 + 0x314);
    uvalue22 = *(uint32_t *)(*(int *)((intptr_t)DAT_0057c670 + 0xa0) + 0x18);
    flag20 = flag2;
    uvalue4 = Random_RangeFast(1,0x20);
    fVar15 = Recipe_StreamConstruct(self,uvalue22,5,value7,uvalue4,flag20,value23);
    value8 = value8 + -0x10;
    *local_4c = (float)((double)*local_4c - fVar15);
  }
  if (7 < value8) {
    value23 = 8;
    local_4c = (float *)((intptr_t)self + (uint32_t)*(uint8_t *)(value7 + 0xa8) * 4 + 0x314);
    uvalue22 = *(uint32_t *)(*(int *)((intptr_t)DAT_0057c670 + 0xa0) + 0x18);
    flag20 = flag2;
    uvalue4 = Random_RangeFast(1,0x20);
    fVar15 = Recipe_StreamConstruct(self,uvalue22,8,value7,uvalue4,flag20,value23);
    value8 = value8 + -8;
    *local_4c = (float)((double)*local_4c - fVar15);
  }
  if (3 < value8) {
    value23 = 4;
    local_4c = (float *)((intptr_t)self + (uint32_t)*(uint8_t *)(value7 + 0xa8) * 4 + 0x314);
    uvalue22 = *(uint32_t *)(*(int *)((intptr_t)DAT_0057c670 + 0xa0) + 0x18);
    flag20 = flag2;
    uvalue4 = Random_RangeFast(1,0x20);
    fVar15 = Recipe_StreamConstruct(self,uvalue22,10,value7,uvalue4,flag20,value23);
    value8 = value8 + -4;
    *local_4c = (float)((double)*local_4c - fVar15);
  }
  if (0 < value8) {
    fptr13 = (float *)((intptr_t)self + (uint32_t)*(uint8_t *)(value7 + 0xa8) * 4 + 0x314);
    fVar15 = Recipe_StreamConstruct
                       (self,*(uint32_t *)(*(int *)((intptr_t)DAT_0057c670 + 0xa0) + 0x18),0xd,value7,1,
                        flag2,1);
    *fptr13 = (float)((double)*fptr13 - fVar15);
  }
  if (0.0 < *(float *)((intptr_t)self + 800)) {
    Recipe_AddCategoryIngredients(self,local_54,arg2,value6,3,3,arg5);
  }
  if (0.0 < *(float *)((intptr_t)self + 0x324)) {
    Recipe_AddCategoryIngredients(self,local_54,arg2,value6,3,4,arg5);
  }
  if (0.0 < *(float *)((intptr_t)self + 0x328)) {
    Recipe_AddCategoryIngredients(self,local_54,arg2,value6,3,5,arg5);
  }
  if (0.0 < *(float *)((intptr_t)self + 0x318)) {
    Recipe_AddCategoryIngredients(self,local_54,arg2,value6,2,1,arg5);
  }
  if (0.0 < *(float *)((intptr_t)self + 0x31c)) {
    Recipe_AddCategoryIngredients(self,local_54,arg2,value6,2,2,arg5);
  }
  if (0.0 < *(float *)((intptr_t)self + 0x32c)) {
    Recipe_AddCategoryIngredients(self,local_54,arg2,value6,2,6,arg5);
  }
  Recipe_RecomputeAllStats(self,arg1);
  Resource_Close(DAT_0057c5d8,*(int *)((intptr_t)self + 0x310));
  PlayerStats_Reset((intptr_t)self);
  fVar15 = Game_GetPlayerWeightedStat((intptr_t)self);
  *(float *)((intptr_t)self + 0x44) = (float)fVar15;
  ExceptionList = local_c;
  return self;
}
