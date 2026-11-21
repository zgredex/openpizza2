/* Branch_ApplyBuildingStyleVariant: reloads the branch's iso map with a
   building style variant (0x47e6a0). */
struct IsoMap {
    char pad[0xf4];
    int variant;
    void Load(int style, int value);
};

struct Branch {
    char pad[0x38];
    int style;
    char pad2[0x14a4];
    IsoMap *map;
    char pad3[0x520];
    int field1a04;
    void ApplyBuildingStyleVariant(int variant);
};

void Branch::ApplyBuildingStyleVariant(int variant)
{
    map->Load(style, variant);
    map->variant = 1;
    field1a04 = variant;
}
