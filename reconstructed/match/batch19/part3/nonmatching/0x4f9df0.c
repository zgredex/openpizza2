/* MapObject_CreateFromTile (0x4f9df0). */

struct IDMapHelper {
    char pad[0x1c];

    void *Lookup(int key, int *out);
};

struct Building {
    char pad0[0x0c];
    int type;                   /* 0x0c */

    int GetLevelFromType(int building);
};

struct Player {
    char pad0[0x15c];
};

struct Game {
    char pad0[0x74];
    IDMapHelper map;            /* 0x74 */

    Player *GetPlayerBySlot(int slot);
    int GetPlayerCity();
    float ComputePrice(int city);
};

extern Game *DAT_0057c670;

void *__cdecl operator new(unsigned int size);

struct Tile {
    int a00;                    /* 0x00 */
    int a04;                    /* 0x04 */
    int a08;                    /* 0x08 */
    int a0c;                    /* 0x0c */
    int a10;                    /* 0x10 */
    unsigned short a14;         /* 0x14 */
    unsigned short a16;         /* 0x16 */
    char a18;                   /* 0x18 */
    char pad[3];
    int a1c;                    /* 0x1c */
    int a20;                    /* 0x20 */
};

struct List {
    void Add(void *item);
};

struct Tree;

struct City {
    void FindListContainingValue(int value, int *out1, int *out2);
    int GetLevelFromType(int building);

    void CreateFromTile(int *param_1, int param_2, unsigned short param_3,
                        unsigned short param_4, char param_5, int param_6,
                        int param_7);
};

void City::CreateFromTile(int *param_1, int param_2, unsigned short param_3,
                          unsigned short param_4, char param_5, int param_6,
                          int param_7)
{
    int player = (int)DAT_0057c670->GetPlayerBySlot(*(int *)(*param_1 + 0x30));
    int city = ((Game *)player)->GetPlayerCity();
    Tile *tile = (Tile *)operator new(0x24);

    tile->a16 = param_4;
    tile->a14 = param_3;
    tile->a1c = param_7;
    tile->a18 = param_5;
    tile->a20 = (param_6 == 1);
    tile->a00 = param_2;
    tile->a04 = 0;
    FindListContainingValue(param_2, &tile->a0c, &tile->a10);

    int id = tile->a0c;
    if (id > 0) {
        Building *building =
            (Building *)DAT_0057c670->map.Lookup(id, 0);

        if (building->type == 5) {
            tile->a08 = param_1[6];
            tile->a1c = 1;
        } else {
            int level = ((Building *)this)->GetLevelFromType((int)building);

            tile->a08 = level;
            if (level == -1)
                tile->a08 = param_1[5];
            if (building->type == 6)
                tile->a1c = 1;
        }
        tile->a04 = (int)((Game *)building)->ComputePrice(city);
    }
    ((List *)param_1[3])->Add(tile);
}
