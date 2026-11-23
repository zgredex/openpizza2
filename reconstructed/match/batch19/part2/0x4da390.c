// Game_AdjustPlayerRankingScores: adjusts each player's ranking score.

extern char DAT_0057c670[];

struct Game {
    void AdjustPlayerRankingScores();
    int GetMostAdvancedCompany();
    void *GetPlayerBySlot(int slot);
    char *GetPlayerCity();
};

void Game::AdjustPlayerRankingScores()
{
    int best = GetMostAdvancedCompany();
    int slot = 0;
    int *score = (int *)((char *)this + 0xcc8);

    do {
        void *player = ((Game *)*(void **)DAT_0057c670)->GetPlayerBySlot(slot);
        if (player != 0) {
            if (best != slot) {
                unsigned int rank = score[0x39];
                if (rank == 0) {
                    *score -= 12;
                } else {
                    unsigned int top =
                        *(unsigned int *)((char *)this + 0xdac + best * 4);
                    if (rank < (top >> 2))
                        *score -= 8;
                    else if (rank < (top >> 1))
                        *score -= 5;
                    else if (rank < top * 2 / 3)
                        *score -= 3;
                    else if (rank > top * 3 / 4)
                        *score += 2;
                }
            } else {
                *score += 8;
            }
            {
                char *city = ((Game *)((Game *)*(void **)DAT_0057c670)
                                  ->GetPlayerBySlot(slot))->GetPlayerCity();
                *score += *(int *)(city + 0x60) + *(int *)(city + 0x48);
            }
            if (*score < 0)
                *score = 0;
            if (*score > 100)
                *score = 100;
        }
        slot++;
        score++;
    } while (slot < 6);
}
