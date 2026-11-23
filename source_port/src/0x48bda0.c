// Game_OnObjectListSelection: ported from Pizza Connection 2 at 0x48bda0.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x48bda0
#include "pc2_port.h"

void __fastcall Game_OnObjectListSelection(void *arg1)

{
  void *pvVar1;
  
                    /* Resolves an object-list selection and forwards it. */
  pvVar1 = (void *)IDMap_Lookup((void *)((intptr_t)arg1 + 0x3c),*(int *)((intptr_t)arg1 + 0x288),
                                (int *)0x0);
  if (pvVar1 != (void *)0x0) {
    Game_SelectFoundObject(arg1,pvVar1);
  }
  return;
}
