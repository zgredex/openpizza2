/* Object_PlaceSpriteAtCenter: places the object's sprite record relative to
   the screen center (0x505eb0). */
struct Record {
    void SetDoubles48(int a, int b, int c);
};

struct Sprite {
    int field0;
    char pad[0x54];
    Record *record;
};

struct Object {
    char pad[0xc8];
    Sprite *sprite;
    void PlaceSpriteAtCenter(int mode, int x, int y);
};

void Object::PlaceSpriteAtCenter(int mode, int x, int y)
{
    if (sprite != 0) {
        if (mode == 1) {
        }
        sprite->record->SetDoubles48(sprite->field0, x - 0xa0, y - 0xd0);
    }
}
