/* Person_SetRouteToBuilding: fills the person's eight route slots with a
   building and sends them there (0x50a080).  Build: /O2 /TP. */
struct Object {
    void SetDestinationAndTarget(int mode, int target);
};

struct Person {
    char pad[0xcc];
    int building;
    int fieldD0;
    int route[8];
    void SetRouteToBuilding(int target);
};

void Person::SetRouteToBuilding(int target)
{
    int i;

    for (i = 0; i < 8; i++)
        route[i] = target;
    building = target;
    ((Object *)this)->SetDestinationAndTarget(2, target);
}
