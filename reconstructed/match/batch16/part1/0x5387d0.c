// Renderer_ReleaseTargets @ 0x5387d0 (148 bytes)
// Releases the renderer's render targets and resets the target table.

typedef void (__stdcall *TargetRelease)(void *target);
typedef void (__stdcall *TargetConfigure)(void *target, int value, int flag);

struct TargetSet {
    void *field0;
    void *field4;
    void *field8;
};

class Renderer {
public:
    char pad0[0x30];
    char flag30;
    char pad31[0xf];
    TargetSet *targetSet;
    int field44;
    int field48;
    int field4c;

    void ReleaseTargets();
    void InitOrCopyState(int value);
    void CopyStateToChildren();
};

void Renderer::ReleaseTargets()
{
    if (this->targetSet->field0 == 0)
        return;
    this->flag30 = 0;
    if (this->field48 != 0)
        return;
    if (this->targetSet->field8 != 0) {
        (*(TargetRelease *)(*(int *)this->targetSet->field8 + 8))(this->targetSet->field8);
        this->targetSet->field8 = 0;
    }
    if (this->targetSet->field4 != 0) {
        (*(TargetRelease *)(*(int *)this->targetSet->field4 + 8))(this->targetSet->field4);
        this->targetSet->field4 = 0;
    }
    if (this->field4c == 0) {
        (*(TargetRelease *)(*(int *)this->targetSet->field0 + 0x4c))(this->targetSet->field0);
        (*(TargetConfigure *)(*(int *)this->targetSet->field0 + 0x50))(
            this->targetSet->field0, this->field44, 8);
    }
    (*(TargetRelease *)(*(int *)this->targetSet->field0 + 8))(this->targetSet->field0);
    this->targetSet->field0 = 0;
    this->InitOrCopyState(0);
    this->CopyStateToChildren();
}
