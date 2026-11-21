/* UI_SetChildLabelText (0x531fb0, 48 bytes).  Build: /O2 /TP.
   Finds the child by id and forwards the label text to it. */
struct UI {
    int BinarySearch8(int key, char mode);
    void SetLabelIdText(int textId, char *text);
    void SetChildLabelText(int id, int textId, char *text);
};

void UI::SetChildLabelText(int id, int textId, char *text)
{
    int index = BinarySearch8(id, 0);

    if (index != -1)
        ((UI *)*(void **)(*(int *)((char *)this + 0xe8) + index * 8))
            ->SetLabelIdText(textId, text);
}
