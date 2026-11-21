/* Gangster_StartProtectionCollection: starts a gangster's protection
   collection (0x50bf00).  Build: /O2 /TP. */
struct Branch {
    char pad[0x16f0];
    int object;
};

struct Object {
    void GetPlayerValue(int value);
    void SetDestinationAndTarget(int mode, int target);
    void SetFieldA4Locked(int value);
    void StartProtectionCollection(Branch *branch);
};

void Object::StartProtectionCollection(Branch *branch)
{
    GetPlayerValue(-1);
    SetDestinationAndTarget(1, branch->object);
    SetFieldA4Locked(0x1a);
}
