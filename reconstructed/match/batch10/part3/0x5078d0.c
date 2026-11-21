/* Person_PathToTileAndStep: start a path to a tile and advance one step. */
extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void);

struct Object {
    int TryStepToTile(int mode, void *target, int x, int y);
    void UpdateWalkStep(void *target, unsigned long time);
};

struct Person {
    char pad[0xc4];
    Object *object;
    void *target;
    int PathToTileAndStep(int x, int y);
};

int Person::PathToTileAndStep(int x, int y)
{
    int result = 0;

    if (target != 0) {
        result = object->TryStepToTile(1, target, x, y);
        object->UpdateWalkStep(target, timeGetTime());
    }
    return result;
}
