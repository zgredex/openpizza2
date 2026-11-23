// Sound_PlayWeaponPageEvent: ported from Pizza Connection 2 at 0x549f50.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x549f50
#include "pc2_port.h"

void __thiscall Sound_PlayWeaponPageEvent(void *self,uint32_t arg1,int arg2)

{
  int value1;
  bool flag2;
  
  if (*(char *)((intptr_t)self + 0xfc) != '\0') {
    flag2 = arg2 == 0;
    switch(arg1) {
    case 0:
      Sound_ProcessEvent(self,0,0,flag2);
      return;
    case 1:
      Sound_ProcessEvent(self,1,0,flag2);
      return;
    case 2:
      Sound_ProcessEvent(self,2,0,flag2);
      return;
    case 3:
      Sound_ProcessEvent(self,3,0,flag2);
      return;
    case 4:
      Sound_ProcessEvent(self,4,0,flag2);
      return;
    case 6:
      Sound_ProcessEvent(self,6,0,flag2);
      return;
    case 7:
      Sound_ProcessEvent(self,7,0,flag2);
      return;
    case 8:
      value1 = 0x21;
      if (flag2) goto LAB_0054a1ed;
    case 5:
      Sound_ProcessEvent(self,5,0,flag2);
      return;
    case 9:
      Sound_ProcessEvent(self,0xb,0,flag2);
      return;
    case 10:
      Sound_ProcessEvent(self,0x14,0,flag2);
      return;
    case 0xb:
      Sound_ProcessEvent(self,0x13,0,flag2);
      return;
    case 0xc:
      Sound_ProcessEvent(self,0x11,0,flag2);
      return;
    case 0xd:
      Sound_ProcessEvent(self,0x12,0,flag2);
      return;
    case 0xe:
      Sound_ProcessEvent(self,0x13,6,flag2);
      return;
    case 0xf:
      Sound_ProcessEvent(self,0x17,0,'\x01');
      return;
    case 0x10:
      Sound_ProcessEvent(self,0x16,0,flag2);
      return;
    case 0x11:
      Sound_ProcessEvent(self,0x1f,0,flag2);
      return;
    case 0x12:
      Sound_ProcessEvent(self,0x1e,0,'\x01');
      return;
    case 0x13:
      Sound_ProcessEvent(self,0x1d,0,'\x01');
      return;
    case 0x14:
      Sound_ProcessEvent(self,0xd,0,'\x01');
      return;
    case 0x15:
      Sound_ProcessEvent(self,10,0,flag2);
      return;
    case 0x16:
      Sound_ProcessEvent(self,0x18,0,flag2);
      return;
    case 0x17:
      Sound_ProcessEvent(self,0x22,0,'\x01');
      return;
    case 0x18:
      Sound_ProcessEvent(self,0x14,7,'\x01');
      return;
    case 0x19:
      Sound_ProcessEvent(self,0xe,0,flag2);
      return;
    case 0x1a:
      value1 = 0x20;
LAB_0054a1ed:
      Sound_ProcessEvent(self,value1,0,flag2);
      return;
    case 0x1b:
      Sound_PlayEffectByIndex(self,0x2c);
      return;
    case 0x1c:
      Sound_PlayEffectByIndex(self,0x21);
      return;
    case 0x1d:
      Sound_PlayEffectByIndex(self,0x22);
    }
  }
  return;
}
