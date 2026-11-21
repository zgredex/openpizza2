/* UI_DrawNeighborhoodCustomerIcons: draws the customer type row for the
   neighborhood around the selected company (0x4a53e0). */
struct Game {
    char pad[0x218];
    int type;
    void CountNearbyTypesAroundRect(int type, int radius, int *counts);
};

struct CustomerGroups {
    void DrawCountRow(void *target, int mode, int *counts);
};

extern struct Game *DAT_0057c670;

void __cdecl UI_DrawNeighborhoodCustomerIcons(void *target, int mode)
{
    int counts[8];

    if (DAT_0057c670->type != 0) {
        DAT_0057c670->CountNearbyTypesAroundRect(DAT_0057c670->type, 0x78, counts);
        ((struct CustomerGroups *)DAT_0057c670)->DrawCountRow(target, mode, counts);
    }
}
