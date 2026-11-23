// Person_UpdateIndoorAction: ported from Pizza Connection 2 at 0x406e90.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x406e90
#include "pc2_port.h"

void __thiscall Person_UpdateIndoorAction(void *self,void *arg1)

{
  int value1;
  char *cptr2;
  
                    /* Dispatches an indoor person to its action handler. */
  value1 = *(int *)((intptr_t)arg1 + 0xf4);
  if ((value1 != 0) &&
     (cptr2 = (char *)Game_GetPlayerSubmapValue(self,*(int *)(value1 + 8),*(int *)(value1 + 0x2c)),
     cptr2 != (char *)0x0)) {
    switch(*(uint32_t *)((intptr_t)arg1 + 0x30)) {
    case 10:
    case 0x12:
    case 0x18:
      Object_UpdateCompanyBuilding(self,cptr2,arg1);
      return;
    default:
      Object_UpdateFallback(self,cptr2,arg1);
      break;
    case 0xd:
    case 0x17:
    case 0x1d:
    case 0x1e:
      Object_UpdateBranchOps(self,cptr2,arg1);
      return;
    case 0xe:
      Customer_UpdateMovement(self,cptr2,arg1);
      return;
    case 0x11:
      Object_UpdateProductionWorker(self,cptr2,arg1);
      return;
    case 0x13:
      Object_UpdateCustomerQueue(self,cptr2,arg1);
      return;
    case 0x14:
      Object_UpdateConstructionWorker(self,cptr2,arg1);
      return;
    case 0x16:
      Object_UpdateSupplyBuilding(self,(intptr_t)cptr2,arg1);
      return;
    case 0x1a:
    case 0x1b:
      Person_EnterBuildingAndWork((intptr_t)cptr2,arg1);
      return;
    case 0x1c:
      Person_SitAndEatPizza(cptr2,arg1);
      return;
    case 0x1f:
      Object_UpdateBranchOpenClose(self,cptr2,arg1);
      return;
    case 0x20:
      Object_UpdateCitizen(cptr2,arg1);
      return;
    case 0x2b:
    case 0x2c:
    case 0x2d:
    case 0x2f:
      Game_UpdateVisitorObjectState(self,cptr2,arg1);
      return;
    }
  }
  return;
}
