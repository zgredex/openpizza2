/* BuildingValue_StreamConstruct: installs the vtable and loads the value (0x4e4370). */
extern void *DAT_0055c5a4[];

struct BuildingValue {
    void *vtable;
    void Load(void *stream);
    BuildingValue *ConstructFromStream(void *stream);
};

BuildingValue *BuildingValue::ConstructFromStream(void *stream)
{
    vtable = (void *)DAT_0055c5a4;
    Load(stream);
    return this;
}
