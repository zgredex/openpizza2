/* GamePlan_StreamConstruct: sets the vtable and loads the plan record (0x50f690). */
struct GamePlan {
    void **vtable;
    GamePlan *StreamConstruct(void *stream);
    void LoadRecord(void *stream);
};

GamePlan *GamePlan::StreamConstruct(void *stream)
{
    vtable = (void **)0x55c688;
    LoadRecord(stream);
    return this;
}
