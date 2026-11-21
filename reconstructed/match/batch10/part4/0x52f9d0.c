/* Window_GadgetNotify_Text_SetLayout (0x52f9d0): packs a text layout into a
   16-byte stack record and sends it to the text gadget handler. */
struct TextLayout {
    short x;
    short y;
    int unused;
    int text;
    int flags;
};

struct Window {
    void GadgetNotify(int id, int type, int code, int value, void *data);
    void GadgetNotify_Text_SetLayout(int id, int text, short x, short y,
                                     int flags);
};

void Window::GadgetNotify_Text_SetLayout(int id, int text, short x, short y,
                                         int flags)
{
    TextLayout layout;

    layout.x = x;
    layout.y = y;
    layout.text = text;
    layout.flags = flags;
    GadgetNotify(id, 3, 0xd8, 0, &layout);
}
