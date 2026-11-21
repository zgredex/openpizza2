struct IDMap {
    char pad[0x14];
    int Lookup(int key, int *out);
    void RemoveRecursive(int key);
};
struct Recipe { virtual void Destroy(int flag); };
struct Company {
    char pad[0x110];
    IDMap recipes;
    int recipeCount;
    void RemoveRecipe(Recipe *recipe);
};
void __cdecl Game_ClearObjectReferences(int object);
void __fastcall Company_InvalidateAllBranchRatings(int company);

void Company::RemoveRecipe(Recipe *recipe)
{
    int count;
    int index;
    Company *self = this;

    Game_ClearObjectReferences((int)recipe);
    count = self->recipeCount;
    index = 0;
    if (count > 0) {
        while (1) {
            if (((IDMap *)((char *)self + 0x110))->Lookup(index, 0) ==
                (int)recipe) {
                break;
            }
            index = index + 1;
            if (index < count) {
                continue;
            }
            Company_InvalidateAllBranchRatings((int)self);
            return;
        }
        ((IDMap *)((char *)self + 0x110))->RemoveRecursive(index);
        if (recipe != 0) {
            recipe->Destroy(1);
        }
    }
    Company_InvalidateAllBranchRatings((int)self);
}
