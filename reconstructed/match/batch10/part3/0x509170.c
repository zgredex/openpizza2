extern double DAT_0055c310;
struct UIList { void SetEntryPosition(int index, double value); };
void __fastcall Record_DoublePositionValue(int param_1)
{
    int *owner = *(int **)(param_1 + 0xc8);
    int list;
    int index;
    double value;
    if (owner == 0 || owner[0x16] == 0) return;
    list = owner[0x16];
    index = *owner;
    if (index >= 0 && index < *(int *)(list + 0x48))
        value = *(double *)(*(int *)(list + 0x4c) + index * 0x48 + 0x28);
    else
        value = DAT_0055c310;
    ((UIList *)list)->SetEntryPosition(index, value + value);
}
