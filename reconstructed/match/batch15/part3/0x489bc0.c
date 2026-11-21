struct Map {
    void **CollectFootprintCells(int placement, int flags);
    void DrawObjectList(int mode, void **cells);
};

struct GameObject {
    int MapRecordToGlobal(int index);
};

struct Building {
    void PruneStaleListRow();
};

struct FootprintCells {
    virtual int Destroy(int flag);
};

struct Game {
    char pad[0x2fc];
    Map *map;
    int CommitObjectPlacement(int object, int placement);
};

struct OtherGame;

void __fastcall Game_SuspendSimulation(Game *game);
void __fastcall Game_ResumeSimulation(Game *game);

int Game::CommitObjectPlacement(int object, int placement)
{
    GameObject *obj = *(GameObject **)((char *)object + 0x16f0);
    if (obj == 0)
        return 0;
    Game_SuspendSimulation(this);
    void **cells = map->CollectFootprintCells(placement, 0);
    map->DrawObjectList(1, cells);
    if (cells != 0)
        ((FootprintCells *)cells)->Destroy(1);
    int i = 0;
    if (*(int *)((char *)obj + 0x8c) > 0) {
        do {
            int record = obj->MapRecordToGlobal(i);
            if (record != 0)
                ((Building *)record)->PruneStaleListRow();
            i++;
        } while (i < *(int *)((char *)obj + 0x8c));
    }
    Game_ResumeSimulation(this);
    return 1;
}
