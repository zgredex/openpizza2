/* Branch_UpdateStarRating - 0x48e6d0, 80 bytes */
struct UI
{
    void ShowChildByID(int id);
    void RemoveObjectByKey(int key);
};

struct City
{
    char pad[0x14b4];
    int stars;
};

struct GameState
{
    char pad[0x9c];
    City *city;
};

extern GameState *DAT_0057c670;

void __cdecl Branch_UpdateStarRating(UI *window)
{
    int stars = DAT_0057c670->city->stars;
    int i;

    for (i = 0; i < stars; i++)
        window->ShowChildByID(i + 0x1f49);
    for (i = stars; i < 5; i++)
        window->RemoveObjectByKey(i + 0x1f49);
}
