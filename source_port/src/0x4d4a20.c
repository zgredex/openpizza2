// City_InitPopulation: ported from Pizza Connection 2 at 0x4d4a20.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d4a20
#include "pc2_port.h"


void __thiscall City_InitPopulation(void *self,int arg1,int arg2)

{
  void *pvVar1;
  uint32_t uvalue2;
  uint32_t *uptr3;
  char *cptr4;
  uint32_t uvalue5;
  int value6;
  char *cptr7;
  int value8;
  char *cptr9;
  int64_t lvalue10;
  int value11;
  char cVar12;
  int value13;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  local_4 = 0xffffffff;
  puStack_8 = &LAB_00558f04;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *(int *)((intptr_t)self + 0x48) = arg1;
  value8 = 0;
  do {
    lvalue10 = __ftol();
    value6 = (intptr_t)lvalue10;
    if (0 < value6) {
      do {
        pvVar1 = operator_new(0x16c);
        local_4 = 0;
        if (pvVar1 == (void *)0x0) {
          uptr3 = (uint32_t *)0x0;
        }
        else {
          value13 = -1;
          value11 = 0;
          uvalue2 = _rand();
          uptr3 = Object_Construct(pvVar1,value8,*(int *)((intptr_t)self + 0xc1c),uvalue2 & 1,value11,value13
                                   );
        }
        local_4 = 0xffffffff;
        IDMap_GetRandomName(DAT_0057ba10,uptr3[9],(char *)(uptr3 + 1));
        Game_AddObjectToRegistry(DAT_0057c670,uptr3);
        value6 = value6 + -1;
      } while (value6 != 0);
    }
    value8 = value8 + 1;
  } while (value8 < 8);
  if ((intptr_t)(*(uint32_t *)((intptr_t)self + 0x48) & 0xfffffffe) < 200) {
    value8 = (intptr_t)*(uint32_t *)((intptr_t)self + 0x48) >> 1;
  }
  else {
    value8 = 100;
  }
  if (0 < value8) {
    do {
      pvVar1 = operator_new(0x14);
      local_4 = 1;
      if (pvVar1 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Car_Construct(pvVar1,*(int *)((intptr_t)self + 0xc1c));
      }
      local_4 = 0xffffffff;
      Game_RegisterObject(DAT_0057c670,uptr3);
      do {
        value6 = Array_GetRandomRecord28B(*(void **)((intptr_t)self + 0xfa8),(int *)0x0);
        value11 = CityView_IsCarSpawnCellFree(*(void **)((intptr_t)self + 0xfa8),value6);
      } while (value11 == 0);
      CityView_ReserveCarCell(*(void **)((intptr_t)self + 0xfa8),value6,uptr3[2]);
      MapObject_PlaceAtPoint(uptr3,value6);
      value8 = value8 + -1;
    } while (value8 != 0);
  }
  uvalue2 = 0;
  do {
    value8 = 10;
    do {
      City_SpawnPerson(self,uvalue2);
      value8 = value8 + -1;
    } while (value8 != 0);
    uvalue2 = uvalue2 + 1;
  } while ((intptr_t)uvalue2 < 4);
  pvVar1 = operator_new(0x16c);
  local_4 = 2;
  if (pvVar1 == (void *)0x0) {
    cptr4 = (char *)0x0;
  }
  else {
    cptr4 = (char *)Object_Construct(pvVar1,0x18,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
  }
  uvalue2 = 0xffffffff;
  local_4 = 0xffffffff;
  cptr9 = DAT_00581064;
  do {
    cptr7 = cptr9;
    if (uvalue2 == 0) break;
    uvalue2 = uvalue2 - 1;
    cptr7 = cptr9 + 1;
    cVar12 = *cptr9;
    cptr9 = cptr7;
  } while (cVar12 != '\0');
  uvalue2 = ~uvalue2;
  cptr7 = cptr7 + -uvalue2;
  cptr9 = cptr4;
  for (uvalue5 = uvalue2 >> 2; cptr9 = cptr9 + 4, uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)cptr9 = *(uint32_t *)cptr7;
    cptr7 = cptr7 + 4;
  }
  for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *cptr9 = *cptr7;
    cptr7 = cptr7 + 1;
    cptr9 = cptr9 + 1;
  }
  Game_AddObjectToRegistry(DAT_0057c670,cptr4);
  arg1 = 0;
  do {
    pvVar1 = operator_new(0x16c);
    local_4 = 3;
    if (pvVar1 == (void *)0x0) {
      cptr4 = (char *)0x0;
    }
    else {
      cptr4 = (char *)Object_Construct(pvVar1,10,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
    }
    uvalue2 = 0xffffffff;
    local_4 = 0xffffffff;
    if (arg1 == 0) {
      cptr9 = DAT_00581fe8;
code_r0x004d4c8e:
      do {
        cptr7 = cptr9;
        if (uvalue2 == 0) break;
        uvalue2 = uvalue2 - 1;
        cptr7 = cptr9 + 1;
        cVar12 = *cptr9;
        cptr9 = cptr7;
      } while (cVar12 != '\0');
      uvalue2 = ~uvalue2;
      cptr7 = cptr7 + -uvalue2;
      cptr9 = cptr4;
      for (uvalue5 = uvalue2 >> 2; cptr9 = cptr9 + 4, uvalue5 != 0; uvalue5 = uvalue5 - 1) {
        *(uint32_t *)cptr9 = *(uint32_t *)cptr7;
        cptr7 = cptr7 + 4;
      }
      for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
        *cptr9 = *cptr7;
        cptr7 = cptr7 + 1;
        cptr9 = cptr9 + 1;
      }
    }
    else {
      if (arg1 == 1) {
        cptr9 = DAT_00582aec;
        goto code_r0x004d4c8e;
      }
      if (arg1 == 2) {
        cptr9 = DAT_00582fbc;
        goto code_r0x004d4c8e;
      }
    }
    Game_AddObjectToRegistry(DAT_0057c670,cptr4);
    *(int *)(cptr4 + 0x10c) = arg1;
    arg1 = arg1 + 1;
  } while (arg1 < 3);
  value8 = 10;
  do {
    pvVar1 = operator_new(0x16c);
    local_4 = 4;
    if (pvVar1 == (void *)0x0) {
      uptr3 = (uint32_t *)0x0;
    }
    else {
      uptr3 = Object_Construct(pvVar1,0x16,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
    }
    local_4 = 0xffffffff;
    Game_FormatObjectName(DAT_0057ba10,uptr3[9],(uint8_t *)(uptr3 + 1),DAT_00581ad4);
    Game_AddObjectToRegistry(DAT_0057c670,uptr3);
    value8 = value8 + -1;
  } while (value8 != 0);
  value8 = arg2;
  if (0 < arg2) {
    do {
      pvVar1 = operator_new(0x16c);
      local_4 = 5;
      if (pvVar1 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Object_Construct(pvVar1,0x1d,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      Game_FormatObjectName(DAT_0057ba10,uptr3[9],(uint8_t *)(uptr3 + 1),DAT_00582eec);
      Game_AddObjectToRegistry(DAT_0057c670,uptr3);
      value8 = value8 + -1;
    } while (value8 != 0);
  }
  value8 = arg2 * 2;
  if (0 < value8) {
    do {
      pvVar1 = operator_new(0x16c);
      local_4 = 6;
      if (pvVar1 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Object_Construct(pvVar1,0x1e,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      Game_FormatObjectName(DAT_0057ba10,uptr3[9],(uint8_t *)(uptr3 + 1),DAT_00582dd0);
      Game_AddObjectToRegistry(DAT_0057c670,uptr3);
      value8 = value8 + -1;
    } while (value8 != 0);
  }
  value8 = arg2 * 3;
  if (0 < value8) {
    do {
      pvVar1 = operator_new(0x16c);
      local_4 = 7;
      if (pvVar1 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Object_Construct(pvVar1,0x1f,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      Game_FormatObjectName(DAT_0057ba10,uptr3[9],(uint8_t *)(uptr3 + 1),DAT_00582418);
      Game_AddObjectToRegistry(DAT_0057c670,uptr3);
      value8 = value8 + -1;
    } while (value8 != 0);
  }
  value8 = arg2 * 4;
  if (0 < value8) {
    do {
      pvVar1 = operator_new(0x16c);
      local_4 = 8;
      if (pvVar1 == (void *)0x0) {
        uptr3 = (uint32_t *)0x0;
      }
      else {
        uptr3 = Object_Construct(pvVar1,0x17,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
      }
      local_4 = 0xffffffff;
      IDMap_GetRandomName(DAT_0057ba10,0,(char *)(uptr3 + 1));
      Game_AddObjectToRegistry(DAT_0057c670,uptr3);
      value8 = value8 + -1;
    } while (value8 != 0);
  }
  pvVar1 = operator_new(0x16c);
  local_4 = 9;
  if (pvVar1 == (void *)0x0) {
    cptr4 = (char *)0x0;
  }
  else {
    cptr4 = (char *)Object_Construct(pvVar1,0xb,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
  }
  uvalue2 = 0xffffffff;
  cptr9 = DAT_00582484;
  do {
    cptr7 = cptr9;
    if (uvalue2 == 0) break;
    uvalue2 = uvalue2 - 1;
    cptr7 = cptr9 + 1;
    cVar12 = *cptr9;
    cptr9 = cptr7;
  } while (cVar12 != '\0');
  uvalue2 = ~uvalue2;
  cptr7 = cptr7 + -uvalue2;
  cptr9 = cptr4;
  for (uvalue5 = uvalue2 >> 2; cptr9 = cptr9 + 4, uvalue5 != 0; uvalue5 = uvalue5 - 1) {
    *(uint32_t *)cptr9 = *(uint32_t *)cptr7;
    cptr7 = cptr7 + 4;
  }
  local_4 = 0xffffffff;
  for (uvalue2 = uvalue2 & 3; uvalue2 != 0; uvalue2 = uvalue2 - 1) {
    *cptr9 = *cptr7;
    cptr7 = cptr7 + 1;
    cptr9 = cptr9 + 1;
  }
  Game_AddObjectToRegistry(DAT_0057c670,cptr4);
  pvVar1 = operator_new(0x16c);
  local_4 = 10;
  if (pvVar1 == (void *)0x0) {
    uptr3 = (uint32_t *)0x0;
  }
  else {
    uptr3 = Object_Construct(pvVar1,0xf,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
  }
  local_4 = 0xffffffff;
  Game_FormatObjectNameRandom(DAT_0057ba10,(uint8_t *)(uptr3 + 1),DAT_00582294);
  Game_AddObjectToRegistry(DAT_0057c670,uptr3);
  pvVar1 = operator_new(0x16c);
  local_4 = 0xb;
  if (pvVar1 == (void *)0x0) {
    uptr3 = (uint32_t *)0x0;
  }
  else {
    uptr3 = Object_Construct(pvVar1,0x21,*(int *)((intptr_t)self + 0xc1c),0,0,-1);
  }
  local_4 = 0xffffffff;
  Game_FormatObjectNameRandom(DAT_0057ba10,(uint8_t *)(uptr3 + 1),DAT_00582294);
  Game_AddObjectToRegistry(DAT_0057c670,uptr3);
  value8 = *(int *)((intptr_t)self + 0xfc0);
  value6 = 0;
  if (0 < value8) {
    do {
      value11 = IDMap_Lookup((void *)((intptr_t)self + 0xfac),value6,(int *)0x0);
      if (*(int *)(value11 + 0x8c) < 1) {
        cVar12 = '\x01';
      }
      else {
        cVar12 = '\x02';
      }
      Map_SetCellObjectFrame(*(void **)((intptr_t)self + 0xfa8),*(int *)(value11 + 0x24),cVar12);
      value6 = value6 + 1;
    } while (value6 < value8);
  }
  ExceptionList = local_c;
  return;
}
