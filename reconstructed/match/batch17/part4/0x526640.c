struct UI {
    void QueueControlCommand(int command, int arg1, int arg2);
    void RefreshChildRect();
    void ForgetChildById(int id);
};

extern "C" int __fastcall Get_Field24(int object);
extern "C" void __fastcall Clear_Field228(int object);

void UI::ForgetChildById(int id)
{
    if (*(int *)((char *)this + 0x230) != 0 &&
        *(int *)(*(int *)((char *)this + 0x230) + 8) == id)
        *(int *)((char *)this + 0x230) = 0;
    if (id == *(int *)((char *)this + 0x82c8)) {
        *(int *)((char *)this + 0x82c8) = 0;
        *(int *)((char *)this + 0x82d4) = 0;
    }
    if (id == *(int *)((char *)this + 0x224)) {
        *(int *)((char *)this + 0x224) = 0;
        *(int *)((char *)this + 0x22c) = 0;
    }
    if (id == *(int *)((char *)this + 0x82d0)) {
        if (*(int *)((char *)this + 0x82d0) != 0 &&
            *(int *)((char *)this + 0x82dc) != 0) {
            if (Get_Field24(*(int *)((char *)this + 0x82dc)) != 0)
                ((UI *)*(void **)((char *)this + 0x82d0))
                    ->QueueControlCommand(
                        *(int *)(*(int *)((char *)this + 0x82dc) + 4), 0xd, 0);
        }
        RefreshChildRect();
        *(int *)((char *)this + 0x82dc) = 0;
        *(int *)((char *)this + 0x82d0) = 0;
    }
    if (id == *(int *)((char *)this + 0x8338)) {
        *(int *)((char *)this + 0x833c) = 0;
        *(int *)((char *)this + 0x8348) = 0;
    }
    if (id == *(int *)((char *)this + 0x228))
        Clear_Field228((int)this);
}
