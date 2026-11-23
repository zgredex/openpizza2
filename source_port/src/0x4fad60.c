// CityMap_PlaceSceneryProps: ported from Pizza Connection 2 at 0x4fad60.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4fad60
#include "pc2_port.h"

void CityMap_PlaceSceneryProps(int *arg1)

{
  char cVar1;
  int *ptr2;
  uint32_t uvalue3;
  int value4;
  int value5;
  int *ptr6;
  int value7;
  uint16_t uvalue8;
  uint16_t uvalue9;
  uint32_t local_28;
  int local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  ptr2 = arg1;
  local_c = AI_SelectBestPlan(1,*(int *)(*arg1 + 0x24),(intptr_t)arg1,&local_24,&local_28,-1,-1);
  local_10 = AI_SelectBestPlan(2,*(int *)(*arg1 + 0x24),(intptr_t)arg1,&local_24,&local_28,4,4);
  if (local_10 == -1) {
    NoOp_Stub();
  }
  AI_SelectBestPlan(5,*(int *)(*arg1 + 0x24),(intptr_t)arg1,&local_24,&local_28,-1,-1);
  Object_GetRect100((void *)arg1[4],&local_14,&local_20,&local_18,&local_1c);
  arg1 = local_18;
  if ((intptr_t)local_18 < local_1c) {
    ptr6 = ptr2 + -10;
    do {
      value7 = 0;
      value5 = local_14;
      if (local_14 < local_20) {
        do {
          cVar1 = *(char *)(value7 + 0x50 + (intptr_t)ptr6);
          uvalue8 = (uint16_t)value5;
          uvalue9 = SUB42(arg1,0);
          if (cVar1 == 'd') {
            value4 = AI_SelectBestPlan(4,*(int *)(*ptr2 + 0x24),(intptr_t)ptr2,&local_24,&local_28,1,1
                                     );
            MapObject_CreateFromTile(ptr2,value4,uvalue8,uvalue9,2,1,0);
          }
          else if (cVar1 == 's') {
            if (((*(char *)(value7 + 0x51 + (intptr_t)ptr6) == 's') &&
                (*(char *)(value7 + 0xa0 + (intptr_t)ptr6) == 's')) &&
               (*(char *)(value7 + 0xa1 + (intptr_t)ptr6) == 's')) {
              uvalue3 = CRT_Toupper((intptr_t)*(char *)(value7 + 0x52 + (intptr_t)ptr6));
              if (uvalue3 == 0x54) {
LAB_004faee6:
                uvalue3 = 1;
              }
              else {
                uvalue3 = CRT_Toupper((intptr_t)*(char *)(value7 + 0xf0 + (intptr_t)ptr6));
                if (uvalue3 == 0x54) {
LAB_004faf06:
                  uvalue3 = 0;
                }
                else {
                  uvalue3 = CRT_Toupper((intptr_t)*(char *)(value7 + 0x4f + (intptr_t)ptr6));
                  if (uvalue3 == 0x54) {
LAB_004faf1d:
                    uvalue3 = 3;
                  }
                  else {
                    uvalue3 = CRT_Toupper((intptr_t)*(char *)(value7 + (intptr_t)ptr6));
                    if (((uvalue3 == 0x54) || (*(char *)(value7 + (intptr_t)ptr6) == 'W')) ||
                       (*(char *)(value7 + (intptr_t)ptr6) == '@')) {
                      uvalue3 = 2;
                    }
                    else {
                      if ((*(char *)(value7 + 0xf0 + (intptr_t)ptr6) == 'W') ||
                         (*(char *)(value7 + 0xa0 + (intptr_t)ptr6) == '@')) goto LAB_004faf06;
                      if ((*(char *)(value7 + 0x52 + (intptr_t)ptr6) == 'W') ||
                         (*(char *)(value7 + 0x51 + (intptr_t)ptr6) == '@')) goto LAB_004faf1d;
                      cVar1 = *(char *)(value7 + 0x4f + (intptr_t)ptr6);
                      if ((cVar1 == 'W') || (cVar1 == '@')) goto LAB_004faee6;
                      uvalue3 = _rand();
                      uvalue3 = uvalue3 & 3;
                    }
                  }
                }
              }
              City_FindListContainingValue(local_c,&local_8,&local_4);
              if (-1 < local_8) {
                value4 = IDMap_Lookup((void *)(DAT_0057c670 + 0x74),local_8,(int *)0x0);
                MapObject_CreateFromTile
                          (ptr2,(intptr_t)*(short *)(value4 + (uvalue3 + (local_4 * 3 + 0x1e) * 2) * 2),
                           uvalue8,uvalue9,2,1,1);
              }
            }
          }
          else if (((((cVar1 == 't') && (*(char *)(value7 + 0xa0 + (intptr_t)ptr6) == 't')) &&
                    (*(char *)(value7 + (intptr_t)ptr6) == 't')) &&
                   ((*(char *)(value7 + -0x50 + (intptr_t)ptr6) == 't' &&
                    (*(char *)(value7 + 0x51 + (intptr_t)ptr6) == 't')))) &&
                  ((*(char *)(value7 + 0x4f + (intptr_t)ptr6) == 't' &&
                   (*(char *)(value7 + 0x4e + (intptr_t)ptr6) == 't')))) {
            MapObject_CreateFromTile(ptr2,local_10,uvalue8,uvalue9,2,1,1);
          }
          value7 = value7 + 1;
          value5 = value5 + 1;
        } while (value5 < local_20);
      }
      ptr6 = ptr6 + 0x14;
      arg1 = (int *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < local_1c);
  }
  return;
}
