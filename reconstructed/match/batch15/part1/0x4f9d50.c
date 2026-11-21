/* Building_GetLevelFromType: maps a building type and level to a numeric level
   (0x4f9d50). */
struct Building {
    char pad[0x10];
    int type;
    unsigned char level;
};

extern "C" int __stdcall Building_GetLevelFromType(Building *building)
{
    switch (building->type) {
    case 0:
        switch (building->level) {
        case 0:
        case 1:
            return 1;
        case 2:
            return 2;
        }
        break;
    case 1:
        switch (building->level) {
        case 0:
            return 1;
        case 1:
            return 2;
        case 2:
            return 3;
        }
        break;
    case 2:
        switch (building->level) {
        case 0:
            return 2;
        case 1:
            return 3;
        case 2:
            return 4;
        }
        break;
    case 3:
        switch (building->level) {
        case 0:
            return 3;
        case 1:
            return 4;
        case 2:
            return 5;
        }
        break;
    }
    return -1;
}
