/* Game_FindTopScoringCompany (0x4ddfb0): finds the active company with the
   highest timeline score, optionally considering a preferred company. */
struct Company {
    char pad[0x14dc];
    Company *related;

    int GetMaxTimelineCount(int type);
};

struct Game {
    int CountActiveCompanies();
    Company *GetActiveCompanyById(int id);
    Company *FindTopScoringCompany(int type, Company *preferred);
};

Company *Game::FindTopScoringCompany(int type, Company *preferred)
{
    int best = 0;
    Company *result = 0;
    int count = CountActiveCompanies();
    int i = 0;
    Company *company = 0;

    if (0 < count) {
        do {
            company = GetActiveCompanyById(i);
            int score = company->GetMaxTimelineCount(type);

            if (score > best) {
                result = company;
                best = score;
            }
            i++;
        } while (i < count);
        company = result;
    }
    if (preferred != 0) {
        Company *candidate = preferred->related;

        if (candidate != 0 &&
            candidate->GetMaxTimelineCount(type) > best)
            return candidate;
    }
    return company;
}
