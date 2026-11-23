/* Object_UpdateState: releases the two occupied map cells of an object
   (0x4f1f70). */
class MapObject {
public:
    void UpdateState(int *record);
};

void MapObject::UpdateState(int *param_1)
{
    int iVar2;
    int *piVar1;

    if (param_1[1] == -1) {
        iVar2 = param_1[0xc];
        if (iVar2 != -1) {
            iVar2 = *(int *)((char *)this + 0x4c) + iVar2 * 0xc;
            if (iVar2 != 0) {
                iVar2 = *(int *)(iVar2 + 8);
                if (iVar2 != 0 && 0 < *(int *)(iVar2 + 0x30)) {
                    *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) - 1;
                }
            }
        }
        if (param_1[0xd] != -1) {
            iVar2 = *(int *)((char *)this + 0x4c) + param_1[0xd] * 0xc;
            if (iVar2 != 0) {
                iVar2 = *(int *)(iVar2 + 8);
                if (iVar2 != 0 && 0 < *(int *)(iVar2 + 0x30)) {
                    *(int *)(iVar2 + 0x30) = *(int *)(iVar2 + 0x30) - 1;
                    param_1[0xc] = -1;
                    param_1[0xd] = -1;
                    return;
                }
            }
        }
    } else {
        iVar2 = param_1[0xc];
        if (iVar2 != -1) {
            piVar1 = (int *)(*(int *)(*(int *)((char *)this + 0x4c) + 8 +
                                      iVar2 * 0xc) +
                            0x34);
            *piVar1 = *piVar1 - 1;
        }
        if (param_1[0xd] != -1) {
            piVar1 = (int *)(*(int *)(*(int *)((char *)this + 0x4c) + 8 +
                                      param_1[0xd] * 0xc) +
                            0x34);
            *piVar1 = *piVar1 - 1;
        }
    }
    param_1[0xc] = -1;
    param_1[0xd] = -1;
}
