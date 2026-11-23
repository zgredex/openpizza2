// City_RemovePersonAndMaintainPopulation @ 0x4d6c10 (153 bytes)
// Removes a person from the city map and keeps the population stable.

extern "C" int Random_RangeFast(int minimum, int maximum);

class IDMap {
public:
    char pad[0x14];
    void *Lookup(int index, int *out);
    int RemoveByKey(int key);
};

class Game {
public:
    int CountObjectsByType2(int type);
};

class City {
public:
    char pad0[0xfc8];
    IDMap map;
    int count;

    int RemovePersonAndMaintainPopulation(int person);
    void SpawnPerson(int type);
};

int City::RemovePersonAndMaintainPopulation(int person)
{
    int count = this->count;
    int index = 0;
    int result = 0;

    if (count > 0) {
        do {
            int *record = (int *)this->map.Lookup(index, 0);
            if (*record == person) {
                result = this->map.RemoveByKey((int)record);
                break;
            }
            index++;
        } while (index < count);
    }
    unsigned char type = *(unsigned char *)(person + 0x824);
    int remaining = ((Game *)this)->CountObjectsByType2(type);
    if (remaining == 0 || Random_RangeFast(0, 99) < 100 - remaining * 30)
        this->SpawnPerson(type);
    return result;
}
