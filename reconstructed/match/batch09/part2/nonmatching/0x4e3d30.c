/* Advertising_StartCampaignAgainstPlayer: starts an advertising campaign
   against a rival player (0x4e3d30). */
struct IDMap {
    int *Lookup(int key, int *out);
};

struct Gangster {
    void StartProtectionCollection(void *player);
};

struct Advertising {
    void StartCampaignAgainstPlayer(void *player, int campaign, int *slot);
};

extern int DAT_0057c670;

void Advertising::StartCampaignAgainstPlayer(void *player, int campaign,
                                             int *slot)
{
    *(int *)((char *)this + *(int *)((char *)player + 0x30) * 4 + 0x94) = campaign;
    *(int *)((char *)this + *(int *)((char *)player + 0x30) * 4 + 0xcc) = 0;
    ((struct Gangster *)((struct IDMap *)(DAT_0057c670 + 0x3c))
         ->Lookup(*slot, 0))
        ->StartProtectionCollection(player);
}
