/* Object_BeginServiceDecision: switches an object into service-decision
   state toward a target (0x50d710). */
struct State {
    int Is2DOr2E();
};

struct Game {
    int ComputeObjectValue(State *state);
};

struct UI {
    void SetChildRecordVariant(int value);
};

struct Object {
    char pad[0x108];
    int state;
    void BeginServiceDecision(State *target);
};

void Object::BeginServiceDecision(State *target)
{
    if (target->Is2DOr2E() == 0) {
        state = 3;
        ((UI *)this)->SetChildRecordVariant(
            ((Game *)this)->ComputeObjectValue(target));
    }
}
