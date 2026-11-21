/* Advertising_StopCampaign: stop a campaign in one advertising slot
   (0x4e3d80). */
struct Advertising {
    void StopCampaign(int slot, int campaign, int cancelJobs);
};

extern "C" void __stdcall Gangster_CancelJobsTargetingPlayer(int player,
                                                             int flag);

void Advertising::StopCampaign(int slot, int campaign, int cancelJobs)
{
    int match = (campaign == *(int *)((char *)this + 0x48));
    int cancel = cancelJobs;

    *(char *)((char *)this + 0xac + slot) = 0;
    *(int *)((char *)this + 0xcc + slot * 4) = 0;
    *(int *)((char *)this + 0xb4 + slot * 4) = 0;
    if (match)
        *(int *)((char *)this + 0x94 + slot * 4) = 0;
    if (cancel != 0)
        Gangster_CancelJobsTargetingPlayer(slot, match);
}
