// SoundSystem_Construct: ported from Pizza Connection 2 at 0x547030.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547030
#include "pc2_port.h"


uint32_t * __fastcall SoundSystem_Construct(uint32_t *arg1)

{
  DWORD DVar1;
  uint32_t uvalue2;
  int value3;
  uint32_t *uptr4;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t local_4;
  
                    /* Constructs the global sound system and initializes DirectSound. */
  local_4 = 0xffffffff;
  puStack_8 = &LAB_0055b87e;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  DVar1 = GetCurrentThreadId();
  arg1[1] = DVar1;
  DVar1 = timeGetTime();
  CRT_Srand(DVar1);
  NamedLockable_Construct(arg1 + 0x5e,(char *)0x0);
  *(uint8_t *)(arg1 + 0x3f) = 0;
  arg1[6] = 1000;
  arg1[7] = 1000;
  *(uint8_t *)((intptr_t)arg1 + 0xfd) = 0;
  arg1[0x42] = 0xffffffff;
  arg1[0x58] = 0xffffffff;
  arg1[0x59] = 0xffffffff;
  *(uint8_t *)((intptr_t)arg1 + 0xfe) = 0;
  *(uint8_t *)((intptr_t)arg1 + 0xff) = 0;
  local_4 = 0;
  *(uint8_t *)(arg1 + 0x40) = 0;
  *arg1 = 0;
  arg1[2] = 0;
  arg1[3] = 0;
  arg1[4] = 0;
  arg1[0x3d] = 0;
  arg1[0x3e] = 0;
  arg1[5] = 0;
  arg1[8] = 0;
  arg1[0x41] = 0;
  arg1[0x51] = 0;
  arg1[0x53] = 0;
  arg1[0x52] = 0x3f800000;
  *(uint8_t *)(arg1 + 0x5a) = 0;
  *(uint8_t *)((intptr_t)arg1 + 0x169) = 0;
  *(uint8_t *)((intptr_t)arg1 + 0x16a) = 0;
  *(uint8_t *)(arg1 + 0x50) = 0;
  arg1[0x5b] = 0;
  arg1[0x5c] = 0x3f800000;
  arg1[0x54] = 0;
  arg1[0x55] = 0;
  arg1[0x56] = 0;
  arg1[0x57] = 0;
  arg1[0x4f] = 0;
  Sound_ClampGlobalLimits();
  arg1[0x74] = DAT_00575094;
  uvalue2 = Sound_ConvertVolumeSetting(DAT_00575098);
  arg1[0x75] = uvalue2;
  uvalue2 = Sound_ConvertVolumeSetting(DAT_0057509c);
  arg1[0x76] = uvalue2;
  uptr4 = arg1 + 9;
  for (value3 = 0x34; value3 != 0; value3 = value3 + -1) {
    *uptr4 = 0;
    uptr4 = uptr4 + 1;
  }
  uptr4 = arg1 + 0x91;
  for (value3 = 8; value3 != 0; value3 = value3 + -1) {
    *uptr4 = 0;
    uptr4 = uptr4 + 1;
  }
  uptr4 = arg1 + 0x43;
  for (value3 = 0xc; value3 != 0; value3 = value3 + -1) {
    *uptr4 = 0;
    uptr4 = uptr4 + 1;
  }
  arg1[0x5d] = 0;
  uptr4 = arg1 + 0x77;
  for (value3 = 0x1a; value3 != 0; value3 = value3 + -1) {
    *uptr4 = 1;
    uptr4 = uptr4 + 1;
  }
  ExceptionList = local_c;
  return arg1;
}
