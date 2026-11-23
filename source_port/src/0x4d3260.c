// Car_ConstructFromSave: ported from Pizza Connection 2 at 0x4d3260.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x4d3260
#include "pc2_port.h"

uint32_t * __thiscall Car_ConstructFromSave(void *self,void *arg1)

{
                    /* Constructs a car record from a save stream. */
  *(uint8_t ***)self = &PTR_Car_Delete_0055c4f8;
  Car_LoadFromStream(self,arg1);
  return self;
}
