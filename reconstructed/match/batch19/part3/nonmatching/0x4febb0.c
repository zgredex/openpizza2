/* Branch_ApplyStyleSettings (0x4febb0). */

struct Game {
    int GetPlayerFieldC20();
    void UpdateObjectRatingScales();
};

struct City {
    void AssignPersonToBuilding(void *branch, int flag);
};

struct Branch {
    char pad0[0x24];
    int style;                  /* 0x24 */
    char pad1[0x149c];
    int v14c0;                  /* 0x14c0 */
    int assigned;               /* 0x14c4 */
    int v14c8;                  /* 0x14c8 */
    int v14cc;                  /* 0x14cc */
    int v14d0;                  /* 0x14d0 */
    int v14d4;                  /* 0x14d4 */

    int ApplyStyleSettings(int player, void *branch);
};

int Branch::ApplyStyleSettings(int player, void *branchPtr)
{
    int value = ((Game *)*(int *)((char *)this + player * 0x168 + 0x70))
                    ->GetPlayerFieldC20();

    if (value < 3)
        return 1;
    Branch *branch = (Branch *)branchPtr;
    if (branch->assigned == 0) {
        ((City *)this)->AssignPersonToBuilding(branch, 1);
        if (branch->assigned == 0)
            return 3;
    }
    int a;
    int b;
    int c;
    int d;

    switch (branch->style) {
    case 0:
    case 4:
        a = 0x32;
        b = 0x1e;
        c = 0;
        d = -10;
        break;
    case 1:
        a = 0x41;
        b = 0x2d;
        c = 10;
        d = 0;
        break;
    case 2:
        c = 10;
        a = 0x46;
        b = 0x37;
        d = 10;
        break;
    case 3:
        c = 0x14;
        a = 0x4b;
        b = 0x50;
        d = 0x14;
        break;
    default:
        b = player;
        c = player;
        d = player;
        a = player;
    }
    branch->v14c8 = b;
    branch->v14cc = a;
    branch->v14d0 = c;
    ((Game *)branch)->UpdateObjectRatingScales();
    branch->v14c0 = d;
    branch->v14d4 = 0;
    ((Game *)branch)->UpdateObjectRatingScales();
    return 1;
}
