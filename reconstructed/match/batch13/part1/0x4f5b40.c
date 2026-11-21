/* Object_CanAssignSlot (0x4f5b40). */
struct SlotHolder {
    int pad0[0xe];
    int slot;               /* 0x38 */
};
struct Request {
    char pad0[0x44];
    int first;              /* 0x44 */
    int second;             /* 0x48 */
    char pad1[8];           /* to 0x54 */
    int value;              /* 0x54 */
};
struct Object {
    char pad0[8];
    SlotHolder *holder;     /* 0x08 */
};

int __stdcall Object_CanAssignSlot(Object *object, Request *request,
                                  int *slotOut, int *changedOut)
{
    SlotHolder *holder;
    int value;

    *slotOut = -1;
    if (changedOut != 0)
        *changedOut = 0;
    holder = object->holder;
    if (holder->slot != 0) {
        value = holder->pad0[0];
        if (value != request->first && value != request->second) {
            if (request->value > 0xc8) {
                holder->slot = 0;
                if (changedOut != 0)
                    *changedOut = 1;
                return 0;
            }
            *slotOut = value;
            return 1;
        }
    }
    return 0;
}
