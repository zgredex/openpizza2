/* Car_PickRandomRoadStep: sends an idle car to a random road record (0x4d35e0). */
struct Array {
    void *GetRandomRecord28B(int index);
};

struct Car {
    char pad[4];
    Array *array;
    char *road;
    void DriveToPoint(int point, void *record);
    void PickRandomRoadStep();
};

void Car::PickRandomRoadStep()
{
    int point = *(int *)(road + 0x20);
    void *record = array->GetRandomRecord28B(0);

    DriveToPoint(point, record);
}
