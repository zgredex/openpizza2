struct Renderer {
    char pad0[0x14];
    int target;
    char pad1[0x24];
    int needsRelease;

    void ReleaseTarget();
};

void Renderer::ReleaseTarget()
{
    if (target != 0) {
        target = 0;
        needsRelease = 1;
    }
}
