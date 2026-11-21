/* Gfx_RectList_Construct: builds a rectangle list and allocates its vertex
   buffer (0x534d60). */
extern "C" {
extern int DAT_0055c810;
extern void *operator_new(unsigned int size);
}

extern "C" void __fastcall Surface_FillFF(void *surface);

struct RectList {
    void *vtable;
    int field4;
    int field8;
    int fieldC;
    int field10;
    void *buffer;

    RectList *Construct(void *param_1, int param_2, int param_3);
};

RectList *RectList::Construct(void *param_1, int param_2, int param_3)
{
    int stride;

    field4 = (int)param_1;
    fieldC = param_3;
    vtable = &DAT_0055c810;
    stride = param_3 * 2 + 2;
    field8 = param_2;
    field10 = stride;
    buffer = operator_new(stride * param_2 * 2);
    Surface_FillFF(this);
    return this;
}
