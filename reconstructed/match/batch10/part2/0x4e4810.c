/* Map_PickRandomExitDirection: choose one of the available exit
   directions at random (0x4e4810). */
extern "C" int Random_RangeFast(int low, int high);

extern "C" unsigned char __fastcall Map_PickRandomExitDirection(int map)
{
    unsigned int options[4];
    unsigned int value = 1;
    int count = 0;
    unsigned int *option = options;

    do {
        if (*(char *)((value & 0xff) + 200 + map) >= 0) {
            *option = value;
            count++;
            option++;
        }
        value++;
    } while ((int)value <= 3);
    value = Random_RangeFast(0, count - 1);
    return (char)options[value];
}
