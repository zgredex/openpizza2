/* Game_CountFreeBuildingsTypeD: counts free buildings of type 0xd (0x4800c0). */
struct BuildingManager {
    void CountFreeBuildingsByType(int type);
};

void __fastcall Game_CountFreeBuildingsTypeD(char *this_)
{
    (*(BuildingManager **)(this_ + 0x16f0))->CountFreeBuildingsByType(0xd);
}
