struct Window {
    void GadgetNotify(int a1, int a2, int a3, int a4, int a5);
};

struct Text {
    void SetMode(int param_1, int param_2);
};

void Text::SetMode(int param_1, int param_2)
{
    ((Window *)this)->GadgetNotify(param_1, 3, 0x1f, param_2, 0);
}
