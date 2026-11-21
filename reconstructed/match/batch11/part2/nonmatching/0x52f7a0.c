/* Gadget_SetButtonTextLayout: forwards a button text layout to the window
   gadget notifier (0x52f7a0). */
struct Layout {
    short x;
    short y;
    short width;
    short height;
    int value;
    char pad[4];
};

struct GadgetHelper {
    void GadgetNotify(int id, int command, int size, int extra, Layout *layout);
};

struct Gadget {
    void SetButtonTextLayout(int id, int value, short x, short y, short width,
                             short height);
};

void Gadget::SetButtonTextLayout(int id, int value, short x, short y,
                                 short width, short height)
{
    Layout layout;

    layout.y = y;
    layout.x = x;
    layout.height = height;
    layout.width = width;
    layout.value = value;
    ((GadgetHelper *)this)->GadgetNotify(id, 2, 0xd8, 0, &layout);
}
