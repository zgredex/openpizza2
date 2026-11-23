// SpriteCache_MakeKey: ported from Pizza Connection 2 at 0x5273c0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5273c0
#include "pc2_port.h"

void SpriteCache_MakeKey(char *arg1,uint32_t *arg2)

{
  char *cptr1;
  
  cptr1 = _strrchr(arg1,0x5c);
  if (cptr1 != (char *)0x0) {
    arg1 = cptr1 + 1;
  }
  _strncpy((char *)arg2,arg1,0x3f);
  *(uint8_t *)((intptr_t)arg2 + 0x3f) = 0;
  CRT_Strupr(arg2);
  return;
}
