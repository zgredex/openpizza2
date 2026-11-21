/* Branch_GetBuildingValue (0x47fd90): returns the value of the branch's
   building record or recomputes it for the owning player. */
extern int DAT_0057c670;

struct IDMap {
    int Lookup(int key, int *out);
};

struct Array {
    int GetStride60(int index);
};

struct Player {
    void *FindRecordByCityId(void *branch);
    float Compute(void *array, int stride);
};

struct Game {
    char pad[4];
    IDMap objects;
    void *GetPlayerBySlot(int slot);
};

float __fastcall Branch_GetBuildingValue(int param_1)
{
    int record;
    Player *player;
    Array *array;
    void *found;
    int stride = 0;
    int key;
    void *branch;

    record = ((IDMap *)(param_1 + 0x1998))->Lookup(0, 0);
    if (record != 0 && *(int *)(record + 0x1c) != 0) {
        return *(float *)(record + 0x10);
    }
    player = (Player *)((Game *)DAT_0057c670)->GetPlayerBySlot(
        *(int *)(param_1 + 0x30));
    key = *(int *)(param_1 + 0x34);
    array = (Array *)((Game *)DAT_0057c670)->objects.Lookup(key, 0);
    branch = (void *)param_1;
    found = player->FindRecordByCityId(branch);
    if (found != 0) {
        stride = array->GetStride60(*(int *)((char *)found + 0x30));
    }
    return player->Compute(array, stride);
}
