/* Game_GetPreviousPlayerSlot: walks the player slots backwards and returns
   the previous slot owned by another company (0x486ec0). */
struct Player {
    char pad[0x48];
    int company;
};

struct Game {
    int GetPlayerBySlot(int slot);
    int GetCurrentPlayerCompanyName();

    int GetPreviousPlayerSlot(int slot, char anyCompany);
};

int Game::GetPreviousPlayerSlot(int slot, char anyCompany)
{
    int index = slot - 1;

    while (index != -1) {
        struct Player *player;

        if (index < -1) {
            index = 5;
        }
        player = (struct Player *)GetPlayerBySlot(index);
        if (player != 0) {
            int company;

            if (anyCompany) {
                return index;
            }
            company = player->company;
            if (company != GetCurrentPlayerCompanyName()) {
                return index;
            }
        }
        index--;
    }
    return -1;
}
