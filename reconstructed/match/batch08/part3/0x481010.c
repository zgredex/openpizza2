/* Branch_SetName: copies the branch name and refreshes its map marker
   (0x481010). */
#pragma intrinsic(strcpy)

extern "C" char * __cdecl strcpy(char *dest, const char *src);

struct Game {
    void UpdateObjectMapMarker();
};

struct Branch {
    char pad[4];
    char name[0x16f0 - 4];
    void *marker;              /* 0x16f0 */
    void SetName(char *value);
};

void Branch::SetName(char *value)
{
    strcpy(name, value);
    ((Game *)marker)->UpdateObjectMapMarker();
}
