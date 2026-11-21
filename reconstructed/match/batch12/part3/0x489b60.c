/* Game_AdvanceAnimFrame (0x489b60). */

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Anim {
    void AdvanceAnimFrame();
};

void Anim::AdvanceAnimFrame()
{
    short *frames;

    frames = (short *)((struct IDMap *)((char *)this + 0x74))->Lookup(
        *(int *)((char *)this + 0x344), 0);
    if (frames != 0) {
        *(int *)((char *)this + 0x350) = *(int *)((char *)this + 0x350) + 1;
        if (3 < *(int *)((char *)this + 0x350)) {
            *(int *)((char *)this + 0x350) = 0;
        }
        if (frames[*(int *)((char *)this + 0x350)
                   + (*(int *)((char *)this + 0x354) + 10) * 6] == -1) {
            *(int *)((char *)this + 0x350) = 0;
        }
    }
}
