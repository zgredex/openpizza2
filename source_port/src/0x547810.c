// Sound_LoadEffectBuffers: ported from Pizza Connection 2 at 0x547810.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x547810
#include "pc2_port.h"

void __fastcall Sound_LoadEffectBuffers(int arg1)

{
  int value1;
  int value2;
  uint8_t **pptr3;
  uint32_t *uptr4;
  uint8_t local_104 [260];
  
  pptr3 = &PTR_s_Sfx_Makepizza_Cut_Food_wav_005750a0;
  value2 = arg1 + 0x24;
  do {
    String_Format(local_104,(uint8_t *)s_sfx__s_005760c8,*pptr3);
    value1 = (**(code **)(**(int **)(arg1 + 8) + 0x28))(*(int **)(arg1 + 8),local_104,value2);
    if (value1 < 0) break;
    pptr3 = pptr3 + 1;
    value2 = value2 + 4;
  } while ((intptr_t)pptr3 < 0x57510c);
  pptr3 = &PTR_s_Sfx_Action_Bomb_Explo_wav_0057510c;
  uptr4 = (uint32_t *)(arg1 + 0x90);
  do {
    String_Format(local_104,(uint8_t *)s_sfx__s_005760c8,*pptr3);
    value2 = (**(code **)(**(int **)(arg1 + 8) + 0x28))(*(int **)(arg1 + 8),local_104,uptr4);
    if (-1 < value2) {
      (**(code **)(**(int **)(arg1 + 8) + 0x9c))
                (*(int **)(arg1 + 8),*(uint32_t *)(arg1 + 0xf4),*uptr4);
    }
    pptr3 = pptr3 + 1;
    uptr4 = uptr4 + 1;
  } while ((intptr_t)pptr3 < 0x575170);
  return;
}
