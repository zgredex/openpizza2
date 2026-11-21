/* UI_ComposeOverlayWindowFromRecord (0x54bb00, 48 bytes).  Build: /O2 /TP.
   Unpacks the overlay rectangle fields from a record and composes the window.
   The field values are staged in an array so they stay in registers until the
   whole argument list is ready, as in the original. */
struct UI {
    void ComposeOverlayWindow(void *owner, int x, int y, void *surface,
                              int width, int height, int flags);
    void ComposeOverlayWindowFromRecord(void *owner, int x, int record);
};

void UI::ComposeOverlayWindowFromRecord(void *owner, int x, int record)
{
    int field[5];

    field[0] = *(int *)(record + 0x30);
    field[1] = *(int *)(record + 0x28);
    field[2] = *(int *)(record + 0x2c);
    field[3] = *(int *)(record + 0x34);
    field[4] = *(int *)(record + 0x24);
    ComposeOverlayWindow(owner, x, field[4], (void *)field[3], field[2],
                         field[1], field[0]);
}
