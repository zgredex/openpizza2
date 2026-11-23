// EmployeeAvatar_Destroy: ported from Pizza Connection 2 at 0x54b640.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x54b640
#include "pc2_port.h"

void __fastcall EmployeeAvatar_Destroy(uint32_t *arg1)

{
  void *local_c;
  uint8_t *puStack_8;
  int local_4;
  
  puStack_8 = &LAB_0055b9a1;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  *arg1 = &PTR_EmployeeAvatar_Delete_0055cb44;
  local_4 = 7;
  IDMap_DeleteContents(arg1 + 8);
  IDMap_DeleteContents(arg1 + 1);
  IDMap_DeleteContents(arg1 + 0x16);
  IDMap_DeleteContents(arg1 + 0xf);
  IDMap_DeleteContents(arg1 + 0x24);
  IDMap_DeleteContents(arg1 + 0x1d);
  IDMap_DeleteContents(arg1 + 0x32);
  IDMap_DeleteContents(arg1 + 0x2b);
  local_4 = (local_4 & ~(0x0u << 8)) | (((6) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x32);
  local_4 = (local_4 & ~(0x0u << 8)) | (((5) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x2b);
  local_4 = (local_4 & ~(0x0u << 8)) | (((4) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x24);
  local_4 = (local_4 & ~(0x0u << 8)) | (((3) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x1d);
  local_4 = (local_4 & ~(0x0u << 8)) | (((2) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0x16);
  local_4 = (local_4 & ~(0x0u << 8)) | (((1) & 0x0u) << 8);
  List_Node_Destroy(arg1 + 0xf);
  local_4 = (uint32_t)((uint8_t)((local_4) >> 24)) << 8;
  List_Node_Destroy(arg1 + 8);
  local_4 = 0xffffffff;
  List_Node_Destroy(arg1 + 1);
  ExceptionList = local_c;
  return;
}
