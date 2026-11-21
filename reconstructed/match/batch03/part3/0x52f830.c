struct Window {
    void GadgetNotify(int a1, int a2, int a3, int a4, int a5);
};

struct Gadget {
    void SetText(int param_1, int param_2);
};

void Gadget::SetText(int param_1, int param_2)
{
    ((Window *)this)->GadgetNotify(param_1, 2, 0xe, 0, param_2);
}
