struct Company {
    float GetMaxTimelineCategoryValue(int category);
};

struct StatsObject {
    int CountActiveCompanies();
    Company *GetActiveCompanyById(int index);
    int GetLeadingCompanyForCategory(int category, void *exclude);
};

int StatsObject::GetLeadingCompanyForCategory(int category, void *exclude)
{
    float best = 0.0f;
    int bestCompany = 0;
    int count = CountActiveCompanies();
    int index = 0;
    int company = 0;
    if (count > 0) {
        do {
            company = (int)GetActiveCompanyById(index);
            float value = ((Company *)company)->GetMaxTimelineCategoryValue(category);
            if (value > best) {
                best = value;
                bestCompany = company;
            }
            index++;
        } while (index < count);
        company = bestCompany;
    }
    if (exclude != 0) {
        int other = *(int *)((char *)exclude + 0x14dc);
        if (other != 0) {
            float value = ((Company *)other)->GetMaxTimelineCategoryValue(category);
            if (value <= best)
                return company;
            return other;
        }
    }
    return company;
}
