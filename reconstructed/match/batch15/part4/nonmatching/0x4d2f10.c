/* Non-matching candidate.
   First difference: offset 0x3d, 3 bytes differ.
   only Game_GetTimeByMode call scheduling differs (original pushes edi before mov ecx,esi).
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;

struct Game {
    void ReassignDestroyedObjectReferences(void *building);
    int GetTimeSegment();
    void ReassignObjectsFromRemovedBuilding(void *building);
};

struct MapObject {
    char pad0[0x4c];
    int field4c;
    char pad1[0x54 - 0x50];
    int field54;
    char pad2[0xd0 - 0x58];
    int fieldd0;
    int slots[10];
    void *fieldfc;
    void SetChildState(int state);
    void GetTimeByMode(int mode);
    void SetDestinationAndTarget(int mode, int target);
};

struct Building {
    char pad0[0x8c];
    int count;
    int MapRecordToGlobal(int index);
    void RemoveObjectFromList(void *object, int mode);
};

void __fastcall Building_EvictOccupants(Building *building)
{
    ((Game *)DAT_0057c670)->ReassignDestroyedObjectReferences(building);
    int index = building->count - 1;
    while (index >= 0) {
        MapObject *object = (MapObject *)building->MapRecordToGlobal(index);
        if (*(short *)((char *)object + 0x40) == 0x11) {
            object->field4c = 0;
            object->field54 = 0;
            object->SetChildState(-1);
            object->GetTimeByMode(0);
        }
        if (object->fieldfc != building) {
            building->RemoveObjectFromList(object, 1);
        } else {
            unsigned segment = (unsigned)((Game *)DAT_0057c670)->GetTimeSegment();
            int slot = object->slots[segment];
            object->SetDestinationAndTarget(6, slot);
            object->fieldd0 = slot;
        }
        index--;
    }
    ((Game *)DAT_0057c670)->ReassignObjectsFromRemovedBuilding(building);
}
