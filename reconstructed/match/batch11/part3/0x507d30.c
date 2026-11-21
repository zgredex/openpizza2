struct Link { char pad[0x20]; int field20; int field24; };
struct Array { void *PickRandomActiveRecord28(int flag, int a, int b); };
struct MapObject {
    char pad[0xc4];
    struct Array *array;
    struct Link *link;
    void StepToRandomCell();
    int IsVisibleThisFrame();
    void PathToTileAndStep(int a, void *record);
    void RecomputePathStep(void *record);
};
void MapObject::StepToRandomCell()
{
    int a = this->link ? this->link->field20 : 0;
    int b = this->link ? this->link->field24 : 0;
    void *record = array->PickRandomActiveRecord28(1, a, b);

    if (IsVisibleThisFrame() != 0) {
        RecomputePathStep(record);
        return;
    }
    PathToTileAndStep(a, record);
}
