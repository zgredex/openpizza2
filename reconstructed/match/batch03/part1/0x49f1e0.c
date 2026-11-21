/* RecipeKitchen_ShowPlacedIngredient: shows an ingredient child with a +100000 id bias (0x49f1e0). */
struct UI {
    void ShowChildByID(int id);
};

void __cdecl RecipeKitchen_ShowPlacedIngredient(void *ui, int id)
{
    ((UI *)ui)->ShowChildByID(id + 0x186a0);
}
