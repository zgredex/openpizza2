/* Object_ScrollViewToObject (0x508070): centers the map on an object's view
   rectangle when the object has a screen position. */
extern int DAT_0057c670;

struct Object;

struct Rect {
    void Center(int *x, int *y);
};

struct Map {
    void ScrollToClamped(void *view, int x, int y);
};

struct MapObject {
    char pad[0x74];
    int field74;
    char pad2[0xc4 - 0x78];
    Rect *view;                /* 0xc4 */
    void *fieldc8;             /* 0xc8 */
    void GetScreenPosition(int flag, int *x, int *y);
};

void __fastcall Object_ScrollViewToObject(void *param_1)
{
    MapObject *object = (MapObject *)param_1;
    int local_4;
    int local_8;

    if (object->view != 0 && object->fieldc8 != 0 &&
        *(int *)((char *)object->fieldc8 + 0x58) != 0) {
        object->GetScreenPosition(object->field74 != 0, &local_8, &local_4);
        object->view->Center(&local_8, &local_4);
        {
            int x = local_8;
            int y = local_4;
            Rect *view = object->view;
            ((Map *)DAT_0057c670)->ScrollToClamped(view, x, y);
        }
    }
}
