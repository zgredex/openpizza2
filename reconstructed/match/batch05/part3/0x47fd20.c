/* Branch_ClearConstructionSites: consumes every pending construction site (0x47fd20). */
struct Branch {
    char pad[0x19ac];
    int siteCount;
    void ConsumeObject(int flag);
    void ClearConstructionSites();
};

void Branch::ClearConstructionSites()
{
    while (siteCount > 0)
        ConsumeObject(0);
}
