/* Branch_RemoveConstructionOrder: clears the pending construction order,
   removes the order's object from the branch ID map at 0x16f8 and re-checks
   the branch's upgrade state (0x47c5b0).  Build: /O2 /TP. */
struct IDMap {
    int RemoveByKey(int key);
};

struct Branch {
    char pad[0x16f8];
    int map[8];
    int field1718;
    void RemoveConstructionOrder(int key);
};

struct Game {
    void CheckObjectUpgrade();
};

void Branch::RemoveConstructionOrder(int key)
{
    field1718 = 0;
    ((IDMap *)map)->RemoveByKey(key);
    ((Game *)this)->CheckObjectUpgrade();
}
