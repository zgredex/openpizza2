/* Object_StartWorkOrderAndSetState: starts work order 1 toward the target
   stored in another object and records the new state (0x50be90). */
struct WorkSource {
    char pad[0x16f0];
    int target;
};

struct Object {
    char pad[0xac];
    int state;
    void SetDestinationAndTarget(int order, int target);
    void SetFieldA4Locked(int value);
    void StartWorkOrderAndSetState(WorkSource *source, int value, int state);
};

void Object::StartWorkOrderAndSetState(WorkSource *source, int value, int state)
{
    SetDestinationAndTarget(1, source->target);
    SetFieldA4Locked(value);
    this->state = state;
}
