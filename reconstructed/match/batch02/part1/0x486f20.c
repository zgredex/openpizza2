/* Game_MarkObjectsDirtyType6: marks objects of type 6 dirty (0x486f20). */
struct ObjectList {
    void MarkAllDirty(int type);
};

void __stdcall Game_MarkObjectsDirtyType6(ObjectList *objects)
{
    objects->MarkAllDirty(6);
}
