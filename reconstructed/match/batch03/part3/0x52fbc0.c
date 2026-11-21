struct Window {
    void GadgetNotify(int a1, int a2, int a3, int a4, int a5);
};

struct Input {
    void SetText(int param_1, int param_2);
};

void Input::SetText(int param_1, int param_2)
{
    ((Window *)this)->GadgetNotify(param_1, 4, 0xe, 0, param_2);
}
