/* Person_SendToBranchForAction (0x50bed0, 46 bytes).  Build: /O2 /TP.
   Sends a person to a branch for a specific action. */
struct WorkSource {
    char pad[0x16f0];
    int target;
};

struct Object {
    int GetPlayerValue(int index);
    void SetDestinationAndTarget(int action, int target);
    void SetFieldA4Locked(int value);
};

struct Person {
    void SendToBranchForAction(WorkSource *source, int action);
};

void Person::SendToBranchForAction(WorkSource *source, int action)
{
    ((Object *)this)->GetPlayerValue(-1);
    ((Object *)this)->SetDestinationAndTarget(1, source->target);
    ((Object *)this)->SetFieldA4Locked(action);
}
