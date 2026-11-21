/* UI_SetMultipleLabels: applies a NULL-terminated (-1 sentinel) table of
   label id/text pairs to a UI object (0x4c70b0). */
struct UI {
    void SetChildLabelText(int id, int flag, char *text);
};

void UI_SetMultipleLabels(UI *ui, int *labels)
{
    char done = 0;

    do {
        if (*labels == -1) {
            done = 1;
        } else {
            ui->SetChildLabelText(*labels, 1, (char *)labels[1]);
        }
        labels += 2;
    } while (!done);
}
