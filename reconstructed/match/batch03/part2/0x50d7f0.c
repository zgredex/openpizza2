/* Object_GetLevelProperty - 0x50d7f0, 24 bytes */
extern int __fastcall Object_GetClampedLevel(void *this_);
extern int DAT_0056d0e0[];

struct Object
{
    int GetLevelProperty(int index);
};

int Object::GetLevelProperty(int index)
{
    int level = Object_GetClampedLevel(this);

    return DAT_0056d0e0[index + level * 2 + level];
}
