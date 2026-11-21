/* Object_SetState: change an object state under the global lock. */
extern int DAT_0057c670;
extern "C" void __fastcall CS_Enter(int lock);
extern "C" void __fastcall CS_Leave(int lock);
extern "C" void __fastcall UI_DestroyChildObject(void *object);

struct Object {
    void SetState(int state);
};

void Object::SetState(int state)
{
    CS_Enter(*(int *)(DAT_0057c670 + 0x240));
    *(int *)((char *)this + 0x38) = state;
    if (state == 0x1f || state == 0x2e) {
        UI_DestroyChildObject(this);
        *(int *)((char *)this + 0xc4) = 0;
    }
    CS_Leave(*(int *)(DAT_0057c670 + 0x240));
}
