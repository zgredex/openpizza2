/* UI_DetachObject: detaches the object from the renderer effects (0x521b90). */
struct UI {
    void RemoveEffectObject(void *object);
};

struct Renderer {
    char pad[0x134];
    UI *ui;
};

struct Object {
    int field0;
    int field4;
    Renderer *renderer;
    char pad[0x40];
    int field4C;
    char pad2[0x20];
    int field70;
    int field74;
    void DetachObject();
};

void Object::DetachObject()
{
    if (field4C != 0) {
        renderer->ui->RemoveEffectObject(this);
        field4C = 0;
    }
    field74 = 0;
    field70 = 0;
}
