/* Employee_NextSpriteVariant: advances a sprite variant index and returns the
   selected variant table (0x549930). */
struct Employee {
    void *NextSpriteVariant(int slot, int current, int limit);
};

void *Employee::NextSpriteVariant(int slot, int current, int limit)
{
    int value = *(int *)((char *)this + slot * 4 + 0x1dc);

    if (current < limit) {
        if (value != limit)
            current = value + 1;
        *(int *)((char *)this + slot * 4 + 0x1dc) = current;
    }
    switch (value) {
    case 1:
        return (void *)0x5762b0;
    case 2:
        return (void *)0x5762b4;
    default:
        return (void *)0x5762b0;
    }
}
