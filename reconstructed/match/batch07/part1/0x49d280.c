/* UI_RemoveAllObjects (0x49d280, 47 bytes).  Build: /O2 /TP.
   Removes every object reachable from key 100000 upward. */
struct Array {
    int GetRecordByKeyPtr(int key);
};

struct UI {
    void RemoveObject(int key);
};

extern "C" void UI_RemoveAllObjects(void *object)
{
    int key = 100000;

    while (((Array *)object)->GetRecordByKeyPtr(key) != 0) {
        ((UI *)object)->RemoveObject(key);
        key++;
    }
}
