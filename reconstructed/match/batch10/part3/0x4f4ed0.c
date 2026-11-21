/* Object_ResetLinkVisitedFlags: clear the visited byte of each valid record. */
struct Object {
    void ResetLinkVisitedFlags();
    void ClearRecordFirstBytes(int *value);
    int GetBufferCount(int *which);
    char *GetRecord28(int which, int index);
    int CountValid8(char *record);
};

void Object::ResetLinkVisitedFlags()
{
    int i;

    ClearRecordFirstBytes(0);
    for (i = 0; i < GetBufferCount((int *)1); i++) {
        char *record = GetRecord28(1, i);

        if (CountValid8(record) == 0)
            *record = 1;
    }
}
