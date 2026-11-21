/* Non-matching candidate.
   First difference: offset 0x43, 3 bytes differ.
   only the register pair used for the order pointer and player id is swapped (eax/ecx vs ecx/edx).
   Kept for evidence; not part of the strict match set. */
extern void *DAT_0057c670;

struct IDMap {
    void *Lookup(int key, int *out);
};

struct Game {
    int CountObjectsByState(int state);
};

struct Object {
    void SetFieldA4Locked(int state);
    void AbortOrderAndReturnHome();
};

void __stdcall Gangster_CancelJobsTargetingPlayer(int player, int cancel)
{
    int index = 0;
    int count = ((Game *)DAT_0057c670)->CountObjectsByState(-1);
    if (count > 0) {
        do {
            char *object = (char *)((IDMap *)((char *)DAT_0057c670 + 0x3c))
                               ->Lookup(index, 0);
            if (*(int *)(object + 0x30) == 0x1d &&
                (*(int *)(object + 0xa4) == 0x19 ||
                 *(int *)(object + 0xa4) == 0x1a) &&
                *(int *)(*(int *)(object + 0xfc) + 8) == player) {
                if (cancel == 0) {
                    ((Object *)object)->SetFieldA4Locked(0x1a);
                } else {
                    ((Object *)object)->AbortOrderAndReturnHome();
                    if (*(int *)(object + 0x74) != 0)
                        *(char *)(object + 0x81) = 1;
                }
            }
            index++;
            count = ((Game *)DAT_0057c670)->CountObjectsByState(-1);
        } while (index < count);
    }
}
