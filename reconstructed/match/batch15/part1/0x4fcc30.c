/* Object_AdjustShortPercent: adds a signed percentage to one of an object's
   short percentage fields and clamps it to 0..100 (0x4fcc30). */
extern int *DAT_0057c670;
extern char DAT_0057bb20;

struct IDMap {
    void *Lookup(int index, int *out);
};

struct Object {
    void AdjustShortPercent(int index, short amount);
};

void Object::AdjustShortPercent(int index, short amount)
{
    short *value;
    int record;
    int type;

    record = (int)((struct IDMap *)((char *)DAT_0057c670 + 4))
                 ->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
    if (record != 0) {
        record = record + 4;
    } else {
        record = 0;
    }
    type = *(int *)(record + 0x33c);
    if (DAT_0057bb20 != 0 ||
        (type != 4 && type != 6 && type != 9)) {
        value = (short *)((char *)this + index * 0x168 + 0x130);
        *value = *value + amount;
        value = (short *)((char *)this + index * 0x168 + 0x130);
        if (*(short *)((char *)this + index * 0x168 + 0x130) < 0) {
            *value = 0;
        }
        if (100 < *value) {
            *value = 100;
        }
    }
}
