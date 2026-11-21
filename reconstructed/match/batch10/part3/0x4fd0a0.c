extern "C" int __fastcall Game_GetPlayerFieldC20(void *player);
struct Shop;
struct Company {
    void EnsureRequiredBranch(int param_1, void *param_2, int branchType);
    Shop *FindCheapestShop(int type, void *player, int flag);
    void BuildHeadquarters(int type, void *player, Shop *shop, int branchType, int one);
};
void Company::EnsureRequiredBranch(int param_1, void *param_2, int branchType)
{
    int type = *(int *)(param_1 + 0x48);
    if (Game_GetPlayerFieldC20((void *)param_1) == 0) {
        int field = *(int *)(param_1 + 0x48);
        Shop *shop = FindCheapestShop(field, param_2, 0);
        if (shop != 0) {
            BuildHeadquarters(type, param_2, shop, branchType, 1);
            *(int *)((char *)param_2 + type * 4 + 0xc20) = branchType;
        }
    }
}
