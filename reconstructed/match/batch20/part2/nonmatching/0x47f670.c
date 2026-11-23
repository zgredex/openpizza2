/* Company::RemoveAttachedBuildingObjects (0x47f670). */
extern "C" void __fastcall CS_Enter(void *);
extern "C" void __fastcall CS_Leave(void *);
struct IDMapHelper {
    char pad[0x1c];
    void *Lookup(int key, int *index);
};

struct Game {
    char pad0[0x3c];
    IDMapHelper persons;
    char pad1[0x240 - 0x3c - 0x1c];
    void *lock;
    void *MapRecordToGlobal(int index);
};

extern "C" Game *g_Game;

struct Building {
    char pad[0x8c];
    int count;
};

struct Object {
    void SetState(int state);
    void SetFieldA4Locked(int value);
};

struct Person {
    char pad[0x74];
    int attached;
    char pad2[0xf4 - 0x78];
    void *owner;
    int CanContinuePath();
    void TruncatePathToCurrentStep();
};

struct UI {
    void DetachChildRecord();
};

struct Branch {
    void RemoveBuildingObject(void *record);
};

struct Company {
    int RemoveAttachedBuildingObjects();
};

int Company::RemoveAttachedBuildingObjects()
{
    int result = 0;
    Building *building;
    int i;
    Person *person;

    CS_Enter(g_Game->lock);
    building = *(Building **)((char *)this + 0x16f0);
    if (building == 0) {
        CS_Leave(g_Game->lock);
        return 0;
    }
    i = building->count - 1;
    if (i >= 0) {
    do {
        int *record = (int *)((Game *)building)->MapRecordToGlobal(i);
        if (record[0xc] >= 0x2b && record[0xc] <= 0x2c) {
            int personId = record[0x43];
            person = (Person *)g_Game->persons.Lookup(personId, 0);
            if (person != 0 && person->attached != 0 &&
                person->owner == *(void **)((char *)this + 0x16f0)) {
                if (person->CanContinuePath() == 0) {
                    ((UI *)person)->DetachChildRecord();
                } else {
                    person->TruncatePathToCurrentStep();
                }
                ((Object *)person)->SetState(6);
                ((Object *)person)->SetFieldA4Locked(-1);
            }
            ((Branch *)this)->RemoveBuildingObject(record);
            result = 1;
        }
        i--;
    } while (i >= 0);
    }
    CS_Leave(g_Game->lock);
    if (result != 0) {
        *(int *)((char *)this + 0x1718) = 0;
    }
    return result;
}
