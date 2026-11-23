// Game_FindNearestTransportBuilding @ 0x4d8be0 (153 bytes)
// Finds the transport building closest to the starting building.

class IDMap {
public:
    char pad[0x14];
    void *Lookup(int index, int *out);
};

class Array {
public:
    int GetRecord28(int one, int index);
};

class Map {
public:
    int FindShortestPath(int start, int target, int flag);
};

class City {
public:
    char pad0[0xfa8];
    Array *array;
    IDMap map;
    int count;

    int FindNearestTransportBuilding(int start);
};

int City::FindNearestTransportBuilding(int start)
{
    Array *array = this->array;
    int firstPath = array->GetRecord28(1, *(int *)(start + 0x54));
    int best = 0;
    int index = 0;
    int bestDistance = 10000000;

    if (this->count > 0) {
        do {
            int *record = (int *)this->map.Lookup(index, 0);
            if (record[1] - 2 == 0 && *(int *)((char *)record + 0x54) != -1) {
                int secondPath = this->array->GetRecord28(1, *(int *)((char *)record + 0x54));
                int distance = ((Map *)this->array)->FindShortestPath(firstPath, secondPath, 0);
                if (distance < bestDistance) {
                    bestDistance = distance;
                    best = (int)record;
                }
            }
            index++;
        } while (index < this->count);
    }
    return best;
}
