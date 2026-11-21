/* UI_FindStringRecord: finds a string record and returns its address
   (0x527810). */
struct StringList {
    int Find(char *name, int *index);
};

struct UI {
    char pad[0x82f8];
    char *records;
    int FindStringRecord(char *name);
};

int UI::FindStringRecord(char *name)
{
    if (((StringList *)this)->Find(name, (int *)&name) != 0)
        return (int)&records[(int)name * 0x48];
    return 0;
}
