/* PC2 byte-match candidate: UI_Group_DestroyMemberList (0x532510, 8 bytes).
   Build: /O2 /TP; entry ?DestroyMemberList@UI_Group@@QAEXXZ. */
struct Array {
    void Destroy(void);
};

struct UI_Group {
    int field_00;
    Array members;
    void DestroyMemberList(void);
};

void UI_Group::DestroyMemberList(void)
{
    members.Destroy();
}
