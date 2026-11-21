/* Car_ConstructFromSave: installs the vtable and loads the car (0x4d3260). */
extern void *DAT_0055c4f8[];

struct Car {
    void *vtable;
    void LoadFromStream(void *stream);
    Car *InitFromSave(void *stream);
};

Car *Car::InitFromSave(void *stream)
{
    vtable = (void *)DAT_0055c4f8;
    LoadFromStream(stream);
    return this;
}
