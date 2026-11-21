/* Car_Save: saves a car sprite through the stream at offset 4 (0x4d3450). */
struct MapSprite {
    void Save(void *stream, int *record);
};

struct Car {
    char pad[4];
    MapSprite *sprite;
    int *record;
    void Save(void *stream);
};

void Car::Save(void *stream)
{
    sprite->Save(stream, record);
}
