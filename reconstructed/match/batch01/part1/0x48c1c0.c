/* Object_AbortOrderForTarget: abort an object's order when its target matches (0x48c1c0). */
int __fastcall State_Is2DOr2E(void *this_);
void __fastcall Object_AbortOrderAndReturnHome(void *this_);

void __stdcall Object_AbortOrderForTarget(void *obj, int target, int force)
{
    int current;

    if (State_Is2DOr2E(obj) != 0)
        return;
    if (force == 0 &&
        (*(int *)((char *)obj + 0xa4) == 0x19 ||
         *(int *)((char *)obj + 0xa4) == 0x1a))
        return;
    if (*(int *)((char *)obj + 0x74) != 0)
        current = *(int *)((char *)obj + 0xf4);
    else
        current = *(int *)((char *)obj + 0xfc);
    if (current == target) {
        Object_AbortOrderAndReturnHome(obj);
        if (*(int *)((char *)obj + 0x74) != 0)
            *(char *)((char *)obj + 0x81) = 1;
    }
}
