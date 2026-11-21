/* Object_GetChildOrigin: returns the origin stored in the child object
   (0x527ad0). */
struct Object {
    char pad[0x8310];
    int *child;
    void GetChildOrigin(int *x, int *y);
};

void Object::GetChildOrigin(int *x, int *y)
{
    int *c = child;

    if (c != 0) {
        *x = c[3];
        *y = c[4];
        return;
    }
    *x = 0;
    *y = 0;
}
