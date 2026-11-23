// Recipe_SaveToStream: ported from Pizza Connection 2 at 0x510640.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x510640
#include "pc2_port.h"

void __thiscall Recipe_SaveToStream(void *self,void *arg1,char arg2)

{
  void *this_00;
  void *this_01;
  int value1;
  void *pvVar2;
  void *local_4;
  
  this_00 = arg1;
  local_4 = self;
  CRT_Ostream_Write(arg1,(intptr_t)self + 4,0x40);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x44,4);
  local_4 = *(void **)((intptr_t)self + 0x5c);
  CRT_Ostream_Write(this_00,&local_4,4);
  arg1 = (void *)0x0;
  if (0 < (intptr_t)local_4) {
    do {
      pvVar2 = this_00;
      this_01 = (void *)IDMap_Lookup((void *)((intptr_t)self + 0x48),(intptr_t)arg1,(int *)0x0);
      RecipeTopping_Save(this_01,pvVar2);
      arg1 = (void *)((intptr_t)arg1 + 1);
    } while ((intptr_t)arg1 < (intptr_t)local_4);
  }
  CRT_Ostream_Write(this_00,(intptr_t)self + 100,0x158);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x1bc,0x1c);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x1d8,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x1dc,1);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x1e0,0x60);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x240,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x244,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x248,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x24c,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x250,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x254,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 600,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x264,0x20);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x284,0x20);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2a4,0x20);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x2c4,0x20);
  if (*(int *)((intptr_t)self + 0x304) == 0) {
    arg1 = (void *)0x0;
    CRT_Ostream_Write(this_00,&arg1,4);
  }
  else if (arg2 == '\0') {
    arg1 = (void *)0x0;
    CRT_Ostream_Write(this_00,&arg1,4);
  }
  else {
    arg1 = (void *)0x1;
    CRT_Ostream_Write(this_00,&arg1,4);
    local_4 = *(void **)(*(int *)((intptr_t)self + 0x304) + 0x14);
    CRT_Ostream_Write(this_00,&local_4,4);
    arg1 = (void *)0x0;
    if (0 < (intptr_t)local_4) {
      do {
        value1 = IDMap_Lookup(*(void **)((intptr_t)self + 0x304),(intptr_t)arg1,(int *)0x0);
        CRT_Ostream_Write(this_00,value1,4);
        CRT_Ostream_Write(this_00,value1 + 4,4);
        CRT_Ostream_Write(this_00,value1 + 8,4);
        CRT_Ostream_Write(this_00,value1 + 0xc,4);
        CRT_Ostream_Write(this_00,value1 + 0x10,4);
        CRT_Ostream_Write(this_00,value1 + 0x14,4);
        CRT_Ostream_Write(this_00,value1 + 0x18,4);
        arg1 = (void *)((intptr_t)arg1 + 1);
      } while ((intptr_t)arg1 < (intptr_t)local_4);
    }
  }
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x308,4);
  CRT_Ostream_Write(this_00,(intptr_t)self + 0x30c,4);
  return;
}
