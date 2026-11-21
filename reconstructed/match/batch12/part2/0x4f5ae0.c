/* Object_ClearSlotRefs: clears an object's references in two slots
   (0x4f5ae0). */
struct Ref {
    char pad[0x38];
    int owner;
};

struct SlotObject {
    char pad[0x44];
    int slot44;
    int slot48;
};

struct Object {
    char pad[0x4c];
    int slots;

    void ClearSlotRefs(struct SlotObject *object);
};

void Object::ClearSlotRefs(struct SlotObject *object)
{
    if (object->slot44 != -1) {
        int *entry = (int *)(slots + object->slot44 * 0xc);

        if (entry != 0) {
            struct Ref *ref = (struct Ref *)entry[2];

            if (ref != 0) {
                ref->owner = 0;
            }
        }
        object->slot44 = -1;
    }
    if (object->slot48 != -1) {
        int *entry = (int *)(slots + object->slot48 * 0xc);

        if (entry != 0) {
            struct Ref *ref = (struct Ref *)entry[2];

            if (ref != 0) {
                ref->owner = 0;
            }
        }
        object->slot48 = -1;
    }
}
