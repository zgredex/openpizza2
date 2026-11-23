extern "C" int __cdecl Random_RangeFast(int min, int max);

/* City_SpawnPerson: creates a character and registers it with the city list
   (0x4d4940). */
struct Character {
    void SetMotivation(unsigned int motivation);
};

struct Game {
    Character *Construct(int a, int b);
    int GetRecordByField814();
};

struct UI {
    void SetChildIconAndRatingHeight(int record);
};

struct List {
    void Add(void *item);
};

struct City {
    Character *SpawnPerson(int kind);
};


Character *City::SpawnPerson(int kind)
{
    Character *character = 0;
    unsigned int motivation;
    int *entry;

    if (kind == -1) {
        kind = Random_RangeFast(0, 3);
    }
    {
        void *memory = operator new(0x828);

        if (memory != 0) {
            character = ((Game *)this)->Construct(*(int *)((char *)this + 0xc1c), kind);
        }
    }
    if (*(char *)0x57bb20 == '\0' && *(int *)((char *)this + 0x340) == 7) {
        motivation = Random_RangeFast(5, 0x14);
        character->SetMotivation(motivation);
    }
    entry = (int *)operator new(8);
    if (entry == 0) {
        entry = 0;
    } else {
        entry[1] = -1;
        entry[0] = (int)character;
    }
    ((UI *)this)->SetChildIconAndRatingHeight(((Game *)character)->GetRecordByField814());
    ((List *)((char *)this + 0xfc8))->Add(entry);
    return (Character *)entry;
}
