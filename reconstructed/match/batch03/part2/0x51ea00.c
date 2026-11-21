/* RefPtr_Release - 0x51ea00, 21 bytes */
struct RefTarget
{
    virtual void Release(int flag);
};

void __fastcall RefPtr_Release(void *this_)
{
    RefTarget *target;

    *(int *)((char *)this_ + 0x14) = 0;
    target = *(RefTarget **)((char *)this_ + 4);
    if (target != 0)
        target->Release(1);
}
