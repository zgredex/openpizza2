struct Window {
    void GadgetNotify(int a1, int a2, int a3, int a4, int a5);
};

struct Text {
    void GetFont(int param_1);
};

void Text::GetFont(int param_1)
{
    ((Window *)this)->GadgetNotify(param_1, 3, 0x33, 0, 0);
}
