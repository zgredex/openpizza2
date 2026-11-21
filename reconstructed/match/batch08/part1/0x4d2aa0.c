/* Game_FindObjectByClass: finds the first object whose class field matches
   (0x4d2aa0). */
struct Game { char pad[0x8c]; int objectCount; int MapRecordToGlobal(int record); int FindObjectByClass(int classId); };
int Game::FindObjectByClass(int classId)
{
    int index = 0;
    while (index < objectCount) {
        int object = MapRecordToGlobal(index);
        if (*(int *)(object + 0x30) == classId) return object;
        index++;
    }
    return 0;
}
