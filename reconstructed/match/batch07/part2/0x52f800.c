/* Gadget_SetButtonState (0x52f800, 48 bytes).  Build: /O2 /TP.
   Sends the button-state notification for the gadget. */
struct Window {
    void GadgetNotify(int gadget, int type, int a, int state, int b);
};

struct Gadget {
    void SetButtonState(int gadget, int state);
};

void Gadget::SetButtonState(int gadget, int state)
{
    if (state != 0)
        ((Window *)this)->GadgetNotify(gadget, 2, 0, 1, 0);
    else
        ((Window *)this)->GadgetNotify(gadget, 2, 0, 0, 0);
}
