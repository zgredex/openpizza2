/* ConstructionOrder_Construct: constructs a furniture construction order
   (0x4e5d60). */
struct ConstructionOrder {
    void **vtable;
    int furniture;
    int quality;
    int fieldC;
    int field10;
    int field14;
    int field18;
    int field1C;
    int field20;
    ConstructionOrder(int furniture, int quality);
};

ConstructionOrder::ConstructionOrder(int furniture, int quality)
{
    this->furniture = furniture;
    this->quality = quality;
    vtable = (void **)0x55c5bc;
    fieldC = 100;
    field10 = 0;
    field14 = -1;
    field18 = -1;
    field1C = -1;
    field20 = 0;
}
