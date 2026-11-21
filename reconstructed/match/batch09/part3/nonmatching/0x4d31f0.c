/* Car_Construct: initialises a car record from the game's car table
   (0x4d31f0). */
extern "C" {
extern int DAT_0057c670;
extern int DAT_0055c4f8;
}

struct IDMap {
    int *Lookup(int key, int *unused);
};

struct MapSprite {
    void InitializeRecord();
};

struct Car {
    void *vtable;
    int carId;
    int field8;
    int variant;

    Car *Construct(int index);
};

extern int Random_RangeFast(int minimum, int maximum);

Car *Car::Construct(int index)
{
    int *record;

    vtable = &DAT_0055c4f8;
    record = ((IDMap *)((char *)DAT_0057c670 + 4))->Lookup(index, 0);
    carId = *(int *)((char *)record + 0xfa8);
    variant = Random_RangeFast(0, 0x2c);
    ((MapSprite *)this)->InitializeRecord();
    return this;
}
