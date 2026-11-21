/* MapObject_GetScreenPosition: converts the record coordinates to screen
   space with a fixed 0xa0/0xd0 offset (0x505ef0). */
struct Record {
    int GetTwoFloats48(int id, int *outX, int *outY);
};

struct Rec {
    int id;
    char pad[0x54];
    Record *field58;
};

struct MapObject {
    char pad[0xc8];
    Rec *rec;

    void GetScreenPosition(int flag, int *x, int *y);
};

void MapObject::GetScreenPosition(int flag, int *x, int *y)
{
    int localX;
    int localY;

    if (rec != 0) {
        rec->field58->GetTwoFloats48(rec->id, &localX, &localY);
        *x = localX + 0xa0;
        *y = localY + 0xd0;
    }
}
