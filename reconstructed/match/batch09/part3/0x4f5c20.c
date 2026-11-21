/* UI_GetViewRect: returns the viewport rectangle in window coordinates
   (0x4f5c20). */
struct UIView {
    void GetViewRect(int *rect);
};

void UIView::GetViewRect(int *rect)
{
    char *self = (char *)this;

    rect[0] = *(int *)(self + 0x1016c) + *(int *)(self + 0x2c);
    rect[2] = *(int *)(self + 0x10160) - *(int *)(self + 0x10168);
    rect[1] = *(int *)(self + 0x30) - *(int *)(self + 0x10174);
    rect[3] = *(int *)(self + 0x10170) + *(int *)(self + 0x10164);
}
