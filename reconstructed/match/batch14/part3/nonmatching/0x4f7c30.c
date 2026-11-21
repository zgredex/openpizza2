/* Branch_ValidateMenuAndRecalculate (0x4f7c30): validates a branch menu mix
   and recalculates its economy.  Returns 1. */
struct Branch {
    int CountObjectsByType(int type);
};

struct BranchManager {
    int RemoveAllStaff(Branch *branch);
    void AssignEntranceAndCustomerSlots(Branch *branch, int flag);
    void AutoTunePrice(Branch *branch);
    int ValidateMenuAndRecalculate(Branch *branch);
};

int BranchManager::ValidateMenuAndRecalculate(Branch *branch)
{
    int all = branch->CountObjectsByType(-1);
    int zero = branch->CountObjectsByType(0);
    int hot = branch->CountObjectsByType(3);
    int cold = branch->CountObjectsByType(2);

    if ((zero == 0 || hot + cold == 0) && all > 0)
        RemoveAllStaff(branch);
    else if (all != 0)
        goto recalculate;
    AssignEntranceAndCustomerSlots(branch, 0);
recalculate:
    AutoTunePrice(branch);
    return 1;
}
