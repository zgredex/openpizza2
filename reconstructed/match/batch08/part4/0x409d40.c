/* Object_AdvanceToQueuedTarget: advances to the next queued target or walks
   to the current one (0x409d40). */
struct AdCampaign {
    int GoToNextQueuedBuilding(void *object, void *target);
};

struct Object {
    void SetChildField2C(int value);
};

struct Customer {
    void ApproachBranchEntrance(void *object, void *target);
};

struct Actor {
    int AdvanceToQueuedTarget(void *object, void *target);
};

int Actor::AdvanceToQueuedTarget(void *object, void *target)
{
    if (((AdCampaign *)this)->GoToNextQueuedBuilding(object, target) == 0) {
        ((Object *)target)->SetChildField2C(0x10);
        ((Customer *)this)->ApproachBranchEntrance(object, target);
        return 0;
    }
    return 1;
}
