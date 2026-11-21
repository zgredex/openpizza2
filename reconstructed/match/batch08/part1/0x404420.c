/* SetScreenRects: initializes the two global screen rectangles
   (0x404420). */
__declspec(dllimport) int __stdcall SetRect(int *rect, int left, int top,
                                            int right, int bottom);

extern int DAT_00573d38[4];
extern int DAT_0057c1e8[4];

void __cdecl SetScreenRects(void)
{
    SetRect(DAT_00573d38, 0, 0, 800, 600);
    SetRect(DAT_0057c1e8, 800, 0, 0x35c, 600);
}
