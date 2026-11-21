/* UI_GetRecordCenteredRect: centers a record within the UI (0x4f34f0). */
struct UI {
    char pad[0x4c];
    int *records;
    void ComputeCenteredRect(int *record, int *left, int *top);
    void GetRecordCenteredRect(int index, int *left, int *top);
};

void UI::GetRecordCenteredRect(int index, int *left, int *top)
{
    ComputeCenteredRect(records + index * 3, left, top);
}
