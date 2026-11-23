// Palette_Init @ 0x535d70 (154 bytes)
// Initializes a palette from a 256-color table, using stack or heap storage.

extern "C" void *operator_new(unsigned int size);
extern "C" void *memcpy(void *dest, const void *source, unsigned int size);
#pragma intrinsic(memcpy)

class Palette {
public:
    int *data;
    char pad0[0x202];
    short field206;
    char field208;

    Palette *Initialize(int param, int *source, int useStack);
    void Convert256(int param);
};

Palette *Palette::Initialize(int param, int *source, int useStack)
{
    int local[0xc0];
    int *buffer;

    this->field206 = -1;
    this->field208 = 0;
    if (useStack != 0) {
        this->data = local;
        memcpy(local, source, 0x300);
        this->Convert256(param);
        this->data = 0;
        return this;
    }
    buffer = (int *)operator_new(0x300);
    this->data = buffer;
    memcpy(buffer, source, 0x300);
    this->Convert256(param);
    return this;
}
