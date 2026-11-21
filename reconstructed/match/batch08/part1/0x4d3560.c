/* MapObject_PlaceAtPoint: places a map object at a screen point
   (0x4d3560). */
struct Record {
    void SetDoubles48(int index, int first, int second);
};

struct MapRecord {
    int index;
    char pad[0x1c];
    int *point;
    char pad2[0x34];
    struct Record *records;
};

struct MapObject {
    char pad[8];
    struct MapRecord *record;
    void PlaceAtPoint(int *point);
};

void MapObject::PlaceAtPoint(int *point)
{
    ((struct MapRecord *)this->record)->records->SetDoubles48(
        ((struct MapRecord *)this->record)->index, point[3] - 0xa0,
        point[4] - 0xd0);
    ((struct MapRecord *)this->record)->point = point;
}
