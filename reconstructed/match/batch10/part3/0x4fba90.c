/* Map_GridToScreenOffset: convert a grid position to a screen offset. */
struct Object {
    void GetRect100(int *x, int *right, int *top, int *bottom);
};

extern "C" void __stdcall Map_GridToScreenOffset(int param_1, int param_2,
                                                 int param_3, int *param_4,
                                                 int *param_5)
{
    int local_4;
    int local_c;
    int local_8;

    ((Object *)param_1)->GetRect100(&param_1, &local_4, &local_c, &local_8);
    *param_4 = param_1 + param_2;
    *param_5 = local_c + param_3;
}
