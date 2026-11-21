/* UI_BriefingList_Construct: constructs the briefing list object
   (0x54a880). */
struct List {
    void Construct(int value);
};

void * __fastcall UI_BriefingList_Construct(void *self)
{
    ((List *)((char *)self + 4))->Construct(0);
    *(void **)self = (void *)0x55cb40;
    *(int *)((char *)self + 0x20) = 0x122;
    *(int *)((char *)self + 0x24) = 0x22d;
    *(int *)((char *)self + 0x28) = 0x20;
    *(int *)((char *)self + 0x34) = 0;
    *(int *)((char *)self + 0x30) = 0;
    return self;
}
