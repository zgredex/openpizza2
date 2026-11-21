/* Car_DriveToPoint: steps a car's object toward a tile and advances its
   walk animation (0x4d35a0). */
extern unsigned int (__stdcall *DAT_0055c294)(void);

struct Object {
    void TryStepToTile(int zero, void *sprite, int x, int y);
    void UpdateWalkStep(void *sprite, unsigned int time);
};

struct Car {
    char pad[4];
    Object *object;
    void *sprite;
    void DriveToPoint(int x, int y);
};

void Car::DriveToPoint(int x, int y)
{
    object->TryStepToTile(0, sprite, x, y);
    object->UpdateWalkStep(sprite, DAT_0055c294());
}
