/* UI_WarpCursorToControl (0x4c6780). */
struct Window {
    void SetCursorPosition(int x, int y, int a, int b);
};
struct UI {
    void *GetRecordByKeyPtr(int key);
    void OffsetPoint(int *x, int *y);
    void WarpCursorToControl(int key);
};
extern Window *DAT_0057c5e0;

void __cdecl UI_WarpCursorToControl(UI *ui, int key)
{
    void *record = ui->GetRecordByKeyPtr(key);

    if (record != 0) {
        int x = ((*(int *)((char *)record + 0x30) -
                  *(int *)((char *)record + 0x28)) >> 1) +
                 *(int *)((char *)record + 0x38);
        int y = ((*(int *)((char *)record + 0x34) -
                  *(int *)((char *)record + 0x2c)) >> 1) +
                 *(int *)((char *)record + 0x3c);

        ui->OffsetPoint(&x, &y);
        DAT_0057c5e0->SetCursorPosition(x, y, 1, 1);
    }
}
