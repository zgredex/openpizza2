/* Courier_StartHeadquartersBombing (0x50be30, 46 bytes).  Build: /O2 /TP.
   Starts a courier on a headquarters bombing job. */
struct UI {
    void SetChildState(int state);
};

struct Object {
    void SetFieldA4Locked(int value);
    void SetChildField2C(int value);
    void SetDestinationAndTarget(int action, int target);
};

struct Courier {
    void StartHeadquartersBombing(int target);
};

void Courier::StartHeadquartersBombing(int target)
{
    ((Object *)this)->SetFieldA4Locked(5);
    ((UI *)this)->SetChildState(0x22);
    ((Object *)this)->SetChildField2C(0x10);
    ((Object *)this)->SetDestinationAndTarget(0xc, target);
}
