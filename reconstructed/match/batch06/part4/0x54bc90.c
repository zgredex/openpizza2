/* UI_RemoveAllBriefings: detaches the active briefing object and clears the
   six briefing rows (0x54bc90).  Build: /O2 /TP. */
struct UI {
    void *field0;
    UI *field4;
    char rows[6 * 0x44];
    void DetachObject();
    void DecrementRowCounter(void *row);
    void RemoveAllBriefings();
};

void UI::RemoveAllBriefings()
{
    char *row;
    int count;

    if (field4 != 0)
        field4->DetachObject();
    row = (char *)this + 8;
    for (count = 6; count != 0; count--) {
        ((UI *)field0)->DecrementRowCounter(row);
        row += 0x44;
    }
}
