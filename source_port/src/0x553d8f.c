// CRT_SetEnvp: ported from Pizza Connection 2 at 0x553d8f.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x553d8f
#include "pc2_port.h"

void CRT_SetEnvp(void)

{
  char cVar1;
  size_t svalue2;
  uint32_t *uptr3;
  void *pvVar4;
  int value5;
  uint32_t *uptr6;
  
  if (DAT_00586d2c == 0) {
    FUN_00556979();
  }
  value5 = 0;
  for (uptr6 = DAT_00585654; (char)*uptr6 != '\0'; uptr6 = (uint32_t *)((intptr_t)uptr6 + svalue2 + 1)) {
    if ((char)*uptr6 != '=') {
      value5 = value5 + 1;
    }
    svalue2 = _strlen((char *)uptr6);
  }
  uptr3 = _malloc(value5 * 4 + 4);
  DAT_00585630 = uptr3;
  if (uptr3 == (uint32_t *)0x0) {
    __amsg_exit(9);
  }
  cVar1 = (char)*DAT_00585654;
  uptr6 = DAT_00585654;
  while (cVar1 != '\0') {
    svalue2 = _strlen((char *)uptr6);
    if ((char)*uptr6 != '=') {
      pvVar4 = _malloc(svalue2 + 1);
      *uptr3 = pvVar4;
      if (pvVar4 == (void *)0x0) {
        __amsg_exit(9);
      }
      _strcpy((uint32_t *)*uptr3,uptr6);
      uptr3 = uptr3 + 1;
    }
    uptr6 = (uint32_t *)((intptr_t)uptr6 + svalue2 + 1);
    cVar1 = (char)*uptr6;
  }
  CRT_FreeInternal(DAT_00585654);
  DAT_00585654 = (uint32_t *)0x0;
  *uptr3 = 0;
  DAT_00586d28 = 1;
  return;
}
