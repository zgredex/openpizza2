/* UI_Child_Activate: activates a UI child once, selecting its group member
   and dirtying its clip rect (0x520e30).  Build: /O2 /TP. */
struct UI_Group {
    void SelectMemberByKey(int key);
};

struct UI {
    void ClipRect(int *rect, int mode);
};

struct Child {
    char pad[4];
    int key;
    UI_Group *group;
    char pad2[0x14];
    int active;
    char pad3[4];
    int rect[4];
    void Activate();
};

void Child::Activate()
{
    if (active == 0) {
        active = 1;
        group->SelectMemberByKey(key);
        ((UI *)group)->ClipRect(rect, 1);
    }
}
