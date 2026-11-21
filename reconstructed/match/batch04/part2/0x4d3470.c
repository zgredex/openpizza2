/* Car_LoadSpriteRecord: initializes the sprite and reads the actor record (0x4d3470). */
struct MapSprite {
    void *vtable;
    void InitializeRecord();
};

struct MapActor {
    void ReadFromStream(void *stream, void *record);
};

struct Car : MapSprite {
    void *actor;
    void *spriteRecord;
    void LoadSpriteRecord(void *stream);
};

void Car::LoadSpriteRecord(void *stream)
{
    InitializeRecord();
    ((MapActor *)actor)->ReadFromStream(stream, spriteRecord);
}
