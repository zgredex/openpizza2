// UI_Child_HandleControlCommand: ported from Pizza Connection 2 at 0x521390.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x521390
#include "pc2_port.h"

uint32_t __thiscall
UI_Child_HandleControlCommand(void *self,uint32_t arg1,uint32_t arg2,int arg3)

{
  void *local_4;
  
  local_4 = self;
  switch(arg1) {
  case 4:
    break;
  case 5:
    if (*(int *)((intptr_t)self + 0x50) == 0) {
      return *(uint32_t *)((intptr_t)self + 0x58) | *(uint32_t *)((intptr_t)self + 0x54);
    }
    *(uint32_t *)((intptr_t)self + 0x50) = 0;
    return *(uint32_t *)((intptr_t)self + 0x58) | *(uint32_t *)((intptr_t)self + 0x54);
  case 6:
    UI_QueueControlCommand(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),6,arg3);
    *(uint32_t *)((intptr_t)self + 0x54) = 1;
    return *(uint32_t *)((intptr_t)self + 0x58) | 1;
  case 7:
    if (*(int *)((intptr_t)self + 0x50) != 0) {
      UI_QueueControlCommand(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),5,0);
    }
    UI_QueueControlCommand(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),7,arg3);
    *(uint32_t *)((intptr_t)self + 0x54) = 0;
    return *(uint32_t *)((intptr_t)self + 0x58);
  case 8:
    UI_QueueControlCommand(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),9,arg3);
    *(uint32_t *)((intptr_t)self + 0x58) = 1;
    return *(uint32_t *)((intptr_t)self + 0x54) | 1;
  case 9:
    UI_QueueControlCommand(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),10,arg3);
    *(uint32_t *)((intptr_t)self + 0x58) = 0;
    return *(uint32_t *)((intptr_t)self + 0x54);
  case 10:
    *(uint32_t *)((intptr_t)self + 0x50) = 0;
    *(uint32_t *)((intptr_t)self + 0x58) = 0;
    *(uint32_t *)((intptr_t)self + 0x54) = 0;
  default:
    return 0;
  case 0x36:
    return (uint32_t)self;
  case 0xd4:
  case 0xde:
    return 1;
  case 0xd5:
    Sprite_GetSize(*(void **)((intptr_t)self + 0x60),(int *)&arg1,(int *)&local_4);
    return arg1;
  case 0xdf:
    Sprite_GetSize(*(void **)((intptr_t)self + 0x60),(int *)&arg1,(int *)&local_4);
    return (uint32_t)local_4;
  }
  UI_QueueControlCommand(*(void **)((intptr_t)self + 8),*(int *)((intptr_t)self + 4),8,arg3);
  if (*(int *)((intptr_t)self + 0x50) == 0) {
    *(uint32_t *)((intptr_t)self + 0x50) = 1;
    return *(uint32_t *)((intptr_t)self + 0x58) | *(uint32_t *)((intptr_t)self + 0x54);
  }
  return *(uint32_t *)((intptr_t)self + 0x58) | *(uint32_t *)((intptr_t)self + 0x54);
}
