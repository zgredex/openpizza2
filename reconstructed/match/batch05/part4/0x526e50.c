/* UI_MarkFullRectDirty: unions the full UI rectangle into the dirty area (0x526e50). */
struct Rect {
    void Union(int left, int top, int width, int height);
};

extern int DAT_00584508;

void __fastcall UI_MarkFullRectDirty(int ui)
{
    DAT_00584508 = 1;
    ((Rect *)ui)->Union(0, 0, *(int *)(ui + 0x270), *(int *)(ui + 0x274));
}
