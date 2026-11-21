struct BranchData { char pad[0x14a8]; int field14a8; int field14ac; };
struct BranchValue { float GetBuildingValue(); float GetFloat44(); };
struct Branch { float ComputeRecipePrice(BranchData *data, int percent); };
float Branch::ComputeRecipePrice(BranchData *data, int percent)
{
    if (percent == -999) percent = data->field14a8;
    int base = data->field14ac;
    float factor = ((BranchValue *)data)->GetBuildingValue() * ((float)percent * *(float *)0x55c348);
    float r = ((BranchValue *)this)->GetFloat44() * factor;
    return r + base;
}
