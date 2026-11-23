// Window_ExportDialog: ported from Pizza Connection 2 at 0x524e80.
// Readable source-port phase; this is not a byte-verified match.
// original: 0x524e80
#include "pc2_port.h"

void __thiscall Window_ExportDialog(char *self,char *arg1,void **arg2,int *arg3)

{
  HWND hWnd;
  int value1;
  BOOL BVar2;
  uint32_t *uptr3;
  int value4;
  uint8_t uStack00000000;
  tagOFNA local_150 [3];
  
  if ((arg1 == (void *)0x0) && (arg1 = *(void **)((intptr_t)self + 0x228), arg1 == (void *)0x0))
  {
    value4 = *(int *)((intptr_t)self + 0x23c) + -1;
    if (value4 < 0) {
      return;
    }
    uptr3 = (uint32_t *)((intptr_t)self + value4 * 4 + 0x14);
    while (((arg1 = (void *)*uptr3, arg1 == (void *)0x0 ||
            (*(int *)((intptr_t)arg1 + 0x4c) == 0)) ||
           (value1 = Rect_ContainsPoint(arg1,arg3), value1 == 0))) {
      value4 = value4 + -1;
      uptr3 = uptr3 + -1;
      if (value4 < 0) {
        return;
      }
    }
    if (value4 < 0) {
      return;
    }
    if (arg1 == (void *)0x0) {
      return;
    }
  }
  if (arg2 == (void **)0x0) {
    hWnd = *(HWND *)((intptr_t)self + 0x8320);
    local_150[0].pvReserved = ((intptr_t)(local_150[0].pvReserved) & ~(0x0u << 8)) | ((((intptr_t)(0)) & 0x0u) << 8);
    local_150[0].hInstance = (HINSTANCE)GetWindowLongA(hWnd,-6);
    local_150[0].lpstrFile = (LPSTR)&local_150[0].pvReserved;
    local_150[0].lStructSize = 0x4c;
    local_150[0].lpstrFilter = s_subedit_dialog_file____dlg__00574258;
    local_150[0].lpstrCustomFilter = (LPSTR)0x0;
    local_150[0].nMaxCustFilter = 0;
    local_150[0].nFilterIndex = 1;
    local_150[0].nMaxFile = 0x104;
    local_150[0].lpstrFileTitle = (LPSTR)0x0;
    local_150[0].nMaxFileTitle = 0;
    local_150[0].lpstrInitialDir = (LPCSTR)0x0;
    local_150[0].lpstrTitle = s_Specify_file_to_export_window_di_00574230;
    local_150[0].Flags = 0xc;
    local_150[0].nFileOffset = 0;
    local_150[0].nFileExtension = 0;
    local_150[0].lpstrDefExt = &DAT_0057422c;
    local_150[0].lCustData = 0;
    local_150[0].lpfnHook = (LPOFNHOOKPROC)0x0;
    local_150[0].lpTemplateName = (LPCSTR)0x0;
    local_150[0].hwndOwner = hWnd;
    BVar2 = GetSaveFileNameA_Thunk(local_150);
    if (BVar2 == 0) {
      return;
    }
    arg2 = &local_150[0].pvReserved;
    if (&uStack00000000 == (uint8_t *)0x104) {
      return;
    }
  }
  Dialog_SaveToFile(arg1,(LPCSTR)arg2);
  return;
}
