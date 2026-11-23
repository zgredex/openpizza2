// ___timet_from_ft: ported from Pizza Connection 2 at 0x54f585.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54f585
#include "pc2_port.h"

struct pc2_obj_0x54f585_arg1 { intptr_t dwLowDateTime; intptr_t dwHighDateTime; };
struct pc2_obj_0x54f585_local_1c { intptr_t wYear; intptr_t wMonth; intptr_t wDay; intptr_t wHour; intptr_t wMinute; intptr_t wSecond; };
/* Library Function - Single Match
    ___timet_from_ft
   
   Library: Visual Studio 2003 Release */

int __cdecl ___timet_from_ft(struct pc2_obj_0x54f585_arg1 *arg1)

{
  BOOL BVar1;
  int value2;
  struct pc2_obj_0x54f585_local_1c *local_1c;
  _FILETIME local_c;
  
  if ((arg1->dwLowDateTime != 0) || (arg1->dwHighDateTime != 0)) {
    BVar1 = FileTimeToLocalFileTime(arg1,&local_c);
    if (BVar1 != 0) {
      BVar1 = FileTimeToSystemTime(&local_c,&local_1c);
      if (BVar1 != 0) {
        value2 = CRT_LoctoTime64((uint32_t)local_1c->wYear,(uint32_t)local_1c->wMonth,(uint32_t)local_1c->wDay,
                                (uint32_t)local_1c->wHour,(uint32_t)local_1c->wMinute,(uint32_t)local_1c->wSecond,
                                -1);
        return value2;
      }
    }
  }
  return -1;
}
