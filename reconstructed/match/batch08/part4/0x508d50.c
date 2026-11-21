/* Object_ApplyDeferredType: applies a deferred object type transformation
   (0x508d50). */
struct Object {
    void InitCompanyBuildingGraphics(int value);
    void SetState(int state);
    void ApplyDeferredType(int type);
};

struct UI {
    void SetChildIconAndRatingHeight();
};

void Object::ApplyDeferredType(int type)
{
    if (type != 0x10) {
        if (type != 0x23)
            return;
        *(int *)((char *)this + 0x30) = 0x23;
        ((Object *)this)->SetState(4);
        *(int *)((char *)this + 0xa0) = 0;
        return;
    }
    ((Object *)this)->InitCompanyBuildingGraphics(-1);
    ((UI *)this)->SetChildIconAndRatingHeight();
}
