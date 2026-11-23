// SoundSystem_Init: ported from Pizza Connection 2 at 0x5475a0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5475a0
#include "pc2_port.h"

void __thiscall SoundSystem_Init(void *self,int arg1)

{
  int value1;
  uint32_t *uptr2;
  int *ptr3;
  
  if (arg1 == 0) {
    ptr3 = *(int **)((intptr_t)self + 8);
    if (ptr3 != (int *)0x0) {
      (**(code **)(*ptr3 + 4))();
      *(uint32_t *)((intptr_t)self + 8) = 0;
      *(uint32_t *)((intptr_t)self + 0xc) = 0;
      *(uint32_t *)((intptr_t)self + 0x10) = 0;
      *(uint32_t *)((intptr_t)self + 0x14) = 0;
      *(uint32_t *)((intptr_t)self + 0x20) = 0;
      *(uint32_t *)((intptr_t)self + 0xf4) = 0;
      *(uint32_t *)((intptr_t)self + 0xf8) = 0;
      uptr2 = (uint32_t *)((intptr_t)self + 0x244);
      for (value1 = 8; value1 != 0; value1 = value1 + -1) {
        *uptr2 = 0;
        uptr2 = uptr2 + 1;
      }
      *(uint8_t *)((intptr_t)self + 0xfc) = 0;
      *(uint8_t *)((intptr_t)self + 0xfd) = 0;
      *(uint32_t *)self = 0;
      DebugConsole_Printf(DAT_0057c1e0,0xff0000,(uint8_t *)s_Sound_disabled__005760b8,ptr3);
      return;
    }
  }
  else {
    uptr2 = (uint32_t *)((intptr_t)self + 8);
    if (*(int *)((intptr_t)self + 8) == 0) {
      Sound_ClampGlobalLimits();
      value1 = Sound_CreatePrimaryBuffer(0,DAT_0057c5d0,uptr2);
      *(bool *)((intptr_t)self + 0xfd) = -1 < value1;
      if (-1 < value1) {
        *(uint8_t *)((intptr_t)self + 0xfc) = 1;
        (**(code **)(*(int *)*uptr2 + 0xc))((int *)*uptr2,1);
        (**(code **)(*(int *)*uptr2 + 0x14))((int *)*uptr2,s_Sound__005760b0);
        (**(code **)(*(int *)*uptr2 + 0x18))((int *)*uptr2,s_resources_sound_pak_0057609c);
        (**(code **)(*(int *)*uptr2 + 0x10))((int *)*uptr2,1);
        (**(code **)(*(int *)*uptr2 + 0x24))((int *)*uptr2,0);
        (**(code **)(*(int *)*uptr2 + 0x38))((int *)*uptr2,(intptr_t)self + 0xf4);
        ptr3 = (int *)*uptr2;
        (**(code **)(*ptr3 + 0x38))(ptr3,(intptr_t)self + 0xf8);
        Sound_LoadEffectBuffers((intptr_t)self);
        Sound_ApplySettings(self,&DAT_00575090);
        Sound_LoadSpeechSet(self);
        DebugConsole_Printf(DAT_0057c1e0,0xff0000,(uint8_t *)s_Sound_successfully_initialized__0057607c
                            ,ptr3);
      }
    }
  }
  return;
}
