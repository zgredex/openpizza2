/* UI_ShowChildByID: find a child by id and activate it (0x5316b0). */
int __fastcall BinarySearch8(void *this_, int dummy, int key, int zero);
void __fastcall UI_Child_Activate(void *this_);

int __fastcall UI_ShowChildByID(void *this_, int dummy, int id)
{
    int index = BinarySearch8(this_, dummy, id, 0);
    if (index == -1)
        return 0;
    UI_Child_Activate(*(void **)(*(int *)((char *)this_ + 0xe8) + index * 8));
    return 1;
}
