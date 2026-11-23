// CityMap_StampObjectPattern: ported from Pizza Connection 2 at 0x4f9ee0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4f9ee0
#include "pc2_port.h"

uint32_t
CityMap_StampObjectPattern
          (int *arg1,uint32_t arg2,uint32_t arg3,int *arg4,int arg5,int arg6,int arg7,
          char arg8)

{
  uint8_t *uptr1;
  char cVar2;
  short svalue3;
  int value4;
  int *ptr5;
  uint32_t uvalue6;
  int value7;
  int value8;
  char *cptr9;
  uint32_t uvalue10;
  uint8_t *uptr11;
  uint32_t uvalue12;
  short svalue13;
  int value14;
  uint8_t *uptr15;
  uint32_t uvalue16;
  int *ptr17;
  int *ptr18;
  char *cptr19;
  int *ptr20;
  bool flag21;
  char local_2d6;
  char local_2d5;
  int *local_2d4;
  int *local_2d0;
  uint32_t local_2cc;
  int local_2c8;
  int *local_2c4;
  int *local_2c0;
  int *local_2bc;
  int local_2b8;
  int local_2b4;
  int local_2b0;
  uint32_t local_2ac;
  uint32_t local_2a8;
  int local_2a0;
  int local_29c;
  int local_298;
  void *local_294;
  int local_290;
  uint8_t abStack_28c [32];
  uint32_t local_26c;
  int local_268 [32];
  int local_1e8 [32];
  int local_168 [30];
  int local_f0 [30];
  int local_78 [30];
  
  uvalue12 = arg3;
  if (arg8 == ' ') {
    local_2d6 = '#';
    local_2d5 = 'W';
  }
  else if ((arg8 == '-') || (arg8 == '+')) {
    local_2d6 = '1';
    local_2d5 = '#';
  }
  else if (arg8 == '1') {
    local_2d5 = '1';
    local_2d6 = '1';
    arg8 = '-';
  }
  else if (arg8 == '2') {
    local_2d5 = '1';
    local_2d6 = '1';
    arg8 = '+';
  }
  local_2ac = arg2 * arg3;
  ptr17 = local_1e8;
  for (uvalue6 = local_2ac >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *ptr17 = *arg4;
    arg4 = arg4 + 1;
    ptr17 = ptr17 + 1;
  }
  for (uvalue6 = local_2ac & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *(char *)ptr17 = (char)*arg4;
    arg4 = (int *)((intptr_t)arg4 + 1);
    ptr17 = (int *)((intptr_t)ptr17 + 1);
  }
  uvalue6 = 0;
  Object_GetRect100((void *)arg1[4],&local_2b8,&local_2b4,&local_298,&local_2b0);
  if (arg6 == 0) {
    local_2c8 = 0;
    local_2c4 = (int *)local_298;
    if (local_2b0 <= local_298) {
      return 0;
    }
    local_2d0 = (int *)0x0;
    uvalue16 = local_2cc;
    do {
      if (0x1d < (intptr_t)uvalue6) break;
      local_2cc = 0;
      local_2d4 = (int *)local_2b8;
      if (local_2b8 < local_2b4) {
        while ((intptr_t)uvalue6 < 0x1e) {
          uvalue10 = 0;
          if (0 < (intptr_t)arg3) {
            value14 = (intptr_t)local_2d0 + local_2cc + 0x28 + (intptr_t)arg1;
            do {
              uvalue16 = 0;
              if (0 < (intptr_t)arg2) {
                do {
                  if (*(char *)(value14 + uvalue16) != arg8) {
                    if ((intptr_t)uvalue16 < (intptr_t)arg2) goto LAB_004fa55d;
                    break;
                  }
                  uvalue16 = uvalue16 + 1;
                } while ((intptr_t)uvalue16 < (intptr_t)arg2);
              }
              uvalue10 = uvalue10 + 1;
              value14 = value14 + 0x50;
            } while ((intptr_t)uvalue10 < (intptr_t)arg3);
          }
LAB_004fa55d:
          if ((uvalue10 == arg3) && (uvalue16 == arg2)) {
            local_78[uvalue6] = (intptr_t)local_2d4;
            local_f0[uvalue6] = (intptr_t)local_2c4;
            local_168[uvalue6] = local_2cc;
            local_268[uvalue6] = local_2c8;
            uvalue10 = _rand();
            if ((uvalue10 & 1) == 0) {
              abStack_28c[uvalue6] = 2;
            }
            else {
              abStack_28c[uvalue6] = 0;
            }
            uvalue6 = uvalue6 + 1;
            if (uvalue6 == 0x1e) break;
          }
          uvalue10 = 0;
          if (0 < (intptr_t)arg2) {
            cptr19 = (char *)((intptr_t)local_2d0 + local_2cc + 0x28 + (intptr_t)arg1);
            do {
              uvalue16 = 0;
              if (0 < (intptr_t)arg3) {
                cptr9 = cptr19;
                do {
                  if (*cptr9 != arg8) {
                    if ((intptr_t)uvalue16 < (intptr_t)arg3) goto LAB_004fa60a;
                    break;
                  }
                  uvalue16 = uvalue16 + 1;
                  cptr9 = cptr9 + 1;
                } while ((intptr_t)uvalue16 < (intptr_t)arg3);
              }
              uvalue10 = uvalue10 + 1;
              cptr19 = cptr19 + 0x50;
            } while ((intptr_t)uvalue10 < (intptr_t)arg2);
          }
LAB_004fa60a:
          if ((uvalue10 == arg2) && (uvalue16 == arg3)) {
            local_78[uvalue6] = (intptr_t)local_2d4;
            local_f0[uvalue6] = (intptr_t)local_2c4;
            local_168[uvalue6] = local_2cc;
            local_268[uvalue6] = local_2c8;
            uvalue10 = _rand();
            if ((uvalue10 & 1) == 0) {
              abStack_28c[uvalue6] = 3;
            }
            else {
              abStack_28c[uvalue6] = 1;
            }
            break;
          }
          local_2cc = local_2cc + 1;
          local_2d4 = (int *)((intptr_t)local_2d4 + 1);
          if (local_2b4 <= (intptr_t)local_2d4) break;
        }
      }
      local_2c8 = local_2c8 + 1;
      local_2d0 = (int *)((intptr_t)local_2d0 + 0x50);
      local_2c4 = (int *)((intptr_t)local_2c4 + 1);
    } while ((intptr_t)local_2c4 < local_2b0);
  }
  else {
    local_2c8 = 0;
    local_2c4 = (int *)local_298;
    if (local_2b0 <= local_298) {
      return 0;
    }
    do {
      if (0x1d < (intptr_t)uvalue6) break;
      value14 = 0;
      if (local_2b8 < local_2b4) {
        local_2d4 = local_78 + uvalue6;
        local_2d0 = local_268 + uvalue6;
        local_2bc = local_168 + uvalue6;
        local_2c0 = local_f0 + uvalue6;
        local_2a8 = 1 - local_2b8;
        do {
          if (0x1d < (intptr_t)uvalue6) break;
          value7 = local_2c8 * 0x50;
          cVar2 = *(char *)(value7 + value14 + 0x28 + (intptr_t)arg1);
          if ((cVar2 == local_2d6) || (cVar2 == local_2d5)) {
            if (arg8 != '-') {
              local_2cc = 1;
              flag21 = arg2 == 1;
              if (1 < (intptr_t)arg2) {
                do {
                  cVar2 = *(char *)((intptr_t)arg1 + local_2cc + value7 + value14 + 0x28);
                  if ((cVar2 != local_2d6) && (cVar2 != local_2d5)) break;
                  local_2cc = local_2cc + 1;
                } while ((intptr_t)local_2cc < (intptr_t)arg2);
                flag21 = local_2cc == arg2;
              }
              if (flag21) {
                uvalue16 = 0;
                if (0 < (intptr_t)arg3) {
                  value8 = value7 + value14 + 0x78 + (intptr_t)arg1;
                  do {
                    local_2cc = 0;
                    if (0 < (intptr_t)arg2) {
                      do {
                        if (*(char *)(value8 + local_2cc) != arg8) {
                          if ((intptr_t)local_2cc < (intptr_t)arg2) goto LAB_004fa102;
                          break;
                        }
                        local_2cc = local_2cc + 1;
                      } while ((intptr_t)local_2cc < (intptr_t)arg2);
                    }
                    uvalue16 = uvalue16 + 1;
                    value8 = value8 + 0x50;
                  } while ((intptr_t)uvalue16 < (intptr_t)arg3);
                }
LAB_004fa102:
                if ((uvalue16 == arg3) && (local_2cc == arg2)) {
                  abStack_28c[uvalue6] = 0;
                  uvalue6 = uvalue6 + 1;
                  *local_2d4 = value14 + local_2b8;
                  *local_2c0 = (intptr_t)local_2c4;
                  *local_2bc = value14;
                  *local_2d0 = local_2c8 + 1;
                  local_2c0 = local_2c0 + 1;
                  local_2d0 = local_2d0 + 1;
                  local_2bc = local_2bc + 1;
                  local_2d4 = local_2d4 + 1;
                  if (uvalue6 == 0x1e) break;
                }
                uvalue16 = 0;
                if (0 < (intptr_t)arg3) {
                  cptr19 = (char *)(value7 + value14 + -0x28 + (intptr_t)arg1);
                  do {
                    local_2cc = 0;
                    if (0 < (intptr_t)arg2) {
                      cptr9 = cptr19;
                      do {
                        if (*cptr9 != arg8) {
                          if ((intptr_t)local_2cc < (intptr_t)arg2) goto LAB_004fa1d4;
                          break;
                        }
                        local_2cc = local_2cc + 1;
                        cptr9 = cptr9 + 1;
                      } while ((intptr_t)local_2cc < (intptr_t)arg2);
                    }
                    uvalue16 = uvalue16 + 1;
                    cptr19 = cptr19 + -0x50;
                  } while ((intptr_t)uvalue16 < (intptr_t)arg3);
                }
LAB_004fa1d4:
                if ((uvalue16 == arg3) && (local_2cc == arg2)) {
                  abStack_28c[uvalue6] = 2;
                  *local_2d4 = value14 + local_2b8;
                  *local_2c0 = (intptr_t)local_2c4;
                  *local_2bc = value14;
                  *local_2d0 = local_2c8;
                  uvalue16 = arg3;
                  if (0 < (intptr_t)arg3) {
                    do {
                      *local_2c0 = *local_2c0 + -1;
                      *local_2d0 = *local_2d0 + -1;
                      uvalue16 = uvalue16 - 1;
                    } while (uvalue16 != 0);
                  }
                  local_2d0 = local_2d0 + 1;
                  local_2c0 = local_2c0 + 1;
                  uvalue6 = uvalue6 + 1;
                  local_2bc = local_2bc + 1;
                  local_2d4 = local_2d4 + 1;
                  if (uvalue6 == 0x1e) break;
                }
              }
            }
            uvalue16 = 1;
            flag21 = arg2 == 1;
            if (1 < (intptr_t)arg2) {
              cptr19 = (char *)(value7 + value14 + 0x78 + (intptr_t)arg1);
              do {
                if ((*cptr19 != local_2d6) && (*cptr19 != local_2d5)) break;
                uvalue16 = uvalue16 + 1;
                cptr19 = cptr19 + 0x50;
              } while ((intptr_t)uvalue16 < (intptr_t)arg2);
              flag21 = uvalue16 == arg2;
            }
            if (flag21) {
              if (arg8 != '-') {
                uvalue16 = 0;
                if (0 < (intptr_t)arg2) {
                  cptr19 = (char *)(value7 + value14 + 0x27 + (intptr_t)arg1);
                  do {
                    local_2cc = 0;
                    if (0 < (intptr_t)arg3) {
                      cptr9 = cptr19;
                      do {
                        if (*cptr9 != arg8) {
                          if ((intptr_t)local_2cc < (intptr_t)arg3) goto LAB_004fa313;
                          break;
                        }
                        local_2cc = local_2cc + 1;
                        cptr9 = cptr9 + -1;
                      } while ((intptr_t)local_2cc < (intptr_t)arg3);
                    }
                    uvalue16 = uvalue16 + 1;
                    cptr19 = cptr19 + 0x50;
                  } while ((intptr_t)uvalue16 < (intptr_t)arg2);
                }
LAB_004fa313:
                if ((uvalue16 == arg2) && (local_2cc == arg3)) {
                  abStack_28c[uvalue6] = 1;
                  *local_2d4 = value14 + local_2b8;
                  *local_2c0 = (intptr_t)local_2c4;
                  *local_2bc = value14;
                  *local_2d0 = local_2c8;
                  uvalue16 = arg3;
                  if (0 < (intptr_t)arg3) {
                    do {
                      *local_2d4 = *local_2d4 + -1;
                      *local_2bc = *local_2bc + -1;
                      uvalue16 = uvalue16 - 1;
                    } while (uvalue16 != 0);
                  }
                  uvalue6 = uvalue6 + 1;
                  local_2c0 = local_2c0 + 1;
                  local_2bc = local_2bc + 1;
                  local_2d0 = local_2d0 + 1;
                  local_2d4 = local_2d4 + 1;
                  if (uvalue6 == 0x1e) break;
                }
              }
              uvalue16 = 0;
              if (0 < (intptr_t)arg2) {
                cptr19 = (char *)(value7 + value14 + 0x29 + (intptr_t)arg1);
                do {
                  local_2cc = 0;
                  if (0 < (intptr_t)arg3) {
                    cptr9 = cptr19;
                    do {
                      if (*cptr9 != arg8) {
                        if ((intptr_t)local_2cc < (intptr_t)arg3) goto LAB_004fa403;
                        break;
                      }
                      local_2cc = local_2cc + 1;
                      cptr9 = cptr9 + 1;
                    } while ((intptr_t)local_2cc < (intptr_t)arg3);
                  }
                  uvalue16 = uvalue16 + 1;
                  cptr19 = cptr19 + 0x50;
                } while ((intptr_t)uvalue16 < (intptr_t)arg2);
              }
LAB_004fa403:
              if ((uvalue16 == arg2) && (local_2cc == arg3)) {
                *local_2c0 = (intptr_t)local_2c4;
                value7 = local_2a8 + value14 + local_2b8;
                abStack_28c[uvalue6] = 3;
                *local_2bc = value7;
                *local_2d0 = local_2c8;
                uvalue6 = uvalue6 + 1;
                *local_2d4 = value7 + local_2b8;
                local_2c0 = local_2c0 + 1;
                local_2d4 = local_2d4 + 1;
                local_2bc = local_2bc + 1;
                local_2d0 = local_2d0 + 1;
                if (uvalue6 == 0x1e) break;
              }
            }
          }
          value14 = value14 + 1;
        } while (value14 + local_2b8 < local_2b4);
      }
      local_2c8 = local_2c8 + 1;
      local_2c4 = (int *)((intptr_t)local_2c4 + 1);
    } while ((intptr_t)local_2c4 < local_2b0);
  }
  if (uvalue6 == 0) {
    return 0;
  }
  if (arg7 == 0) {
    uvalue6 = 0;
  }
  else {
    uvalue6 = Random_Mod(uvalue6);
  }
  local_2d0 = (int *)local_78[uvalue6];
  local_2c8 = local_f0[uvalue6];
  value14 = local_168[uvalue6];
  local_2a8 = (uint32_t)abStack_28c[uvalue6];
  value7 = local_268[uvalue6];
  if ((local_2a8 == 1) || (uvalue6 = arg2, local_2a8 == 3)) {
    value8 = 0;
    if (0 < (intptr_t)arg3) {
      ptr17 = local_1e8;
      do {
        value4 = 0;
        if (0 < (intptr_t)arg2) {
          uptr11 = (uint8_t *)((intptr_t)local_268 + value8);
          do {
            uptr15 = (uint8_t *)((intptr_t)ptr17 + value4);
            value4 = value4 + 1;
            *uptr11 = *uptr15;
            uptr11 = uptr11 + arg3;
          } while (value4 < (intptr_t)arg2);
        }
        value8 = value8 + 1;
        ptr17 = (int *)((intptr_t)ptr17 + arg2);
      } while (value8 < (intptr_t)arg3);
    }
    ptr17 = local_268;
    ptr5 = local_1e8;
    for (uvalue6 = local_2ac >> 2; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *ptr5 = *ptr17;
      ptr17 = ptr17 + 1;
      ptr5 = ptr5 + 1;
    }
    for (uvalue6 = local_2ac & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
      *(char *)ptr5 = (char)*ptr17;
      ptr17 = (int *)((intptr_t)ptr17 + 1);
      ptr5 = (int *)((intptr_t)ptr5 + 1);
    }
    arg3 = arg2;
    uvalue6 = uvalue12;
    if (local_2a8 != 1) goto LAB_004fa7c3;
    if (0 < (intptr_t)arg2) {
      ptr17 = local_1e8;
      uptr11 = (uint8_t *)((intptr_t)&local_26c + 3);
      uvalue6 = arg2;
      do {
        uptr11 = uptr11 + uvalue12;
        value8 = 0;
        if (0 < (intptr_t)uvalue12) {
          uptr15 = uptr11;
          do {
            uptr1 = (uint8_t *)((intptr_t)ptr17 + value8);
            value8 = value8 + 1;
            *uptr15 = *uptr1;
            uptr15 = uptr15 + -1;
          } while (value8 < (intptr_t)uvalue12);
        }
        ptr17 = (int *)((intptr_t)ptr17 + uvalue12);
        uvalue6 = uvalue6 - 1;
      } while (uvalue6 != 0);
    }
    uvalue6 = arg2 * uvalue12;
    arg2 = uvalue12;
  }
  else {
LAB_004fa7c3:
    arg2 = uvalue6;
    if (local_2a8 != 2) goto LAB_004fa843;
    if (0 < (intptr_t)arg3) {
      ptr5 = local_1e8;
      local_2cc = arg3;
      ptr17 = (int *)((intptr_t)local_268 + (arg3 - 1) * arg2);
      do {
        if (0 < (intptr_t)arg2) {
          ptr18 = ptr5;
          ptr20 = ptr17;
          for (uvalue12 = arg2 >> 2; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
            *ptr20 = *ptr18;
            ptr18 = ptr18 + 1;
            ptr20 = ptr20 + 1;
          }
          for (uvalue12 = arg2 & 3; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
            *(char *)ptr20 = (char)*ptr18;
            ptr18 = (int *)((intptr_t)ptr18 + 1);
            ptr20 = (int *)((intptr_t)ptr20 + 1);
          }
        }
        ptr17 = (int *)((intptr_t)ptr17 - arg2);
        ptr5 = (int *)((intptr_t)ptr5 + arg2);
        local_2cc = local_2cc - 1;
      } while (local_2cc != 0);
    }
    uvalue6 = arg2 * arg3;
  }
  ptr17 = local_268;
  ptr5 = local_1e8;
  for (uvalue12 = uvalue6 >> 2; uvalue12 != 0; uvalue12 = uvalue12 - 1) {
    *ptr5 = *ptr17;
    ptr17 = ptr17 + 1;
    ptr5 = ptr5 + 1;
  }
  for (uvalue6 = uvalue6 & 3; uvalue6 != 0; uvalue6 = uvalue6 - 1) {
    *(char *)ptr5 = (char)*ptr17;
    ptr17 = (int *)((intptr_t)ptr17 + 1);
    ptr5 = (int *)((intptr_t)ptr5 + 1);
  }
LAB_004fa843:
  local_2bc = (int *)0x0;
  if ((intptr_t)arg3 < 1) {
    return 1;
  }
  local_2c0 = local_1e8;
  local_2d4 = (int *)(value7 * 0x50 + value14 + 0x28 + (intptr_t)arg1);
  do {
    local_2cc = 0;
    local_290 = (intptr_t)local_2d0;
    if (0 < (intptr_t)arg2) {
      local_2c4 = local_2c0;
      do {
        *(uint8_t *)((intptr_t)local_2d4 + local_2cc) = 0x78;
        if ((char)*local_2c4 != ' ') {
          value7 = 0;
          uvalue6 = (uint32_t)(char)*local_2c4;
          value14 = 0;
          uvalue12 = local_2cc;
          while( true ) {
            ptr17 = local_2c4;
            ptr5 = local_2bc;
            if (((intptr_t)arg2 <= (intptr_t)uvalue12) || ((intptr_t)*(char *)((intptr_t)local_2c4 + value14) != uvalue6))
            break;
            uvalue12 = uvalue12 + 1;
            value14 = value14 + 1;
          }
          for (; ((intptr_t)ptr5 < (intptr_t)arg3 && ((intptr_t)(char)*ptr17 == uvalue6));
              ptr17 = (int *)((intptr_t)ptr17 + arg2)) {
            value7 = value7 + 1;
            ptr5 = (int *)((intptr_t)ptr5 + 1);
          }
          uvalue12 = CRT_Tolower(uvalue6);
          value8 = *(int *)(arg5 + (uvalue12 - 0x61) * 8);
          value4 = *(int *)(arg5 + 4 + (uvalue12 - 0x61) * 8) - value8;
          if (local_2a8 == 1) {
            if (value4 < 3) {
joined_r0x004fa959:
              if (0 < value4) {
                value8 = value8 + 1;
              }
            }
            else {
              value8 = value8 + 3;
            }
          }
          else if (local_2a8 == 2) {
            if (1 < value4) {
              value8 = value8 + 2;
            }
          }
          else if (local_2a8 == 3) goto joined_r0x004fa959;
          City_FindListContainingValue(value8,(int *)&local_2ac,&local_26c);
          if (0 < (intptr_t)local_2ac) {
            local_294 = (void *)IDMap_Lookup((void *)(DAT_0057c670 + 0x74),local_2ac,(int *)0x0);
          }
          Object_GetPair68(local_294,&local_2a0,&local_29c);
          if ((((local_2a0 == 0) || (10 < local_2a0)) || (local_29c == 0)) || (10 < local_29c))
          break;
          if ((local_2a0 <= value14) && (local_29c <= value7)) {
            if (local_2a0 == 3) {
              svalue13 = (short)local_2d0 + 1;
            }
            else {
              svalue13 = (short)local_2d0;
              if ((3 < local_2a0) && (local_2a0 < 6)) {
                svalue13 = (short)local_2d0 + 2;
              }
            }
            svalue3 = (short)local_2c8;
            switch(local_29c) {
            case 2:
              svalue3 = (short)local_2c8 + 1;
              break;
            case 3:
              svalue3 = (short)local_2c8 + 1;
              break;
            case 4:
              svalue3 = (short)local_2c8 + 3;
              break;
            case 5:
              svalue3 = (short)local_2c8 + 2;
            }
            MapObject_CreateFromTile(arg1,value8,svalue13,svalue3,2,1,0);
            if (0 < local_2a0) {
              ptr17 = local_2c4;
              value14 = local_2a0;
              do {
                if (0 < local_29c) {
                  ptr5 = ptr17;
                  value7 = local_29c;
                  do {
                    *(char *)ptr5 = ' ';
                    ptr5 = (int *)((intptr_t)ptr5 + arg2);
                    value7 = value7 + -1;
                  } while (value7 != 0);
                }
                ptr17 = (int *)((intptr_t)ptr17 + 1);
                value14 = value14 + -1;
              } while (value14 != 0);
            }
          }
        }
        local_2d0 = (int *)((intptr_t)local_2d0 + 1);
        local_2cc = local_2cc + 1;
        local_2c4 = (int *)((intptr_t)local_2c4 + 1);
      } while ((intptr_t)local_2cc < (intptr_t)arg2);
    }
    local_2d0 = (int *)local_290;
    local_2c8 = local_2c8 + 1;
    local_2c0 = (int *)((intptr_t)local_2c0 + arg2);
    local_2bc = (int *)((intptr_t)local_2bc + 1);
    local_2d4 = (int *)((intptr_t)local_2d4 + 0x50);
    if ((intptr_t)arg3 <= (intptr_t)local_2bc) {
      return 1;
    }
  } while( true );
}
