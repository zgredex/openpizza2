/* Branch_UpdateActiveConstruction: refreshes the active construction site (0x47f210). */
struct Branch {
    char pad[0x14c4];
    int activeSite;
    char pad2[4];
    int siteIndex;
    void GetBestObject(int a, int b, float *out);
    void UpdateActiveConstruction();
};

void Branch::UpdateActiveConstruction()
{
    if (activeSite != 0) {
        float local;
        GetBestObject(1, siteIndex, &local);
    }
}
