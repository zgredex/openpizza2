/* Game_UpdateFreeBuildingCount: counts free buildings of type 0x17 (0x480060). */
struct BuildingManager {
    void CountFreeBuildingsByType(int type);
};

void __fastcall Game_UpdateFreeBuildingCount(char *this_)
{
    (*(BuildingManager **)(this_ + 0x16f0))->CountFreeBuildingsByType(0x17);
}
