/* Tooltip_Construct: initialises a tooltip window (0x52e4b0). */
extern char DAT_0055c804;

struct Renderer {
    void *CreateChild();
};

struct Tooltip {
    void *vtable;
    int field4;
    int field8;
    int fieldC;
    int field10;
    int field14;
    int field18;
    void *child1C;
    int field20;
    int field24;
    int field28;
    int field2C;
    int field30;
    int field34;
    int field38;
    int field3C;

    Tooltip *Construct(void *parent, int value);
};

Tooltip *Tooltip::Construct(void *parent, int value)
{
    fieldC = 10;
    field10 = 10;
    *(void **)this = &DAT_0055c804;
    field38 = value;
    field18 = 0;
    field4 = 0x50;
    field8 = 200;
    field14 = 0;
    field20 = 0;
    field24 = 0;
    field28 = 0xe0ffff;
    field2C = 0;
    field30 = 0;
    field3C = 0;
    child1C = ((Renderer *)parent)->CreateChild();
    return this;
}
