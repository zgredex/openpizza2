/* AI_WanderToRandomRoadTile: gives an idle object a random road wander target
   (0x50d790). */
int __cdecl Random_RangeFast(int low, int high);

struct Object;

struct Path {
    int Compute(int a, int b, int c);
};

struct Array {
    void *GetPtr4(unsigned index);
};

struct Wanderer {
    void AdvanceRoute(int target);
};

extern "C" void __fastcall AI_WanderToRandomRoadTile(void *object)
{
    int path;
    int target;

    if (*(int *)((char *)object + 0xc8) == 0) {
        return;
    }
    path = ((struct Path *)*(void **)((char *)object + 0xc4))->Compute(0, 0, 0);
    ((struct Wanderer *)object)->AdvanceRoute(path);
    target = Random_RangeFast(5, 0xc);
    target = (int)((struct Array *)(*(int *)((char *)object + 0xc8) + 0x14))
                 ->GetPtr4(target);
    if (target != 0) {
        ((struct Wanderer *)object)->AdvanceRoute(target);
    }
    *(int *)((char *)object + 0x108) = 5;
}
