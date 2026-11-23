// GamePlan_LoadRecord @ 0x50f750 (156 bytes)
// Reads the serialized game-plan fields from an input stream in save order.

class IStream {
public:
    void Read(void *data, int size);
};

class GamePlan {
public:
    char pad0[4];
    int f04;
    int f08;
    int f0c;
    int f10;
    int f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int f2c;

    void LoadRecord(IStream *stream);
};

void GamePlan::LoadRecord(IStream *stream)
{
    stream->Read(&f04, 4);
    stream->Read(&f08, 4);
    stream->Read(&f10, 4);
    stream->Read(&f14, 4);
    stream->Read(&f18, 4);
    stream->Read(&f1c, 4);
    stream->Read(&f20, 4);
    stream->Read(&f2c, 4);
    stream->Read(&f0c, 4);
    stream->Read(&f24, 4);
    stream->Read(&f28, 4);
}
