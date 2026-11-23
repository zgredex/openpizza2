// __cfltcvt: ported from Pizza Connection 2 at 0x551d98.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x551d98
#include "pc2_port.h"

/* Library Function - Single Match
    __cfltcvt
   
   Library: Visual Studio 2003 Release */

errno_t __cdecl
__cfltcvt(double *arg,char *buffer,size_t sizeInBytes,int format,int precision,int caps)

{
  char *cptr1;
  uint8_t *uptr2;
  
  if ((sizeInBytes == 0x65) || (sizeInBytes == 0x45)) {
    uptr2 = CRT_Cftoe(arg,buffer,format,precision);
  }
  else {
    if (sizeInBytes == 0x66) {
      cptr1 = CRT_Cftof(arg,buffer,format);
      return (errno_t)cptr1;
    }
    uptr2 = (uint8_t *)CRT_Cftog(arg,buffer,format,precision);
  }
  return (errno_t)uptr2;
}
