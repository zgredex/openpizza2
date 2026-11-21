/* RecordMap_Lookup1998: looks up a key in the map at offset 0x1998 (0x47f400). */
struct IDMap {
    void *Lookup(int key, int *out);
};

struct RecordMap {
    char pad[0x1998];
    IDMap map;
    void Lookup1998(int key);
};

void RecordMap::Lookup1998(int key)
{
    map.Lookup(key, 0);
}
