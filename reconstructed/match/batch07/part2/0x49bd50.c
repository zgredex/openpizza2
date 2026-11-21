/* Player_AddRecipeToMenu (0x49bd50, 49 bytes).  Build: /O2 /TP.
   Adds the recipe to the current player's menu. */
extern int DAT_0057c670;

struct IDMap {
    int Lookup(int key, int *out);
};

struct Recipe {
    void SetOnMenu(int record, int enabled);
};

extern "C" void Player_AddRecipeToMenu(int recipe)
{
    Recipe *player = *(Recipe **)(DAT_0057c670 + 0x200 +
                                  *(int *)(DAT_0057c670 + 0x2ec) * 4);
    int record = ((IDMap *)((char *)player + 0x110))->Lookup(recipe, 0);

    player->SetOnMenu(record, 1);
}
