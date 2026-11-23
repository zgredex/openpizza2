// UI_RichText_SetMarkupText: ported from Pizza Connection 2 at 0x52c500.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x52c500
#include "pc2_port.h"

void __thiscall UI_RichText_SetMarkupText(void *self,char *arg1)

{
  char cVar1;
  uint8_t flag2;
  void *pvVar3;
  uint32_t *uptr4;
  size_t _Count;
  uint32_t uvalue5;
  char *cptr6;
  uint32_t uvalue7;
  int value8;
  uint32_t uvalue9;
  int value10;
  int value11;
  int value12;
  char *cptr13;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  char local_80 [128];
  
                    /* Parses rich-text markup into a text control's display buffer. */
  uvalue7 = 0xffffffff;
  cptr6 = arg1;
  do {
    if (uvalue7 == 0) break;
    uvalue7 = uvalue7 - 1;
    cVar1 = *cptr6;
    cptr6 = cptr6 + 1;
  } while (cVar1 != '\0');
  value8 = ~uvalue7 - 1;
  local_8c = value8;
  if (*(int *)((intptr_t)self + 0x78) < value8) {
    if (*(LPVOID *)((intptr_t)self + 0x74) != (LPVOID)0x0) {
      Mem_Free(*(LPVOID *)((intptr_t)self + 0x74));
    }
    *(uint32_t *)((intptr_t)self + 0x74) = 0;
    *(uint32_t *)((intptr_t)self + 0x78) = 0;
  }
  *(uint32_t *)((intptr_t)self + 0x7c) = 0;
  if (*(int *)((intptr_t)self + 0x88) != 0) {
    pvVar3 = *(void **)(*(int *)((intptr_t)self + 8) + 0x134);
    value8 = 0x10;
    do {
      if (pvVar3 != (void *)0x0) {
        UI_ReleaseRefCount(pvVar3,*(int *)(value8 + *(int *)((intptr_t)self + 0x88)));
      }
      value11 = value8 + 4;
      *(uint32_t *)(value8 + *(int *)((intptr_t)self + 0x88)) = 0;
      value8 = value11;
    } while (value11 < 0x34);
    value8 = local_8c;
  }
  local_90 = 0;
  while( true ) {
    if ((value8 <= local_90) || ((flag2 = arg1[local_90], 0x20 < flag2 && (flag2 != 0x7b))))
    goto LAB_0052c5f0;
    if ((flag2 == 0x7b) &&
       ((uvalue7 = CRT_Toupper((uint32_t)(uint8_t)arg1[local_90 + 1]), uvalue7 == 0x48 &&
        (uvalue7 = CRT_Toupper((uint32_t)(uint8_t)arg1[local_90 + 2]), uvalue7 == 0x45)))) break;
    local_90 = local_90 + 1;
  }
  *(uint32_t *)((intptr_t)self + 0x7c) = 1;
LAB_0052c5f0:
  value8 = 0;
  if (*(int *)((intptr_t)self + 0x74) == 0) {
    *(int *)((intptr_t)self + 0x78) = local_8c;
    pvVar3 = operator_new(local_8c + 1);
    *(void **)((intptr_t)self + 0x74) = pvVar3;
  }
  if (*(int *)((intptr_t)self + 0x7c) == 0) {
    uvalue7 = 0xffffffff;
    do {
      cptr6 = arg1;
      if (uvalue7 == 0) break;
      uvalue7 = uvalue7 - 1;
      cptr6 = arg1 + 1;
      cVar1 = *arg1;
      arg1 = cptr6;
    } while (cVar1 != '\0');
    uvalue7 = ~uvalue7;
    cptr6 = cptr6 + -uvalue7;
    cptr13 = *(char **)((intptr_t)self + 0x74);
    for (uvalue9 = uvalue7 >> 2; uvalue9 != 0; uvalue9 = uvalue9 - 1) {
      *(uint32_t *)cptr13 = *(uint32_t *)cptr6;
      cptr6 = cptr6 + 4;
      cptr13 = cptr13 + 4;
    }
    for (uvalue7 = uvalue7 & 3; uvalue7 != 0; uvalue7 = uvalue7 - 1) {
      *cptr13 = *cptr6;
      cptr6 = cptr6 + 1;
      cptr13 = cptr13 + 1;
    }
    cptr6 = *(char **)((intptr_t)self + 0x74);
    while ((cptr6 != (char *)0x0 && (cptr6 = _strchr(cptr6,10), cptr6 != (char *)0x0))) {
      *cptr6 = '\r';
      cptr6 = cptr6 + 1;
    }
    *(uint32_t *)((intptr_t)self + 0x5c) = 0xffffffff;
    return;
  }
  if (*(int *)((intptr_t)self + 0x88) == 0) {
    uptr4 = operator_new(0x34);
    *(uint32_t **)((intptr_t)self + 0x88) = uptr4;
    for (value11 = 0xd; value11 != 0; value11 = value11 + -1) {
      *uptr4 = 0;
      uptr4 = uptr4 + 1;
    }
    **(uint32_t **)((intptr_t)self + 0x88) = 0x14;
    *(uint32_t *)(*(int *)((intptr_t)self + 0x88) + 4) = 0;
    *(uint32_t *)(*(int *)((intptr_t)self + 0x88) + 8) = 2;
    *(uint32_t *)(*(int *)((intptr_t)self + 0x88) + 0xc) = *(uint32_t *)((intptr_t)self + 0x54);
  }
  value11 = 1;
  local_88 = 1;
  local_84 = 0;
  local_90 = 0;
  if (0 < local_8c) {
    do {
      flag2 = arg1[local_90];
      value10 = local_90;
      if (flag2 < 0x20) {
        if (value11 == 0) {
          if (flag2 == 10) {
            if (local_84 == 0) {
              local_84 = 1;
            }
            else {
              *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = 0xd;
              value8 = value8 + 1;
            }
          }
        }
        goto LAB_0052caae;
      }
      if (flag2 != 0x7b) {
        if (value11 == 0) {
          local_84 = 1;
          *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = flag2;
          value8 = value8 + 1;
        }
        goto LAB_0052caae;
      }
      value10 = local_90 + 1;
      flag2 = arg1[value10];
      while ((0x1f < flag2 && (flag2 != 0x7d))) {
        value11 = value10 + 1;
        value10 = value10 + 1;
        flag2 = arg1[value11];
      }
      cptr6 = local_80;
      for (value11 = 0x20; value11 != 0; value11 = value11 + -1) {
        cptr6[0] = '\0';
        cptr6[1] = '\0';
        cptr6[2] = '\0';
        cptr6[3] = '\0';
        cptr6 = cptr6 + 4;
      }
      _Count = (value10 - local_90) - 1;
      if (0x7f < (intptr_t)_Count) {
        _Count = 0x7f;
      }
      _strncpy(local_80,arg1 + local_90 + 1,_Count);
      local_90 = 1;
      value12 = value8;
      if (local_88 != 0) {
        uvalue7 = CRT_Toupper((intptr_t)local_80[0]);
        if (uvalue7 == 0x44) {
          Text_SkipFieldSeparators((intptr_t)local_80,&local_90);
          value11 = Dialog_ParseInteger(local_80,&local_90);
          Text_SkipFieldSeparators((intptr_t)local_80,&local_90);
          uvalue7 = UI_LoadFontByName(*(void **)(*(int *)((intptr_t)self + 8) + 0x134),local_80 + local_90)
          ;
          *(uint32_t *)(*(int *)((intptr_t)self + 0x88) + 0xc + value11 * 4) = uvalue7;
          value11 = local_88;
        }
        else if (uvalue7 == 0x48) {
          if (' ' < local_80[local_90]) {
            do {
              value11 = local_90 + 1;
              local_90 = local_90 + 1;
            } while (' ' < local_80[value11]);
          }
          Text_SkipFieldSeparators((intptr_t)local_80,&local_90);
          value11 = Dialog_ParseInteger(local_80,&local_90);
          if (value11 != -1) {
            **(int **)((intptr_t)self + 0x88) = value11;
          }
          Text_SkipFieldSeparators((intptr_t)local_80,&local_90);
          value11 = Dialog_ParseInteger(local_80,&local_90);
          if (value11 != -1) {
            if (0x13 < value11) {
              value11 = 0x14;
            }
            *(int *)(*(int *)((intptr_t)self + 0x88) + 8) = value11;
          }
          Text_SkipFieldSeparators((intptr_t)local_80,&local_90);
          value11 = Dialog_ParseInteger(local_80,&local_90);
          if (value11 == -1) goto switchD_0052c8a8_caseD_2e;
          *(int *)(*(int *)((intptr_t)self + 0x88) + 4) = value11;
          value11 = local_88;
        }
        else {
          if (uvalue7 != 0x54) goto switchD_0052c8a8_caseD_2e;
          local_88 = 0;
          value11 = 0;
        }
        goto LAB_0052caae;
      }
      uvalue7 = CRT_Toupper((intptr_t)local_80[0]);
      switch(uvalue7) {
      case 0x2d:
        *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = 1;
        *(uint8_t *)(value8 + 1 + *(int *)((intptr_t)self + 0x74)) = 1;
        *(uint8_t *)(value8 + 2 + *(int *)((intptr_t)self + 0x74)) = 5;
        value12 = value8 + 3;
      default:
switchD_0052c8a8_caseD_2e:
        value11 = local_88;
        value8 = value12;
        break;
      case 0x41:
        *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = 1;
        *(uint8_t *)(value8 + 1 + *(int *)((intptr_t)self + 0x74)) = 2;
        *(uint8_t *)(value8 + 2 + *(int *)((intptr_t)self + 0x74)) = 4;
        value12 = value8 + 3;
        Text_SkipFieldSeparators((intptr_t)local_80,&local_90);
        uvalue7 = CRT_Toupper((intptr_t)local_80[local_90]);
        value11 = local_88;
        if (uvalue7 == 0x43) {
          *(uint8_t *)(value12 + *(int *)((intptr_t)self + 0x74)) = 2;
          value8 = value8 + 4;
        }
        else if (uvalue7 == 0x4c) {
          *(uint8_t *)(value12 + *(int *)((intptr_t)self + 0x74)) = 0;
          value8 = value8 + 4;
        }
        else {
          if (uvalue7 != 0x52) goto switchD_0052c8a8_caseD_2e;
          *(uint8_t *)(value12 + *(int *)((intptr_t)self + 0x74)) = 1;
          value8 = value8 + 4;
        }
        break;
      case 0x43:
        *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = 1;
        *(uint8_t *)(value8 + 1 + *(int *)((intptr_t)self + 0x74)) = 4;
        *(uint8_t *)(value8 + 2 + *(int *)((intptr_t)self + 0x74)) = 1;
        uvalue5 = Dialog_ParseInteger(local_80,&local_90);
        *(char *)(value8 + 3 + *(int *)((intptr_t)self + 0x74)) = (char)uvalue5;
        value8 = value8 + 4;
        Text_SkipFieldSeparators((intptr_t)local_80,&local_90);
        uvalue5 = Dialog_ParseInteger(local_80,&local_90);
        *(char *)(value8 + *(int *)((intptr_t)self + 0x74)) = (char)uvalue5;
        goto LAB_0052ca2e;
      case 0x45:
        *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = 1;
        *(uint8_t *)(value8 + 1 + *(int *)((intptr_t)self + 0x74)) = 2;
        value8 = value8 + 2;
        Text_SkipFieldSeparators((intptr_t)local_80,&local_90);
        uvalue7 = CRT_Toupper((intptr_t)local_80[local_90]);
        if (uvalue7 == 0x44) {
          *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = 3;
        }
        else {
          *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = 2;
        }
LAB_0052ca2e:
        Text_SkipFieldSeparators((intptr_t)local_80,&local_90);
        uvalue5 = Dialog_ParseInteger(local_80,&local_90);
        *(char *)(value8 + 1 + *(int *)((intptr_t)self + 0x74)) = (char)uvalue5;
        value8 = value8 + 2;
        value11 = local_88;
        break;
      case 0x46:
        *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = 1;
        *(uint8_t *)(value8 + 1 + *(int *)((intptr_t)self + 0x74)) = 2;
        *(uint8_t *)(value8 + 2 + *(int *)((intptr_t)self + 0x74)) = 0;
        uvalue5 = Dialog_ParseInteger(local_80,&local_90);
        *(char *)(value8 + 3 + *(int *)((intptr_t)self + 0x74)) = (char)uvalue5;
        value8 = value8 + 4;
        value11 = local_88;
      }
LAB_0052caae:
      local_90 = value10 + 1;
    } while (local_90 < local_8c);
  }
  *(uint8_t *)(value8 + *(int *)((intptr_t)self + 0x74)) = 0;
  *(uint32_t *)((intptr_t)self + 0x5c) = 0xffffffff;
  return;
}
