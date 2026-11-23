// UI_SetImageFromTemplate: ported from Pizza Connection 2 at 0x4cb860.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4cb860
#include "pc2_port.h"

void __cdecl UI_SetImageFromTemplate(void *arg1)

{
  int in_stack_000000a8;
  int in_stack_000000ac;
  int in_stack_000000b0;
  int in_stack_000000b4;
  void *in_stack_000000b8;
  int in_stack_000000c8;
  
  UI_ComposeOverlayWindow
            (arg1,in_stack_000000c8,in_stack_000000a8,in_stack_000000b8,in_stack_000000b0,
             in_stack_000000ac,in_stack_000000b4);
  return;
}
