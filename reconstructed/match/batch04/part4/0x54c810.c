/* PC2 byte-match candidate: List_FreeValuesAndObject (0x54c810, 28 bytes).
   Build: /O2 /TP.  Frees the container values and releases the object. */
struct ListObject {
    virtual void Release(int immediate);
};

struct List {
    ListObject *object;
    void FreeContainerValues();
    void FreeValuesAndObject();
};

void List::FreeValuesAndObject()
{
    FreeContainerValues();
    if (object != 0) {
        object->Release(1);
        object = 0;
    }
}
