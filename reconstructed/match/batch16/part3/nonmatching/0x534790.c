/* Record_GetScreenOffset: computes the screen coordinates of a record from
   its map field and screen origin (0x534790). */
class Record {
public:
    void GetScreenOffset(int index, int *x, int *y);
};

void Record::GetScreenOffset(int param_1, int *param_2, int *param_3)
{
    unsigned short uVar1;
    int iVar2;
    int iVar3;
    int iVar4;

    if ((0 <= param_1) && (param_1 < *(int *)((char *)this + 0x48))) {
        iVar2 = param_1 * 0x48;
        if (*(int *)(*(int *)((char *)this + 0x4c) + iVar2) != -1) {
            iVar4 = *(int *)(*(int *)((char *)this + 0x4c) + iVar2);
            iVar3 = *(short *)(*(int *)((char *)this + 0x4c) + iVar2 + 0x32) * 2;
            *param_2 = (int)(*param_2 +
                             *(double *)(*(int *)((char *)this + 0x50) +
                                         iVar4 * 0x98 + 0x70)) +
                       ((int)*(short *)(*(int *)((char *)this + 0x20) + iVar3) >> 2) +
                       *(unsigned short *)(*(int *)((char *)this + 0x28) + iVar3);
            uVar1 = *(unsigned short *)(*(int *)((char *)this + 0x2c) + iVar3);
            *param_3 = uVar1 + (int)(*param_3 +
                                     *(double *)(*(int *)((char *)this + 0x50) +
                                                 iVar4 * 0x98 + 0x78));
        }
    }
}
