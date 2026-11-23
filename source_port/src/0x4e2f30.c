// Game_BuildCompanyStatusText: ported from Pizza Connection 2 at 0x4e2f30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e2f30
#include "pc2_port.h"

void __thiscall Game_BuildCompanyStatusText(void *self,int arg1,int *arg2,char *arg3)

{
  char cVar1;
  int value2;
  bool flag3;
  bool flag4;
  int *ptr5;
  int value6;
  int value7;
  uint32_t uvalue8;
  uint32_t uvalue9;
  char *cptr10;
  char *cptr11;
  char *cptr12;
  int *local_7c;
  int local_78 [30];
  
  ptr5 = local_78;
  for (value7 = 0x1e; value7 != 0; value7 = value7 + -1) {
    *ptr5 = 0;
    ptr5 = ptr5 + 1;
  }
  value7 = 0;
  flag4 = false;
  flag3 = false;
  if (0 < *(int *)((intptr_t)self + 0x1cc)) {
    do {
      ptr5 = (int *)IDMap_Lookup((void *)((intptr_t)self + 0x1b8),value7,(int *)0x0);
      value6 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),*ptr5,(int *)0x0);
      if (*(int *)(value6 + 0x74) == 0) {
        if ((*(int *)(value6 + 0xfc) == arg1) && (*(int *)(value6 + 0xa4) != -1)) {
          value2 = *(int *)(value6 + 0x30);
          local_78[*(int *)(value6 + 0xa4)] = 1;
          if (value2 == 0x1d) {
            arg2[6] = arg2[6] + 1;
          }
          else if (value2 == 0x1e) {
            arg2[4] = arg2[4] + 1;
          }
          else if (value2 == 0x1f) {
            arg2[2] = arg2[2] + 1;
          }
        }
      }
      else if ((*(int *)(value6 + 0xf4) == arg1) && (*(int *)(value6 + 0xa4) != -1)) {
        value2 = *(int *)(value6 + 0x30);
        local_78[*(int *)(value6 + 0xa4)] = 1;
        if (value2 == 0x1d) {
          arg2[7] = arg2[7] + 1;
        }
        else if (value2 == 0x1e) {
          arg2[5] = arg2[5] + 1;
        }
        else if (value2 == 0x1f) {
          arg2[3] = arg2[3] + 1;
        }
      }
      value7 = value7 + 1;
    } while (value7 < *(int *)((intptr_t)self + 0x1cc));
  }
  value7 = 0;
  if (0 < *(int *)(DAT_0057c670 + 0x50)) {
    do {
      value6 = IDMap_Lookup((void *)(DAT_0057c670 + 0x3c),value7,(int *)0x0);
      if (((*(int *)(value6 + 0x110) == *(int *)((intptr_t)self + 0x48)) &&
          (*(int *)(value6 + 0x30) == 0x16)) && (*(int *)(value6 + 0xa4) != -1)) {
        if (*(int *)(value6 + 0x74) == 0) {
          if (*(int *)(value6 + 0xfc) == arg1) {
            *arg2 = *arg2 + 1;
            local_78[*(int *)(value6 + 0xa4)] = 1;
          }
        }
        else if (*(int *)(value6 + 0xf4) == arg1) {
          arg2[1] = arg2[1] + 1;
          local_78[*(int *)(value6 + 0xa4)] = 1;
        }
      }
      value7 = value7 + 1;
    } while (value7 < *(int *)(DAT_0057c670 + 0x50));
  }
  value6 = 0;
  ptr5 = local_78;
  value7 = -5;
  do {
    if (0 < *ptr5) {
      value6 = value6 + 1;
      switch(value7) {
      case 0:
      case 1:
      case 10:
      case 0xb:
      case 0xc:
      case 0x18:
        flag3 = true;
        break;
      default:
        flag4 = true;
      }
    }
    ptr5 = ptr5 + 1;
    value2 = value7 + 6;
    value7 = value7 + 1;
  } while (value2 < 0x1e);
  if (value6 < 5) {
    local_7c = local_78;
    value7 = -1;
    do {
      if (0 < *local_7c) {
        switch(value7) {
        case 0:
          cptr10 = DAT_00582bc4;
          break;
        case 1:
          cptr10 = DAT_00582024;
          break;
        case 2:
          cptr10 = DAT_0058200c;
          break;
        default:
          goto switchD_004e3219_caseD_3;
        case 4:
          cptr10 = DAT_00582698;
          break;
        case 5:
          cptr10 = DAT_00580e1c;
          break;
        case 6:
          cptr10 = DAT_005827c4;
          break;
        case 8:
          cptr10 = DAT_00582fa4;
          break;
        case 0xc:
          cptr10 = DAT_00581788;
          break;
        case 0xd:
          cptr10 = DAT_00580f4c;
          break;
        case 0xe:
          cptr10 = DAT_00582398;
          break;
        case 0xf:
          cptr10 = DAT_005828a8;
          break;
        case 0x10:
          cptr10 = DAT_00582a70;
          break;
        case 0x18:
        case 0x19:
          cptr10 = DAT_00582918;
          break;
        case 0x1c:
          cptr10 = DAT_00582aac;
        }
        uvalue8 = 0xffffffff;
        do {
          cptr11 = cptr10;
          if (uvalue8 == 0) break;
          uvalue8 = uvalue8 - 1;
          cptr11 = cptr10 + 1;
          cVar1 = *cptr10;
          cptr10 = cptr11;
        } while (cVar1 != '\0');
        uvalue8 = ~uvalue8;
        value6 = -1;
        cptr10 = arg3;
        do {
          cptr12 = cptr10;
          if (value6 == 0) break;
          value6 = value6 + -1;
          cptr12 = cptr10 + 1;
          cVar1 = *cptr10;
          cptr10 = cptr12;
        } while (cVar1 != '\0');
        cptr10 = cptr11 + -uvalue8;
        cptr11 = cptr12 + -1;
        for (uvalue9 = uvalue8 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
          *(uint32_t *)cptr11 = *(uint32_t *)cptr10;
          cptr10 = cptr10 + 4;
          cptr11 = cptr11 + 4;
        }
        for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
          *cptr11 = *cptr10;
          cptr10 = cptr10 + 1;
          cptr11 = cptr11 + 1;
        }
switchD_004e3219_caseD_3:
        uvalue8 = 0xffffffff;
        cptr10 = &DAT_0056d140;
        do {
          cptr11 = cptr10;
          if (uvalue8 == 0) break;
          uvalue8 = uvalue8 - 1;
          cptr11 = cptr10 + 1;
          cVar1 = *cptr10;
          cptr10 = cptr11;
        } while (cVar1 != '\0');
        uvalue8 = ~uvalue8;
        value6 = -1;
        cptr10 = arg3;
        do {
          cptr12 = cptr10;
          if (value6 == 0) break;
          value6 = value6 + -1;
          cptr12 = cptr10 + 1;
          cVar1 = *cptr10;
          cptr10 = cptr12;
        } while (cVar1 != '\0');
        cptr10 = cptr11 + -uvalue8;
        cptr11 = cptr12 + -1;
        for (uvalue9 = uvalue8 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
          *(uint32_t *)cptr11 = *(uint32_t *)cptr10;
          cptr10 = cptr10 + 4;
          cptr11 = cptr11 + 4;
        }
        for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
          *cptr11 = *cptr10;
          cptr10 = cptr10 + 1;
          cptr11 = cptr11 + 1;
        }
      }
      local_7c = local_7c + 1;
      value6 = value7 + 2;
      value7 = value7 + 1;
    } while (value6 < 0x1e);
    uvalue8 = 0xffffffff;
    cptr10 = arg3;
    do {
      if (uvalue8 == 0) break;
      uvalue8 = uvalue8 - 1;
      cVar1 = *cptr10;
      cptr10 = cptr10 + 1;
    } while (cVar1 != '\0');
    arg3[~uvalue8 - 2] = '\0';
  }
  else {
    if (!flag3) {
      uvalue8 = 0xffffffff;
      cptr10 = DAT_00582ce8;
      do {
        cptr11 = cptr10;
        if (uvalue8 == 0) break;
        uvalue8 = uvalue8 - 1;
        cptr11 = cptr10 + 1;
        cVar1 = *cptr10;
        cptr10 = cptr11;
      } while (cVar1 != '\0');
      uvalue8 = ~uvalue8;
      value7 = -1;
      do {
        cptr10 = arg3;
        if (value7 == 0) break;
        value7 = value7 + -1;
        cptr10 = arg3 + 1;
        cVar1 = *arg3;
        arg3 = cptr10;
      } while (cVar1 != '\0');
      cptr11 = cptr11 + -uvalue8;
      cptr10 = cptr10 + -1;
      for (uvalue9 = uvalue8 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
        *(uint32_t *)cptr10 = *(uint32_t *)cptr11;
        cptr11 = cptr11 + 4;
        cptr10 = cptr10 + 4;
      }
      for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *cptr10 = *cptr11;
        cptr11 = cptr11 + 1;
        cptr10 = cptr10 + 1;
      }
      return;
    }
    uvalue8 = 0xffffffff;
    cptr10 = DAT_00582ce8;
    do {
      cptr11 = cptr10;
      if (uvalue8 == 0) break;
      uvalue8 = uvalue8 - 1;
      cptr11 = cptr10 + 1;
      cVar1 = *cptr10;
      cptr10 = cptr11;
    } while (cVar1 != '\0');
    uvalue8 = ~uvalue8;
    value7 = -1;
    cptr10 = arg3;
    do {
      cptr12 = cptr10;
      if (value7 == 0) break;
      value7 = value7 + -1;
      cptr12 = cptr10 + 1;
      cVar1 = *cptr10;
      cptr10 = cptr12;
    } while (cVar1 != '\0');
    cptr10 = cptr11 + -uvalue8;
    cptr11 = cptr12 + -1;
    for (uvalue9 = uvalue8 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
      *(uint32_t *)cptr11 = *(uint32_t *)cptr10;
      cptr10 = cptr10 + 4;
      cptr11 = cptr11 + 4;
    }
    for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
      *cptr11 = *cptr10;
      cptr10 = cptr10 + 1;
      cptr11 = cptr11 + 1;
    }
    if (flag4) {
      uvalue8 = 0xffffffff;
      cptr10 = &DAT_0056d140;
      do {
        cptr11 = cptr10;
        if (uvalue8 == 0) break;
        uvalue8 = uvalue8 - 1;
        cptr11 = cptr10 + 1;
        cVar1 = *cptr10;
        cptr10 = cptr11;
      } while (cVar1 != '\0');
      uvalue8 = ~uvalue8;
      value7 = -1;
      cptr10 = arg3;
      do {
        cptr12 = cptr10;
        if (value7 == 0) break;
        value7 = value7 + -1;
        cptr12 = cptr10 + 1;
        cVar1 = *cptr10;
        cptr10 = cptr12;
      } while (cVar1 != '\0');
      cptr10 = cptr11 + -uvalue8;
      cptr11 = cptr12 + -1;
      for (uvalue9 = uvalue8 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
        *(uint32_t *)cptr11 = *(uint32_t *)cptr10;
        cptr10 = cptr10 + 4;
        cptr11 = cptr11 + 4;
      }
      for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *cptr11 = *cptr10;
        cptr10 = cptr10 + 1;
        cptr11 = cptr11 + 1;
      }
      uvalue8 = 0xffffffff;
      cptr10 = DAT_0058114c;
      do {
        cptr11 = cptr10;
        if (uvalue8 == 0) break;
        uvalue8 = uvalue8 - 1;
        cptr11 = cptr10 + 1;
        cVar1 = *cptr10;
        cptr10 = cptr11;
      } while (cVar1 != '\0');
      uvalue8 = ~uvalue8;
      value7 = -1;
      do {
        cptr10 = arg3;
        if (value7 == 0) break;
        value7 = value7 + -1;
        cptr10 = arg3 + 1;
        cVar1 = *arg3;
        arg3 = cptr10;
      } while (cVar1 != '\0');
      cptr11 = cptr11 + -uvalue8;
      cptr10 = cptr10 + -1;
      for (uvalue9 = uvalue8 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
        *(uint32_t *)cptr10 = *(uint32_t *)cptr11;
        cptr11 = cptr11 + 4;
        cptr10 = cptr10 + 4;
      }
      for (uvalue8 = uvalue8 & 3; uvalue8 != 0; uvalue8 = uvalue8 - 1) {
        *cptr10 = *cptr11;
        cptr11 = cptr11 + 1;
        cptr10 = cptr10 + 1;
      }
      return;
    }
  }
  return;
}
