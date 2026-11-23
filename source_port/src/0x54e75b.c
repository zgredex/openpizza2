// CRT_SeTranslatorFrameHandler: ported from Pizza Connection 2 at 0x54e75b.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54e75b
#include "pc2_port.h"

struct pc2_obj_0x54e75b_arg1 { intptr_t ExceptionFlags; };
uint32_t __cdecl
CRT_SeTranslatorFrameHandler(struct pc2_obj_0x54e75b_arg1 *arg1,PVOID arg2,DWORD arg3)

{
  uint32_t uvalue1;
  
                    /* Handles unwinding for the SEH translator call frame. */
  if ((arg1->ExceptionFlags & 0x66) != 0) {
    *(uint32_t *)((intptr_t)arg2 + 0x24) = 1;
    return 1;
  }
  CRT_InternalCxxFrameHandler
            (arg1,*(PVOID *)((intptr_t)arg2 + 0xc),arg3,0,*(int **)((intptr_t)arg2 + 8),
             *(int *)((intptr_t)arg2 + 0x10),*(PVOID *)((intptr_t)arg2 + 0x14),'\x01');
  if (*(int *)((intptr_t)arg2 + 0x24) == 0) {
    CRT_Unwind(arg2,arg1);
  }
                    /* WARNING: Could not recover jumptable at 0x0054e7c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uvalue1 = (**(code **)((intptr_t)arg2 + 0x18))();
  return uvalue1;
}
