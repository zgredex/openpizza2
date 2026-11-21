/* UI_SetActiveChild: switches the active child, deactivating the previous one
   (0x528200).  Build: /O2 /TP. */
struct Child {
    virtual void Field0();
    virtual void Field4();
    virtual void Field8();
    virtual void SetState(int state, int a, int b);
};

struct UI {
    char pad[0x230];
    Child *activeChild;
    void SetActiveChild(Child *child);
};

void UI::SetActiveChild(Child *child)
{
    Child *old = activeChild;

    if (child != old) {
        if (old != 0)
            old->SetState(10, 0, 0);
        activeChild = child;
    }
}
