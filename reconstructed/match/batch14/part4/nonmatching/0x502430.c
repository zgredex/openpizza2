/* Game_GetStatBandByIndex (0x502430): dispatches a statistics band query to
   the matching helper function. */
struct Game {
    int GetPlayerStaffBand();
    int GetActivityVolumeBand();
    int GetPlayerWealthBand();
    int GetCityShareRank();
    int GetBestBuildingRatingBand();
    int GetBuildingQualityBand();
    int GetPlayerSatisfactionBand();
    int ComputeCategory7();
    int GetLevelFromFourCounters();
    int GetGlobalStatsBand();
    int GetMarketRank();
    int GetLevelFromTenCounters();
    int GetPlayerTierFromC20();

    unsigned int GetStatBandByIndex(unsigned int index);
};

unsigned int Game::GetStatBandByIndex(unsigned int index)
{
    unsigned int value = index;

    switch (value) {
    case 0:
        return GetPlayerStaffBand();
    case 1:
        return GetActivityVolumeBand();
    case 2:
        return GetPlayerWealthBand();
    case 3:
        return GetCityShareRank();
    case 4:
        return GetBestBuildingRatingBand();
    case 5:
        return GetBuildingQualityBand();
    case 6:
        return GetPlayerSatisfactionBand();
    case 7:
        return ComputeCategory7();
    case 8:
        return GetLevelFromFourCounters();
    case 9:
        return GetGlobalStatsBand();
    case 10:
        return GetMarketRank();
    case 11:
        return GetLevelFromTenCounters();
    case 12:
        return GetPlayerTierFromC20();
    default:
        break;
    }
    return *(unsigned int *)&index;
}
