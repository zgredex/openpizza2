/* Person_CanContinuePath (0x50e7a0, 46 bytes).  Build: /O2 /TP.
   Tests whether a person's current path step is walkable. */
struct Object {
    int IsVisibleThisFrame(void);
};

struct Person {
    int CanContinuePath(void);
};

int Person::CanContinuePath(void)
{
    if (*(int *)((char *)this + 0xc8) != 0) {
        if (((Object *)this)->IsVisibleThisFrame()) {
            if (*(short *)(*(int *)((char *)this + 0xc8) + 0x28) != -1)
                return 1;
        }
    }
    return 0;
}
