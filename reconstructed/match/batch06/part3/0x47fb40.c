/* Branch_EndConstructionMode: restores the player's background image when the
   branch is the current construction site, then leaves construction mode
   (0x47fb40).  Build: /O2 /TP. */
struct Game {
    char pad[0x2fc];
    int field2fc;
    void LoadBackgroundImage(int value);
};

struct Branch {
    char pad[0x14e0];
    int field14e0;
    char pad2[0x16f5 - 0x14e4];
    unsigned char field16f5;
    void EndConstructionMode();
};

void Branch::EndConstructionMode()
{
    Game *game = *(Game **)0x57c670;

    if (game->field2fc == field14e0)
        game->LoadBackgroundImage(0);
    field16f5 = 0;
}
