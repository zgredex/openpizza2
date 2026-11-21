struct Window {
    void GadgetNotify(int a1, int a2, int a3, int a4, int a5);
};

struct Input {
    void SetFilter(int param_1, int param_2);
};

void Input::SetFilter(int param_1, int param_2)
{
    ((Window *)this)->GadgetNotify(param_1, 4, 0x1d, param_2, 0);
}
