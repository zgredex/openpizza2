// Product_MapCategory: ported from Pizza Connection 2 at 0x512a10.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x512a10
#include "pc2_port.h"

char * Product_MapCategory(char *arg1)

{
  char *cptr1;
  char cVar2;
  char *cptr3;
  char *cptr4;
  char local_58 [28];
  char local_3c [60];
  
  local_58[0] = '\t';
  local_58[2] = 0x26;
  local_3c[0x1d] = 9;
  local_3c[0x2b] = 0x26;
  local_58[1] = 0x11;
  local_58[3] = 0x35;
  local_58[4] = 0x3b;
  local_58[5] = 0x3e;
  local_58[6] = 0x41;
  local_58[7] = 0xff;
  local_3c[0x18] = 0;
  local_3c[0x19] = 1;
  local_3c[0x1a] = 2;
  local_3c[0x1b] = 3;
  local_3c[0x1c] = 7;
  local_3c[0x1e] = 10;
  local_3c[0x1f] = 0xd;
  local_3c[0x20] = 0x11;
  local_3c[0x21] = 0x12;
  local_3c[0x22] = 0x13;
  local_3c[0x23] = 0x14;
  local_3c[0x24] = 0x15;
  local_3c[0x25] = 0x18;
  local_3c[0x26] = 0x1b;
  local_3c[0x27] = 0x20;
  local_3c[0x28] = 0x22;
  local_3c[0x29] = 0x23;
  local_3c[0x2a] = 0x25;
  local_3c[0x2c] = 0x28;
  local_3c[0x2d] = 0x2d;
  local_3c[0x2e] = 0x30;
  local_3c[0x2f] = 0x31;
  local_3c[0x30] = 0x33;
  local_3c[0x31] = 0x36;
  local_3c[0x32] = 0x37;
  local_3c[0x33] = 0x38;
  local_3c[0x34] = 0x39;
  local_3c[0x35] = 0x3a;
  local_3c[0x36] = 0x3c;
  local_3c[0x37] = 0x3d;
  local_3c[0x38] = 0x41;
  local_3c[0x39] = 0xff;
  local_3c[0] = '\0';
  local_3c[1] = 8;
  local_3c[2] = 10;
  local_3c[3] = 0xd;
  local_3c[4] = 0xe;
  local_3c[5] = 0xf;
  local_3c[6] = 0x10;
  local_3c[7] = 0x16;
  local_3c[8] = 0x1c;
  local_3c[9] = 0x24;
  local_3c[10] = 0x27;
  local_3c[0xb] = 0x2b;
  local_3c[0xc] = 0x2c;
  local_3c[0xd] = 0x2d;
  local_3c[0xe] = 0x30;
  local_3c[0xf] = 0x33;
  local_3c[0x10] = 0x35;
  local_3c[0x11] = 0x36;
  local_3c[0x12] = 0x37;
  local_3c[0x13] = 0x3b;
  local_3c[0x14] = 0x3c;
  local_3c[0x15] = 0x3e;
  local_3c[0x16] = 0x3f;
  local_3c[0x17] = 0xff;
  local_58[8] = 0;
  local_58[9] = 0x11;
  local_58[10] = 0x1c;
  local_58[0xb] = 0x1e;
  local_58[0xc] = 0x24;
  local_58[0x12] = 0x30;
  local_58[0xd] = 0x27;
  local_58[0xe] = 0x2a;
  local_58[0xf] = 0x2b;
  local_58[0x10] = 0x2c;
  local_58[0x11] = 0x2d;
  local_58[0x13] = 0x31;
  local_58[0x14] = 0x39;
  local_58[0x15] = 0x3a;
  local_58[0x16] = 0x3b;
  local_58[0x17] = 0x41;
  local_58[0x18] = 0xff;
  switch(arg1[6]) {
  case '\0':
    cptr4 = local_58 + 8;
    cptr3 = (char *)0x0;
    break;
  case '\x01':
    cptr4 = local_3c;
    cptr3 = (char *)0x0;
    break;
  case '\x02':
    cptr4 = local_3c + 0x18;
    cptr3 = (char *)0x1;
    break;
  case '\x03':
    cptr4 = local_58;
    cptr3 = (char *)0x1;
    break;
  default:
    cptr3 = arg1;
    cptr4 = arg1;
  }
  cVar2 = *cptr4;
  cptr1 = (char *)(uint32_t)(cptr3 == (char *)0x0);
  if (cVar2 != -1) {
    while (cVar2 != arg1[4]) {
      cVar2 = cptr4[1];
      cptr4 = cptr4 + 1;
      if (cVar2 == -1) {
        return (char *)(uint32_t)(cptr3 == (char *)0x0);
      }
    }
    cptr1 = cptr3;
  }
  return cptr1;
}
