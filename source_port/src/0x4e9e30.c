// Game_Destroy: ported from Pizza Connection 2 at 0x4e9e30.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4e9e30
#include "pc2_port.h"


void __fastcall Game_Destroy(uint32_t *arg1)

{
  int value1;
  int *ptr2;
  int value3;
  int *ptr4;
  int local_14;
  void *pvStack_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
  puStack_8 = &LAB_00559e5e;
  pvStack_c = ExceptionList;
  ExceptionList = &pvStack_c;
  *arg1 = &PTR_Game_Delete_0055c5d0;
  ptr2 = (int *)arg1[7];
  local_4 = 0;
  if (ptr2 != (int *)0x0) {
    PaletteList_Free(ptr2);
    Mem_Free(ptr2);
  }
  ptr2 = arg1 + 0x1a;
  local_14 = 0x9c4;
  do {
    if ((uint32_t *)ptr2[-4] != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)ptr2[-4])(1);
      ptr2[-4] = 0;
    }
    if (*ptr2 != 0) {
      value3 = 0;
      if (0 < *(int *)(*ptr2 + 0x14)) {
        do {
          value1 = IDMap_Lookup((void *)*ptr2,value3,(int *)0x0);
          if (*(uint32_t **)(value1 + 0x48) != (uint32_t *)0x0) {
            (**(code **)**(uint32_t **)(value1 + 0x48))(1);
          }
          value3 = value3 + 1;
        } while (value3 < *(int *)(*ptr2 + 0x14));
      }
      if ((uint32_t *)*ptr2 != (uint32_t *)0x0) {
        (*(code *)**(uint32_t **)*ptr2)(1);
      }
    }
    if ((uint32_t *)ptr2[-3] != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)ptr2[-3])(1);
    }
    if ((uint32_t *)ptr2[-2] != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)ptr2[-2])(1);
    }
    if ((uint32_t *)ptr2[-1] != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)ptr2[-1])(1);
    }
    ptr2 = ptr2 + 0x12;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  if ((uint32_t *)arg1[3] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[3])(1);
  }
  if ((uint32_t *)arg1[5] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[5])(1);
  }
  if ((uint32_t *)arg1[4] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[4])(1);
  }
  if ((uint32_t *)arg1[6] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[6])(1);
  }
  Record_Clear48((void *)arg1[0xb0ee],arg1[0xb105]);
  Record_Clear48((void *)arg1[0xb0ed],arg1[0xb106]);
  ptr2 = arg1 + 0xb126;
  ptr4 = arg1 + 0xb107;
  value3 = 6;
  do {
    Record_Clear48((void *)arg1[0xb0f5],*ptr4);
    Record_Clear48((void *)arg1[0xb0fa],ptr2[-1]);
    Record_Clear48((void *)arg1[0xb0fb],*ptr2);
    Record_Clear48((void *)arg1[0xb0fc],ptr2[1]);
    Record_Clear48((void *)arg1[0xb0fd],ptr2[2]);
    Record_Clear48((void *)arg1[0xb0f6],ptr2[-0x19]);
    Record_Clear48((void *)arg1[0xb0f7],ptr2[-0x18]);
    Record_Clear48((void *)arg1[0xb0f8],ptr2[-0x17]);
    Record_Clear48((void *)arg1[0xb0f9],ptr2[-0x16]);
    ptr4 = ptr4 + 1;
    ptr2 = ptr2 + 4;
    value3 = value3 + -1;
  } while (value3 != 0);
  value3 = 0;
  ptr2 = arg1 + 0xb003;
  do {
    if (value3 != 0x10) {
      if ((uint32_t *)ptr2[-0x30] != (uint32_t *)0x0) {
        (*(code *)**(uint32_t **)ptr2[-0x30])(1);
      }
      if ((uint32_t *)*ptr2 != (uint32_t *)0x0) {
        (*(code *)**(uint32_t **)*ptr2)(1);
      }
      if ((uint32_t *)ptr2[0x8a] != (uint32_t *)0x0) {
        (*(code *)**(uint32_t **)ptr2[0x8a])(1);
      }
      if ((uint32_t *)ptr2[0xba] != (uint32_t *)0x0) {
        (*(code *)**(uint32_t **)ptr2[0xba])(1);
      }
    }
    value3 = value3 + 1;
    ptr2 = ptr2 + 1;
  } while (value3 < 0x30);
  ptr2 = arg1 + 0xb033;
  value3 = 0x2d;
  do {
    if ((uint32_t *)*ptr2 != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)*ptr2)(1);
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  if ((uint32_t *)arg1[0xb060] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb060])(1);
  }
  if ((uint32_t *)arg1[0xb061] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb061])(1);
  }
  if ((uint32_t *)arg1[0xb067] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb067])(1);
  }
  if ((uint32_t *)arg1[0xb06d] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb06d])(1);
  }
  if ((uint32_t *)arg1[0xb073] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb073])(1);
  }
  if ((uint32_t *)arg1[0xb079] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb079])(1);
  }
  if ((uint32_t *)arg1[0xb07a] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb07a])(1);
  }
  if ((uint32_t *)arg1[0xb080] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb080])(1);
  }
  if ((uint32_t *)arg1[0xb086] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb086])(1);
  }
  if ((uint32_t *)arg1[0xb087] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb087])(1);
  }
  if ((uint32_t *)arg1[0xb0ed] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb0ed])(1);
  }
  if ((uint32_t *)arg1[0xb0ee] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb0ee])(1);
  }
  if ((uint32_t *)arg1[0xb0ef] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb0ef])(1);
  }
  if ((uint32_t *)arg1[0xb0f0] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb0f0])(1);
  }
  if ((uint32_t *)arg1[0xb0f2] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb0f2])(1);
  }
  if ((uint32_t *)arg1[0xb0f1] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb0f1])(1);
  }
  if ((uint32_t *)arg1[0xb0f3] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb0f3])(1);
  }
  if ((uint32_t *)arg1[0xb0f4] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb0f4])(1);
  }
  if ((uint32_t *)arg1[0xb0f5] != (uint32_t *)0x0) {
    (*(code *)**(uint32_t **)arg1[0xb0f5])(1);
  }
  ptr2 = arg1 + 0xb0f6;
  value3 = 4;
  do {
    if ((uint32_t *)ptr2[4] != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)ptr2[4])(1);
    }
    if ((uint32_t *)*ptr2 != (uint32_t *)0x0) {
      (*(code *)**(uint32_t **)*ptr2)(1);
    }
    ptr2 = ptr2 + 1;
    value3 = value3 + -1;
  } while (value3 != 0);
  value3 = 0;
  do {
    if (*(uint32_t **)((intptr_t)&DAT_005806ec + value3) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)((intptr_t)&DAT_005806ec + value3))(1);
    }
    if (*(uint32_t **)((intptr_t)&DAT_0058070c + value3) != (uint32_t *)0x0) {
      (**(code **)**(uint32_t **)((intptr_t)&DAT_0058070c + value3))(1);
    }
    value3 = value3 + 4;
  } while (value3 < 0x20);
  if (DAT_00580730 != (uint32_t *)0x0) {
    (**(code **)*DAT_00580730)(1);
  }
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 0xb0fe);
  ExceptionList = pvStack_c;
  return;
}
