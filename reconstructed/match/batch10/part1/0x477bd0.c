/* Branch_SetAssignedEmployee: assigns an employee to a branch and refreshes
   the owning company's ratings (0x477bd0). */
struct Game {
    char pad[0x264];
    void *control;

    int GetPlayerBySlot(int slot);
    void ClearObjectFlag20();
};

struct UI {
    void QueueControlCommand(int message, int wparam, int lparam);
};

extern Game *DAT_0057c670;

__fastcall void Company_InvalidateAllBranchRatings(void *company);

struct Branch {
    void SetAssignedEmployee(int employee);
};

void Branch::SetAssignedEmployee(int employee)
{
    *(int *)((char *)this + 0x14dc) = employee;
    Company_InvalidateAllBranchRatings(
        (void *)DAT_0057c670->GetPlayerBySlot(*(int *)((char *)this + 0x30)));
    if (DAT_0057c670->control != 0) {
        ((struct UI *)DAT_0057c670->control)->QueueControlCommand(
            -0x18658, 0x23, 0);
    }
    ((struct Game *)this)->ClearObjectFlag20();
}
