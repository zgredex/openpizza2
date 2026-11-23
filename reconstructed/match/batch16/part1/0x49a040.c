/* Game_IsCompanyNameTaken (0x49a040): checks the active company list for
   an equal name. The boolean result is initialized before the list pointer is
   derived so the slot scratch uses EDX and the result uses CL. */
extern "C" int strcmp(const char *a, const char *b);
#pragma intrinsic(strcmp)
extern char *DAT_0057c670;
class IDMap { public: void *Lookup(int index, int *out); };
extern "C" bool __cdecl Game_IsCompanyNameTaken(unsigned char *name)
{
    bool result = false;
    int slot = *(int *)(DAT_0057c670 + 0x2ec);
    char *list = *(char **)(DAT_0057c670 + 0x200 + slot * 4);
    for (int index = 0; index < *(int *)(list + 0x124); index++) {
        int found = (int)((IDMap *)(list + 0x110))->Lookup(index, 0);
        if (found != *(int *)(DAT_0057c670 + 0x98)) {
            if (strcmp((char *)(found + 4), (char *)name) == 0) {
                result = true;
                break;
            }
        }
    }
    return result;
}
