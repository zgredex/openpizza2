extern void *DAT_0057d270;

struct Window {
    void ShowChildByID(int id);
};

extern "C" void TradeOffer_UpdatePanel(void *page, void *data);

extern "C" void TradeOffer_Page_Init(void *page)
{
    Window *window = (Window *)page;
    window->ShowChildByID(0x1f67);
    window->ShowChildByID(0x1f66);
    window->ShowChildByID(0x433);
    window->ShowChildByID(0x43a);
    window->ShowChildByID(0x1f61);
    window->ShowChildByID(0x1f63);
    window->ShowChildByID(0x1f62);
    window->ShowChildByID(0x1f65);
    window->ShowChildByID(0x1f64);
    window->ShowChildByID(0x439);
    TradeOffer_UpdatePanel(page, DAT_0057d270);
}
