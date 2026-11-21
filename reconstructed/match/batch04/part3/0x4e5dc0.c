/* ConstructionOrder_StreamConstruct: sets the vtable and loads the record (0x4e5dc0). */
struct ConstructionOrder {
    void **vtable;
    ConstructionOrder *StreamConstruct(void *stream);
    void Load(void *stream);
};

ConstructionOrder *ConstructionOrder::StreamConstruct(void *stream)
{
    vtable = (void **)0x55c5bc;
    Load(stream);
    return this;
}
