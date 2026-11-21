/* Object_GetRect100: copies the object's 0x100 rectangle fields to four
   outputs (0x4f3b30). */
struct Object {
    char pad[0x100];
    int f100;
    int f104;
    int f108;
    int f10c;
    void GetRect100(int *a, int *b, int *c, int *d);
};

void Object::GetRect100(int *a, int *b, int *c, int *d)
{
    *a = f100;
    *b = f108;
    *c = f104;
    *d = f10c;
}
