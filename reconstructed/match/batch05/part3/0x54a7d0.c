/* Dialog_SetItemText: writes the standard dialog text into item 0x3ef (0x54a7d0). */
typedef void *HWND;

__declspec(dllimport) HWND __stdcall GetDlgItem(HWND hwnd, int id);
__declspec(dllimport) int __stdcall SetWindowTextA(HWND hwnd, const char *text);

extern char DAT_00579aec;

void __fastcall Dialog_SetItemText(int dialog)
{
    HWND hwnd = *(HWND *)(dialog + 4);

    if (hwnd != 0)
        SetWindowTextA(GetDlgItem(hwnd, 0x3ef), &DAT_00579aec);
}
