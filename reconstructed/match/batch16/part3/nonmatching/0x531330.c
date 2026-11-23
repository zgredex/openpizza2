/* BinarySearch8: binary-searches the eight-byte records of the object table
   (0x531330). */
class Object {
public:
    int BinarySearch8(int key, char nearest);
};

int Object::BinarySearch8(int param_1, char param_2)
{
    int iVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    int iVar5;

    iVar1 = *(int *)((char *)this + 0xf0);
    if (iVar1 < 1) {
        return (param_2 != '\0') - 1;
    }
    iVar5 = 0;
    iVar3 = iVar1;
    if (0 < iVar1 + -1) {
        do {
            iVar4 = iVar3 + iVar5 >> 1;
            iVar2 = *(int *)(*(int *)((char *)this + 0xe8) + 4 + iVar4 * 8);
            if (iVar2 == param_1) {
                return iVar4;
            }
            if (iVar2 < param_1) {
                iVar5 = iVar4;
            } else {
                iVar3 = iVar4;
            }
        } while (iVar5 < iVar3 + -1);
    }
    iVar2 = *(int *)(*(int *)((char *)this + 0xe8) + 4 + iVar5 * 8);
    if (iVar2 != param_1) {
        if ((iVar3 < iVar1) &&
            (*(int *)(*(int *)((char *)this + 0xe8) + 4 + iVar3 * 8) == param_1)) {
            return iVar3;
        }
        if (param_2 == '\0') {
            return -1;
        }
        if (iVar2 < param_1) {
            return iVar3;
        }
    }
    return iVar5;
}
