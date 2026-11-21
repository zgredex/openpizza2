struct Object {
    char pad[0x30];
    int appliedType;
    char pad2[0x44];
    int pendingType;
    void ApplyPendingType(int type);
};

void Object::ApplyPendingType(int type)
{
    if (type != 0x23)
        appliedType = pendingType;
}
