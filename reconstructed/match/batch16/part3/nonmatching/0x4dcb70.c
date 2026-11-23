/* Random_SwapOneOfFour: replaces one randomly chosen slot of four with the
   supplied value and returns the previous value (0x4dcb70). */
extern "C" int Random_RangeFast(int minimum, int maximum);

class Object {
public:
    int SwapOneOfFour(int index, unsigned avoid, int value);
};

int Object::SwapOneOfFour(int param_1, unsigned param_2, int param_3)
{
    unsigned uVar1;
    int uVar2;

    uVar2 = 0;
    do {
        uVar1 = Random_RangeFast(0, 3);
    } while (uVar1 == param_2);
    switch (uVar1) {
    case 0:
        uVar2 = *(int *)((char *)this + param_1 * 4 + 0x200);
        *(int *)((char *)this + param_1 * 4 + 0x200) = param_3;
        return uVar2;
    case 1:
        uVar2 = *(int *)((char *)this + param_1 * 4 + 0x240);
        *(int *)((char *)this + param_1 * 4 + 0x240) = param_3;
        return uVar2;
    case 2:
        uVar2 = *(int *)((char *)this + param_1 * 4 + 0x220);
        *(int *)((char *)this + param_1 * 4 + 0x220) = param_3;
        return uVar2;
    case 3:
        uVar2 = *(int *)((char *)this + param_1 * 4 + 0x260);
        *(int *)((char *)this + param_1 * 4 + 0x260) = param_3;
    }
    return uVar2;
}
