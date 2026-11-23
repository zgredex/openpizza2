// TimerClass_Construct: ported from Pizza Connection 2 at 0x4039d0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4039d0
#include "pc2_port.h"


uint32_t * __fastcall TimerClass_Construct(uint32_t *arg1)

{
  char cVar1;
  HANDLE pvVar2;
  uint32_t uvalue3;
  uint32_t uvalue4;
  char *cptr5;
  char *cptr6;
  
                    /* Constructs the timer class, event, and worker thread. */
  NamedLockable_Construct(arg1 + 4,(char *)0x0);
  uvalue3 = 0xffffffff;
  *arg1 = &PTR_TimerClass_ScalarDeletingDestructor_0055c308;
  cptr5 = s_timer_crit_00563818;
  do {
    cptr6 = cptr5;
    if (uvalue3 == 0) break;
    uvalue3 = uvalue3 - 1;
    cptr6 = cptr5 + 1;
    cVar1 = *cptr5;
    cptr5 = cptr6;
  } while (cVar1 != '\0');
  uvalue3 = ~uvalue3;
  cptr5 = cptr6 + -uvalue3;
  cptr6 = (char *)(arg1 + 0xb);
  for (uvalue4 = uvalue3 >> 2; uvalue4 != 0; uvalue4 = uvalue4 - 1) {
    *(uint32_t *)cptr6 = *(uint32_t *)cptr5;
    cptr5 = cptr5 + 4;
    cptr6 = cptr6 + 4;
  }
  for (uvalue3 = uvalue3 & 3; uvalue3 != 0; uvalue3 = uvalue3 - 1) {
    *cptr6 = *cptr5;
    cptr5 = cptr5 + 1;
    cptr6 = cptr6 + 1;
  }
  arg1[1] = 0;
  arg1[2] = 0;
  arg1[3] = 0;
  arg1[0x1a] = 0;
  pvVar2 = CreateEventA((LPSECURITY_ATTRIBUTES)0x0,0,0,s_TimerClassHandle_00563804);
  arg1[0x1b] = pvVar2;
  CRT_BeginThread(0x4039c0,0,(intptr_t)arg1);
  return arg1;
}
