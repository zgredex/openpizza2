// FullscreenImage_LoadTGA: ported from Pizza Connection 2 at 0x536350.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x536350
#include "pc2_port.h"


uint32_t __thiscall
FullscreenImage_LoadTGA(void *self,int arg1,char *arg2,void *arg3,uint8_t *arg4)

{
  bool flag1;
  uint8_t flag2;
  void *pvVar3;
  int *ptr4;
  char *cptr5;
  char *cptr6;
  uint32_t uvalue7;
  char cVar8;
  uint32_t uvalue9;
  uint32_t uvalue10;
  int value11;
  uint32_t uvalue12;
  int value13;
  uint8_t *bptr14;
  uint8_t *bptr15;
  char *cptr16;
  uint8_t *bptr17;
  bool flag18;
  FILE *local_750;
  int iStack_74c;
  char *pcStack_748;
  uint8_t *pbStack_73c;
  int iStack_738;
  int iStack_730;
  uint8_t abStack_724 [4];
  uint32_t local_720;
  short sStack_71b;
  uint32_t uStack_719;
  short local_714;
  short local_712;
  uint16_t local_710;
  uint8_t abStack_70c [1024];
  char acStack_30c [768];
  void *local_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;
  
  uStack_4 = 0xffffffff;
  puStack_8 = &LAB_0055acdc;
  local_c = ExceptionList;
  uvalue9 = 0xffffffff;
  do {
    cptr5 = arg2;
    if (uvalue9 == 0) break;
    uvalue9 = uvalue9 - 1;
    cptr5 = arg2 + 1;
    cVar8 = *arg2;
    arg2 = cptr5;
  } while (cVar8 != '\0');
  uvalue9 = ~uvalue9;
  cptr6 = (char *)((intptr_t)self + 0x1c);
  cptr5 = cptr5 + -uvalue9;
  cptr16 = cptr6;
  ExceptionList = &local_c;
  for (uvalue10 = uvalue9 >> 2; uvalue10 != 0; uvalue10 = uvalue10 - 1) {
    *(uint32_t *)cptr16 = *(uint32_t *)cptr5;
    cptr5 = cptr5 + 4;
    cptr16 = cptr16 + 4;
  }
  for (uvalue9 = uvalue9 & 3; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
    *cptr16 = *cptr5;
    cptr5 = cptr5 + 1;
    cptr16 = cptr16 + 1;
  }
  if (arg3 == (void *)0x0) {
    local_750 = (FILE *)CRT_Fopen(cptr6,&DAT_00563184);
    if (local_750 == (FILE *)0x0) {
      ExceptionList = local_c;
      return 0;
    }
    CRT_FreadLocked((char *)&local_720,1,0x12,(int *)local_750);
  }
  else {
    local_750 = (FILE *)Resource_Open(arg3,cptr6,0);
    if (local_750 == (FILE *)0x0) {
      ExceptionList = local_c;
      return 0;
    }
    Resource_Read(arg3,(char *)&local_720,0x12,(intptr_t)local_750);
  }
  if (((((uint16_t)((local_720) >> 8)) == '\t') || (((uint16_t)((local_720) >> 8)) == '\n')) ||
     (flag1 = false, ((uint16_t)((local_720) >> 8)) == '\v')) {
    flag1 = true;
  }
  flag2 = (uint8_t)local_710;
  *(uint8_t *)((intptr_t)self + 0x10) = flag2;
  flag18 = ((uint8_t)((uint16_t)local_710 >> 8) & 0x20) != 0x20;
  *(int *)((intptr_t)self + 4) = (intptr_t)local_714;
  *(int *)((intptr_t)self + 8) = (intptr_t)local_712;
  if (flag2 < 9) {
    *(uint8_t *)((intptr_t)self + 0x11) = 1;
  }
  else if (flag2 < 0x11) {
    *(uint8_t *)((intptr_t)self + 0x11) = 2;
  }
  else if (flag2 < 0x19) {
    *(uint8_t *)((intptr_t)self + 0x11) = 3;
  }
  else {
    *(uint8_t *)((intptr_t)self + 0x11) = 4;
  }
  if (arg4 != (uint8_t *)0x0) {
    (*(code *)arg4)((intptr_t)local_712);
  }
  if (arg3 == (void *)0x0) {
    CRT_Fseek((int *)local_750,(local_720 & 0xff) + 0x12,0);
  }
  else {
    Stream_Seek((local_720 & 0xff) + 0x12,(intptr_t)local_750,0);
  }
  if (((uint8_t)((local_720) >> 8)) == '\x01') {
    uvalue9 = (intptr_t)((intptr_t)sStack_71b * (uStack_719 & 0xff)) >> 3;
    cptr5 = acStack_30c;
    for (value11 = 0xc0; value11 != 0; value11 = value11 + -1) {
      cptr5[0] = '\0';
      cptr5[1] = '\0';
      cptr5[2] = '\0';
      cptr5[3] = '\0';
      cptr5 = cptr5 + 4;
    }
    if (arg3 == (void *)0x0) {
      CRT_FreadLocked(acStack_30c,1,uvalue9,(int *)local_750);
    }
    else {
      Resource_Read(arg3,acStack_30c,uvalue9,(intptr_t)local_750);
    }
    pvVar3 = operator_new(0x20c);
    uStack_4 = 0;
    if (pvVar3 == (void *)0x0) {
LAB_005365c1:
      ptr4 = (int *)0x0;
    }
    else {
      ptr4 = Palette_Init(pvVar3,(uint32_t)*(uint8_t *)(arg1 + 0x18),(uint32_t *)acStack_30c,0);
    }
  }
  else {
    if ((((uint16_t)((local_720) >> 8)) != '\x03') && (((uint16_t)((local_720) >> 8)) != '\v')) goto LAB_005365d1;
    value11 = 0;
    cptr5 = acStack_30c;
    do {
      cVar8 = (char)value11;
      *cptr5 = cVar8;
      cptr5[1] = cVar8;
      cptr5[2] = cVar8;
      cptr5 = cptr5 + 3;
      value11 = value11 + 1;
    } while (value11 < 0x100);
    pvVar3 = operator_new(0x20c);
    uStack_4 = 1;
    if (pvVar3 == (void *)0x0) goto LAB_005365c1;
    ptr4 = Palette_Init(pvVar3,(uint32_t)*(uint8_t *)(arg1 + 0x18),(uint32_t *)acStack_30c,0);
  }
  uStack_4 = 0xffffffff;
  *(int **)((intptr_t)self + 0x14) = ptr4;
LAB_005365d1:
  value11 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x11) * *(int *)((intptr_t)self + 4) * *(int *)((intptr_t)self + 8);
  *(int *)((intptr_t)self + 0xc) = value11;
  cptr5 = operator_new((value11 >> 1) * 2 + 2);
  uvalue9 = (uint32_t)*(uint8_t *)((intptr_t)self + 0x11) * *(int *)((intptr_t)self + 4);
  *(char **)((intptr_t)self + 0x18) = cptr5;
  if (flag1) {
    iStack_74c = *(int *)((intptr_t)self + 8) + -1;
    iStack_738 = 0;
    value11 = iStack_74c;
    if (!flag18) {
      value11 = (*(int *)((intptr_t)self + 8) - iStack_74c) + -1;
    }
    bptr14 = (uint8_t *)(cptr5 + value11 * uvalue9);
    if (arg3 == (void *)0x0) {
      CRT_FreadLocked((char *)abStack_70c,1,0x400,(int *)local_750);
      value11 = 0;
    }
    else {
      Resource_Read(arg3,(char *)abStack_70c,0x400,(intptr_t)local_750);
      value11 = 0;
    }
    do {
      flag2 = abStack_70c[value11];
      uvalue10 = (uint32_t)flag2;
      value11 = value11 + 1;
      if (value11 == 0x400) {
        if (arg3 == (void *)0x0) {
          CRT_FreadLocked((char *)abStack_70c,1,0x400,(int *)local_750);
        }
        else {
          Resource_Read(arg3,(char *)abStack_70c,0x400,(intptr_t)local_750);
        }
        value11 = 0;
      }
      if (flag2 < 0x80) {
        iStack_730 = 0;
        if (uvalue10 != 0xffffffff) {
          pbStack_73c = (uint8_t *)(cptr5 + iStack_74c * uvalue9);
          do {
            if (0x3ff < (intptr_t)((uint32_t)*(uint8_t *)((intptr_t)self + 0x11) + value11)) {
              value13 = -value11;
              uvalue7 = value13 + 0x400;
              bptr15 = abStack_70c + value11;
              bptr17 = abStack_70c;
              for (uvalue12 = uvalue7 >> 2; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
                *(uint32_t *)bptr17 = *(uint32_t *)bptr15;
                bptr15 = bptr15 + 4;
                bptr17 = bptr17 + 4;
              }
              for (uvalue12 = uvalue7 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
                *bptr17 = *bptr15;
                bptr15 = bptr15 + 1;
                bptr17 = bptr17 + 1;
              }
              if (arg3 == (void *)0x0) {
                CRT_FreadLocked(acStack_30c + value13,1,0x400 - uvalue7,(int *)local_750);
              }
              else {
                Resource_Read(arg3,acStack_30c + value13,0x400 - uvalue7,(intptr_t)local_750);
              }
              value11 = 0;
            }
            flag2 = *(uint8_t *)((intptr_t)self + 0x11);
            bptr15 = abStack_70c + value11;
            bptr17 = bptr14;
            for (uvalue7 = (uint32_t)(flag2 >> 2); uvalue7 != 0; uvalue7 = uvalue7 - 1) {
              *(uint32_t *)bptr17 = *(uint32_t *)bptr15;
              bptr15 = bptr15 + 4;
              bptr17 = bptr17 + 4;
            }
            for (uvalue7 = flag2 & 3; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
              *bptr17 = *bptr15;
              bptr15 = bptr15 + 1;
              bptr17 = bptr17 + 1;
            }
            value11 = value11 + (uint32_t)*(uint8_t *)((intptr_t)self + 0x11);
            iStack_738 = iStack_738 + 1;
            bptr14 = bptr14 + *(uint8_t *)((intptr_t)self + 0x11);
            if (iStack_738 == *(int *)((intptr_t)self + 4)) {
              iStack_74c = iStack_74c + -1;
              pbStack_73c = pbStack_73c + -uvalue9;
              iStack_738 = 0;
              if (arg4 != (uint8_t *)0x0) {
                (*(code *)arg4)(iStack_74c);
              }
              if (iStack_74c < 0) goto LAB_00536a5f;
              if (flag18) {
                bptr14 = pbStack_73c;
              }
              else {
                bptr14 = (uint8_t *)(cptr5 + ((*(int *)((intptr_t)self + 8) - iStack_74c) + -1) * uvalue9);
              }
            }
            iStack_730 = iStack_730 + 1;
          } while (iStack_730 < (intptr_t)(uvalue10 + 1));
        }
      }
      else {
        abStack_724[0] = 0;
        abStack_724[1] = 0;
        abStack_724[2] = 0;
        abStack_724[3] = 0;
        if (0x3ff < (intptr_t)((uint32_t)*(uint8_t *)((intptr_t)self + 0x11) + value11)) {
          value13 = -value11;
          uvalue7 = value13 + 0x400;
          bptr15 = abStack_70c + value11;
          bptr17 = abStack_70c;
          for (uvalue12 = uvalue7 >> 2; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
            *(uint32_t *)bptr17 = *(uint32_t *)bptr15;
            bptr15 = bptr15 + 4;
            bptr17 = bptr17 + 4;
          }
          for (uvalue12 = uvalue7 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
            *bptr17 = *bptr15;
            bptr15 = bptr15 + 1;
            bptr17 = bptr17 + 1;
          }
          if (arg3 == (void *)0x0) {
            CRT_FreadLocked(acStack_30c + value13,1,0x400 - uvalue7,(int *)local_750);
          }
          else {
            Resource_Read(arg3,acStack_30c + value13,0x400 - uvalue7,(intptr_t)local_750);
          }
          value11 = 0;
        }
        bptr15 = abStack_70c + value11;
        flag2 = *(uint8_t *)((intptr_t)self + 0x11);
        iStack_730 = 0;
        value11 = value11 + (uint32_t)flag2;
        bptr17 = abStack_724;
        for (uvalue7 = (uint32_t)(flag2 >> 2); uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *(uint32_t *)bptr17 = *(uint32_t *)bptr15;
          bptr15 = bptr15 + 4;
          bptr17 = bptr17 + 4;
        }
        for (uvalue7 = flag2 & 3; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
          *bptr17 = *bptr15;
          bptr15 = bptr15 + 1;
          bptr17 = bptr17 + 1;
        }
        if ((uvalue10 & 0x7f) != 0xffffffff) {
          pbStack_73c = (uint8_t *)(cptr5 + iStack_74c * uvalue9);
          do {
            flag2 = *(uint8_t *)((intptr_t)self + 0x11);
            bptr15 = abStack_724;
            bptr17 = bptr14;
            for (uvalue7 = (uint32_t)(flag2 >> 2); uvalue7 != 0; uvalue7 = uvalue7 - 1) {
              *(uint32_t *)bptr17 = *(uint32_t *)bptr15;
              bptr15 = bptr15 + 4;
              bptr17 = bptr17 + 4;
            }
            for (uvalue7 = flag2 & 3; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
              *bptr17 = *bptr15;
              bptr15 = bptr15 + 1;
              bptr17 = bptr17 + 1;
            }
            iStack_738 = iStack_738 + 1;
            bptr14 = bptr14 + *(uint8_t *)((intptr_t)self + 0x11);
            if (iStack_738 == *(int *)((intptr_t)self + 4)) {
              iStack_74c = iStack_74c + -1;
              pbStack_73c = pbStack_73c + -uvalue9;
              iStack_738 = 0;
              if (arg4 != (uint8_t *)0x0) {
                (*(code *)arg4)(iStack_74c);
              }
              if (iStack_74c < 0) goto LAB_00536a5f;
              if (flag18) {
                bptr14 = pbStack_73c;
              }
              else {
                bptr14 = (uint8_t *)(cptr5 + ((*(int *)((intptr_t)self + 8) - iStack_74c) + -1) * uvalue9);
              }
            }
            iStack_730 = iStack_730 + 1;
          } while (iStack_730 < (intptr_t)((uvalue10 & 0x7f) + 1));
        }
      }
    } while (-1 < iStack_74c);
  }
  else {
    value11 = *(int *)((intptr_t)self + 8);
    value13 = 0;
    if (0 < value11) {
      pcStack_748 = cptr5;
      do {
        if (arg4 != (uint8_t *)0x0) {
          (*(code *)arg4)((value11 - value13) + -1);
        }
        if (flag18) {
          cptr6 = cptr5 + ((*(int *)((intptr_t)self + 8) - value13) + -1) * uvalue9;
        }
        else {
          cptr6 = pcStack_748;
        }
        if (arg3 == (void *)0x0) {
          CRT_FreadLocked(cptr6,1,uvalue9,(int *)local_750);
        }
        else {
          Resource_Read(arg3,cptr6,uvalue9,(intptr_t)local_750);
        }
        value11 = *(int *)((intptr_t)self + 8);
        value13 = value13 + 1;
        pcStack_748 = pcStack_748 + uvalue9;
      } while (value13 < value11);
    }
  }
LAB_00536a5f:
  if (arg3 == (void *)0x0) {
    CRT_Fclose(local_750);
  }
  else {
    Resource_Close(arg3,(intptr_t)local_750);
  }
  ExceptionList = local_c;
  return 1;
}
