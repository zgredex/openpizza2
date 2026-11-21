/* Non-matching candidate.
   First difference: offset 0x5b, 5 bytes differ.
   original pushes the PickRandomLinkedCellInSteps arguments before loading ecx with this.
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;
extern char DAT_00572fbc;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct CriticalSection {
    void Enter();
    void Leave();
};

extern "C" void NoOp_Stub(void *arg);

struct MapObject {
    int GetRecord28(int flag, int id);
    int PickRandomLinkedCellInSteps(int cell, int steps);
};

struct Person {
    int PickRandomLinkedCellInSteps(int cell, int steps);
    void PathToTileAndStep(int target, int cell);
};

void __fastcall Person_WanderToLinkedCell(char *person)
{
    int record = (int)((IDMap *)((char *)DAT_0057c670 + 4))
                     ->Lookup(*(int *)((char *)DAT_0057c670 + 0x2f4), 0);
    char *object = *(char **)(record + 0xfa8);
    ((CriticalSection *)*(void **)((char *)DAT_0057c670 + 0x240))->Enter();
    if (*(int *)(person + 0xd0) == 0)
        NoOp_Stub(&DAT_00572fbc);
    int record_id = *(int *)(*(int *)(person + 0xcc) + 0x54);
    int cell = ((MapObject *)object)->GetRecord28(1, record_id);
    cell = ((Person *)person)->PickRandomLinkedCellInSteps(cell, 2);
    int target;
    if (*(int *)(person + 0xc8) != 0)
        target = *(int *)(*(int *)(person + 0xc8) + 0x20);
    else
        target = 0;
    ((Person *)person)->PathToTileAndStep(target, cell);
    ((CriticalSection *)*(void **)((char *)DAT_0057c670 + 0x240))->Leave();
}
