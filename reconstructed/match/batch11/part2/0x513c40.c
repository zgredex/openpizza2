/* Branch_GetRecipePriceParts: splits the recipe price into base, factor and
   truncated value (0x513c40). */
struct BranchData {
    char pad[0x14a8];
    int field14a8;
    int field14ac;
};

struct BranchValue {
    float GetBuildingValue();
    float GetFloat44();
};

struct Branch {
    void GetRecipePriceParts(BranchData *data, int *basePrice, float *factor,
                             int *percent, int *value);
};

void Branch::GetRecipePriceParts(BranchData *data, int *basePrice,
                                 float *factor, int *percent, int *value)
{
    if (*percent == -999)
        *percent = data->field14a8;
    *basePrice = data->field14ac;
    *value = (int)(((BranchValue *)data)->GetBuildingValue() *
                   *(float *)0x55c320);
    *factor = ((BranchValue *)this)->GetFloat44();
}
