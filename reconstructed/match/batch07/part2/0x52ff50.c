/* Window_GadgetNotify_Button_SetState (0x52ff50, 48 bytes).  Build: /O2 /TP.
   Sends the button-state notification with notification type 1. */
struct Window {
    void GadgetNotify(int gadget, int type, int a, int state, int b);
};

struct Window_GadgetNotify {
    void Button_SetState(int gadget, int state);
};

void Window_GadgetNotify::Button_SetState(int gadget, int state)
{
    if (state != 0)
        ((Window *)this)->GadgetNotify(gadget, 1, 0, 1, 0);
    else
        ((Window *)this)->GadgetNotify(gadget, 1, 0, 0, 0);
}
