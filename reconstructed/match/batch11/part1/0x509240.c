/* UI_SetChildHeightFromValue: derives the child height from the game value
   and clamps it (0x509240). */
struct UIHelper {
    int State_Is2DOr2E();
};

struct UI {
    char pad[0xa8];
    int value;
    char pad2[0x1c];
    int child;

    void SetChildHeightFromValue();
};

void UI::SetChildHeightFromValue()
{
    if (child != 0) {
        if (((UIHelper *)this)->State_Is2DOr2E() == 0) {
            int height =
                (int)(value * *(float *)0x55c680);

            *(short *)(*(int *)((char *)this + 0xc8) + 8) =
                (short)(0x99 - height);
            if (*(short *)(*(int *)((char *)this + 0xc8) + 8) < 0x88)
                *(short *)(*(int *)((char *)this + 0xc8) + 8) = 0x88;
        }
    }
}
