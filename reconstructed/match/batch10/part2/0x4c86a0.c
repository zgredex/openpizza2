/* EndResultGraph_SelectCategory: highlight the selected result category
   and redraw the chart (0x4c86a0). */
extern "C" int DAT_0056b270;
extern "C" int DAT_0056b230[];

extern "C" void EndResultGraph_DrawChart(void *menu);

struct Gadget {
    void SetButtonState(int id, int state);
};

struct Window_GadgetNotify_Button {
    void SetState(int id, int state);
};

extern "C" void EndResultGraph_SelectCategory(void *menu)
{
    if (DAT_0056b270 == -1) {
        ((struct Gadget *)menu)->SetButtonState(0x4d0, 1);
        EndResultGraph_DrawChart(menu);
        return;
    }
    ((struct Window_GadgetNotify_Button *)menu)->SetState(
        DAT_0056b230[DAT_0056b270], 1);
    EndResultGraph_DrawChart(menu);
}
