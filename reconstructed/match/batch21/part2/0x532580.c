class Array {
public:
    int data;
    void *GetPtr(int index);
    int IndexOfInt(int key);
    void *GetRecordByKeyPtr(int key);
};
class UI {
public:
    void SetActiveChild(void *child);
    void SelectObjectRecord(void *group, int record);
};
class UI_Group {
public:
    void ApplyMemberSelection(void *member, int key);
    void SelectMemberByKey(int key);
};
struct Member {
    int type;
    Array keys;
    char pad0[0x14 - 8];
    int count;
};

void UI_Group::SelectMemberByKey(int key)
{
    int count = *(int *)((char *)this + 0x158);
    int index = 0;
    Member *member;
    int found;

    while (index < count) {
        member = (Member *)((Array *)((char *)this + 0x148))->GetPtr(index);
        found = member->keys.IndexOfInt(key);
        if (found != -1)
            goto found;
        index++;
    }
    return;
found:
    {
        if (member->type == 3) {
            found++;
            if (found >= member->count)
                found = 0;
            void *record = member->keys.GetPtr(found);
            Member *selected =
                (Member *)((Array *)this)->GetRecordByKeyPtr((int)record);
            ((UI *)*(void **)((char *)this + 0x134))->SetActiveChild(selected);
            ((UI *)*(void **)((char *)this + 0x134))
                ->SelectObjectRecord(this, (int)record);
            return;
        }
        this->ApplyMemberSelection(member, key);
    }
}
