/* Car_LoadFromStream: deserialises a car and rebuilds its sprite record
   (0x4d34e0). */
extern "C" int DAT_0057c5cc;

struct IStream {
    void Read(void *destination, int size);
};

struct CarManager {
    int UpdateIDMapEntry(int id);
};

struct Car {
    void *vtable;
    int carId;
    int field8;
    int variant;

    void LoadFromStream(void *stream);
    void LoadSpriteRecord(void *stream);
};

void Car::LoadFromStream(void *stream)
{
    void *saved = stream;
    int id;

    ((IStream *)saved)->Read(&id, 4);
    carId = ((CarManager *)DAT_0057c5cc)->UpdateIDMapEntry(id);
    ((IStream *)saved)->Read((char *)this + 0xc, 4);
    ((Car *)this)->LoadSpriteRecord(saved);
}
