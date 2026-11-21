/* UI_Group_ClearAll: destroys and frees every member of the group's member
   array (0x532520). */
struct Array {
    void *GetPtr(int index);
    void Clear();
};

struct MemberList {
    void DestroyMemberList();
};

struct UI_Group {
    char pad[0x148];
    char members[0x10];
    int memberCount;

    int ClearAll();
};

void Mem_Free(void *block);

int UI_Group::ClearAll()
{
    int count = memberCount;
    int i;

    for (i = 0; i < count; i++) {
        void *member = ((struct Array *)members)->GetPtr(i);

        if (member != 0) {
            ((struct MemberList *)member)->DestroyMemberList();
            Mem_Free(member);
        }
    }
    ((struct Array *)members)->Clear();
    return 0;
}
