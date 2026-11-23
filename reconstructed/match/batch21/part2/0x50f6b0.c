// GamePlan_SaveRecord @ 0x50f6b0 (156 bytes)
// Writes the serialized game-plan fields to an output stream in save order.

class OStream {
public:
    void Write(void *data, int size);
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

    void SaveRecord(OStream *stream);
};

void GamePlan::SaveRecord(OStream *stream)
{
    stream->Write(&f04, 4);
    stream->Write(&f08, 4);
    stream->Write(&f10, 4);
    stream->Write(&f14, 4);
    stream->Write(&f18, 4);
    stream->Write(&f1c, 4);
    stream->Write(&f20, 4);
    stream->Write(&f2c, 4);
    stream->Write(&f0c, 4);
    stream->Write(&f24, 4);
    stream->Write(&f28, 4);
}
