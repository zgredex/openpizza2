/* PC2 byte-match candidate: RefCount_Release (0x53ef70, 29 bytes).
   Build: /O2 /TP.  Decrements the count and releases at zero. */
struct RefCounted {
    virtual void slot_0();
    virtual void slot_1();
    virtual void slot_2();
    virtual void Release(int immediate);
    int count;
};

int __stdcall RefCount_Release(RefCounted *object)
{
    if (--object->count == 0) {
        if (object != 0)
            object->Release(1);
        return 0;
    }
    return object->count;
}
