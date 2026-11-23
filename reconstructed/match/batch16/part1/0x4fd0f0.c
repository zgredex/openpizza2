// Player_BuildHeadquarters @ 0x4fd0f0 (149 bytes)
// Starts headquarters construction (or upgrade) for a player.

class Person;
class Game;
class MapObject;

extern Game *DAT_0057c670;
extern int DAT_00568188[4];

class Game {
public:
    void AcquireStateLock(int reason);
    Person *GetPlayerBySlot(int slot);
};

class Window {
public:
    void UnlockState();
};

struct MapState {
    char pad[0xf4];
    int fieldF4;
};

class MapObject {
public:
    char pad0[0xfa8];
    MapState *state;

    void SpawnByKind(Person *person, int kind, int slot, int unknown, int offset);
};

class Person {
public:
    char pad0[0x48];
    int kind;
    int field4c;
    int field50;
    char pad2[0x1d8 - 0x54];
    Person *field1d8;
};

extern "C" void __stdcall Player_BuildHeadquarters(int slot, MapObject *map, Person *person,
                                        int index, int flag)
{
    int value;

    DAT_0057c670->AcquireStateLock(0);
    value = person->kind;
    if (value >= 0 && value < 4)
        value = DAT_00568188[value];
    int offset = value + 0x818 + index * 4;
    if (flag)
        map->SpawnByKind(person, 6, slot, 0x1c, offset);
    else
        map->SpawnByKind(person, 4, slot, 0x1c, offset);
    map->state->fieldF4 = 1;
    person->field4c = 0;
    person->field50 = 0;
    ((Person *)DAT_0057c670->GetPlayerBySlot(slot))->field1d8 = person;
    ((Window *)DAT_0057c670)->UnlockState();
}
