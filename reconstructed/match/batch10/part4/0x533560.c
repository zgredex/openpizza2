/* Sprite_GetPointPair (0x533560): returns the sprite's point pair as integers
   when the index is in range. */
struct PointPair {
    int key;
    int flags;
    double x;
    double y;
    char pad[0x48 - 0x18];
};

struct Sprite {
    char pad[0x48];
    int count;
    PointPair *points;

    char GetPointPair(int index, int *x, int *y);
};

char Sprite::GetPointPair(int index, int *x, int *y)
{
    if (index < 0 || index >= count)
        return 0;
    *x = (int)points[index].x;
    *y = (int)points[index].y;
    return 1;
}
