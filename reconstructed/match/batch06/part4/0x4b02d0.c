/* StatisticsBackdrop_RestoreCategorySelection: restores the statistics
   category button selection from the saved index (0x4b02d0).
   Build: /O2 /TP. */
struct Gadget {
    void SetButtonState(int id, int state);
};

struct Window {
    void GadgetNotify_Button_SetState(int id, int state);
};

void StatisticsBackdrop_RestoreCategorySelection(Gadget *gadget)
{
    int index = *(int *)0x56a68c;

    if (index == -1)
        gadget->SetButtonState(0x1f41, 1);
    else
        ((Window *)gadget)->GadgetNotify_Button_SetState(
            ((int *)0x56a66c)[index], 1);
}
