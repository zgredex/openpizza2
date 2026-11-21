/* BuildingProject_ResetState: resets every project field and the embedded
   list node (0x503280). */
struct List_Node {
    char pad[0x1c];
    void Reset();
};

struct BuildingProject {
    char pad[4];
    unsigned char field4;
    int field8;
    char pad2[0x34];
    int field40;
    int field44;
    int field48;
    int field4C;
    int field50;
    int field54;
    int field58;
    int field5C;
    unsigned char field60;
    char pad3[3];
    int field64;
    List_Node node;
    int field84;
    void ResetState();
};

void BuildingProject::ResetState()
{
    field4 = 0;
    field44 = -1;
    field40 = -1;
    field48 = -1;
    field4C = -1;
    field50 = -1;
    field54 = -1;
    field58 = -1;
    field60 = 0;
    field64 = -1;
    field8 = -1;
    field84 = -1;
    node.Reset();
}
