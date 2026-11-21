/* UI_Group_RemoveAt (0x5324c0): removes the group member at the given index,
   destroys its member list and frees the record. */
extern "C" {
void Mem_Free(void *block);
}

struct Array {
    void *GetPtr(int index);
    int RemoveAt(int index);
};

struct UI_Group {
    char pad[0x148];
    Array array;

    void DestroyMemberList();
    int RemoveAt(int index);
};

int UI_Group::RemoveAt(int index)
{
    Array *list = (Array *)((char *)this + 0x148);
    int result = 0;
    void *member = list->GetPtr(index);

    if (member != 0) {
        result = list->RemoveAt(index);
        ((UI_Group *)member)->DestroyMemberList();
        Mem_Free(member);
    }
    return result;
}
