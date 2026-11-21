/* Gadget_SetButtonColors: assigns the normal, pressed and disabled colours of
   a gadget button (0x52f750). */
struct Window {
    void GadgetNotify(int id, int group, int message, int value, int flags);
};

struct Gadget {
    void SetButtonColors(int id, int normal, int pressed, int disabled);
};

void Gadget::SetButtonColors(int id, int normal, int pressed, int disabled)
{
    ((Window *)this)->GadgetNotify(id, 2, 0xd, normal, 0);
    ((Window *)this)->GadgetNotify(id, 2, 0x17, pressed, 0);
    ((Window *)this)->GadgetNotify(id, 2, 0x15, disabled, 0);
}
