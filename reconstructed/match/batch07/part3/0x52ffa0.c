/* Rect_ContainsPoint: inclusive-exclusive rectangle hit test (0x52ffa0). */
struct Point {
    int x;
    int y;
};

struct Rect {
    int field0;
    int field4;
    int left;
    int top;
    int right;
    int bottom;
    int ContainsPoint(Point *point);
};

int Rect::ContainsPoint(Point *point)
{
    if (point->x < left || point->x >= right || point->y < top ||
        point->y >= bottom)
        return 0;
    return 1;
}
