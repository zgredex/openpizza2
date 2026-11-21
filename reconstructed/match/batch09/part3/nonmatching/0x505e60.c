/* UI_SetChildTracking: points a UI child at its tracked record and updates the
   record's screen offsets (0x505e60). */
struct Record {
    void SetDoubles48(int a, int b, int c);
};

struct UIChild {
    void SetChildTracking(int mode, int *child);
};

void UIChild::SetChildTracking(int mode, int *child)
{
    char *self = (char *)this;
    int *tracking = *(int **)(self + 0xc8);

    if (tracking != 0) {
        int x = *(int *)((char *)child + 0xc);
        int y = *(int *)((char *)child + 0x10);

        tracking[8] = (int)child;
        ((Record *)tracking[0x16])
            ->SetDoubles48(tracking[0], x - 0xa0, y - 0xd0);
    }
}
