struct Game {
    void *MapRecordToGlobal(int index);
    void RemoveRecordFromLocalMap(void *record);
};

struct Map {
    char pad0[0x16f0];
    void *objectList;
    void *FindNearestCompanyBuilding(void *target);
};

void *Map::FindNearestCompanyBuilding(void *target)
{
    void *list = *(void **)((char *)this + 0x16f0);
    if (list == 0)
        return 0;
    int targetField = *(int *)((char *)target + 0xc8);
    void *targetPos = targetField != 0 ? *(void **)(targetField + 0x20) : 0;
    int count = *(int *)((char *)list + 0x8c);
    int bestDist = 0;
    void *best = 0;
    while (--count >= 0) {
        void *record = ((Game *)list)->MapRecordToGlobal(count);
        if (*(int *)((char *)record + 0x38) == 0xd) {
            if (*(int *)((char *)record + 0xc4) != *(int *)((char *)target + 0xc4)) {
                ((Game *)list)->RemoveRecordFromLocalMap(record);
            } else {
                int recordField = *(int *)((char *)record + 0xc8);
                void *recordPos = recordField != 0 ? *(void **)(recordField + 0x20) : 0;
                int dx = *(int *)((char *)targetPos + 0xc) -
                         *(int *)((char *)recordPos + 0xc);
                int dy = *(int *)((char *)targetPos + 0x10) -
                         *(int *)((char *)recordPos + 0x10);
                int dist = dy * dy + dx * dx;
                if (best == 0 || dist < bestDist) {
                    bestDist = dist;
                    best = record;
                }
            }
        }
    }
    return best;
}
