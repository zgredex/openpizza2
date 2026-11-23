// DebugConsole_Destructor: ported from Pizza Connection 2 at 0x54a630.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54a630
#include "pc2_port.h"

void __fastcall DebugConsole_Destructor(uint32_t *arg1)

{
                    /* Destroys the debug console and its edit-control DLL. */
  *arg1 = &PTR_DebugConsole_Delete_0055cb3c;
  if ((HWND)arg1[1] != (HWND)0x0) {
    DestroyWindow((HWND)arg1[1]);
  }
  if ((HMODULE)arg1[9] != (HMODULE)0x0) {
    FreeLibrary((HMODULE)arg1[9]);
  }
  return;
}
