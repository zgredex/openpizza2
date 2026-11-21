/* Map_AssignObjectToCell: links an object record into the global id map and
   tags it with its cell kind (0x4d2280). */
struct IDMap {
    int *Lookup(int key, int *out);
};

struct Game;

extern struct Game *DAT_0057c670;

struct Map {
    void AssignObjectToCell(int object);
};

void Map::AssignObjectToCell(int object)
{
    ((struct IDMap *)((char *)DAT_0057c670 + 4))->Lookup(*(int *)((char *)this + 0x28), 0);
    *(unsigned int *)((char *)this + 0x54) = *(unsigned short *)(object + 4);
    if (object != 0) {
        if (*(int *)((char *)this + 4) == 0x20) {
            *(char *)(object + 6) = 2;
            return;
        }
        *(char *)(object + 6) = 1;
    }
}
