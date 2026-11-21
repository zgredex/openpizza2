/* MissionGoal_Evaluate - 0x504430, 413 bytes */
struct Game
{
    char IsInputIndexUsed(int index);
    char AnyBuildingRatingAbove(int rating);
    char AnyBuildingCategoryRatingAbove(int rating);
    char IsObjectStatAbove(int value);
    char AllBuildingCategoryRatingsAbove(int rating);
};

struct UI
{
    void AppendCommandIfActive(int command, int value);
    void DecrementTimer(int timer, int flag);
};

struct List
{
    void Node_Reset();
};

struct MissionGoal
{
    char pad[0x48];
    int goal;
    char pad2[0x68 - 0x4c];
    List node;
    void Evaluate(int param_1);
    void HandleEvent(int event, int a, int b);
};

void MissionGoal::Evaluate(int param_1)
{
    switch (goal)
    {
    case 0x15:
        if (param_1 % 3 == 0)
            node.Node_Reset();
        break;
    case 0x18:
        ((UI *)this)->AppendCommandIfActive(0x18, -1);
        if (((Game *)this)->IsInputIndexUsed(0x50))
            HandleEvent(0x18, -1, -1);
        break;
    case 0x1b:
        ((UI *)this)->AppendCommandIfActive(0x1b, -1);
        if (((Game *)this)->AnyBuildingRatingAbove(0x50))
            HandleEvent(0x1b, -1, -1);
        break;
    case 0x1c:
        ((UI *)this)->AppendCommandIfActive(0x1c, -1);
        if (((Game *)this)->AnyBuildingCategoryRatingAbove(0x50))
            HandleEvent(0x1c, -1, -1);
        break;
    case 0x1e:
        ((UI *)this)->AppendCommandIfActive(0x1e, -1);
        if (((Game *)this)->IsObjectStatAbove(0x50))
            HandleEvent(0x1e, -1, -1);
        break;
    case 0x21:
        ((UI *)this)->AppendCommandIfActive(0x21, -1);
        if (((Game *)this)->AllBuildingCategoryRatingsAbove(0x32))
            HandleEvent(0x21, -1, -1);
        break;
    case 0x20:
        ((UI *)this)->AppendCommandIfActive(0x20, -1);
        if (((Game *)this)->IsInputIndexUsed(0x32) &&
            ((Game *)this)->AnyBuildingRatingAbove(0x32) &&
            ((Game *)this)->AnyBuildingCategoryRatingAbove(0x32) &&
            ((Game *)this)->IsObjectStatAbove(0x32) &&
            ((Game *)this)->AllBuildingCategoryRatingsAbove(0x32))
            HandleEvent(0x20, -1, -1);
        break;
    }
    ((UI *)this)->DecrementTimer(0x30, 1);
    ((UI *)this)->DecrementTimer(0xf, 1);
    ((UI *)this)->DecrementTimer(4, 1);
    ((UI *)this)->DecrementTimer(0x2c, 1);
    ((UI *)this)->DecrementTimer(0x30, 0);
    ((UI *)this)->DecrementTimer(0x10, 0);
    ((UI *)this)->DecrementTimer(4, 0);
}
