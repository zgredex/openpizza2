struct Window {
    void GadgetNotify(int a1, int a2, int a3, int a4, int a5);
};

struct Gadget {
    void GetSpriteFrames(int param_1);
};

void Gadget::GetSpriteFrames(int param_1)
{
    ((Window *)this)->GadgetNotify(param_1, 0, 0x42, 0, 0);
}
