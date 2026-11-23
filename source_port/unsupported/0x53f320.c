// PORT_STATUS: STUB
// Bulk translation did not compile: /home/patryk/pizzaconnection2/source_port/src/0x53f320.c:25:53: error: invalid operands to binary expression ('char[4]' and 'int')
// SoundSample_ParseWavFormat: ported from Pizza Connection 2 at 0x53f320.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x53f320
#include "pc2_port.h"

uint32_t __fastcall SoundSample_ParseWavFormat(int arg1)

{
  int *ptr1;
  uint32_t uvalue2;
  int value3;
  char *cptr4;
  char local_4 [4];
  
  if (*(int *)(arg1 + 0xc) == 0) {
    return 0x80004003;
  }
  local_4[0] = '\0';
  local_4[1] = '\0';
  local_4[2] = '\0';
  local_4[3] = '\0';
  Stream_Seek(0x10,*(int *)(arg1 + 0xc),0);
  uvalue2 = SoundPakStream_Read(*(void **)(arg1 + 8),local_4,4,*(int *)(arg1 + 0xc));
  if (3 < uvalue2) {
    *(short *)(arg1 + 0x24) = ((uint64_t)((local_4) >> 16)) + -0x10;
    uvalue2 = SoundPakStream_Read(*(void **)(arg1 + 8),(char *)(arg1 + 0x14),0x10,
                                *(int *)(arg1 + 0xc));
    if (0xf < uvalue2) {
      if (*(short *)(arg1 + 0x14) == 1) {
        Stream_Seek(4,*(int *)(arg1 + 0xc),1);
        value3 = *(int *)(arg1 + 0xc);
        cptr4 = (char *)(arg1 + 0x28);
      }
      else {
        value3 = Sound_AllocDecompressedBuffer(arg1);
        if (value3 < 0) {
          NoOp_Stub();
          return 0x80004001;
        }
        Stream_Seek(*(uint16_t *)(arg1 + 0x24) + 8,*(int *)(arg1 + 0xc),1);
        ptr1 = (int *)(arg1 + 0x28);
        uvalue2 = SoundPakStream_Read(*(void **)(arg1 + 8),(char *)ptr1,4,*(int *)(arg1 + 0xc)
                                   );
        if (uvalue2 < 4) {
          return 0x80004005;
        }
        *ptr1 = (uint32_t)*(uint16_t *)(arg1 + 0x16) * *ptr1 * 2;
        Stream_Seek(4,*(int *)(arg1 + 0xc),1);
        value3 = *(int *)(arg1 + 0xc);
        cptr4 = (char *)(arg1 + 0x38);
      }
      uvalue2 = SoundPakStream_Read(*(void **)(arg1 + 8),cptr4,4,value3);
      if (3 < uvalue2) {
        *(uint32_t *)(arg1 + 0x2c) = *(uint32_t *)(*(int *)(arg1 + 0xc) + 0x10);
        return 0;
      }
    }
  }
  return 0x80004005;
}
