/* UI_Text_BeginScrollAnimation: registers a text object with the effect
   manager and stores its scroll bounds (0x520f30). */
struct UI {
    void AddEffectObject(void *object);
    void BeginScrollAnimation(int low, int high);
};

void UI::BeginScrollAnimation(int low, int high)
{
    char *self = (char *)this;

    if (*(int *)(self + 0x4c) == 0) {
        ((UI *)*(int *)(*(int *)(self + 8) + 0x134))->AddEffectObject(this);
        *(int *)(self + 0x4c) = 1;
        *(int *)(self + 0x48) = high;
        *(int *)(self + 0x44) = low;
    } else {
        *(int *)(self + 0x48) = high;
        *(int *)(self + 0x44) = low;
    }
}
