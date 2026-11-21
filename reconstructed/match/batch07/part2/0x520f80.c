/* UI_DetachChild (0x520f80, 48 bytes).  Build: /O2 /TP.
   Removes the child from its parent's effect list and clears the link. */
struct UI {
    void RemoveEffectObject(int child);
};

extern "C" void __fastcall UI_DetachChild(int child)
{
    if (*(int *)(child + 0x4c) != 0) {
        ((UI *)*(void **)(*(int *)(child + 8) + 0x134))->RemoveEffectObject(child);
        *(int *)(child + 0x48) = 0;
        *(int *)(child + 0x44) = 0;
        *(int *)(child + 0x4c) = 0;
    }
}
