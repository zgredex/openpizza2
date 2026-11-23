// UI_SetBackgroundSurfaceEnabled @ 0x526e80 (150 bytes)
// Enables or disables the UI background surface under the global lock.

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(
    void *handle, unsigned long milliseconds);

extern void *DAT_0057c0d8;
extern char *DAT_0057c5c8;

class CS {
public:
    void Enter();
    void Leave();
};

class Object {
public:
    int GetRootType();
};

class Sprite {
public:
    void ClearBuffers(int first, int second);
};

class UI {
public:
    char pad0[0x1c0];
    int field1c0;
    char pad1[0x1c8 - 0x1c4];
    CS *lock;
    char pad2[0x284 - 0x1cc];
    int field284;
    char pad3[0x8358 - 0x288];
    int field8358;

    void SetBackgroundSurfaceEnabled(int enabled);
    void MarkFullRectDirty();
};

void UI::SetBackgroundSurfaceEnabled(int enabled)
{
    int value;

    if (WaitForSingleObject(DAT_0057c0d8, 0) == 0)
        return;
    this->lock->Enter();
    this->field284 = enabled;
    if (enabled != 0) {
        if (*(int *)(DAT_0057c5c8 + 0x98) == 0 && this->field8358 == 0) {
            if (((Object *)DAT_0057c5c8)->GetRootType() == 2) {
                int *source = *(int **)(DAT_0057c5c8 + 0x40);
                this->field1c0 = source ? source[2] : 0;
            }
            ((Sprite *)DAT_0057c5c8)->ClearBuffers(this->field1c0, 0);
        }
        this->MarkFullRectDirty();
    }
    this->lock->Leave();
}
