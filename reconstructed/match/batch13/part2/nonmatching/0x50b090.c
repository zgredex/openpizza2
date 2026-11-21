/* UI_HitTestChildPoint (0x50b090). */
struct HitObject {
    void GetTwoFloats48(int type, int *position, void **value);
};
struct UI {
    char pad0[0xc4];
    int *transform;         /* 0xc4 */

    unsigned int HitTestChildPoint(int container);
    unsigned int ComputeObjectDirection(int position, int value);
};

unsigned int UI::HitTestChildPoint(int container)
{
    void *value = this;
    int *child = *(int **)(container + 0xc8);

    if (child == 0 || (void *)child[0x16] == 0)
        return 0;
    ((HitObject *)child[0x16])->GetTwoFloats48(*child, &container, &value);
    container += *(int *)((char *)transform + 0xf8);
    value = (void *)((int)value + *(int *)((char *)transform + 0xfc));
    return ComputeObjectDirection(container, (int)value);
}
