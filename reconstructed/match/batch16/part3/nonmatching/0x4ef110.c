/* Object_InsertSortedByScreenY: inserts an object into the screen-y sorted
   object chain (0x4ef110). */
class Object {
public:
    int GetScreenSortY(void *record);
    void InsertSortedByScreenY(int list, int *record);
};

void Object::InsertSortedByScreenY(int param_1, int *param_2)
{
    int *piVar1;
    int *piVar2;
    int *piVar3;
    int *local_4;

    piVar3 = *(int **)(*(int *)(param_1 + 8) + 0x20);
    if (piVar3 == 0) {
        *(int **)(*(int *)(param_1 + 8) + 0x20) = param_2;
        param_2[0x1b] = 0;
        return;
    }
    local_4 = 0;
    piVar1 = (int *)GetScreenSortY(piVar3);
    piVar2 = (int *)GetScreenSortY(param_2);
    if ((int)piVar1 <= (int)piVar2) {
        do {
            local_4 = piVar3;
            piVar3 = (int *)local_4[0x1b];
            if (piVar3 == 0) {
                local_4[0x1b] = (int)param_2;
                param_2[0x1b] = 0;
                return;
            }
            piVar1 = (int *)GetScreenSortY(piVar3);
            piVar2 = (int *)GetScreenSortY(param_2);
        } while ((int)piVar1 <= (int)piVar2);
    }
    param_2[0x1b] = (int)piVar3;
    if (local_4 == 0) {
        *(int **)(*(int *)(param_1 + 8) + 0x20) = param_2;
        return;
    }
    local_4[0x1b] = (int)param_2;
}
