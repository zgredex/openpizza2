/* Thug_StartRestaurantRampage: sends the thug to rampage at the restaurant (0x50be60). */
struct Object {
    void SetDestinationAndTarget(int mode, int target);
    void SetFieldA4Locked(int value);
};

struct Thug {
    void StartRestaurantRampage(char *restaurant, int value);
};

void Thug::StartRestaurantRampage(char *restaurant, int value)
{
    ((Object *)this)->SetDestinationAndTarget(1, *(int *)(restaurant + 0x16f0));
    ((Object *)this)->SetFieldA4Locked(value);
}
