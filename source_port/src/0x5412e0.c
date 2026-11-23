// Sound_QueryFormatFlags: ported from Pizza Connection 2 at 0x5412e0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x5412e0
#include "pc2_port.h"

uint32_t __fastcall Sound_QueryFormatFlags(int arg1)

{
  uint32_t uvalue1;
  
  if (*(int **)(arg1 + 0xac) == (int *)0x0) {
    return 0x80004003;
  }
  *(uint32_t *)(arg1 + 0xb0) = 0;
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),2);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 1;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),3);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 2;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),4);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 4;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),5);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 8;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),6);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 0x10;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),7);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 0x20;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),8);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 0x40;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),9);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 0x80;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),10);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 0x100;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),0xb);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 0x200;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),0xc);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 0x400;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),0xd);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 0x800;
  }
  uvalue1 = Input_GetDeviceObjectInfo(*(int **)(arg1 + 0xac),0xe);
  if ((char)uvalue1 != '\0') {
    *(uint32_t *)(arg1 + 0xb0) = *(uint32_t *)(arg1 + 0xb0) | 0x1000;
  }
  return (uint32_t)(*(int *)(arg1 + 0xb0) != 0x1fff);
}
