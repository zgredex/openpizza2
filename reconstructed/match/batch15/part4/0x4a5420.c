struct Window {
    void SetField14ByKey(int id, int value);
    void SetChildLabelText(int id, int flag, char *text);
};

extern "C" void UI_RemoveProfileStatElements(void *page);
extern "C" void UI_DrawNeighborhoodCustomerIcons(void *page, int id);

extern "C" void BauenPage_ResetBuildingSlots(void *page)
{
    Window *window = (Window *)page;
    window->SetField14ByKey(0x1f79, 0);
    window->SetField14ByKey(0x1f7a, 0);
    window->SetField14ByKey(0x1f7b, 0);
    window->SetField14ByKey(0x1f7c, 0);
    window->SetChildLabelText(0x1f68, 1, 0);
    window->SetChildLabelText(0x1f69, 1, 0);
    window->SetChildLabelText(0x1f6a, 1, 0);
    window->SetChildLabelText(0x1f6b, 1, 0);
    UI_RemoveProfileStatElements(page);
    UI_DrawNeighborhoodCustomerIcons(page, 0x43f);
}
