/* Game_CenterViewOnObject (0x4d23b0). */
struct IDMap {
    char pad[0x14];
    void *Lookup(int key, int *out);
};
struct Rect {
    void Center(int *a, int *b);
};
struct MapView {
    char pad[0xfa8];
    void *map;              /* 0xfa8 */
};
struct Object {
    char pad0[0x28];
    int key;                /* 0x28 */

    int GetObjectCenterY();
    int GetObjectBottom();
    void CenterViewOnObject();
};
struct Game {
    char pad0[4];
    IDMap map;              /* 0x04 */

    void ScrollToClamped(void *map, int a, int b);
};
extern Game *DAT_0057c670;

void Object::CenterViewOnObject()
{
    MapView *record = (MapView *)DAT_0057c670->map.Lookup(key, 0);
    void *view = record->map;

    if (view != 0) {
        int center = GetObjectCenterY();
        int bottom = GetObjectBottom();
        int *centerPtr = &center;
        int *bottomPtr = &bottom;

        ((Rect *)view)->Center(centerPtr, bottomPtr);
        DAT_0057c670->ScrollToClamped(view, center, bottom);
    }
}
